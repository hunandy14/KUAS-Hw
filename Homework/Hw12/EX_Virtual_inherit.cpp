/**********************************************************
Name : 虛擬繼承範例
Date : 2016/06/07
By   : CharlotteHonG
Final: 2016/06/07

參考：
http://pcedu.pconline.com.cn/empolder/gj/c/0503/579115_all.html
http://www.voidcn.com/blog/sinat_20265495/article/p-5780390.html
**********************************************************/
#include <iostream>
using namespace std;

class Vehicle{
public:
    Vehicle(int weight = 0){
        Vehicle::weight = weight;
        cout<<"載入Vehicle類構造函數"<<endl;
    }
    void SetWeight(int weight){
        cout<<"重新設置重量"<<endl;
        Vehicle::weight = weight;
    }
    virtual void ShowMe() = 0;
protected:
    int weight;
};

//汽車，這裡是虛擬繼承
class Car:virtual public Vehicle{
public:
    Car(int weight=0,int aird=0):Vehicle(weight)
    {
        Car::aird = aird;
        cout<<"載入Car類構造函數"<<endl;
    }
    void ShowMe()
    {
        cout<<"我是汽車！"<<endl;
    }
protected:
    int aird;
};

//船，這裡是虛擬繼承
class Boat:virtual public Vehicle{
public:
    Boat(int weight=0,float tonnage=0):Vehicle(weight){
        Boat::tonnage = tonnage;
        cout<<"載入Boat類構造函數"<<endl;
    }
    void ShowMe(){
        cout<<"我是船！"<<endl;
    }
protected:
    float tonnage;
};

//水陸兩用汽車，多重繼承的體現
class AmphibianCar:public Car,public Boat{
public:
    //多重繼承要注意調用基類的構造函數
    AmphibianCar(int weight,int aird,float tonnage)
    :Vehicle(weight),Car(weight,aird),Boat(weight,tonnage){
        cout<<"載入AmphibianCar類構造函數"<<endl;
    }
    void ShowMe(){
        cout<<"我是水陸兩用汽車！"<<endl;
    }
    void ShowMembers(){
        cout<<"重量："<<weight<<"頓，"<<"空氣排量："<<aird<<"CC，"<<"排水量："<<tonnage<<"頓"<<endl;
    }
};

int main(){
    AmphibianCar a(4,200,1.35f);
    a.ShowMe();
    a.ShowMembers();
    a.SetWeight(3);
    a.ShowMembers();
}

