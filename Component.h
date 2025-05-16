#pragma once
#include <iostream>
#include<fstream>
#include <cstring>
#include "Data.h"
using namespace std;
class CMP
{
private:
    int name; // ���������
    double price;        // ����۸�
    char categ[64];         // ����ķ���� eg:Core i7 13th Gen��̨ʽ��/�����ܴ�������
    char model[80];        // ������ͺ�
    char manufacturer[32]; // �������������
    date quotetime;      // ����ı���ʱ��,����
public:
    CMP(int n=0, double p = 0.0, const char * c = "null", const char *mo = "null", const char * ma = "null", const date &qt = date(2000, 1))
    {
        name = n;
        price = p;
        strcpy(categ, c);
        strcpy(model, mo);
        strcpy(manufacturer, ma);
        quotetime = qt;
    }
    CMP &operator=(const CMP &c)
    {
        name = c.name;
        price = c.price;
        strcpy(categ, c.categ);
        strcpy(model, c.model);
        strcpy(manufacturer, c.manufacturer);
        quotetime = c.quotetime;
        return *this;
    }
    friend istream &operator>>(istream &in, CMP &c);
    friend ostream &operator<<(ostream &out, const CMP &a);
    int getname(){return name;};
    double getprice(){return price;};
    char *getcateg(){return categ;};
    char *getmodel(){return model;};
    char *getmanufacturer(){return manufacturer;};
    date getquotetime(){return quotetime;};
};
