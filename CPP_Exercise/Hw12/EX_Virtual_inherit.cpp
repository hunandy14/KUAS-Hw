/**********************************************************
Name : �����~�ӽd��
Date : 2016/06/07
By   : CharlotteHonG
Final: 2016/06/07

�ѦҡG
http://pcedu.pconline.com.cn/empolder/gj/c/0503/579115_all.html
http://www.voidcn.com/blog/sinat_20265495/article/p-5780390.html
**********************************************************/
#include <iostream>
using namespace std;

class Vehicle{
public:
    Vehicle(int weight = 0){
        Vehicle::weight = weight;
        cout<<"���JVehicle���c�y���"<<endl;
    }
    void SetWeight(int weight){
        cout<<"���s�]�m���q"<<endl;
        Vehicle::weight = weight;
    }
    virtual void ShowMe() = 0;
protected:
    int weight;
};

//�T���A�o�̬O�����~��
class Car:virtual public Vehicle{
public:
    Car(int weight=0,int aird=0):Vehicle(weight)
    {
        Car::aird = aird;
        cout<<"���JCar���c�y���"<<endl;
    }
    void ShowMe()
    {
        cout<<"�ڬO�T���I"<<endl;
    }
protected:
    int aird;
};

//��A�o�̬O�����~��
class Boat:virtual public Vehicle{
public:
    Boat(int weight=0,float tonnage=0):Vehicle(weight){
        Boat::tonnage = tonnage;
        cout<<"���JBoat���c�y���"<<endl;
    }
    void ShowMe(){
        cout<<"�ڬO��I"<<endl;
    }
protected:
    float tonnage;
};

//������ΨT���A�h���~�Ӫ���{
class AmphibianCar:public Car,public Boat{
public:
    //�h���~�ӭn�`�N�եΰ������c�y���
    AmphibianCar(int weight,int aird,float tonnage)
    :Vehicle(weight),Car(weight,aird),Boat(weight,tonnage){
        cout<<"���JAmphibianCar���c�y���"<<endl;
    }
    void ShowMe(){
        cout<<"�ڬO������ΨT���I"<<endl;
    }
    void ShowMembers(){
        cout<<"���q�G"<<weight<<"�y�A"<<"�Ů�ƶq�G"<<aird<<"CC�A"<<"�Ƥ��q�G"<<tonnage<<"�y"<<endl;
    }
};

int main(){
    AmphibianCar a(4,200,1.35f);
    a.ShowMe();
    a.ShowMembers();
    a.SetWeight(3);
    a.ShowMembers();
}

