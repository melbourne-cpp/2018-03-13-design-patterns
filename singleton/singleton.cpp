struct a {};
struct b {};

#include <mutex>

template<class T>
class Singleton : public T
{
public:
    static Singleton * getOrCreateInstance(int pass)
    {
        mutex.lock();
        if (!instance) {
            instance = new Singleton(pass);
        }
        mutex.unlock();
        return instance;
    }

    static Singleton * getInstance()
    {
        return instance;
    }

    int getSomething() const {
        return 1*2*3*x;
    }

private:
    static Singleton * instance;
    static std::mutex mutex;
    int x;

    Singleton(int init) : x(init) { }
};

template<> Singleton<a> * Singleton<a>::instance = nullptr;
template<> std::mutex Singleton<a>::mutex = {};
//template<> Singleton<b> * Singleton<b>::instance = nullptr;

#include <iostream>

int main()
{
    Singleton<a>::getOrCreateInstance(5);

    Singleton<a> * s = Singleton<a>::getInstance();
    std::cout << s << ' ' << s->getSomething() << std::endl;

    Singleton<a> * s2 = Singleton<a>::getInstance();
    std::cout << s2 << ' ' << s2->getSomething() << std::endl;

  /*  Singleton<b> * s3 = Singleton<b>::getInstance();
    std::cout << s3 << ' ' << s3->getSomething() << std::endl;*/
    return 0;
}
