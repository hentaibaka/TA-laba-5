#include "List1.h"
#include "include.h"

template <typename T>
List1<T>::List1() {
    First = nullptr;
    Size = 0;
}
template <typename T>
void List1<T>::PushBack(Node1<T>* node) {
    if (First == nullptr) PushFront(node);
    else {
        Node1<T>* n = First;
        while (n->Next) n = n->Next;
        n->Next = node;
        Size++;
    }
}
template <typename T>
void List1<T>::PopBack() {
    if (First == nullptr) return;
    else {
        Node1<T>* n = First;
        Node1<T>* p = nullptr;
        while (n->Next) {
            p = n;
            n = n->Next;
        }
        if (!p) PopFront();
        else {
            p->Next = nullptr;
            delete n;
        }
    }
    Size--;
}
template <typename T>
void List1<T>::PushFront(Node1<T>* node) {
    if (First != nullptr) node->Next = First;
    First = node;
    Size++;
}
template <typename T>
void List1<T>::PopFront() {
    if (First == nullptr) return;

    Node1<T>* n = First;

    First = n->Next;

    delete n;
    Size--;
}
template <typename T>
Node1<T>* List1<T>::GetNth(unsigned int i) {
    if (First == nullptr) return nullptr;

    Node1<T>* n = First;

    for (i; i > 0; i--) {
        n = n->Next;
        if (!n) {
            //cout << "index out of range" << endl;
            return nullptr;
        }
    }
    return n;
}
template <typename T>
void List1<T>::DeleteNth(unsigned int i) {
    if (First == nullptr) return;
    Node1<T>* n = First;
    Node1<T>* p = nullptr;
    for (i; i > 0; i--) {
        if (!n->Next) break;
        p = n;
        n = n->Next;
    }
    if (!p) PopFront();
    else if (i == 0) {
        p->Next = n ? n->Next : nullptr;
        delete n;

        Size--;
    }
    else cout << "index out of range" << endl;
}
template <typename T>
void List1<T>::Insert(unsigned int i, Node1<T>* node) {
    if (i == 0 or First == nullptr) PushFront(node);
    else {
        Node1<T>* n = First;
        for (i; i > 1; i--) {
            n = n->Next;

            if (!n->Next) {
                PushBack(node);
                return;
            }
        }
        if (i == 1) {
            Node1<T>* p = n->Next;
            n->Next = node;
            n->Next->Next = p;

            Size++;
        }
    }
}
template <typename T>
void List1<T>::DeleteAll(T value) {
    if (!First) return;

    Node1<T>* n = First->Next;
    Node1<T>* p = First;
    Node1<T>* t = nullptr;

    while (n) {
        if (n->Value == value) {
            p->Next = n->Next;
            t = n;
        }
        n = n->Next;
        if (!t)p = p->Next;
        else {
            delete t;
            t = nullptr;

            Size--;
        }
    }
    if (First && First->Value == value) PopFront();
}
template <typename T>
void List1<T>::Show() {
    if (First == nullptr) {
        cout << "empty list" << endl;
    }

    Node1<T>* n = First;

    cout << "size(" << Size << ") ";

    while (n) {
        cout << n->Value << " ";
        n = n->Next;
    }

    cout << endl;
}
