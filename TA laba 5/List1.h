#ifndef LIST1_H
#define LIST1_H
#include "Node1.h"

template <typename T>
class List1 {
	Node1<T>* First;
	int Size;
	void RecurciveMergeSort(Node1<T>** refHead);
	void Split(Node1<T>* head, Node1<T>** refLeft, Node1<T>** refRight);
	Node1<T>* Sort(Node1<T>* left, Node1<T>* right);
public:
	List1();
	void PushBack(Node1<T>* node);
	void PopBack();
	void PushFront(Node1<T>* node);
	void PopFront();
	Node1<T>* GetNth(unsigned int i);
	void DeleteNth(unsigned int i);
	void Insert(unsigned int i, Node1<T>* node);
	void DeleteAll(T value);
	void Show();
	void MergeSort();
};
#endif 