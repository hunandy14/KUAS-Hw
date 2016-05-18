/**********************************************************
Name : Hw14_main.h
Date : 2016/05/19
By   : CharlotteHonG
Final: 2016/05/19
**********************************************************/
using namespace std;
static int element[]={5,-2,4};

class fun {
public:
    fun(int* arr, int n);
    void set(int* arr, int n);
    void pri(int n);
    void pri();
    int sum();
    int product();
    int square_of_sum();

private:
    int* ptr, len;
};