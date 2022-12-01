#include "Node2.h"

template <typename T>
Node2<T>::Node2(T value) {
	Value = value;
	Prev = nullptr;
	Next = nullptr;
}