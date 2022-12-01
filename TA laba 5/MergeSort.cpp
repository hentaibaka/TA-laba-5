#include "include.h"
#include "List1.h"

template <typename T>
Node1<T>* List1<T>::Sort(Node1<T>* left, Node1<T>* right) {
	Node1<T>* res = nullptr;

	if (left == nullptr) return right;
	if (right == nullptr) return left;

	if (left->Value < right->Value) {
		res = left;
		res->Next = Sort(left->Next, right);
	}
	else {
		res = right;
		res->Next = Sort(left, right->Next);
	}
	return res;
}
template <typename T>
void List1<T>::Split(Node1<T>* head, Node1<T>** refLeft, Node1<T>** refRight) {
	Node1<T>* slow = head;
	Node1<T>* fast = head->Next;

	while (fast != nullptr) {
		fast = fast->Next;
		if (fast != nullptr) {
			slow = slow->Next;
			fast = fast->Next;
		}
	}

	*refLeft = head;
	*refRight = slow->Next;
	slow->Next = nullptr;
}
template <typename T>
void List1<T>::RecurciveMergeSort(Node1<T>** refHead) {
	Node1<T>* head = *refHead;
	Node1<T>* left = nullptr;
	Node1<T>* right = nullptr;

	if (head == nullptr || head->Next == nullptr) return;

	Split(head, &left, &right);

	RecurciveMergeSort(&left);
	RecurciveMergeSort(&right);

	*refHead = Sort(left, right);
}
template <typename T>
void List1<T>::MergeSort() {
	Node1<T>* head = First;
	RecurciveMergeSort(&head);
	First = head;
}
