#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class phone
{
private:
	char *number=new char[10];
	char type;
	int status;
	char* name = new char[99];
public:
	phone()
	{
		type = 'A';
		status = 0;
	}
	void set(char *num, char t, int st, char* n)
	{
		strcpy(number, num);
		cout << number << " constructed." << endl;
		type = t;
		status = st;
		strcpy(name, n);
	}
	~phone()
	{
		cout << number << " destructed." << endl;
		delete[] name;
		delete[] number;
	}
	int search(char *num)
	{
		if (strcmp(number, num) == 0)
			return 1;
		return 0;
	}
	void print()
	{
		if(status==1)
			cout << "Phone=" << number << "--Type=" << type << "--State=use--Owner=" << name << endl;
		else
			cout << "Phone=" << number << "--Type=" << type << "--State=unuse--Owner=" << name << endl;
	}
};
int main()
{
	int t;
	phone *a = new phone[3];
	for(int k=0;k<3;k++)
	{
		int st;
		char* n = new char[99];
		char t;
		char* num=new char[10];
		cin >>num>> t >> st >> n;
		a[k].set(num,t,st,n);
		delete[] n;
		delete[] num;
	}
	cin >> t;
	while (t--)
	{
		
		int sum = 0;
		char* tel=new char[10];
		cin >> tel;
		for (int i = 2; i >= 0; i--)
		{
			
			if (a[i].search(tel) == 1)
			{
				a[i].print();
			}
			else
				sum++;
		}
		if (sum == 3)
			cout << "wrong number." << endl;
		delete[] tel;
	}
	delete[] a;
}/*��Ŀ����
����绰�������ԣ��绰�š�״̬������������
1���绰����һ���࣬��������������ͣ����к������������ͣ������õ�����ĸ��ʾ�û����A��ʾ������B��ʾ��ҵ��C��ʾ���ˡ�������������졢���ԵĻ�ȡ�����õȷ�����������Ҫ���б�д��
2��״̬��һ�����ֱ�ʾ��1��ʾ���ã�0��ʾδ�ã�
3������������һ���ַ���
�绰�������������졢��������ӡ�Ͳ�ѯ��
1�����캯����Ҫ���Ǹ������Ա�Ĺ��죬���������ʾ��Ϣ������绰����Ϊ12345678�����캯�����"12345678 constructed."
2����ӡ������绰�������Ϣ����������绰״̬�����������use��״̬��δ�������unuse�������ʽ��ʾ����
3�����������������ʾ��Ϣ������绰��Ϊ12345678���������������"12345678 destructed. "
4����ѯ�����Ǹ��ݸ����ĺ����ѯ�绰������绰�������͸������벻��ͬ���򷵻�0������绰�������͸���������ͬ���򷵻�1
��C++���������˼��ʵ������Ҫ��
1������������ݣ����������绰���󣬲�ͨ�����췽����ʼ����
2���������ɸ��绰���룬ͨ����ѯ������ѯ��Щ�����Ƿ��������绰�����У�������������"wrong number."����������ô�ӡ��������绰��Ϣ�����忴���������
����
ͷ�������������绰��Ϣ��ÿ�а����绰���롢�绰���͡�״̬����������

����һ������t����ʾ��t������Ҫ��ѯ

����t������t���绰����

���
t�����t������Ĳ�ѯ���

��������
80000001 A 1 tom
80000002 B 0 ken
80000003 C 1 mary
3
50000002
80000003
80000002
�������
80000001 constructed.
80000002 constructed.
80000003 constructed.
wrong number.
Phone=80000003--Type=C--State=use--Owner=mary
Phone=80000002--Type=B--State=unuse--Owner=ken
80000003 destructed.
80000002 destructed.
80000001 destructed.*/