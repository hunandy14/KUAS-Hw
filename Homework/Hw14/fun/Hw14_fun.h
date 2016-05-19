/**********************************************************
Name : Hw14_main.h
Date : 2016/05/19
By   : CharlotteHonG
Final: 2016/05/19
**********************************************************/
using namespace std;
static int element[]={5,-2,4};

template <typename T1, typename T2>
class Demo {
    public:
        /* setter */
        Demo();
        Demo(const T1 &p, const T2 &n);
        void set(const T1 &p, const T2 &n);

        /* getter */
        void pri(const T2 &n);
        void pri();
        T2 length();

        /* function */
        T2 sum();
        T2 product();
        T2 square_of_sum();

    private:
        T1 ptr;
        T2 len;
};