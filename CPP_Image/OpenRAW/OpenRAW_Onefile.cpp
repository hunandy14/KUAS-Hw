/**********************************************************
Name : OpenRAW.cpp
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/03
**********************************************************/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define Pic_name_in "in.raw"
#define Pic_name_out "out.raw"
#define Pic_sizeX 256
#define Pic_sizeY 256

int main(int argc, char const *argv[]){
    // �ŧi
    fstream img;
    vector<char> img_data;
    ifstream::pos_type filesize;

    // �G�i��Ҧ��}�ɴ���
    img.open(Pic_name_in, ios::in | ios::binary);
        //�p�G�}���ɮץ��ѡAfp��0�F���\�Afp���D0
    if(!img){
        img.close();
        cout << "No file." << endl;
        exit(1);
    }img.close();

    // �G�i��Ҧ�Ū��
        // ���o�`��
    img.open(Pic_name_in, ios::in | ios::binary);
    img.seekg(0, ios::end);
    filesize = img.tellg();
    img.seekg(0, ios::beg);
        // Ū����
    img_data.resize(filesize);
    img.read(&img_data[0], filesize);
    img.close();

    // �C���I-40 (����|�ܶ�)
    for (int i = 0; i < filesize; ++i){
        if (img_data[i]>=0+40 && img_data[i]<=255-40){
            img_data[i]-=40;
        }else if(img_data[i]<=0+40){
            img_data[i]=0;
        }else if (img_data[i]>=255-40){
            img_data[i]=255;
        }
    }

    // �i��Ҧ��g��
    img.open(Pic_name_out, ios::out | ios::binary);
    img.write(&img_data[0], filesize);
    img.close();

    return 0;
}