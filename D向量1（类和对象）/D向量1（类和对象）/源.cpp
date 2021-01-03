#include<iostream>
using namespace std;
class CVector
{
private:
	int* date;
	int n;
public:
	CVector()
	{
		n = 5;
		int d[5] = { 0,1,2,3,4 };
		date = new int[n];
		for (int i = 0; i < n; i++)
		{
			date[i] = d[i];
		}
	}
	CVector(int n1, int* d)
	{
		n = n1;
		date = new int[n];
		for (int i = 0; i < n; i++)
		{
			date[i] = d[i];
		}
	}
	~CVector()
	{
		delete[] date;
	}
	void printf()
	{
		for (int i = 0; i < n; i++)
		{
			if (i == (n - 1))
				cout << date[i] << endl;
			else
				cout << date[i] << " ";
		}
	}
};
int main()
{
	int n;
	cin >> n;
	int* d = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}
	CVector a;
	CVector b(n, d);
	a.printf();
	b.printf();
	return 0;
}
/*��Ŀ����
n��������a1,a2,...,an��ɵ������Ϊnά������ Ϊnά��������CVector�࣬����˽�����ݳ�Ա��

int *data��//�洢nά����

int n�� //����ά����

�����У��޲ι��캯��������n=5,data�����ݷֱ�Ϊ0,1,2,3,4�����캯���������n1������a��ʼ��n��data�����ݣ��������������ʽ���nά������ֵ������������

�������������ݣ�����CVector���󲢵�������������ԡ�

����
����n

����nά����

���
�ֱ�����޲κʹ��ι��캯������2��CVector����������ǵ�ֵ��

��������
6
10 1 2 3 4 5

�������
0 1 2 3 4
10 1 2 3 4 5*/