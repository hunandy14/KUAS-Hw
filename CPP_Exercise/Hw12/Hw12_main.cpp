/**********************************************************
Name : Hw06�~��
Date : 2016/06/02
By   : CharlotteHonG
Final: 2016/06/07
**********************************************************/
#include <iostream>
#include "obj\Organism"
using namespace std;
/*=======================================================*/
int main(int argc, char const *argv[]){
    Monster baron(2000,500,100);
    cout << "baron = " << endl;
    baron.Monster::pri();

    Arms arms("�ŧ�����");
    Apparel apparel("�n�Ԫ��Z��");
    Shoe shoe("�R�ڥ��Ȥ��u");
    Equipment equipment(&arms, &apparel, &shoe);
    Summoner man(500, 200, 50, &equipment);
    cout << endl << "Fizz = " << endl;
    man.Summoner::pri();
    
    return 0;
}
/*=======================================================*/