#include<iostream>
#include<string.h>
using namespace std;
class Student
{
public:
	void set(char n[50], char num[50], char xy[50], char zy[50], char xb[50], char ss[50], char p[50])
	{
		strcpy(name, n);
		strcpy(number, num);
		strcpy(xueyuan, xy);
		strcpy(zhuanye, zy);
		strcpy(xingbie,xb);
		strcpy(sushe, ss);
		strcpy(phone, p);
	}
	void printf()
	{
		cout << name << " " << number << " " << xueyuan << " " << zhuanye << " " << xingbie << " " << sushe << " " << phone << endl;
	}
protected:
	char name[50];
	char number[50];
	char xueyuan[50];
	char zhuanye[50];
	char xingbie[50];
	char sushe[50];
	char phone[50];
};
int main()
{
	int t;
	char n[50];
	char num[50];
	char xy[50];
	char zy[50];
	char xb[50];
	char ss[50];
	char p[50];
	cin >> t;
	while (t--)
	{
		Student a;
		cin >> n >> num >> xy >> zy >> xb >> ss >> p;
		a.set(n, num, xy, zy, xb, ss, p);
		a.printf();
	}
	return 0;
}
/*��Ŀ����
   ������������Ƶ����ľ��ǰѿ͹��������Ϊ����������һ�ζδ��룬У԰���������ѧ����������ѧ�������ܶ����ԣ�����������ѧ�š�����ѧԺ��רҵ���Ա�סַ����ϵ�绰�������������ȵȣ�����Щ���ԣ���Ҫ�������ǵĶ����������ȡ������������������ȡѧ�š�����ѧ�š������������ȵȣ���������ǿ���˵�����Ժͷ������������Ժͷ������������з��ʿ��Ʒ�ʽ���ƣ���ʾΪpublic��private��protected�ȣ��������ϵ���Ϣ�������һ��������ѧ���ඨ�壺Student�����������n���������ĸ�������ֵ��

����
��һ�б�ʾҪ����n������

�����������벻ͬ����ĸ�����ֵ��ÿ������һ�С�

���
�����ͬ����ĸ�������

ÿ������ռһ��

��������
2
WangHai 2014150112 ����� �������ѧ�뼼�� �� ����215 13760222222
LiBin 2013151292 ����� ������� �� ����318 13677777777
�������
WangHai 2014150112 ����� �������ѧ�뼼�� �� ����215 13760222222
LiBin 2013151292 ����� ������� �� ����318 13677777777*/