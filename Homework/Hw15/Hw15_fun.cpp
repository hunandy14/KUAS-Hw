/**********************************************************
Name:KUAS-Hw/Hw15
Date:2016/05/10
Final:2016/05/11
By CharlotteHong
**********************************************************/
#include "Hw15_fun.h"
#include "stringsplit.cpp"
/* ===================================================== */
string one(string str){
    string str_dig;
    for (int i = 0; i < (int)str.length(); ++i){
        switch (str[i]) {
            case '0':
                str_dig += "Zero";
                break;
            case '1':
                str_dig += "One";
                break;
            case '2':
                str_dig += "Two";
                break;
            case '3':
                str_dig += "Three";
                break;
            case '4':
                str_dig += "Four";
                break;
            case '5':
                str_dig += "Five";
                break;
            case '6':
                str_dig += "Six";
                break;
            case '7':
                str_dig += "Seven";
                break;
            case '8':
                str_dig += "Egiht";
                break;
            case '9':
                str_dig += "Nine";
                break;
            default:
                break;
        }
    }
    return str_dig;
}

string two(string str, int n){
    string str_de = str;
    int len = str_de.length();
    // 插入跳行
    for (int i = 0; i < len/2; ++i){
        str_de.insert(((i+1)*2)+i," ");
    }
    return str_de;
}

string three(string str){
    string str_s, slen;
    stringstream ss;
    // 切割字串
    string* temp = str_split(str.c_str(), " ");
    int len=strarr_len(temp);
    // 取得子字串長度
    for (int i = 1; i < len+1; ++i){
        ss.str("");
        ss << temp[i].length();
        slen.erase();
        slen = ss.str();
        str_s += temp[i]+"["+slen+"] ";
    }
    // cout << endl << "str_s=" << str_s << endl;
    delete [] temp;
    return str_s;
}
/* ===================================================== */