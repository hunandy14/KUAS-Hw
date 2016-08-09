/**********************************************************
Name : 
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/03
**********************************************************/
imgraw::imgraw(int y, int x) {
    this->width = x;
    this->high = y;
    this->img_data.resize(x*y);
    this->filesize = x*y;
}

// 匯入檔案
void imgraw::read(string filename) {
    this->filename = filename;
    // 二進位模式開檔測試
    img.open(filename, ios::in | ios::binary);
    // 如果開啟檔案失敗，fp為0；成功，fp為非0
    if(!img) {
        img.close();
        cout << "No file." << endl;
        exit(1);
    }
    else {
        cout << "File ok." << endl;
    } img.close();
    // 二進位模式讀檔
    // 取得總長
    img.open(this->filename, ios::in | ios::binary);
    img.seekg(0, ios::end);
    this->filesize = img.tellg();
    img.seekg(0, ios::beg);
    // 讀取值
    this->img_data.resize(this->filesize);
    img.read(&this->img_data[0], this->filesize);
    img.close();
}

// 將記憶體資料匯出
void imgraw::write(string filename) {
    // 進位模式寫檔
    img.open(filename, ios::out | ios::binary);
    img.write(&img_data[0], this->filesize);
    img.close();
}

// 讀檔單點
vector<char> imgraw::point_read(int y, int x) {
    int pos = (y*this->width)+x;
    vector<char> temp(1);
    temp[0] = this->img_data[pos];
    return temp;
}

// 寫入記憶體單點
void imgraw::point_write(int y, int x, vector<char> value) {
    int pos = (y*this->width)+x;
    this->img_data[pos] = value[0];
}

// ZroOrder調整大小
void imgraw::resize_zero(float Ratio){
    //=========================================
    float rat = (float)Ratio;
    int Pic_x = this->width;
    int Pic_y = this->high;
    imgraw img2(Pic_y*Ratio, Pic_x*Ratio);

    float rat_r = floor(rat);
    int apend_p=0; // 需要補的點
    int white=0; //幾個原點 (黑) 補一個新點 (白)
    int black=0; //處理放大倍率小數點，每幾個原點多補一個新點
    int limx=0,limy=0, limx_c=0,limy_c=0;
    int debug=0;
    apend_p = Pic_x*(rat-1);

    if(rat>1) {
        white = (rat_r)-1;
        if((rat-rat_r) > 0) {
            black = 1/(rat-rat_r);
            cout << "   **" << (rat-rat_r) <<endl;
            cout << "   black = " << black <<endl;
            limx = Pic_x * (rat-rat_r);
            limy = Pic_y * (rat-rat_r);
        }

        // 單點操作
        for(int j=0, yp=0; j < Pic_y; ++j) {
            limx_c=0;
            for(int i=0, xp=0; i < Pic_x; ++i) {
                // 填入原圖的點
                img2.point_write(j+yp, i+xp, this->point_read(j, i));
                // 補點 (整數) 每經一圓點補多少新點
                for(int k = 0; k < white; ++k) {
                    // k=補點位移指標，不是填入點位移指標
                    img2.point_write(j+yp, (i+xp)+k+1, this->point_read(j, i));
                } xp+=white; //填入點位移指標
                // 補點 2 (小數點倍率) 每經幾原點補一點新點
                if(black!=0 && (i+1)%black==0) { // 從0開始故多+1
                    // debug++;
                    if(limx_c<limx) {
                        limx_c+=1;
                        img2.point_write(j+yp, (i+xp)+1, this->point_read(j, i));
                        xp+=1;
                    }
                }
            }

            // 補排 (整數)
            for(int i = 0; i < white; ++i) {
                for(int k=0; k < Pic_x*rat; ++k)
                    img2.point_write(j+yp+1+i, k, img2.point_read(j+yp, k));
                // debug+=1;
            } yp+=white; //填入排位移指標
            // 補排 2 (小數點倍率)
            if(black!=0 && (j+1)%black==0) { // 從0開始故多+1
                if(limy_c<limy) {
                    if(white==0) { // 倍率介於1~2時
                        if(limy_c<limy) {
                            limy_c+=1;
                            for(int k=0; k < Pic_x*rat; ++k)
                                img2.point_write(j+yp+1, k, img2.point_read(j+yp, k));
                        }
                    }
                    else {
                        for(int i = 0; i < white; ++i) {
                            if(limy_c<limy) {
                                limy_c+=1;
                                for(int k=0; k < Pic_x*rat; ++k)
                                    img2.point_write(j+yp+1+i, k, img2.point_read(j+yp, k));
                            }
                            // debug+=1;
                        }
                    }
                    yp+=1; //填入排位移指標
                }
            }
        }
    } else { // 縮小
        int jmp=0; // 每讀幾點跳過
        jmp = (1 / (1-rat));
        cout << "jmp=" << jmp << endl;
        limx = floor(Pic_x*rat);
        limy = floor(Pic_y*rat);
        for(int j = 0, yp = 0; j < Pic_y; ++j){
            // 列
            limx_c=0;
            for(int i = 0,xp = 0; i < Pic_x; ++i){
                if ((i+1)%jmp!=0){// 每隔 jmp 點就跳過
                    img2.point_write(yp, xp, this->point_read(j, i));
                    limx_c+=1;
                    xp+=1;
                    // 這裡的次數太少
                }
            }
            // 排
            if ((j+1)%jmp!=0 && limy_c< floor(Pic_x*rat)-1){
                // if (limy_c<limy){
                    limy_c+=1;
                    yp+=1;
                // }
            }
        }
    }

    cout << "pix = " << (int)(Pic_x*Ratio) << endl;
    cout << "apend_p = "   << apend_p   << endl;
    cout << "Pic_x = "   << Pic_x   << endl;
    cout << "white = "   << white   << endl;
    cout << "black = "   << black   << endl;
    cout << "limx = "   << limx   << endl;
    cout << "limy = "   << limy   << endl;
    cout << "limx_c = "   << limx_c   << endl;
    cout << "limy_c = "   << limy_c   << endl;
    cout << "debug = "   << debug   << endl;
    // cout << "t = "   << ((float)Ratio-(int)Ratio)   << endl;

    // 將暫存寫回主檔
    this->img_data=img2.img_data;
    this->filesize=img2.filesize;
    this->width=img2.width;
    this->high=img2.high;
}