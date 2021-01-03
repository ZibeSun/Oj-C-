#include<iostream>
using namespace std;
class CVector
{
private:
	int* date;
	int m;
public:
	friend class CMatrix;
	CVector()
	{
		m = 5;
		int d[5] = { 0,1,2,3,4 };
		date = new int[m];
		for (int i = 0; i < m; i++)
		{
			date[i] = d[i];
		}
	}
	CVector(int m1)
	{
		m = m1;
		date = new int[m];
		for (int i = 0; i < m; i++)
		{
			cin >> date[i];
		}
	}
	~CVector()
	{
		delete[] date;
	}
	void printf()
	{
		for (int i = 0; i < m; i++)
		{
			if (i == (m - 1))
				cout << date[i] << endl;
			else
				cout << date[i] << " ";
		}
	}
};
class CMatrix
{
private:
	int n;
	int** data;
public:
	CMatrix(int x)
	{
		n = x;
		data = new int * [n];			  //�ȴ���m��
		for (int i = 0; i < n; i++)
		{
			data[i] = new int[n];       //�ٴ���n��
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> data[i][j];
		}
	}
	~CMatrix()
	{
		delete[] data;
	}
	CVector multi(CVector& v)
	{
		CVector s;
		s.m = n;
		for (int i = 0; i < n; i++)
		{
			s.date[i] = 0;
			for (int k = 0; k < n; k++)
			{
				s.date[i] += data[i][k] * v.date[k];
			}
		}
		return s;
	}
	bool judge(CVector& v)
	{
		if (v.m == n)
			return true;
		else
		{
			return false;
		}
	}
	void show()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		CMatrix a(n);
		cin >> m;
		CVector b(m);
		if (a.judge(b))
		{
			a.multi(b).printf();
		}
		else
			cout << "error" << endl;
	}
	return 0;
}
/*��Ŀ����


������CVector��Ĵ����ϣ�����n�׾�����CMatrix������˽�����ݳ�ԱM�洢�������ݣ�n�洢���������

��CMatrix����ΪCVector����Ԫ�ࡣ

ΪCMatrix��ӳ�Ա������CVector Multi(const CVector &V1)������n�׾�����nά����V1�ĳ˻���

ΪCMatrix��ӳ�Ա�������ж�����������V1�Ƿ�ɼ���˻���

ΪCMatrix�����Ҫ�Ĺ��캯��������������������Ա������

�������������ݣ����Ծ����������ĳ˻���

����n�׾������n*

����
���Դ���t

��ÿ��������ݣ���ʽ����

��һ�У��������n ����ά��m

n�׾���

mά����

���
��ÿ��������ݣ����������������ܼ���˻������error���������������

��������
1
3
1 0 0
0 1 0
0 0 1
3
1 2 3
�������
1 2 3*/