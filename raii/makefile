CXXFLAGS = -Wpedantic -Werror

all: t1 t2 t3 t4

t1:
	g++ test1.cpp -std=c++98 -Wall -Wextra -Werror -pedantic -o t1.exe

t2:
	g++ test2.cpp -std=c++98 -Wall -Wextra -Werror -pedantic -o t2.exe

t3:
	g++ test3.cpp -std=c++11 -Wall -Wextra -Werror -pedantic -o t3.exe

t4:
	g++ test4.cpp -std=c++11 -Wall -Wextra -Werror -pedantic -o t4.exe

clean:
	rm t1.exe t2.exe t3.exe t4.exe
