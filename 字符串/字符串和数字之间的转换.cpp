// 数字转字符串
string num2str(int x){
    string res;
    stringstream ss;          //定义流ss
    ss << x;                     //将数字a转化成流ss
    ss >> res;                  //将流ss转化成字符串
    return res;
}

// 字符串转数字
int str2num(string x){
    double a;
    stringstream ss;
    ss << x;
    ss >> a;
    return a;
}