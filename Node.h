#pragma once
#include<iostream>
#include"Component.h"
using namespace std;
class Node
{
    private:
        CMP data; // 节点数据
        Node *next; // 指向下一个节点的指针
    public:
        Node(const CMP &d = CMP(), Node *p = NULL) {
            data = d; // 初始化节点数据
            next = p; // 初始化指向下一个节点的指针
        } // 构造函数
        friend class CMPList; // 友元类

};