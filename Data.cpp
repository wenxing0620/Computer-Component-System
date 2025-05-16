#include <iostream>
#include <fstream>
#include "Data.h"
using namespace std;
istream &operator>>(istream &in, date &c1)
{
    cout << "请输入年，月：";
    cin >> c1.year >> c1.month;
    while (1)
    {
        if (c1.year < 0)
        {
            cout << "输入的年份不合理，请重新输入年份:" << endl;
            cin >> c1.year;
        }
        else if (c1.month < 1 || c1.month > 12)
        {
            cout << "输入的月份不合理，请重新输入月份:" << endl;
            cin >> c1.month;
        }
        else
            break;
    }
    return in;
}
ostream &operator<<(ostream &out, const date &c2)
{
    out << c2.year << "-" << c2.month;
    return out;
}
bool date::operator<=(const date &d)
{
    if (year < d.year)
        return true;
    else if (year == d.year && month <= d.month)
        return true;
    else
        return false;
}
bool date::operator>=(const date &d)
{
    if (year > d.year)
        return true;
    else if (year == d.year && month >= d.month)
        return true;
    else
        return false;
}
bool date::operator<(const date &d)
{
    if (year < d.year)
        return true;
    else if (year == d.year && month < d.month)
        return true;
    else
        return false;
}
bool date::operator>(const date &d)
{
    if (year > d.year)
        return true;
    else if (year == d.year && month > d.month)
        return true;
    else
        return false;
}