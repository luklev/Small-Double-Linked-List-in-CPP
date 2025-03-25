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
}