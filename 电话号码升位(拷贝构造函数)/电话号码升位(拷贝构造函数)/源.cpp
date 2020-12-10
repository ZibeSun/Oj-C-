#include<iostream>
#include<cstring>
using namespace std;
class CTelNumber
{
	char* telnum = new char[9];
public:
	CTelNumber(char* tel)
	{
		for (int i = 0; i < 7; i++)
		{
			telnum[i] = tel[i];
		}
		telnum[8] = '\0';
	}
	CTelNumber(CTelNumber& s)
	{
		if ((s.telnum[0] == '2') || (s.telnum[0] == '3') || (s.telnum[0] == '4'))
		{
			//telnum = new char[8];
			telnum[0] = '8';
			for (int i = 1; i < 8; i++)
			{
				telnum[i] = s.telnum[i - 1];
			}
			telnum[8] = '\0';
		}
		else if ((s.telnum[0] == '5') || (s.telnum[0] == '6') || (s.telnum[0] == '7') || (s.telnum[0] == '8'))
		{
			//telnum = new char[8];
			telnum[0] = '2';
			for (int i = 1; i < 8; i++)
			{
				telnum[i] = s.telnum[i - 1];
			}
			telnum[8] = '\0';
		}
	}
	~CTelNumber()
	{
		delete[] telnum;
	}
	void print()
	{
		cout << telnum << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char* num = new char[99];
		cin >> num;
		int k = 0;
		if ((num[0] == '0') || (num[0] == '1') || (num[0] == '9'))
		{
			cout << "Illegal phone number" << endl;
		}
		else
		{
			for (int i = 0; i < 7; i++)
			{
				if ((num[i] >= '0') && (num[i] <= '9'))
				{
					k++;
				}
			}
			if ((k == 7) && (num[7] == '\0'))
			{
				CTelNumber n1(num);
				CTelNumber n2(n1);
				n2.print();
			}
			else
			{
				cout << "Illegal phone number" << endl;
			}
		}

	}
	return 0;
}
/*��Ŀ����
����һ���绰������CTelNumber,����1���ַ�ָ�����ݳ�Ա,�Լ����졢��������ӡ���������캯����

�ַ�ָ�������ڶ�̬����һ���ַ����飬Ȼ�󱣴���������ĵ绰����

���캯���Ĺ�����Ϊ�������ü��������7λ�绰���룬

�������캯���Ĺ�������ԭ��7λ����Ķ�����λΪ8λ�������,Ҳ����˵��������Ķ�����Դ���������.�绰��λ�Ĺ�����ԭ2��3��4��ͷ�ĵ绰����ǰ���8��ԭ5��6��7��8��ͷ��ǰ���2��

ע��:�绰����ֻ��ȫ���������ַ�������������������������Ϊ�Ƿ�)

����
�������ݵ����� t

��һ��7λ����

�ڶ���7λ����

......

���
��һ��������λ��ĺ���

�ڶ���������λ��ĺ���

......

��������������ɹ��������������Ϣ�����忴ʾ��

��������
3
6545889
3335656
565655
�������
26545889
83335656
Illegal phone number*/