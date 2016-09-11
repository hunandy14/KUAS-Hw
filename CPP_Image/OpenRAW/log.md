## 方法回傳為參考時，必須同時定義 const 與非const 版本
有些時候必須使用const，比如說運算子重載的時候
這時候沒有定義你就沒有辦法直接使用了

[下标操作符为什么要定义const和非const两个版本？](http://zhidao.baidu.com/question/517798128.html)
[const 放置位置的意義](http://blog.xuite.net/tsai.oktomy/program/65131235-const+%E6%94%BE%E7%BD%AE%E4%BD%8D%E7%BD%AE%E7%9A%84%E6%84%8F%E7%BE%A9)

## 重載運算子
用來暫存的temp忘記定義影像大小，找bug找好久QQ
要把影像大小預設值為0拔掉了
