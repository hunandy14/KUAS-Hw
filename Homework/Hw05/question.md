## 參數如何可有可無
比如說 `fun(list,12);` `fun(list);` 同時可接受這種格式

## 物件導向
C++似乎可以把它寫成 `list.fun(12)` 是如何做到的
又是如何做到參數可有可無

## 多重指標意義
什麼時候才需要2個 ** 意義在哪


## 關於typedef有什麼差別呢


通常他可能是長這個樣子，這樣子可以直接用node宣告
<pre>
    typedef struct node_struct {
        struct node_struct *link;
        int data;
        struct node_struct *rlink;
    } node;
</pre>
---

裡面的宣告，我看別人是打struct node_struct  
我發現就算少了struct直接打node_struct  
也可以過編譯，有影響嗎
<pre>
    typedef struct node_struct {
        node_struct *link;
        int data;
        node_struct *rlink;
    } node;
</pre>
---

如果把它換成這樣子似乎比較好理解
<pre>
    typedef struct node_struct node;
    struct node_struct {
        node *link;
        int data;
        node *rlink;
    };
</pre>
---

我有發現到順序換過來也可以使用，會有什麼影響?
<pre>
    struct node_struct {
        node *link;
        int data;
        node *rlink;
    };
    typedef struct node_struct node;
</pre>
---

為何這樣子編譯過不了
<pre>
    typedef struct node_struct node;
    node {
        node *link;
        int data;
        node *rlink;
    };
</pre>
---

## const 意義是什麼
參考 <https://gist.github.com/hunandy14/f52956ba1d17ba8da5bce465e34cd058>

為何 `int* str_split(char* str, const char* sp)`  
這裡的第二個參數必須要用const否則無法編譯   
第一個參數不管有沒有用const都可以編譯   
是基於什麼理由才導致這樣的   
我是跑去翻找`strcmp()`的.h原始程式  
發現他有加跟著加結果就過了，結果就過了QQ   
另外我也很疑惑 uint8_t 做什麼用的，官方文件似乎都是用這個   
