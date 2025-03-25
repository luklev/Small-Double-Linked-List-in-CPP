#include "MyList.h"
#include <iostream>

//List class

MyList::MyList() {
	if (count != 0) return;

	count = 0;
	head = tail = nullptr;
}

void MyList::firstNode(int value) {
	if (count != 0) return;
	count = 1;
	head = new Node(value);
	tail = head;
	return;
}

MyList::MyList(int value) {
	firstNode(value);
}

void MyList::append(int value) {
	if (count == 0) {
		firstNode(value);
		return;
	}

	Node* oldTail = tail;
	tail = new Node(value);
	oldTail->next = tail;
	tail->prev = oldTail;
	count++;
	return;
}

void MyList::prepend(int value) {
	if (count == 0) {
		firstNode(value);
		return;
	}

	Node* oldHead = head;
	head = new Node(value);
	oldHead->prev = head;
	head->next = oldHead;
	count++;
	return;
}

void MyList::insert(int index, int value) {
	if (index > count || index < 0) return;
	if (count == 0) {
		firstNode(value);
		return;
	}
	if (index == 0) {
		prepend(value);
		return;
	}
	if (index == count) {
		append(value);
		return;
	}

	Node* newNode = new Node(value);
	Node* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	Node* oldPrev = current->prev;
	oldPrev->next = newNode;
	current->prev = newNode;
	newNode->prev = oldPrev;
	newNode->next = current;
	count++;
	return;
}

int MyList::get(int index) {
	if (index >= count || index < 0) return 0;
	Node* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current->val;
}

int MyList::size() {
	return count;
}

std::string MyList::print() {
	std::string output = "size: " + std::to_string(count) + "\n";
	if (count <= 0) return output;
	Node* current = head;
	for (int i = 0; i < count-1; i++) {
		output += std::to_string(current->val) + " <-> ";
		current = current->next;
	}
	output += std::to_string(tail->val) + "\n";
	return output;
}

int MyList::getHead() {
	return head->val;
}

int MyList::getTail() {
	return tail->val;
}

//Node struct

MyList::Node::Node(int value) {
	val = value;
	next = prev = nullptr;
}