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
    // �غc�l 
    frac();
    frac(const T1 &num, const T1 &den);
    // �B��l����
    frac operator+(const frac &a, const frac &b);
    // �L�X
    void pri();
    // ���o
    T1 get_num();
    T1 get_den();
private:
    T1 num;
    T1 den;
    //�T�w�O�_�����Ŀ�J
    int flag=0;
};