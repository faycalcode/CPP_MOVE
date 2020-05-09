#include "Move.h"
#include <iostream>

/* 
	to prevent self copy or self move if(this != &other) is needed
*/

X::X() throw(std::bad_alloc) :
	_size(1),
	_head(new char[1])
{
	_head[0] = '\0';
	std::cout << "default" << std::endl;
}

X::X(const X& other) throw (std::bad_alloc):
	_size(other._size),
	_head(new char[other._size])
{
	memcpy(_head, other._head, _size);
	std::cout << "copy" << std::endl;
}

X::X(X&& rvalue) noexcept:
	_size(std::move(rvalue._size)),
	_head(std::move(rvalue._head))
{
	rvalue._head = nullptr;
	std::cout << "move" << std::endl;
}

X& X::operator=(const X& other) throw (std::bad_alloc)
{
	delete[] _head;
	_size = other._size;
	_head = new char[other._size];
	std::memcpy(_head, other._head, _size);
	std::cout << "operator=&" << std::endl;
	return *this;
}

X& X::operator=(X&& rvalue) noexcept
{
	delete[] _head;
	_size = std::move(rvalue._size);
	_head = std::move(rvalue._head);
	rvalue._head = nullptr;
	std::cout << "operator=&&" << std::endl;
	return *this;
}

X::X( const char* s) throw (std::bad_alloc):
	_size(strlen(s) + 1 ),
	_head(new char[_size])
{
	std::memcpy(_head, s, _size);
	std::cout << "value" << std::endl;
}

X::~X()
{
	std::cout << "destroying :" << std::endl;
	delete[] _head;
}