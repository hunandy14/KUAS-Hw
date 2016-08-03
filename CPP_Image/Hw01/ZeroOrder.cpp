/**********************************************************
Name : 
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/03
**********************************************************/
#include <iostream>
using namespace std;
/*=======================================================*/
#include <iostream>
#define Pic_name_in "in.raw"
#define Pic_name_out "out.raw"
#define Pic_sizeX 256
#define Pic_sizeY 256
#define Vary 40

int main(int argc, char const *argv[]){
    // 宣告
    FILE *img,*out;
    int arr_image[Pic_sizeX][Pic_sizeY];

    // 二進位模式開檔 (唯讀)
    img=fopen(Pic_name_in ,"rb");
    if(img == NULL) {
        printf("\n Can't open the image  !! \n");
        exit(0);
    } fclose(img);

    // 二進位模式開檔 (讀檔)
    img=fopen(Pic_name_in ,"rb");
    for(int i=0; i<Pic_sizeY; i++) {
        for(int j=0; j<Pic_sizeX; j++) {
            arr_image[i][j]=fgetc(img);
        }
    } fclose(img);

    // 每個點增加40
    out=fopen(Pic_name_out,"wb");
    for(int i=0,temp; i<Pic_sizeY; i++) {
        for(int j=0; j<Pic_sizeX; j++) {
        	temp=arr_image[i][j];
            fputc(temp,out);
        }
    } fclose(out);
    return 0;
}
/*=======================================================*/