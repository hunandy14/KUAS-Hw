## 問題
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

### macro
> macro當參數用最好不要大於兩個以上
> 如果會反覆用到，用一個變數導入