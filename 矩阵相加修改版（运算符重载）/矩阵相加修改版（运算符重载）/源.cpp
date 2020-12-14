#include<iostream>
using namespace std;
class Matrix
{
protected:
	int m;
	int n;
	int **data;
public:
	Matrix(int x, int y,int z)
	{
		m = x;
		n = y;
		data = new int* [m];			  //�ȴ���m��
		for (int i = 0; i < m; i++)
		{
			data[i] = new int[n];       //�ٴ���n��
		}
		if (z == 1)
		{
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					cin >> data[i][j];
			}
		}
	}
	void show()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}
	~Matrix()
	{
		delete[] data;
	}
	int getm()
	{
		return m;
	}
	int getn()
	{
		return n;
	}
	friend Matrix operator+(Matrix& a, Matrix& b);
};
Matrix operator+(Matrix& a, Matrix& b)
{
	Matrix sum(a.getm(), a.getn(), 0);
	for (int i = 0; i < sum.getm(); i++)
	{
		for (int j = 0; j < sum.getn(); j++)
		{
			cout << i << " " << j << endl;
			sum.data[i][j] = a.data[i][j] + b.data[i][j];
		}
	}
	return sum;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		Matrix a(m, n,1);
		Matrix b(m, n,1);
		(a+b).show();
	}
	return 0;
}
/*��Ŀ����
��֪һ�������������m������n����ֵdata�������ԣ�������ʼ�����������ӵȲ�����Ҫ��

1�����ඨ���У������data������һ������ָ����ָ�롣ֻ�д�������ʱ����������������������������Ű�ָ����һ����ά����

2������������صķ���ʵ����������������ӣ����������ָ���������ÿ��λ���ϵ�����Ԫ�����

3���ù��캯��ʵ�ֶ���ĳ�ʼ�������������ʵ�־�����������ʾ���ڹ��캯������������Լ��ٺܶ��鷳

4�����������������ͷ����������Դ

����ָ���ɶ�λ����Ĳο�����

//m��n������������
int m, n;
int **data;
int i, j;
cin>>m>>n;
data=new int*[m];  //�ȴ���m��
for(i=0;i<m;i++)
  { data[i]=new int[n]; }  //�ٴ���n��

for (i=0; i<m; i++)
  for (j=0; j<n; j++)
    cin>>data[i][j];

����
��һ������t��ʾt��ʵ��

�ڶ��������һ��ʾ���ľ�����������������������������������������ͬ��

�������������һ������ľ�������

�������ƣ�����ڶ�������ľ�������

�������ƣ�������һ��ʾ��������

���
���ÿ����������ӵĽ��

��������
2
2 3
1 2 3 
4 5 6
-1 -2 -3
6 5 4
2 2
11 22
33 44
55 66
77 88
�������
0 0 0 
10 10 10 
66 88 
110 132 */