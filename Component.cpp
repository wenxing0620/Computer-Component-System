#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Component.h"
using namespace std;
istream &operator>>(istream &in, CMP &a)
{
    cout << "������������������:" << endl
         << "����������   1" << endl
         << "������������ 2" << endl
         << "�ڴ��������� 3" << endl
         << "�Կ�������   4" << endl
         << "Ӳ��������   5" << endl
         << "��Դ������   6" << endl
         << "����������   7" << endl;
    while (1)
    {
        cout << "������������������(1-7):";
        in >> a.name;
        if (a.name >= 1 && a.name <= 7)
            break;
        else
            cout << "���벻����,����������!:";
        in.clear();
        in.ignore(1024, '\n');
    }
    in.ignore(1024, '\n');
    cout << "�������������ļ۸�(��λ��Ԫ):";
    while (1)
    {
        in >> a.price;
        if (a.price > 0)
            break;
        else
            cout << "����ļ۸񲻺���,����������!:";
        in.clear();
        in.ignore(1024, '\n');
    }
    in.ignore(1024, '\n');
    cout << "�������������ķ����:";
    cout << "(eg:Core i7 13th Gen)";
    in.getline(a.categ, sizeof(a.categ));
    cout << "���������������ͺ�:";
    in.getline(a.model, sizeof(a.model));
    cout << "����������������������:";
    in.getline(a.manufacturer, sizeof(a.manufacturer));
    cout << "�������������ı���ʱ��(��ʽYYYY-MM):"<<endl;
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
        out << "����" ;
        break;
    case 2:
        out << "������" ;
        break;
    case 3:
        out << "�ڴ���" ;
        break;
    case 4:
        out << "�Կ�" ;
        break;
    case 5:
        out << "Ӳ��" ;
        break;
    case 6:
        out << "��Դ" ;
        break;
    case 7:
        out << "����" ;
        break;
    default:
        out << "δ֪����" ;
        break;
    }
    out<<setw(10)<<a.price<<setw(30)<<a.categ<<setw(40)<<a.model<<setw(20)<<a.manufacturer<<a.quotetime;
    out<<endl;
    return out;
}
