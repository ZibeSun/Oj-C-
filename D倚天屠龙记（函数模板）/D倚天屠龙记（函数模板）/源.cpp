#include<iostream>
using namespace std;
template<class T>
void wudi(T* yitian, T* tulong,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << tulong[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << yitian[i];
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		char type;
		cin >> type >> n;
		if (type == 'I')
		{
			int* yitian = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> yitian[i];
			}
			int* tulong = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> tulong[i];
			}
			wudi(yitian, tulong,n);
			delete[] yitian;
			delete[] tulong;
		}
		else if (type == 'C')
		{
			char* yitian = new char[n];
			for (int i = 0; i < n; i++)
			{
				cin >> yitian[i];
			}
			char* tulong = new char[n];
			for (int i = 0; i < n; i++)
			{
				cin >> tulong[i];
			}
			wudi(yitian, tulong,n);
			delete[] yitian;
			delete[] tulong;
		}
		else if (type == 'D')
		{
			double* yitian = new double[n];
			for (int i = 0; i < n; i++)
			{
				cin >> yitian[i];
			}
			double* tulong = new double[n];
			for (int i = 0; i < n; i++)
			{
				cin >> tulong[i];
			}
			wudi(yitian, tulong,n);
			delete[] yitian;
			delete[] tulong;
		}
	}
	return 0;
}
/*��Ŀ����
��������һ�����ԣ�ֻҪ���콣���������а��ص�����ƴ��һ�𣬾��ܵõ������޵е��ڹ����š����һ������ģ�壬���ƴ�յĹ��ܣ������콣���������ӵ��������ĺ��棩�������������. ����ÿ��������n��Ԫ����ɣ�����ΪT��

����
��һ������t��ʾ��t������ʵ��

�ڶ���������һ����д��ĸ��ʾ�������ͣ�I��ʾ�������ͣ�D��ʾ˫���������ͣ�C��ʾ�ַ��ͣ�Ȼ������n��ʾ���ݸ�����

�������������콣��n������

������������������n������

��������t��ʵ��

���
ÿ�����һ�����

��������
2
I 5
5 3 51 27 9
27 0 0 5 1
C 5
kitty
hello
�������
2700515351279
hellokitty*/