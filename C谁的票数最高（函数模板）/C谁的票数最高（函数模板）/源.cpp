#include<iostream>
using namespace std;
template<class T>
void find(T* p,int n)
{
	int* k = new int[n];
	for (int i = 0; i < n; i++)
	{
		k[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (p[j] == p[i])
				k[i]++;
		}
	}
	int sum = 0;
	T code;
	for (int i = 0; i < n; i++)
	{
		if (k[i] > sum)
		{
			sum = k[i];
			code = p[i];
		}
	}
	cout << code << " " << sum << endl;
	delete[] k;
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
			find(p,n);
			delete[] p;
		}
		else if (type == 'C')
		{
			char* p = new char[n];
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			find(p, n);
			delete[] p;
		}
		else if (type == 'S')
		{
			string* p = new string[n];
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			find(p, n);
			delete[] p;
		}
		else if (type == 'D')
		{
			double* p = new double[n];
			for (int i = 0; i < n; i++)
			{
				cin >> p[i];
			}
			find(p, n);
			delete[] p;
		}
	}
	return 0;
}
/*��Ŀ����
ĳС��ҪƱѡ�򳤣���Ʊ����ߵ�ѡ��������ͶƱ���Ʋ���ȫ������ÿ��ͶƱʱ����ѡ����ͶƱϵͳ��ʶ�������Ͳ�һ�¡����д����ģ�壬����Զ������͵����ݣ����ҳ���Ʊ��ߵ�Ԫ�ء����У�ÿ��ͶƱ��ѡƱ��n�ţ�ʶ��������ΪT

ע�⣺����ʹ��ģ�庯��

����
��һ������t��ʾ��t������ʵ��

�ڶ���������һ����д��ĸ��ʾʶ�������ͣ�I��ʾ�������ͣ�C��ʾ�ַ��ͣ�S��ʾ�ַ����ͣ�Ȼ������n��ʾ���鳤�ȡ�

����������n������

��������t��ʵ��

���
ÿ�����һ��������ֱ������ѡ�ߵ�ʶ����͵�Ʊ�����Կո�ֿ���

��������
3
I 10
5 3 5 2 9 7 3 7 2 3
C 8
a b a e b e e q
S 5
sandy david eason cindy cindy
�������
3 3
e 3
cindy 2*/