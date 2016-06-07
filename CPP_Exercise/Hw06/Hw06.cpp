/**********************************************************
Name:KUAS-Hw/Hw06
DATE:2016/03/27
By CharlotteHong
**********************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <sstream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

#define arraylen 10
int randnum(int num);
void printarray(int array[arraylen][arraylen]);

int main(int argc, char const *argv[]){
    srand((unsigned)time(NULL));
    int array[arraylen][arraylen],*ptr=&array[0][0];

    int high=sizeof(array)/sizeof(array[0]);
    int weith=sizeof(array[0])/sizeof(array[0][0]);

    // set array
    for (int i = 0; i < high*weith; ++i,ptr++){
        *ptr=randnum(50);
        // printf("%d\n",*ptr );
    }
    // reset ptr
    ptr=&array[0][0];

    // print array
    printarray(array);
    
    // add array
    for (int i = 0; i < (high*weith)/2; ++i){
        *(ptr+1)=*ptr+*(ptr+1);
        ptr+=2;
    }

    // print array
    printarray(array);

    cout << endl;
    return 0;
}

int randnum(int num){
    int randnum=rand()%num+1;
    return randnum;
}

void printarray(int array[arraylen][arraylen]){
    printf("=====================================================\n");
    for (int j = 0; j < arraylen; ++j){
        for (int i = 0; i < arraylen; ++i){
            printf("%5d",array[j][i] );
        }
        printf("\n");
    }
    printf("\n");
}



