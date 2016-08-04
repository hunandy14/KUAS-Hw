/**********************************************************
Name : 
Date : 2016/08/03
By   : CharlotteHonG
Final: 2016/08/03
**********************************************************/
imgraw::imgraw(int y, int x){
    this->width = x;
    this->high = y;
    this->filesize = x*y;
    this->img_data = new char[x*y];
}
imgraw::~imgraw(){
    delete [] this->img_data;
}


void imgraw::read(string filename){
    this->filename = filename;
    // 二進位模式開檔測試
    img.open(filename, ios::in | ios::binary);
        //如果開啟檔案失敗，fp為0；成功，fp為非0
    if(!img){
        img.close();
        cout << "No file." << endl;
        exit(1);
    }
    else{
        cout << "File ok." << endl;
    }img.close();
    // 二進位模式讀檔
        // 取得總長
    img.open(this->filename, ios::in | ios::binary);
    img.seekg(0, ios::end);
    this->filesize = img.tellg();
    img.seekg(0, ios::beg);
        // 讀取值
    delete [] this->img_data;
    this->img_data = new char[this->filesize];
    img.read(this->img_data, this->filesize);
    img.close();
}

void imgraw::write(string filename){
    // 進位模式寫檔
    img.open(filename, ios::out | ios::binary);
    img.write(img_data, this->filesize);
    img.close();
}

char imgraw::point_read(int y, int x){
    int pos = (y*this->width)+x;
    return this->img_data[pos];
}

void imgraw::point_write(int y, int x, const char* value){
    int pos = (y*this->width)+x;
    this->img_data[pos] = value[0];
}