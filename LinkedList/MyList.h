#pragma once
#include <string>

class MyList {
private:
	struct Node {
		int val;
		Node* next;
		Node* prev;

		Node(int value);
	};

	int count = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
	void firstNode(int value);
public:
	MyList();
	MyList(int value);
	void append(int value);
	void prepend(int value);
	void insert(int index, int value);
	int get(int index);
	int size();
	std::string print();
	int getHead();
	int getTail();
};