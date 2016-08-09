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

// �פJ�ɮ�
void imgraw::read(string filename) {
    this->filename = filename;
    // �G�i��Ҧ��}�ɴ���
    img.open(filename, ios::in | ios::binary);
    // �p�G�}���ɮץ��ѡAfp��0�F���\�Afp���D0
    if(!img) {
        img.close();
        cout << "No file." << endl;
        exit(1);
    }
    else {
        cout << "File ok." << endl;
    } img.close();
    // �G�i��Ҧ�Ū��
    // ���o�`��
    img.open(this->filename, ios::in | ios::binary);
    img.seekg(0, ios::end);
    this->filesize = img.tellg();
    img.seekg(0, ios::beg);
    // Ū����
    this->img_data.resize(this->filesize);
    img.read(&this->img_data[0], this->filesize);
    img.close();
}

// �N�O�����ƶץX
void imgraw::write(string filename) {
    // �i��Ҧ��g��
    img.open(filename, ios::out | ios::binary);
    img.write(&img_data[0], this->filesize);
    img.close();
}

// Ū�ɳ��I
vector<char> imgraw::point_read(int y, int x) {
    int pos = (y*this->width)+x;
    vector<char> temp(1);
    temp[0] = this->img_data[pos];
    return temp;
}

// �g�J�O������I
void imgraw::point_write(int y, int x, vector<char> value) {
    int pos = (y*this->width)+x;
    this->img_data[pos] = value[0];
}

// ZroOrder�վ�j�p
void imgraw::resize_zero(float Ratio){
    //=========================================
    float rat = (float)Ratio;
    int Pic_x = this->width;
    int Pic_y = this->high;
    imgraw img2(Pic_y*Ratio, Pic_x*Ratio);

    float rat_r = floor(rat);
    int apend_p=0; // �ݭn�ɪ��I
    int white=0; //�X�ӭ��I (��) �ɤ@�ӷs�I (��)
    int black=0; //�B�z��j���v�p���I�A�C�X�ӭ��I�h�ɤ@�ӷs�I
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

        // ���I�ާ@
        for(int j=0, yp=0; j < Pic_y; ++j) {
            limx_c=0;
            for(int i=0, xp=0; i < Pic_x; ++i) {
                // ��J��Ϫ��I
                img2.point_write(j+yp, i+xp, this->point_read(j, i));
                // ���I (���) �C�g�@���I�ɦh�ַs�I
                for(int k = 0; k < white; ++k) {
                    // k=���I�첾���СA���O��J�I�첾����
                    img2.point_write(j+yp, (i+xp)+k+1, this->point_read(j, i));
                } xp+=white; //��J�I�첾����
                // ���I 2 (�p���I���v) �C�g�X���I�ɤ@�I�s�I
                if(black!=0 && (i+1)%black==0) { // �q0�}�l�G�h+1
                    // debug++;
                    if(limx_c<limx) {
                        limx_c+=1;
                        img2.point_write(j+yp, (i+xp)+1, this->point_read(j, i));
                        xp+=1;
                    }
                }
            }

            // �ɱ� (���)
            for(int i = 0; i < white; ++i) {
                for(int k=0; k < Pic_x*rat; ++k)
                    img2.point_write(j+yp+1+i, k, img2.point_read(j+yp, k));
                // debug+=1;
            } yp+=white; //��J�Ʀ첾����
            // �ɱ� 2 (�p���I���v)
            if(black!=0 && (j+1)%black==0) { // �q0�}�l�G�h+1
                if(limy_c<limy) {
                    if(white==0) { // ���v����1~2��
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
                    yp+=1; //��J�Ʀ첾����
                }
            }
        }
    } else { // �Y�p
        int jmp=0; // �CŪ�X�I���L
        jmp = (1 / (1-rat));
        cout << "jmp=" << jmp << endl;
        limx = floor(Pic_x*rat);
        limy = floor(Pic_y*rat);
        for(int j = 0, yp = 0; j < Pic_y; ++j){
            // �C
            limx_c=0;
            for(int i = 0,xp = 0; i < Pic_x; ++i){
                if ((i+1)%jmp!=0){// �C�j jmp �I�N���L
                    img2.point_write(yp, xp, this->point_read(j, i));
                    limx_c+=1;
                    xp+=1;
                    // �o�̪����ƤӤ�
                }
            }
            // ��
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

    // �N�Ȧs�g�^�D��
    this->img_data=img2.img_data;
    this->filesize=img2.filesize;
    this->width=img2.width;
    this->high=img2.high;
}