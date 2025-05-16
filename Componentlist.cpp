#include <iostream>
#include <iomanip>
#include <string>
#include "Component.h"
#include "Node.h"
#include <fstream>
#include "Componentlist.h"
#include "Data.h"
using namespace std;
CMPList::CMPList(const CMPList &c) : head(new Node(c.head->data))
{
    Node *p1 = head;
    Node *p2 = c.head->next;
    while (p2 != NULL)
    {
        p1->next = new Node(p2->data);
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = NULL;
}
CMPList &CMPList::operator=(const CMPList &l)
{
    if (this != &l)
    {
        release();
        head->data = l.head->data;
        Node *p1 = head;
        Node *p2 = l.head->next;
        while (p2 != NULL)
        {
            p1->next = new Node(p2->data);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return *this;
}
void CMPList::operator+=(const CMPList &l)
{
    Node *p1 = head;
    while (p1->next != NULL)
    {
        p1 = p1->next;
    }
    Node *p2 = l.head->next;
    while (p2 != NULL)
    {
        p1->next = new Node(p2->data);
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = NULL;
}
void CMPList::add()
{
    CMP c1;
    cin >> c1;
    Node *p = head, *ptr = new Node(c1);
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}
void CMPList::visitAllNode()
{
    Node *p = head->next;
    if (p == NULL)
    {
        cout << "暂无配件信息，请选择添加配件来添加一个配件" << endl;
        return;
    }
    cout << "目前有" << size() << "个配件" << endl;
    cout << left;
    cout << setw(5) << "序号" << setw(10) << "类型" << setw(10) << "价格" << setw(30) << "分类号" << setw(40) << "型号" << setw(20) << "厂商" << setw(10) << "报价时间" << endl;
    int count = 1;
    while (p != NULL)
    {
        cout << setw(5) << count++;
        cout << p->data;
        p = p->next;
    }
}
void CMPList::visitAllNode(int n)
{
    Node *p = head->next;
    if (p == NULL)
    {
        cout << "暂时没有这类配件" << endl;
        return;
    }
    cout << left;
    cout << setw(5) << "序号" << setw(10) << "类型" << setw(10) << "价格" << setw(30) << "分类号" << setw(40) << "型号" << setw(20) << "厂商" << setw(10) << "报价时间" << endl;
    int count = 1;
    while (p != NULL)
    {

        if (p->data.getname() == n)
        {
            cout << setw(5) << count++;
            cout << p->data;
        }
        p = p->next;
    }
}
void CMPList::save()
{
    ofstream outfile("Component.dat", ios::binary | ios::out);
    if (!outfile)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    Node *p = head->next;
    if (p == NULL)
    {
        cout << "空链表" << endl;
        exit(1);
    }
    while (p != NULL)
    {
        outfile.write((char *)&p->data, sizeof(CMP));
        p = p->next;
    }
    outfile.close();
}
void CMPList::read()
{
    ifstream infile("Component.dat", ios::binary | ios::in);
    if (!infile)
    {
        ofstream outfile("Component.dat", ios::binary | ios::out);
        if (!outfile)
        {
            cout << "文件打开失败" << endl;
            exit(1);
        }
        outfile.close();
    }
    CMP c1;
    Node *p = head;
    while (infile.read((char *)&c1, sizeof(CMP)))
    {
        Node *ptr = new Node(c1);
        p->next = ptr;
        p = p->next;
    }
    p->next = NULL;
    infile.close();
}
void CMPList::release()
{
    Node *p = head->next;
    while (p != NULL)
    {
        Node *temp = p;
        p = p->next;
        delete temp;
    }
    head->next = NULL;
}
int CMPList::size()
{
    Node *p = head->next;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
void CMPList::modify()
{
    int choice;
    visitAllNode();
    cout << "请选择要修改哪个配件，请输入序号：" << endl;
    while (1)
    {
        cin >> choice;
        if (choice > 0 && choice <= size())
            break;
        else
        {
            cout << "输入的配件序号不存在哦，请重新输入:" << endl;
            cin.clear();
            cin.ignore();
        }
    }
    choice--;
    Node *p = head->next;
    int count = 0;
    while (count != choice)
    {
        p = p->next;
        count++;
    }
    system("cls");
    CMP c1;
    cout << "请输入要修改的配件的信息：" << endl;
    cin >> c1;
    p->data = c1;
}
void CMPList::deleteNode()
{
    int choice;
    visitAllNode();
    cout << "请选择要删除哪个配件，请输入序号：" << endl;
    while (1)
    {
        cin >> choice;
        if (choice > 0 && choice <= size())
            break;
        else
        {
            cout << "输入的配件序号不存在哦，请重新输入:" << endl;
            cin.clear();
            cin.ignore();
        }
    }
    Node *prev = head;
    int count = 1;
    while (count < choice)
    {
        prev = prev->next;
        count++;
    }
    Node *p1 = prev;
    Node *p2 = p1->next;
    p1->next = p2->next;

    delete p2;
}
void CMPList::find()
{
    int choice;
    cout << "请输入查找的依据" << endl
         << "1.部件名" << endl
         << "2.价格" << endl
         << "3.分类号" << endl
         << "4.型号" << endl
         << "5.厂商" << endl
         << "6.报价时间" << endl;
    cout << "请输入对应的序号：" << endl;
    while (1)
    {
        cin >> choice;
        if (choice > 0 && choice <= 6)
            break;
        else
        {
            cout << "输入的序号不合理，请重新输入:" << endl;
            cin.clear();
            cin.ignore();
        }
    }
    switch (choice)
    {
    case 1:
    {
        cout << "请输入要查找的部件名：" << endl
             << "主板请输入   1" << endl
             << "处理器请输入 2" << endl
             << "内存条请输入 3" << endl
             << "显卡请输入   4" << endl
             << "硬盘请输入   5" << endl
             << "电源请输入   6" << endl
             << "机箱请输入   7" << endl;
        int n;
        while (1)
        {
            cin >> n;
            if (n >= 1 && n <= 7)
                break;
            else
            {
                cout << "输入的序号不合理，请重新输入：" << endl;
                cin.clear();
                cin.ignore();
            }
        }
        visitAllNode(n);
        break;
    }
    case 2:
    {
        double price_low, price_high;
        cout << "请输入要查找的价格范围：" << endl;
        cout << "请输入价格的下限：";
        while (1)
        {
            cin >> price_low;
            if (price_low >= 0)
                break;
            else
            {
                cout << "输入的价格不合理，请重新输入:" << endl;
                cin.clear();
                cin.ignore();
            }
        }
        cout << "请输入价格的上限：";
        while (1)
        {
            cin >> price_high;
            if (price_high >= 0 && price_high >= price_low)
                break;
            else
            {
                cout << "输入的价格不合理，请重新输入:" << endl;
                cin.clear();
                cin.ignore();
            }
        }
        Node *p = head->next;
        if (p == NULL)
        {
            cout << "暂时没有这类配件" << endl;
            return;
        }
        cout << left;
        cout << setw(5) << "序号" << setw(10) << "类型" << setw(10) << "价格" << setw(30) << "分类号" << setw(40) << "型号" << setw(20) << "厂商" << setw(10) << "报价时间" << endl;
        int c = 1;
        while (p != NULL)
        {
            if (p->data.getprice() >= price_low && p->data.getprice() <= price_high)
            {
                cout << setw(5) << c++;
                cout << p->data;
            }
            p = p->next;
        }
        break;
    }
    case 3:
    {
        char ca[64];
        cout << "请输入要查找的分类号的关键词:" << endl;
        cin.ignore();
        cin.getline(ca, sizeof(ca));
        Node *p1 = head->next;
        if (p1 == NULL)
        {
            cout << "暂时没有配件" << endl;
            return;
        }
        cout << left;
        cout << setw(5) << "序号" << setw(10) << "类型" << setw(10) << "价格" << setw(30) << "分类号" << setw(40) << "型号" << setw(20) << "厂商" << setw(10) << "报价时间" << endl;
        int c1 = 1;
        while (p1 != NULL)
        {

            if (strstr(p1->data.getcateg(), ca) != NULL)
            {
                cout << setw(5) << c1++;
                cout << p1->data;
            }
            p1 = p1->next;
        }
        break;
    }
    case 4:
    {
        char mo[80];
        cout << "请输入要查找的型号的关键词:" << endl;
        cin.ignore();
        cin.getline(mo, sizeof(mo));
        Node *p2 = head->next;
        if (p2 == NULL)
        {
            cout << "暂时没有配件" << endl;
            return;
        }
        cout << left;
        cout << setw(5) << "序号" << setw(10) << "类型" << setw(10) << "价格" << setw(30) << "分类号" << setw(40) << "型号" << setw(20) << "厂商" << setw(10) << "报价时间" << endl;
        int c2 = 1;
        while (p2 != NULL)
        {
            if (strstr(p2->data.getmodel(), mo) != NULL)
            {
                cout << setw(5) << c2++;
                cout << p2->data;
            }
            p2 = p2->next;
        }
        break;
    }
    case 5:
    {
        char ma[32];
        cout << "请输入要查找的厂商的关键词:" << endl;
        cin.ignore();
        cin.getline(ma, sizeof(ma));
        Node *p3 = head->next;
        if (p3 == NULL)
        {
            cout << "暂时没有配件" << endl;
            return;
        }
        cout << left;
        cout << setw(5) << "序号" << setw(10) << "类型" << setw(10) << "价格" << setw(30) << "分类号" << setw(40) << "型号" << setw(20) << "厂商" << setw(10) << "报价时间" << endl;
        int c3 = 1;
        while (p3 != NULL)
        {
            if (strstr(p3->data.getmodel(), ma) != NULL)
            {
                cout << setw(5) << c3++;
                cout << p3->data;
            }
            p3 = p3->next;
        }
        break;
    }
    case 6:
    {
        date d_up, d_down;
        cout << "请输入要查找的日期范围的下限：" << endl;
        cin >> d_down;
        cout << "请输入要查找的日期范围的上限；" << endl;
        while (1)
        {
            cin >> d_up;
            if (d_up >= d_down)
                break;
            else
            {
                cout << "日期的上限应该比下限大哦，请重新输入；" << endl;
                cin.clear();
                cin.ignore();
            }
        }
        Node *p4 = head->next;
        if (p4 = NULL)
        {
            cout << "暂时没有配件" << endl;
            return;
        }
        cout << left;
        cout << setw(5) << "序号" << setw(10) << "类型" << setw(10) << "价格" << setw(30) << "分类号" << setw(40) << "型号" << setw(20) << "厂商" << setw(10) << "报价时间" << endl;
        int c4 = 1;
        while (p4 != NULL)
        {
            if (p4->data.getquotetime() >= d_down && p4->data.getquotetime() <= d_up)
            {
                cout << setw(5) << c4++;
                cout << p4->data;
            }
            p4 = p4->next;
        }
        break;
    }
    default:
        break;
    }
}