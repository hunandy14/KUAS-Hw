/**********************************************************
Name : OpenRaw 2.32
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/09/08
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
/*
    ###               #     #
     #  #    # #####  ##   ##   ##    ####  #    #
     #  ##  ## #    # # # # #  #  #  #      #   #
     #  # ## # #    # #  #  # #    #  ####  ####
     #  #    # #####  #     # ######      # #  #
     #  #    # #   #  #     # #    # #    # #   #
    ### #    # #    # #     # #    #  ####  #    #
*/
// 排序陣列(長度，起始點)
void ImrMask::sort(size_t len=0, size_t start=0) {
    imch temp;
    imch* arr = &this->mask[start];
    if (len == 0){
        len = this->masksize.high*this->masksize.width; 
    }
    // // 插入排序法
    for (int i=1, j; i<(int)len; i++) {
        temp = arr[i];
        for (j=i-1; j>=0 && arr[j]>temp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}
// 以二維方式讀取或寫入
imch& ImrMask::at2d(size_t y, size_t x){
    size_t pos = (y*this->masksize.width) + x;
    return this->mask[pos];
}

/*
       ##

     ####     ### ##    ######  ## ###    ######  ##   ##
       ##     ## # ##  ##   ##  ###      ##   ##  ## # ##
       ##     ## # ##  ##   ##  ##       ##   ##  ## # ##
       ##     ## # ##   ######  ##       ##  ###  ## # ##
     ######   ##   ##       ##  ##        ### ##   ## ##
                        #####
*/
// 取得遮罩值 (原點，遮罩座標，位移)
imch& imgraw::maskVal(ImrCoor ori, ImrCoor mas, 
        ImrCoor shi=ImrCoor(-1,-1)){
    // 取得對應位置
    ImrCoor pos = ori + mas + shi;
    // 修正邊緣
    if (pos.y <0){
        pos.y = 0;
    }
    if (pos.y > (int)this->high-1){
        pos.y = (int)this->high-1;
    }
    if (pos.x <0){
        pos.x = 0;
    }
    if (pos.x > (int)this->width-1){
        pos.x = (int)this->width-1;
    }
    // 回傳正確位置的數值
    return this->at2d((pos.y), (pos.x));
}
// 取得遮罩，回傳一維陣列(原點位置，位移維度)
ImrMask imgraw::getMask(ImrCoor ori, 
        ImrCoor shi = ImrCoor(-1,-1)){
    if (this->masksize.high == 0
        && this->masksize.width == 0){
        cout << "Error! Uninit masksize." << endl;
        return ImrMask();
    }
    // 創建動態陣列
    ImrMask mask;
    mask = ImrMask(this->masksize);
    // 複製遮罩
    for (int j = 0; j < (int)this->masksize.high; ++j){
        for (int i = 0; i < (int)this->masksize.width; ++i){
            // 遮罩位置
            ImrCoor mas(j,i);
            // 複製遮罩數值
            mask.at2d(j,i)=this->maskVal(ori, mas, shi);
        }
    }
    // 印出
    // for (int j = 0; j < 3; ++j){
    //     for (int i = 0; i < 3; ++i){
    //         cout << mask.at2d(j,i);
    //     }cout << endl;
    // }
    // return ImrMask();
    return mask;
}

// 設定遮罩
void imgraw::setMaskSize(ImrSize masksize){
    this->masksize = masksize;
}
/*
     ##   ##             ##
     ###  ##
     ###  ##   #####   ####      #####    #####
     ## # ##  ##   ##    ##     ##       ##   ##
     ## # ##  ##   ##    ##      ####    #######
     ##  ###  ##   ##    ##         ##   ##
     ##   ##   #####   ######   #####     #####

*/
// 高斯
void imgraw::gaussian(double dev=5){
    // 係數
    double sq_12 = sqrt((double)12);
    double sq_10 = sqrt((double)10);
    // 高斯係數
    double gau = (sq_12*dev)/sq_10;
    // 計算
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            // 取亂數
            int ran = rand_int(-dev,dev+1);
            // 雜訊值
            double noise = gau*ran;
            // 寫入圖檔
            double temp = (double)this->point_read(j,i);
            temp += noise;
            if (temp > 255)
                temp = 255;
            else if (temp < 0)
                temp = 0;
            this->point_write(j, i, (imch)temp);
        }
    }

}
// 中值
void imgraw::median_filter(ImrSize size=ImrSize(3,3)){
    this->setMaskSize(size);
    imgraw img2(ImrSize(this->high, this->width));
    int maslen = (int)size.high*(int)size.width;
    int mid=maslen/2;
    // 單點處理
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            ImrMask mask=this->getMask(ImrCoor(j, i));
            mask.sort();
            img2.at2d(j, i) = mask[mid];
        }
    }
    // 寫回舊圖
    *this=img2;
}
// 低通
void imgraw::low_pass(ImrSize size=ImrSize(3,3)){
    imgraw img2(ImrSize(this->high, this->width));
    double maslen = (double)size.high*(double)size.width;
    // 單點處理
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            double long temp=0;
            // 取得遮罩加總數值
            for (int k = 0; k < (int)size.high; ++k){
                for (int l = 0; l < (int)size.width; ++l){
                    ImrCoor ori(j,i);
                    ImrCoor mas(k, l);
                    temp += this->maskVal(ori, mas);
                }
            }
            // 取得平均
            temp = temp/maslen;
            // 寫入新圖
            img2.at2d(j, i) = (imch)temp;
        }
    }
    // 寫回舊圖
    *this=img2;
}
// 胡椒鹽雜訊
void imgraw::salt_pepper(imint white, imint black=0){
    srand((unsigned)time(NULL));
    ImrSize size(this->high, this->width);
    imgraw img2(size);
    int temp;
    // 灑黑點
    temp = ((double)black/(double)100)
                     * this->high * this->width;
    // cout << temp << endl;
    for (int i = 0; i < temp; ++i){
        int y = rand_int(0,256);
        int x = rand_int(0,256);
        if (img2.point_read(y, x) != 1){
            img2.point_write(y, x, (imch)1);
        }else {--i;}
    }
    // 灑白點
    temp = ((double)white/(double)100)
                     * this->high * this->width;
    // cout << temp << endl;
    for (int i = 0; i < temp; ++i){
        int y = rand_int(0,256);
        int x = rand_int(0,256);
        if (img2.point_read(y, x) != 255
            && img2.point_read(y, x) != 1){
            img2.point_write(y, x, (imch)255);
        }else {--i;}
    }
    // 灑到原圖上
    for (int j = 0; j < (int)this->high; ++j){
        for (int i = 0; i < (int)this->width; ++i){
            imch temp = img2.point_read(j, i);
            if (temp == (imch)1){
                this->point_write(j, i, (imch)0);
            }else if (temp == (imch)255){
                this->point_write(j, i, (imch)255);
            }
        }
    }
    // *this = img2;
}
// 取亂數(不包含up)
int imgraw::rand_int(int low, int up){
    int temp;
    if (low < 0)
        low-=1;
    temp = (int)((rand() / (RAND_MAX+1.0)) * (up - low) + low);
    return temp;
}
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

