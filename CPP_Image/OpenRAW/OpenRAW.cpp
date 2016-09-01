/**********************************************************
Name : OpenRaw 2.21
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/25
**********************************************************/
// ImrMask建解構子
// ImrMask::ImrMask(){
// }
// ImrMask::~ImrMask(){
// }

// ImrSize建構子
ImrSize::ImrSize(imint high=0, imint width=0){
    this->high  = high;
    this->width = width;
}

// ImrCoor建構子
ImrCoor::ImrCoor(imint y=0, imint x=0){
    this->y = y;
    this->x = x;
}

// imgraw建構子
imgraw::imgraw(ImrSize size=ImrSize(0,0)) {
    imint x = size.width;
    imint y = size.high;
    this->width = x;
    this->high = y;
    this->img_data.vector::resize(x*y);
    this->filesize = x*y;
    this->masksize = ImrSize(0,0);
}
//=========================================================
// 取得遮罩值
imch imgraw::mask(ImrCoor ori, ImrCoor tar, 
        int sy=-1, int sx=-1){
    // 判斷遮罩大小是否初始化
    if (this->masksize.high == 0 
        && this->masksize.width == 0){
        cout << "masksize uninit." << endl;
        return 0;
    }
    imch temp=0;
    ImrCoor pos;
    // pos=ori+tar;
    // this->point_read()
    return temp;
}
// 設定遮罩
void imgraw::setMaskSize(ImrSize masksize){
    this->masksize = masksize;
}
// 取得遮罩地址
// imch** imgraw::getMask(int oy, int ox,
        // ImrSize size=ImrSize(3,3), int sy=-1, int sx=-1){
    // 創建動態陣列
    // imch** mask;
    // mask = new imch*[(int)size.high];
    // for (int i = 0; i < (int)size.high; ++i)
        // mask[i] = new imch[(int)size.width];
    // 取得周圍16點
    // int foy,fox; // 修復後的原始座標
    // for (int j = 0; j < size.high; ++j){
    //     for (int i = 0; i < size.width; ++i){
    //         foy=oy+(j+(sy)); fox=ox+(i+(sx));
    //         // 超過邊界修復

    //         // 紀錄對應的指標
    //         mask[j][i] = this->point_read(foy, fox);
    //     }
    // }
    // 釋放記憶體
    // for (int i = 0; i < 4; ++i)
    //     delete [] mask[i];
    // delete [] mask;
    // return mask;
// }
//=========================================================
// 匯入檔案
void imgraw::read(string filename) {
    this->filename = filename;
    // 二進位模式開檔測試
    fstream img;
    img.open(filename, ios::in | ios::binary);
    // 如果開啟檔案失敗，fp為0；成功，fp為非0
    if(!img) {
        img.close();
        cout << "No file." << endl;
        exit(1);
    }
    else {
        // cout << "File ok." << endl;
    } img.close();
    // 二進位模式讀檔
    // 取得總長
    img.open(this->filename, ios::in | ios::binary);
    img.seekg(0, ios::end);
    this->filesize = img.tellg();
    img.seekg(0, ios::beg);
    // 讀取值
    this->img_data.vector::resize(this->filesize);
    img.read((char*)&this->img_data[0], this->filesize);
    img.close();
}

// 將記憶體資料匯出
void imgraw::write(string filename) {
    // 進位模式寫檔
    fstream img;
    img.open(filename, ios::out | ios::binary);
    img.write((char*)&img_data[0], this->filesize);
    img.close();
}

// 讀檔單點
imch imgraw::point_read(imint y, imint x) {
    imint pos = (y*this->width)+x;
    return this->img_data.at(pos);
}

// 寫入記憶體單點
void imgraw::point_write(imint y, imint x, imch value) {
    imint pos = (y*this->width)+x;
    this->img_data.vector::at(pos) = value;
}

// 調整畫布大小
void imgraw::resize_canvas(ImrSize size) {
    imint x = size.width;
    imint y = size.high;
    // cout << "x=" << x << endl;
    // cout << "y=" << y << endl;
    this->width = x;
    this->high = y;
}

// 獲得寬
imint imgraw::w() {
    return this->width;
}

// 獲得高
imint imgraw::h() {
    return this->high;
}
// 印出直方圖
void imgraw::pri_htg(string title=""){
    // 取得數據
    this->histogram();
    // 壓縮數據
    int htg_comp[32]={0};
    for (int i = 0; i < 32; ++i){
        htg_comp[i]=(
            htg_data[(i*8)+0]+
            htg_data[(i*8)+1]+ 
            htg_data[(i*8)+2]+ 
            htg_data[(i*8)+3]+
            htg_data[(i*8)+4]+
            htg_data[(i*8)+5]+
            htg_data[(i*8)+6]+
            htg_data[(i*8)+7]
        );
    }
    // 找最高值
    int htg_high=0;
    for (int i = 0; i < 32; ++i){
        if (htg_comp[i]>htg_high){
            htg_high = htg_comp[i];
        }
    }
    // 轉換等比
    int htg_rate[32]={0};
    for (int i = 0; i < 32; ++i){
        htg_rate[i] = (int)((double)htg_comp[i]/(double)htg_high*32);
    }
    // 轉換字串
    string str[32][32];
    for (int j = 0; j < 32; ++j){
        for (int i = 0; i < htg_rate[j]; ++i){
            str[j][i]+=" ▌";
        }
    }
    // 取得整數長度
    string temp;
    stringstream ss;
    ss << htg_high;
    temp.clear();
    ss >> temp;
    ss.clear();
    // 印出
    cout << endl << setw((64-3)-(title.length()/2));
    cout << title << endl;
    for (int i = 31; i >= 0; --i){
        cout << setw(temp.length()) << htg_high/32*(i+1) << " ";
        for (int j = 0; j < 32; ++j){
            cout << setw(3) <<str[j][i];
        }
        cout << endl;   
    }
    // 數據說明欄
    cout << setw(3) << "";
    for (int i = 0; i < 32/2; ++i){
        cout << setw(6) << (i+1)*16;  
    }
    cout << "" << endl;
}
// 取得數據統計(數值0~255有幾個)
void imgraw::histogram(){
    int s=this->width * this->high;
    int temp;
    // 歸零
    for (int i = 0; i < 256; ++i)
        this->htg_data[i]=0;
    // 取得數據
    for (int i = 0; i < s; ++i){
        temp = (int)this->img_data.at(i);
        ++this->htg_data[temp];
    }
}
// 取得數據極值
void imgraw::extremum(){
    imch temp;
    this->min=255;
    this->max=0;
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            temp = this->point_read(j,i);
            if (temp > this->max){
                this->max = temp;
            }else if (temp < this->min){
                this->min = temp;
            }
        }
    }
}
