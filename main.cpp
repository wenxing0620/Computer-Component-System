/*
���Ա���ϵͳ
����Ҫ��
���Ը���������Ϣ���������������۸񡢷���š��ͺţ����̡�����ʱ��ȡ�
����Ҫ��
1����Ʋ˵�ʵ�ֹ���ѡ��
2��������ӡ��޸ġ�ɾ�����Ը���������Ϣ���ܣ�
3����ѯ���ܣ������͡��۸�Ƚ��о�ȷ����ģ����ѯ�� 
4�����ԶԱ�����Ϣ���۸��ͺš����̵���Ϣ������������������
5��ʹ���ļ���д��ص���Ϣ������Ϣ�����ļ����ߴ��ļ��ж�ȡ��Ϣ���в�����
6�����Ǹ������ݵĺϷ��Լ��
*/
#include<iostream>
#include<fstream>
#include"ComponentList.h"
using namespace std;
int main(){
    CMPList cl;
    cl.read();
    cl.visitAllNode();
    system("pause");
    system("cls");
    cl.find();
    cl.save();
    system("pause");
    return 0;
}
