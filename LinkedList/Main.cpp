#include <iostream>
#include <stdio.h>
#include <string>
#include "MyList.h"

int main(void)
{
	MyList* test = new MyList(20);
	test->prepend(10);
	test->append(30);
	test->insert(1, 15);
	test->insert(3, 25);
	std::cout << test->print() + "\nHead: " + std::to_string(test->getHead()) + "\nTail: " + std::to_string(test->getTail());


	test->removeAt(1);
	test->removeAt(2);
	test->removeHead();
	test->removeTail();
	std::cout << "\n\n\n";
	std::cout << test->print() + "\nHead: " + std::to_string(test->getHead()) + "\nTail: " + std::to_string(test->getTail());


	test->prepend(10);
	test->append(30);
	test->insert(1, 15);
	test->insert(3, 25);

	test->removeValue(20);
	std::cout << "\n\n\n";
	std::cout << test->print() + "\nHead: " + std::to_string(test->getHead()) + "\nTail: " + std::to_string(test->getTail());


	test->clear();
	std::cout << "\n\n\n";
	std::cout << test->print() + "\nHead: " + std::to_string(test->getHead()) + "\nTail: " + std::to_string(test->getTail());
}