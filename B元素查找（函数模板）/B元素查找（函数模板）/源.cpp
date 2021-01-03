#include<iostream>
using namespace std;
template<class T>
int find(T* p, T m,int n)
{
	for (int i = 0; i < n; i++)
	{
		if (p[i] == m)
		{
			i++;
			return i;
		}
	}
	return 0;
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
			int* p = new int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			int m;
			cin >> m;
			cout << find(p, m, n) << endl;
			delete[] p;
		}
		else if (type == 'C')
		{
			char* p = new char[n];
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			char m;
			cin >> m;
			cout << find(p, m, n) << endl;
			delete[] p;
		}
		else if (type == 'S')
		{
			string* p = new string[n];
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			string m;
			cin >> m;
			cout << find(p, m, n) << endl;
			delete[] p;
		}
		else if (type == 'D')
		{
			double* p = new double[n];
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			double m;
			cin >> m;
			cout << find(p, m, n) << endl;
			delete[] p;
		}
	}
	return 0;
}
/*��Ŀ����
��дһ���������н��в��ҵĺ���ģ�壬��������Ϊ����n��Ԫ�أ�����ΪT��Ҫ���ҵ�Ԫ��Ϊkey��

ע�⣺����ʹ��ģ�庯��

����
��һ������t��ʾ��t������ʵ��

�ڶ���������һ����д��ĸ��ʾ�������ͣ�I��ʾ�������ͣ�D��ʾ˫���������ͣ�C��ʾ�ַ��ͣ�S��ʾ�ַ����ͣ�Ȼ������n��ʾ���鳤�ȡ�

����������n������

����������key

��������t��ʵ��

���
ÿ�����һ��������ҵ����key�������еĵڼ���Ԫ�أ���1��ʼ�����Ҳ������0

��������
4
I 5
5 3 51 27 9
27
D 3
-11.3 25.42 13.2
2.7
C 6
a b g e u q
a
S 4
sandy david eason cindy
cindy
�������
4
0
1
4*/