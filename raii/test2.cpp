#include <iostream>
using namespace std;

template <typename T>
class Raii
{
//	Raii& operator=(const Raii&) = delete;    needed if using C++11
	void (*dtor)(T&);
	T& data;
public:
	 Raii( void(*f)(T&), T& d) : dtor(f), data(d) { }
	~Raii() { dtor(data); }
};


void handler(int& i)		// cleaner syntax
{
	i = 8;
}


int main(void)
{
	int d = 3;
	{
	//	Raii<decltype(d)> g( handler, d );	// cleaner syntax, C++11
		Raii<int> g( handler, d );	// cleaner syntax
		cout << "d1 = " << d << endl;
		d = 5;
		cout << "d2 = " << d << endl;
	}
	cout << "d3 = " << d << endl;

	return 0;
}
