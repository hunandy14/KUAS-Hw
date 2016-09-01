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

## 指標
重新認識了指標

## 資料結構切割
想了好久最終分了兩部分
1. 主類別內直接取得遮罩數值
2. 次類別用來儲存指標陣列

## size_type
http://blog.csdn.net/lzx_bupt/article/details/6558566
http://stackoverflow.com/questions/2550774/what-is-size-t-in-c

## 類別內建構會智能解構
假設
`img.getMask(ImrCoor(1,1));`
回傳一個動態一維陣列

如果沒有任何東西接住他，那麼在該行執行結束解構子就會被執行
`ImrMask mask = img.getMask(ImrCoor(1,1));`
如果你接住他了，那麼在整個主程式跑完時
結束主類別時將會在那那時候啟動解構子

## 指標的意義
```
class ImrMask{
public:
    ImrMask(ImrSize masksize);
    ~ImrMask();
    imch & operator[](const size_t __n);
    imch & at2d(size_t y, size_t x);
    void sort(size_t len, size_t start);

    imch* mask;
    ImrSize masksize;
};
```

`ImrMask mask(ImrSize(4,4));`
> 創建一個4x4長度的動態陣列

`ImrMask mask2 = mask;`
本來以為會複製16個數值過去頭痛不已
以為要想辦法傳參考出去了，偏偏參考又傳不出去
後來想想不對呀，`imch* mask;`
我只有複製一個指標，複製類別不存在效率問題
只怕被解構子解掉了，實驗一下，會智能解構





















