#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
class CMPList
{
private:
    Node *head;

public:
    CMPList(const CMP &d = CMP()) // 创建只含头节点的链表
    {
        head = new Node(d);
    } // 创建只含头节点的链表
    ~CMPList()
    {
        release();
        delete head;
    } // 析构函数
    CMPList(const CMPList &);            // 链表复制构造函数
    CMPList &operator=(const CMPList &); // 链表赋值运算符重载
    void operator+=(const CMPList &);    // 简单合并在链表尾部
    void add();                          // 尾部添加节点
    void visitAllNode();                 // 从链表里读出数据
    void visitAllNode(int n);            // 从链表中读取数据，参数n为配件的类型
    void save();                         // 保存链表到文件
    void read();                         // 从文件里读出数据储存到链表
    void release();                      // 清空链表
    int size();                          // 链表的节点数
    void modify();                       // 修改节点数据
    void deleteNode();                   // 删除节点
    void find();
};