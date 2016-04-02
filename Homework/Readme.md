## 01
使用 ASCII ASCII碼來輸出 碼來輸出 「Hello WordWordWordWord」。

## 02
1. 輸入某數
2. 計算次方

## 03
小數提取到特定位數

## 04
1. 最大公因數及最小公倍數
2. 旋轉二維陣列

## 05
### API 說明文件

0. 
>切割字串 (要切割的字串,切割的符號)  
>字串的格式如 srt[]="1,2";  
>回傳值為陣列指標地址，陣列[0]是長度  
><code>int* str_split(const char* str, const char* sp);</code>  
  
0.  
>建立新節點並回傳節點地址 (節點的值)  
><code>node* node_creat(int data);  

0. 
>鏈結的長度 (鏈結的開頭)  
<code>int node_lenth(node* nh);  
  
0.  
>尋找最後一個節點的地址 (任意節點)  
<code>node* nodep_final(node* n);
  
0.  
>印出節點的值 (任意節點)  
<code>void nodep_printpt(node* n);
  
0.  
>印所有節點的值 (鏈結開頭)  
<code>void node_printall(node* nh);
  
0.  
>印所有節點的資料 (鏈結開頭)  
<code>void node_printalldata(node* nh);
  
0.  
>印所有節點的地址 (鏈結開頭)  
<code>void node_printalladd(node* nh);
  
0.  
>在鏈結的最後方新增節點 (任意節點,新增節點的數值)    
<code>void nodep_append(node* n, int data);
  
0.  
>批次在尾端新增節點 (任意節點,陣列,數量)  
<code>void nodep_input(node* n, int *ptr, int len);
  
0.  
>節點地址查找,支持反向查找 (鏈結開頭,位置)  
<code>node* node_address(node* nh, int p);
  
0.  
>插入節點,插入點會被往後推 (鏈結開頭,插入位置,數值)  
<code>void node_insert(node* nh, int p, int data);
  
0.  
>刪除節點 (鏈結開頭,刪除位置)  
<code>void node_delete(node* nh, int p);
  
0.  
>刪除鏈結,不會刪除鏈結開頭 (鏈結開頭)  
<code>void node_deleteall(node* nh);
  
0.  
>確認是否為開頭 (任意節點)  
<code>int nodep_checkhead(node* n);
  
0.  
>取出節點,回傳取出的地址,注意點沒有移除 (任意節點)  
<code>node* nodep_unlink(node* n1);
  
0.  
>插入節點,n2插到n1前面 (任意節點,任意節點)  
<code>void nodep_insert(node* n1, node* n2);
  
0.  
>n1鏈結尾端加入n2鏈結 (任意節點,節點開頭)  
<code>void nodep_link(node* n1, node* n2);
  
0.  
>查詢順序是否正確 (任意節點,任意節點)  
<code>int nodep_checkseq(node* n1, node* n2);
  
0.  
>節點交換 (任意節點,任意節點)  
<code>void nodep_change(node* n1, node* n2);
  
0.  
>尋找節點開頭的地址 (任意節點)  
<code>node* nodep_head(node* n);
  
0.  
>找鏈結資料 (鏈結開頭,資料位置)  
<code>int node_value(node* nh, int p);
  
0.  
>排序鏈結資料 (鏈結開頭,排序頭,排序尾)  
<code>void node_short(node* nh, int h, int f);
  
0.  
>排序鏈結全部資料 (鏈結開頭)  
<code>void node_short(node* nh);
  
0.  
>排序鏈結前幾筆資料 (鏈結開頭,排序位置)  
<code>void node_short(node* nh,int p);


## 06
創建陣列，利用指標控制，更改數值
