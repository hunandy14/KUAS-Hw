#include <iostream>
#include "Demo"
using namespace std;

int main(void) {
    Demo<int> t1;
    Demo<int> t2(11);
    Demo<int> t3(11, 22);

    cout << endl;
    cout << t1.do_something() << endl;
    cout << t2.do_something() << endl;
    cout << t3.do_something() << endl;
    cout << endl;

    return 0;
}