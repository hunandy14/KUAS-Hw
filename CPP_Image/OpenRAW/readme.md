# OpenRAW 2.3 refrence

## 如何引入使用
標頭僅需引入 `#include "OpenRAW"`  
使用時須使用命名空間 `namespace imr`  
可以再標頭引入 `using namespace imr;`  

---

---

## 各項類別屬性與建構說明
### 畫布大小
`ImrSize` 用來描述畫布畫布大小  
大小可在建構時設置  
如，設置一個256x256大小的畫布  
`ImrSize size(256,256);`  

使用時可使用公開變數  
`size.width`與`size.high`  
型態為 `size_t`   

> 某些情況可需要轉態  
`for (int i=0; i<=(int)size.high, ++i)`  

---

### 座標位置
`ImrCoor` 用來描述座標位置
座標可在建構時設置  
如，設置一個(0,0)的座標  
`ImrCoor coor(0,0);`  

使用時可使用公開變數  
`size.y`與`size.x`  
型態為 `int`   

**重載**  
`ImrCoor` 提供基本的加減乘除運算子  

```
ImrCoor a(1,2), b(3,4), c;
c = a+b;
```
> C則為(4,6)依此類推  

---

### 遮罩陣列
`ImrMask` 用來儲存遮罩陣列  
使用時需再主程式宣告，並接住(複製)  
方法產生的類別，即可使用。  
`ImrMask mask = img.getMask();`

> 由於僅是接住方法產生的陣列  
> 故不需建構任何資訊(由方法建構)  
> 方法用法請參考該類別說明欄位  

使用時可直接使用[下標]存取指標陣列  
`cout << mask[0] << endl;`  
`mask[0] = 1;`  
型態為`unsigned char*`  

---

### 方法 
#### at2d(y,x)
以二維的方式存取位置(y,x)的遮罩   
`cout << mask.at2d(0,0);`  
`mask.at2d(0,0) = 0;`  

#### sort()  
插入排序遮罩大小，由小到大  
`mask.sort();` 排序全部  

其中可以自由指定那些需要排序  
`sort(len, start);`  
比如說一共有4個我要排序中間兩個  
長度是2，從mask[1]開始排序  
`mask.sort(2,1);`  

---

