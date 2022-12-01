#ifndef LIST2_H
#define LIST2_H
#include "Node2.h"

template <typename T>
class List2 {
    Node2<T>* First;
    Node2<T>* Last;
    int Size;
public:
    List2();
    void PushFront(Node2<T>* node);
    void PushBack(Node2<T>* node);
    void PopFront();
    void PopBack();
    Node2<T>* GetNth(unsigned int n);
    void Insert(unsigned int n, Node2<T>* node);
    void DeleteNth(unsigned int n);
    void DeleteAll(T value);
    void Show();
    void InsertionSort();
};
#endif 
