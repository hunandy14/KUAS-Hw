/**********************************************************
Name : 
Date : 2016/05/31
By   : CharlotteHonG
Final: 2016/06/01
**********************************************************/
using namespace std;

template <typename T1>
class frac{
public:
    // 建構子 
    frac();
    frac(const T1 &num, const T1 &den);
    frac(const T1 &mix, const T1 &num, const T1 &den);
    // 運算子重載
    frac operator+(const frac &p);
    frac operator-(const frac &p);
    frac operator*(const frac &p);
    frac operator/(const frac &p);
    // 印出
    void pri();
    // 取得
    T1 get_num();
    T1 get_den();
    // 分數轉換
    frac impro() const;
    frac mixed() const;
    // 約分
    frac as() const;
private:
    T1 mix;
    T1 num;
    T1 den;
    // 確認是否為有效分數
    int flag=0;
    // 最大公因數
    T1 gcd(T1 a, T1 b) const;
};