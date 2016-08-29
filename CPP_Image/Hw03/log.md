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
[http://goo.gl/DrTtr](http://goo.gl/DrTtr)
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








