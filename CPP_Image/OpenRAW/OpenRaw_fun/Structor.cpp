/**********************************************************
Name : 
Date : 2016/10/03
By   : CharlotteHonG
Final: 2016/10/03
**********************************************************/
// ImrSize建構子
ImrSize::ImrSize(imint high=0, imint width=0){
    this->high  = high;
    this->width = width;
}
// ImrCoor建構子
ImrCoor::ImrCoor(int y=0, int x=0){
    this->y = y;
    this->x = x;
}
// ImrMask建構子

// imgraw建構子
imgraw::imgraw(ImrSize size) {
    imint x = size.width;
    imint y = size.high;
    this->width = x;
    this->high = y;
    this->img_data.vector::resize(x*y);
    this->filesize = x*y;
    this->masksize = ImrSize(0,0);
}