#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
class CMPList
{
private:
    Node *head;

public:
    CMPList(const CMP &d = CMP()) // ����ֻ��ͷ�ڵ������
    {
        head = new Node(d);
    } // ����ֻ��ͷ�ڵ������
    ~CMPList()
    {
        release();
        delete head;
    } // ��������
    CMPList(const CMPList &);            // �����ƹ��캯��
    CMPList &operator=(const CMPList &); // ����ֵ���������
    void operator+=(const CMPList &);    // �򵥺ϲ�������β��
    void add();                          // β����ӽڵ�
    void visitAllNode();                 // ���������������
    void visitAllNode(int n);            // �������ж�ȡ���ݣ�����nΪ���������
    void save();                         // ���������ļ�
    void read();                         // ���ļ���������ݴ��浽����
    void release();                      // �������
    int size();                          // ����Ľڵ���
    void modify();                       // �޸Ľڵ�����
    void deleteNode();                   // ɾ���ڵ�
    void find();
};