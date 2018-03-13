#include <functional>		// introduce this header  for  std::function<>
#include <iostream>
using namespace std;

class Raii
{
	std::function<void()> dtor;
public:
	 Raii( std::function<void()> f ) : dtor(f) { }
	~Raii() { dtor(); }
};


int main(void)
{
	int b = 1;
	{
		Raii g( [b]() mutable	// capture by value
		{
			b++;
		});

		cout << "b1 = " << b << endl;
		b = 5;
		cout << "b2 = " << b << endl;
	}
	cout << "b3 = " << b << endl;

	return 0;
}
