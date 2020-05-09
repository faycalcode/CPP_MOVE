#include "Move.h"
#include <iostream>

int main() {
	
	X a;
	{
	
		X* ptr = new X("test");

		a = *ptr;

		delete ptr;

	}
	
	return 0;
}