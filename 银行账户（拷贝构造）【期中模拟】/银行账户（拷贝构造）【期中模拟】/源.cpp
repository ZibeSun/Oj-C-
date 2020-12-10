#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class Account
{
private:
	float money;
	float rate;
	char* number=new char[10];
	char type;
public:
	Account(char *num,char t,float m,int k)
	{
		strcpy(number, num);
		type = t;
		money = m;
		if (k == 0)
			rate = 0.005;
		else if (k == 1)
		{
			rate = 0.015;
			number[0] += 5;
		}
	}
	~Account()
	{
		delete[] number;
	}
	void calculate()
	{
		float sum;
		sum = money * (1 + rate);
		cout << "Account=" << number << "--sum=" << sum << endl;
	}
	void check()
	{
		if(type=='P')
			cout << "Account=" << number << "--Person--sum=" << money << "--rate=" << rate<<endl;
		else
			cout << "Account=" << number << "--Enterprise--sum=" << money << "--rate=" << rate<<endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char* num = new char[10];
		char t,c1,c2;
		float m;
		cin >> num >> t >> m >> c1 >> c2;
		Account a(num, t, m, 0);
		Account b(num, t, m, 1);
		if (c1 == 'C')
			a.calculate();
		else
			a.check();
		if (c2 == 'P')
			b.check();
		else
			b.calculate();
		delete[] num;
	}
	return 0;
}/*��Ŀ����
�����˻����������ʡ����롢���͵����ԣ����к��ǹ̶�8λ���������ͱ�ʾ���˻�����ҵ�˻�������Ǹ�����P��ʶ����ҵ��E��ʶ��

�˻��ַ�Ϊ�����˻��Ͷ����˻�����������Ϊ0.5%����������Ϊ1.5%��

�˻������м�Ϣ����ѯ��������Ϣ�����Ǹ������ʼ�����Ϣ��������Ϣ���ӵ�����У����������Ϣ�������ѯ����������˻���ȫ����Ϣ��

����һ�������˻�����ͨ�����캯����ʼ���������ԡ�Ȼ��ͨ����������������һ�������˻�����Ϣ������˻�������ͬ����֮ͬ�������������˻������ǻ����˻������50000000��7��0���������Ƕ������ʡ�

Ҫ���������ݳ�Ա����˽������

��C++���Ե��������˼������д����ʵ������Ҫ��

����
������Ը���t����ʾ��t�������˻�

������һ�������˻����˻����롢�˻����͡����������봴�������˻��Ͷ����˻���

����������������������һ���������Ի����˻��������ڶ����������Զ����˻����в������������д��ĸC��ʾ��Ϣ�������������д��ĸP��ʾ��ѯ����

�Դ��������������˻�����Ϣ�Ͳ���

���
ÿ�������һ�Ի����˻��Ͷ����˻��Ĳ��������

��������
2
12345678 P 10000
C P
23456789 E 20000
P C
�������
Account=12345678--sum=10050
Account=62345678--Person--sum=10000--rate=0.015
Account=23456789--Enterprise--sum=20000--rate=0.005
Account=73456789--sum=20300*/