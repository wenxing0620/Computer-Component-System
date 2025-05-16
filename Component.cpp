#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Component.h"
using namespace std;
istream &operator>>(istream &in, CMP &a)
{
    cout << "请输入这个配件的类型:" << endl
         << "主板请输入   1" << endl
         << "处理器请输入 2" << endl
         << "内存条请输入 3" << endl
         << "显卡请输入   4" << endl
         << "硬盘请输入   5" << endl
         << "电源请输入   6" << endl
         << "机箱请输入   7" << endl;
    while (1)
    {
        cout << "请输入这个配件的类型(1-7):";
        in >> a.name;
        if (a.name >= 1 && a.name <= 7)
            break;
        else
            cout << "输入不合理,请重新输入!:";
        in.clear();
        in.ignore(1024, '\n');
    }
    in.ignore(1024, '\n');
    cout << "请输入这个配件的价格(单位：元):";
    while (1)
    {
        in >> a.price;
        if (a.price > 0)
            break;
        else
            cout << "输入的价格不合理,请重新输入!:";
        in.clear();
        in.ignore(1024, '\n');
    }
    in.ignore(1024, '\n');
    cout << "请输入这个配件的分类号:";
    cout << "(eg:Core i7 13th Gen)";
    in.getline(a.categ, sizeof(a.categ));
    cout << "请输入这个配件的型号:";
    in.getline(a.model, sizeof(a.model));
    cout << "请输入这个配件的生产厂商:";
    in.getline(a.manufacturer, sizeof(a.manufacturer));
    cout << "请输入这个配件的报价时间(格式YYYY-MM):"<<endl;
    in >> a.quotetime;
    return in;
}
ostream &operator<<(ostream &out, const CMP &a)
{
    out << left;
    out << setw(10);
    switch (a.name)
    {
    case 1:
        out << "主板" ;
        break;
    case 2:
        out << "处理器" ;
        break;
    case 3:
        out << "内存条" ;
        break;
    case 4:
        out << "显卡" ;
        break;
    case 5:
        out << "硬盘" ;
        break;
    case 6:
        out << "电源" ;
        break;
    case 7:
        out << "机箱" ;
        break;
    default:
        out << "未知类型" ;
        break;
    }
    out<<setw(10)<<a.price<<setw(30)<<a.categ<<setw(40)<<a.model<<setw(20)<<a.manufacturer<<a.quotetime;
    out<<endl;
    return out;
}
