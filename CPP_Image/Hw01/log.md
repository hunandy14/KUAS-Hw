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