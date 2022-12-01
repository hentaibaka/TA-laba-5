#ifndef NODE2_H
#define NODE2_H
template <typename T>
class Node2 {
public:
	T Value;
	Node2<T>* Prev;
	Node2<T>* Next;
	Node2(T value);
};
#endif 