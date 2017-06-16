#include <iostream>

template <typename T = int, typename... Args>
class SinglyLList {
	struct Node {
		T value;
		Args... data;
		Node *next;
		
		Node(T keyValue, Args... args)
		: value(keyValue)
		, data(args)
		, next(nullptr)
		{}
	};
};
