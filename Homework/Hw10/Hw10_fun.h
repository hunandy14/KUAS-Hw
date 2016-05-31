/**********************************************************
Name : 
Date : 2016/05/31
By   : CharlotteHonG
Final: 2016/05/31
**********************************************************/
using namespace std;

template <typename T1>
class frac{
public:
    // 建構子 
    frac();
    frac(const T1 &num, const T1 &den);
    // 運算子重載
    frac operator+(const frac &a, const frac &b);
    // 印出
    void pri();
    // 取得
    T1 get_num();
    T1 get_den();
private:
    T1 num;
    T1 den;
    //確定是否為有效輸入
    int flag=0;
};