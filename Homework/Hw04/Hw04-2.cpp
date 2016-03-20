#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;

int GCD(int a,int b);
int LCM(int a,int b);
// void printarray(int array[][])

int main(int argc, char const *argv[]){
    int num[2]={5,5},ans=0.0;
    cout << "請輸入兩個數，程式將回傳計算結果" << endl;
    cout << "1. 輸入的為長與寬" << endl;
    cout << "2. 順時針繞圈計數" << endl << endl;

    cin >> num[0] >> num[1];
    // printf("%f and %f\n\n",num[0],num[1]);
    cout << "提交的答案=\n";
    
    int xmin=0, ymin=0, ymax=num[0], xmax=num[1];
    int x=0, y=0, count=0,flag=0;
    int array[num[0]][num[1]];

    // SetZero
    for (int j = 0; j < num[0]; j++){
        for (int i = 0; i < num[1]; i++){
            array[j][i]=0;
        }
    }

    // fill num
    while(count < num[0]*num[1]){
        array[y][x]=++count;
        
        
        if(flag==3){
            y--;
            if (y<=ymin){
                flag=0;
                ymin++;
                y++;
            }
        }
        if(flag==2){
            x--;
            if (x<=xmin){
                flag++;
                xmin++;
            }
        }
        if(flag==1){
            y++;
            if (y>=ymax-1){
                flag++;
                ymax--;
            }
        }
        if(flag==0){
            x++;
            if (x>=xmax-1){
                flag++;
                xmax--;
            }
        }

    }

    // information
    // printf("Flag=%d\n",flag );
    // printf("x=%d,y=%d\n",x,y );
    // printf("xmax=%d\n",xmax);
    // printf("ymax=%d\n",ymax);

    // printer
    int high=sizeof(array)/sizeof(array[0]);
    int weith=sizeof(array[0])/sizeof(array[0][0]);
    // cout << weith << high <<endl;
    for (int j = 0; j < high; j++){
        for (int i = 0; i < weith; i++){
            printf("%5d",array[j][i]);
        }
        printf("\n");
    }


    cout << endl;
    return 0;
}

void printinf(){

}
