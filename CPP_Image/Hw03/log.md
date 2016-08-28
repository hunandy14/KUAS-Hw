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

