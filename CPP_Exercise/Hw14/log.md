### ���D  
�J��F�@�ǰ��D�A�o�O�ѨM���
[g++ �sĶ class�˪O ����](https://www.ptt.cc/bbs/C_and_CPP/M.1463665077.A.88E.html)  

#### �p���˪O���O���禡�g�b�~��  
�o�O���T�g�kg++�i�H�s�L  
�쥻�ڪ��ŧi�P�w�q�����[�WDemo<T1, T2>  
`Demo<T1, T2>(const T1 &p, const T2 &n);`  
`Demo<T1, T2>::Demo<T1, T2>(const T1 &p, const T2 &n){....}`  
>��ڤW�u��"::"�e���~�n�[�W�˪O�w�q"<>" (�ڲq���W�h)
  
���O�o�˷|�����A��F���֮ɶ�try���X��  
��ӵo�妳�H�^���ڤF�A�u�O�ӷP�¤F�A���M�o�ت۳¤p��  
���ѯ�a�Ѥ����D����ɭԤ~�|���VB�ӱj�j�F(�ݮe)  
�o��s��ӻ����ˤO�Ӥj�F�A�ӥi�ȤF
�ߺD�F�A���ѨS��VB�F���ç䤣���  

#### �{���X
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