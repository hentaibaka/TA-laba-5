#include "List2.h"
#include "include.h"

template <typename T>
List2<T>::List2() {
    First = nullptr;
    Last = nullptr;
    Size = 0;
}
template <typename T>
void List2<T>::PushFront(Node2<T>* node) {
    if (!Last) Last = node;
    if (First) {
        node->Next = First;
        First->Prev = node;
    }
    First = node;

    Size++;
}
template <typename T>
void List2<T>::PushBack(Node2<T>* node) {
    if (!First) First = node;
    if (Last) {
        node->Prev = Last;
        Last->Next = node;
    }
    Last = node;

    Size++;
}
template <typename T>
void List2<T>::PopFront() {
    if (!First) return;
    if (First == Last) Last = nullptr;
    Node2<T>* node = First;
    First = First->Next;
    First->Prev = nullptr;
    delete node;

    Size--;
}
template <typename T>
void List2<T>::PopBack() {
    if (!First) return;
    if (First == Last) First = nullptr;
    Node2<T>* node = Last;
    Last = Last->Prev;
    Last->Next = nullptr;
    delete node;

    Size--;
}
template <typename T>
Node2<T>*List2<T>::GetNth(unsigned int n) {
    Node2<T>* node = First;
    for (unsigned int i = 0; i < n; i++) {
        if (node == nullptr) return nullptr;
        node = node->Next;
    }
    return node;
}
template <typename T>
void List2<T>::Insert(unsigned int n, Node2<T>* node) {
    Node2<T>* temp = First;
    for (n; n > 0; n--) {
        if (!temp) break;
        temp = temp->Next;
    }
    if (temp == First) PushFront(node);
    else if (temp) {
        temp->Prev->Next = node;
        node->Prev = temp->Prev;
        temp->Prev = node;
        node->Next = temp;
        Size++;
    }
    else PushBack(node);
}
template <typename T>
void List2<T>::DeleteNth(unsigned int n) {
    if (First == nullptr) return;
    Node2<T>* node = First;
    for (n; n > 0; n--) {
        if (!node) break;
        node = node->Next;
    }
    if (node == First) PopFront();
    else if (node == Last) PopBack();
    else if (node) {
        node->Prev->Next = node->Next;
        node->Next->Prev = node->Prev;
        Size--;
    }
    else cout << "index out of range" << endl;
}
template <typename T>
void List2<T>::DeleteAll(T value) {
    if (!First) return;
    Node2<T>* n = First;
    Node2<T>* p = nullptr;
    while (n) {
        if (n->Value == value) {
            if (n->Prev) n->Prev->Next = n->Next;
            else First = n->Next;
            if (n->Next) n->Next->Prev = n->Prev;
            else Last = n->Prev;
            p = n;
            Size--;
        }
        n = n->Next;
    }
}
template <typename T>
void List2<T>::Show() {
    if (First == nullptr) {
        cout << "empty list" << endl;
        return;
    }

    cout << "size(" << Size << ") ";

    Node2<T>* cur = First;
    while (cur != nullptr) {
        cout << cur->Value << " ";
        cur = cur->Next;
    }
    cout << endl;
}
