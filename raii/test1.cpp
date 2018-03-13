#include <iostream>
using namespace std;

class Raii
{
	void (*dtor)(void*);
	void* data;
public:
	 Raii( void(*f)(void*), void* d ) : dtor(f), data(d) { }
	~Raii() { dtor(data); }
};



void handler_func(void* p1)
{
	int* p = static_cast<int*>(p1);		// messy boiler-plate
	*p = 7;
}


int main()
{
	int c = 4;
	{
		Raii g( handler_func, &c );
		cout << "c1 = " << c << endl;
		c = 5;
		cout << "c2 = " << c << endl;
	}
	cout << "c3 = " << c << endl;
	return 0;
}
