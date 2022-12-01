#include "Node1.h"

template <typename T>
Node1<T>::Node1(T value) {
	Value = value;
	Next = nullptr;
}