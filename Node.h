#pragma once
#include<iostream>
#include"Component.h"
using namespace std;
class Node
{
    private:
        CMP data; // �ڵ�����
        Node *next; // ָ����һ���ڵ��ָ��
    public:
        Node(const CMP &d = CMP(), Node *p = NULL) {
            data = d; // ��ʼ���ڵ�����
            next = p; // ��ʼ��ָ����һ���ڵ��ָ��
        } // ���캯��
        friend class CMPList; // ��Ԫ��

};