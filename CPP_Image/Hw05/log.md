紀錄 
===

#20160929
## 後來把無效值得運算去除了
後面有些數值怪怪的，直接break掉
好像有改錯什麼地方左上角沒畫出來，
後來改一改條件又好了

## 原本思想的優化搜索點
不能保證每個點都是連續的，不曉得該如何過濾
保險怕出問題，就不優化了，運算時間也已經優化到差不多了

## 減少三角函數運算，省這麼多時間
從本來的[23~24]縮短到只剩[3~4]
數值在for裡面是重複運算的，但並沒有變動
把它拿出來for外面算一次好

## 浪費時間了
怎麼可能跑過一輪就可以找出所有大小了QQ
這樣也不需要排序了說，想錯了做好久

