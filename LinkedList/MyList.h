#pragma once
#include <string>

/**
* Author: Lukas Levien
* Date: 25/03/2025
* Description: Simple Double Linked List with Integer Values.
* Has: Add & Remove functions
* Planned: Iterator, Sorting
*/
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

	void initialNode(int value);
	bool isEmpty();
	Node* getNodeByIndex(int index);
	Node* getNodeByValue(int value);
	void removeNode(Node* node);
	void removeLonelyNode();
public:
	//constructors
	MyList();
	MyList(int value);

	//add functions
	void append(int value);
	void prepend(int value);
	void insert(int index, int value);

	//remove functions
	void removeAt(int index);
	void removeValue(int value);
	void removeHead();
	void removeTail();
	void clear();

	//iterate funcitons


	//sort functions


	//getters
	int get(int index);
	int size();
	std::string print();
	int getHead();
	int getTail();
};