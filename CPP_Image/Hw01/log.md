# 問題
macro的轉換似乎有著某種關係  

```
if (((float)Ratio-(int)Ratio) > 0){
    black = 1/((float)Ratio-(int)Ratio);
    limx = Pic_x * ((float)Ratio-(int)Ratio);
    limy = Pic_y * ((float)Ratio-(int)Ratio);
}
```

與  

```
if (float temp = ((float)Ratio-(int)Ratio) > 0){
    black = 1/temp;
    limx = Pic_x * temp;
    limy = Pic_y * temp;
}
```

居然是不一樣的  

> macro小數轉換方法有待釐清，
> 估計是小數捨棄方式不一樣
> 或者是計算浮點數時會忽略些什麼
> 注意以後不可以用 macro 計算非整數

## macro
> macro當參數用最好不要大於兩個以上
> 如果會反覆用到，用一個變數導入

## fstream
fstream類別不能被複製
[[問題] 類別的複製 資料裡面有fstream 報錯](https://www.ptt.cc/bbs/C_and_CPP/M.1470845062.A.D86.html)

## 無號字串
原本使用char來儲存圖片，後來發現這會造成問題
有些char的數值會是負號的，必須使用 `unsigned char`
使用的時候造成不少困擾，整個代碼的調整以及
`fstream` 只吃 `char` 參數，爬文之後發現可以
直接`cast`轉過去就好了

`img.read((char*)&this->img_data[0], this->filesize);`

像這樣在最前方加入 `(char*)` 最後有成功解決
[\[問題\] C++讀.raw灰階圖檔](https://goo.gl/45nSe2)

## 副程式的陣列傳遞

### 先處理多重指標連結的問題
這一篇發問 [[問題] 雙重 指標存取字串](https://www.ptt.cc/bbs/C_and_CPP/M.1459748840.A.555.html)
與版主的這一篇解答 [Re: [問題]雙重 指標存取字串](https://www.ptt.cc/bbs/C_and_CPP/M.1459819483.A.4D0.html)

主要的差異在於

這是有錯的

```
    char **ptr;
    int n,m;
    char *temp;
    char *string1 = "BOOK";
    char *string2 = "FOR";
    char *string3 = "YOU";
    ptr = temp;
```

連結方式應該為

```
    temp = string1;
    *ptr = temp;
    *(ptr + 1) = string2;
    *(ptr + 2) = string3;
```

### 副程式的傳遞
指標的指標傳遞方式
[[問題] c語言新手指標問題!](https://www.ptt.cc/bbs/C_and_CPP/M.1463820406.A.81D.html)
[RE:[問題] c語言新手指標問題!](https://www.ptt.cc/bbs/C_and_CPP/M.1464282013.A.4D8.html)

重點擷取
> 推 loveflames: int *a[row]是指標陣列
> → loveflames: int (*a)[row]是指向陣列的指標

副程式傳出可能比較沒問題
傳入的部分要嘛規矩的兩個星星傳入
否則就要使用 指標陣列

1. 指標陣列 => 創建的陣列可以存指標
2. 指標的指標 => 用來儲存指標

不同的是2是完全動態的(x,y)
1則是只有半動態，只有一個可動態
相比之下1的創建就比較簡單