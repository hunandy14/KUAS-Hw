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
    // ������ 
    frac();
    frac(const T1 &num, const T1 &den);
    frac(const T1 &mix, const T1 &num, const T1 &den);
    // �\�������d
    frac operator+(const frac &p);
    frac operator-(const frac &p);
    frac operator*(const frac &p);
    frac operator/(const frac &p);
    // ӡ��
    void pri();
    // ȡ��
    T1 get_num();
    T1 get_den();
    // �֔��D�Q
    frac impro() const;
    frac mixed() const;
    // �s��
    frac as() const;
    frac as(T1 n) const;
    // �U��
    frac ep(T1 n) const;
private:
    T1 mix;
    T1 num;
    T1 den;
    // �_�J�Ƿ����Ч�֔�
    int flag=0;
    // ���ɼs�ֵĳ���
    T1 gcd() const;
};