## 如何取得整數的位數
```
#include<sstream>
int num=123456789;
stringstream ss;
ss<<num;
string str;
ss>>str;
ss.clear();
return (str.length());
```

## 亂數問題
[http://goo.gl/DrTtr](http://edisonx.pixnet.net/blog/post/91314418-%5B%E4%BA%82%E6%95%B8%5D-%3C%E7%B4%B0%E8%AA%AA%3E-c-c%2B%2B-%E4%BA%82%E6%95%B8%E5%9F%BA%E6%9C%AC%E4%BD%BF%E7%94%A8%E8%88%87%E5%B8%B8%E8%A6%8B%E5%95%8F%E9%A1%8C)
`rand() / (RAND_MAX+1.0)) * (up - low + 1.0) + low`

## 亂數撒點
亂數撒點會灑到重複的點

## 在方法內使用方法，類別參數不能留空
> A方法內引入的參數具有設初始值
> B方法使用A方法時一定要給數值，不能留空

## 方法參數有引入類別似乎只能放最後面
放到中間去編譯就出問題了

http://stackoverflow.com/questions/5637679/default-argument-in-the-middle-of-parameter-list

> 參數列有設預設值一定要放在最後方

## 遮罩 存取方式
1. 複製周圍的點
2. 算出相對應的座標






