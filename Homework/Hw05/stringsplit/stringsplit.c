/**********************************************************
Name:String Split
DATE:2016/03/31
By CharlotteHong
**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ================================================== */
void test();
/* 切割字串 (要切割的字串,切割的符號)
字串的格式如 srt[]="1,2";
回傳值為一陣列起始值0為陣列長度 */
int* str_split(const char* str, const char* sp);
/* ================================================== */
int main(int argc, char const *argv[]){
	test();
	return 0;
}
/* ================================================== */
void test(){
	char str[]="18,03,19,50,46,29,23,15,26,48,45";
	int *array=str_split(str,",");

	for (int i = 1; i <= array[0]; ++i){
		printf("[%d]", array[i]);
	}
	printf("\n");
	free(array);
}
int* str_split(const char* str, const char* sp){
	int *ptr;
	char *temp;

	// 計算字串內總共有幾個數
	int len=1;
	for (int i = 0; i < strlen(str); ++i){
		if ( str[i] == sp[0])
			len++;
	}

	// 根據長度配置記憶體
	ptr = (int*)malloc(sizeof(int)*(len+1));
	*ptr = (int)(len);
	
	// 開始切割
	int tempflag=0,index=1;
	temp = (char*)malloc(sizeof(char));
	for (int i = 0; i <= strlen(str); ++i){
		if ( str[i] == sp[0] || i==strlen(str)){
			len++;
			tempflag=0;
			// printf("temp=%c%c\n",temp[0],temp[1] );
			sscanf(temp, "%d", (ptr+index));
			index++;
			free(temp);
			temp = (char*)malloc(sizeof(char));
		}
		else{
			temp[tempflag++]=str[i];
		}
	}
	free(temp);
	return ptr;
}
/* ================================================== */