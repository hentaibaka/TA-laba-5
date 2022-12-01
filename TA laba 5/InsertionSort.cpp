#include "List2.h"
#include "include.h"

template <typename T>
void List2<T>::InsertionSort() {
    if (Size < 2) return;

    Node2<T>* temp;
    Node2<T>* cur;

    for (int i = 1; i < Size; i++) {

        temp = GetNth(i);
        cur = temp->Prev;

        while (cur != nullptr && cur->Value > temp->Value) {

            if (cur->Prev) cur->Prev->Next = temp;
            temp->Prev = cur->Prev;

            if (temp->Next) temp->Next->Prev = cur;
            cur->Next = temp->Next;

            cur->Prev = temp;
            temp->Next = cur;

            if (First == cur) First = temp;
            if (Last == temp) Last = cur;

            cur = temp->Prev;
        }
    }
}