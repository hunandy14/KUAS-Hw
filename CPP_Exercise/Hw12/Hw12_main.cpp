/**********************************************************
Name : Hw06繼承
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

    Arms arms("巫妖之禍");
    Apparel apparel("好戰者鎧甲");
    Shoe shoe("愛歐尼亞之靴");
    Equipment equipment(&arms, &apparel, &shoe);
    Summoner man(500, 200, 50, &equipment);
    cout << endl << "Fizz = " << endl;
    man.Summoner::pri();
    
    return 0;
}
/*=======================================================*/