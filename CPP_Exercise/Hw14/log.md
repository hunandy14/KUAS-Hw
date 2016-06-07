### 問題  
遇到了一些問題，這是解決方案
[g++ 編譯 class樣板 報錯](https://www.ptt.cc/bbs/C_and_CPP/M.1463665077.A.88E.html)  

#### 如何把樣板類別的函式寫在外面  
這是正確寫法g++可以編過  
原本我的宣告與定義都有加上Demo<T1, T2>  
`Demo<T1, T2>(const T1 &p, const T2 &n);`  
`Demo<T1, T2>::Demo<T1, T2>(const T1 &p, const T2 &n){....}`  
>實際上只有"::"前面才要加上樣板定義"<>" (我猜的規則)
  
但是這樣會報錯，花了不少時間try不出來  
後來發文有人回答我了，真是太感謝了，不然這種芝麻小事  
找到天荒地老不知道什麼時候才會找到VB太強大了(兼容)  
這對新手來說殺傷力太大了，太可怕了
習慣了，哪天沒有VB了遠永找不到錯  

#### 程式碼
	#include <iostream>  
	using namespace std;  
	int element[] = {5, -2, 4};</code>  
	  
	template <typename T1, typename T2>  
	class Demo {  
	public:  
		Demo(const T1 &p, const T2 &n);  
		T1 ptr;  
		T2 len;  
	};  
	  
	template <typename T1, typename T2>  
	Demo<T1, T2>::Demo(const T1 &p, const T2 &n) {  
		this->ptr = p;  
		this->len = n;  
	}  
	  
	int main(int argc, char const *argv[]) {  
		Demo<int*, int> arr(element, 3);  
		cout << "arr = " << arr.len << endl;  
		system("PAUSE");  
		return 0;  
	}  