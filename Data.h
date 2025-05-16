#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class date
{
private:
    int year;
    int month;

public:
    date(int y = 2000, int m = 01)
    {
        year = y;
        month = m;
    }
    date(const date &d)
    {
        year = d.year;
        month = d.month;
    }
    date &operator=(const date &d)
    {
        year = d.year;
        month = d.month;
        return *this;
    }
    friend istream &operator>>(istream &in, date &c1);
    friend ostream &operator<<(ostream &out, const date &c2);
    int getyear(){return year;};
    int getmonth(){return month;};
    bool operator<=(const date &d);
    bool operator>=(const date &d);
    bool operator>(const date &d);
    bool operator<(const date &d);
};
