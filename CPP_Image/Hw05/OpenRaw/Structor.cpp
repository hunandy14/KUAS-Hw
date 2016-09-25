/**********************************************************
Name : 
Date : 2016/09/25
By   : CharlotteHonG
Final: 2016/09/25
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
ImrMask::ImrMask(ImrSize masksize=ImrSize(0,0)){
    this->mask.vector::resize(masksize.high * masksize.width);
    this->masksize = masksize;
}

// ImrPolar建構子
ImrPolar::ImrPolar(ImrSize size) {
    this->dis = size.high;
    this->ang = size.width;
    this->polar.vector::resize(size.high*size.width);
    this->P_limit = size.high*180;
}
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