#ifndef MOVE_H
#define MOVE_H

#include <string>

class X {
	size_t _size {0};
	char* _head {nullptr};
public:
	X() throw(std::bad_alloc);

	X(const char*) throw(std::bad_alloc);

	X(const X&) throw(std::bad_alloc);
	X(X&&) noexcept;
	
	X& operator=(const X&) throw(std::bad_alloc);
	X& operator=(X&&) noexcept;

	~X();
};

#endif // MOVE_H