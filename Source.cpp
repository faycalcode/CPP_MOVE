#include "Move.h"
#include <iostream>

int main() {
	
	X a;
	{
	
		a = std::move(a);

	}
	
	return 0;
}