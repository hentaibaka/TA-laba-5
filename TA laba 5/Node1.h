#ifndef NODE1_H
#define NODE1_H
template <typename T> 
class Node1 {
public:
	T Value;
	Node1<T>* Next;
	Node1(T value);
};
#endif 
