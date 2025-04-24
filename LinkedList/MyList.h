#pragma once
#include <string>

/**
* Author: Lukas Levien
* Date: 25/03/2025
* Description: Simple Double Linked List with Integer Values.
* Has: Add & Remove functions
* Planned: Iterator, Sorting
*/
template <typename T>
class MyList {
private:
	struct Node {
		T val;
		Node* next;
		Node* prev;

		Node(T value) {
			val = value;
			next = prev = nullptr;
		}
	};

	int count = 0;
	Node* head = nullptr;
	Node* tail = nullptr;

	void initialNode(T value) {
		if (!isEmpty()) return;
		count = 1;
		head = new Node(value);
		tail = head;
		return;
	}
	bool isEmpty() {
		return (count == 0);
	}
	Node* getNodeByIndex(int index) {
		if (isEmpty() || index < 0 || index >= count) return nullptr;

		if (index == 0) return head;
		if (index + 1 == count) return tail;

		Node* currentNode = head;
		for (int i = 0; i < index; i++) {
			currentNode = currentNode->next;
		}
		return currentNode;
	}
	Node* getNodeByValue(T value) {
		if (isEmpty()) return nullptr;

		Node* currentNode = nullptr;
		for (int i = 0; i < count - 1; i++) {
			if (i == 0) currentNode = head;
			else currentNode = currentNode->next;

			if (currentNode->val == value) return currentNode;
		}
		return nullptr;
	}
	void removeNode(Node* node) {
		if (count == 1) return removeLonelyNode();
		Node* nextNode = node->next;
		Node* prevNode = node->prev;

		nextNode->prev = prevNode;
		prevNode->next = nextNode;
		delete node;
		count--;
		return;
	}
	void removeLonelyNode() {
		if (isEmpty()) return;
		if (count != 1) return;
		delete head;
		head = tail = nullptr;
		count--;
		return;
	}
public:
	//constructors
	MyList() {
		if (!isEmpty()) return;

		count = 0;
		head = tail = nullptr;
	}
	MyList(T value) {
		initialNode(value);
	}

	//add functions
	void append(T value) {
		if (isEmpty()) return initialNode(value);

		Node* oldTail = tail;
		tail = new Node(value);
		oldTail->next = tail;
		tail->prev = oldTail;
		count++;
		return;
	}
	void prepend(T value) {
		if (isEmpty()) return initialNode(value);

		Node* oldHead = head;
		head = new Node(value);
		oldHead->prev = head;
		head->next = oldHead;
		count++;
		return;
	}
	void insert(int index, T value) {
		if (index == 0) return prepend(value);
		if (index == count) return append(value);

		Node* current = getNodeByIndex(index);
		if (current == nullptr) return;

		Node* newNode = new Node(value);
		Node* oldPrev = current->prev;
		oldPrev->next = newNode;
		current->prev = newNode;
		newNode->prev = oldPrev;
		newNode->next = current;
		count++;
		return;
	}

	//remove functions
	void removeAt(int index) {
		if (index == 0) return removeHead();
		if (index + 1 == count) return removeTail();

		Node* current = getNodeByIndex(index);
		if (current == nullptr) return;

		return removeNode(current);
	}
	void removeValue(T value) {
		Node* current = getNodeByValue(value);
		if (current == nullptr) return;

		if (current == head) return removeHead();
		if (current == tail) return removeTail();

		return removeNode(current);
	}
	void removeHead() {
		if (isEmpty()) return;
		if (count == 1) return removeLonelyNode();

		Node* newHead = head->next;
		delete head;
		newHead->prev = nullptr;
		head = newHead;
		count--;
	}
	void removeTail(){
		if (isEmpty()) return;
		if (count == 1) return removeLonelyNode();

		Node* newTail = tail->prev;
		delete tail;
		newTail->next = nullptr;
		tail = newTail;
		count--;
	}
	void clear() {
		while (count > 0) {
			std::cout << count + "\n";
			removeTail();
		}
		return;
	}

	//iterate functions


	//sort functions


	//getters
	T get(int index) {
		if (index >= count || index < 0) return 0;
		Node* current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		return current->val;
	}
	int size() {
		return count;
	}
	std::string print() {
		std::string output = "size: " + std::to_string(count) + "\n";
		if (isEmpty()) return output;
		Node* current = head;
		for (int i = 0; i < count - 1; i++) {
			output += std::to_string(current->val) + " <-> ";
			current = current->next;
		}
		output += std::to_string(tail->val) + "\n";
		return output;
	}
	T peekFirst() {
		if (count == 0) return 0;
		return head->val;
	}
	T peekLast() {
		if (count == 0) return 0;
		return tail->val;
	}
};