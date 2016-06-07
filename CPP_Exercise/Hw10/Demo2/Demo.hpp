template <typename T1>
class Demo {
public:
    Demo();
    Demo(T1 n);
    Demo(T1 n1, T1 n2);
    void setA(T1 n);
    void setB(T1 n);
    T1 getA();
    T1 getB();
    T1 do_something();
 
private:
    T1 a;
    T1 b;
};
#include "Demo.cpp"