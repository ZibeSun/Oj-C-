#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class Hotel
{
public:
	void Set(char* a_Customer)
	{
		strcpy(m_CustomerName, a_Customer);
		m_TotalCustNum++;
		m_TotalEearning += m_Rent;
		m_CustomrrerID = 20150000 + m_TotalCustNum;
	}
	void SetRent(float l)
	{
		m_Rent = l;
	}
	~Hotel()
	{
		delete []m_CustomerName;
	}
	void Display()
	{
		cout << m_CustomerName << " " << m_CustomrrerID << " " << m_TotalCustNum << " " << m_TotalEearning << endl;
	}
private:
	static int m_TotalCustNum;
	static float m_TotalEearning;
	static float m_Rent;
	char* m_CustomerName=new char[99];
	int m_CustomrrerID=0;
};
int Hotel::m_TotalCustNum = 0;
float Hotel::m_TotalEearning = 0;
float Hotel::m_Rent = 0;
int main()
{
	float m;
	cin >> m;
	Hotel a[999];
	int i = 0;
	for (;; i++)
	{
		char* n = new char[99];
		cin >> n;
		if (n[0] == '0')
		{
			break;
		}
		else
		{
			//cout << n << endl;
			a[i].SetRent(m);
			//cout << n << endl;
			a[i].Set(n);
			//cout << n << endl;
			a[i].Display();
		}
		//delete[]n;
	}
	return 0;
}/*��Ŀ����
��д����ͳ��ĳ�ù�ס�޿��˵������������ܶҪ��������˵�������������˱�ţ�2015+˳��ţ�˳���4λ�����1λΪ0001����2λΪ0002���������ƣ����������������Լ������ܶ�������������ܶ��þ�̬��Ա���������Բ�����ͨ�����ݳ�Ա���ù����������£�




����
��1�У������ùݵ����˿ͷ���

��2�п�ʼ����������˿�������0��ʾ���������

���
ÿ����������˿���Ϣ�͵�ǰ�ù���Ϣ�������˿��������˿ͱ�ţ��ùݵ�ǰ���������ùݵ�ǰ�����롣

��������
150  
���� ���� ���� 0
�������
���� 20150001 1 150
���� 20150002 2 300
���� 20150003 3 450*/