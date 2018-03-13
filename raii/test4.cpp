#include <functional>
#include <iostream>
using namespace std;

class Raii
{
	std::function<void()> dtor;
public:
	 Raii( std::function<void()> f ) : dtor(f) { }	// store f in member var
	~Raii() { dtor(); }
};


int main(void)
{
	int a = 1;
	{
		Raii g( [&a]()		// capture by reference
		{
			a++;
		});
		cout << "a1 = " << a << endl;
		a = 5;
		cout << "a2 = " << a << endl;
	}
	cout << "a3 = " << a << endl;  
	// because we captured by reference, the a in the lambda's body is
	//  incremented as the RAII goes out of scope
	return 0;
}
