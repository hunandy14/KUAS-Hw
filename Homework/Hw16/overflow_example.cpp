/**********************************************************
Name : overflow_example.cpp
Date : 2016/05/16
By   : CharlotteHonG
Final: 2016/05/16
http://www.weixueyuan.net/view/6332.html
**********************************************************/
#include <iostream>
using namespace std;
/*=======================================================*/
enum index{underflow, overflow};
int array_index(int *A, int n, int index);
int main()
{
    int *A = new int[10];
    for(int i=0; i<10; i++)
        A[i] = i;
    try
    {
        cout<<array_index(A,10,5)<<endl;
        cout<<array_index(A,10,-1)<<endl;
        cout<<array_index(A,10,15)<<endl;
    }
    catch(index e)
    {
        if(e == underflow)
        {
            cout<<"index underflow!"<<endl;
            exit(-1);
        }
        if(e == overflow)
        {
            cout<<"index overflow!"<<endl;
            exit(-1);
        }
    }
    return 0;
}
int array_index(int *A, int n, int index)
{
    if(index < 0) throw underflow;
    if(index > n-1) throw overflow;
    return A[index];
}
/*=======================================================*/