#### 文件名稱：類別間的關係 – 嵌入與繼承
* 撰寫人員：楊弋軒 
* 硬體要求：PC 
* 軟體要求：C Compiler 

#### 作業內容： 
本次作業主要是熟悉類別物件間使用繼承來達成之間關係。  
這次要模擬出一個小遊戲的架構  

<pre>
Organism(生物){ Summoner, Monster }  
Summoner(主角){HP,SP,ATK,Bag}  
Monster(怪物){HP,SP,ATK}  
HP(生命)、SP(魔力)、ATK(攻擊力)  
Equipment(背包){Food,Arms,Material}  
Arms(武器)、Apparel (服飾)、Shoe(鞋子)  
</pre>

請問如何利用物件導向的方式界定各個資料間的關係？  
請實作出一個小程式，執行時可產生主角與怪物兩個個體，  
利用繼承的方式，將主角與怪物寫成兩個CLASS，最後顯示出  

<pre>
主角
    主角的HP 
    主角的 SP 
    主角的ATK” 
</pre>
<pre>
怪物：
    怪物的 HP 
    怪物的 SP 
    怪物的 ATK” 
</pre>