// 讀檔單點(檢查邊界)
imch imgraw::point_read(imint y, imint x) {
    imint pos = (y*this->width)+x;
    return this->img_data.at(pos);
}
// 寫入記憶體單點(檢查邊界)
void imgraw::point_write(imint y, imint x, imch value) {
    imint pos = (y*this->width)+x;
    this->img_data.vector::at(pos) = value;
}
// 以二維方式讀取或寫入(檢查邊界)
imch& imgraw::at2d(size_t y, size_t x){
    size_t pos = (y*this->width)+x;
    return this->img_data.at(pos);
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
/*
            __  ___  __   __   __
    |__| | /__`  |  /  \ / _` |__)  /\   |\/|
    |  | | .__/  |  \__/ \__> |  \ /~~\  |  |

*/
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
            temp = this->at2d(j,i);
            if (temp > this->max){
                this->max = temp;
            }else if (temp < this->min){
                this->min = temp;
            }
        }
    }
}
//=========================================================
//-----------------------運算子重載-------------------------
//=========================================================
// ImrCoor運算子重載
ImrCoor ImrCoor::operator+(const ImrCoor &p){
    ImrCoor temp;
    temp.y = this->y + p.y;
    temp.x = this->x + p.x;
    return temp;
}
ImrCoor ImrCoor::operator-(const ImrCoor &p){
    ImrCoor temp;
    temp.y = this->y - p.y;
    temp.x = this->x - p.x;
    return temp;
}
ImrCoor ImrCoor::operator*(const ImrCoor &p){
    ImrCoor temp;
    temp.y = this->y * p.y;
    temp.x = this->x * p.x;
    return temp;
}
ImrCoor ImrCoor::operator/(const ImrCoor &p){
    ImrCoor temp;
    temp.y = (int)((double)this->y / (double)p.y);
    temp.x = (int)((double)this->x / (double)p.x);
    return temp;
}
// ImrMask 運算子重載
imch& ImrMask::operator[](const size_t __n){
    return this->mask[__n];
}
// imgraw 運算子重載
imch& imgraw::operator[](const size_t __n){
    return this->img_data[__n];
}