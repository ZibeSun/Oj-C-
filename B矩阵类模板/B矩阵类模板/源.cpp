#include<iostream>
using namespace std;
template<class T>
class Matrix
{
protected:
	int m;
	int n;
	T** data;
	T** transdata;
public:
	Matrix(int x, int y)
	{
		m = x;
		n = y;
		data = new T* [m];			  //�ȴ���m��
		for (int i = 0; i < m; i++)
		{
			data[i] = new T[n];       //�ٴ���n��
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> data[i][j];
		}
		transdata = new T * [n];			  //�ȴ���m��
		for (int i = 0; i < n; i++)
		{
			transdata[i] = new T[m];       //�ٴ���n��
		}
	}
	~Matrix()
	{
		delete[] data;
	}
	void transpose()     //����ת��
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				transdata[i][j] = data[j][i];
		}
	}
	void show()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << transdata[i][j] << " ";
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
		char type;
		int m, n;
		cin >> type;
		if (type == 'I')
		{
			cin >> m >> n;
			Matrix<int> a(m, n);
			a.transpose();
			a.show();
		}
		else if (type == 'D')
		{
			cin >> m >> n;
			Matrix<double> a(m, n);
			a.transpose();
			a.show();
		}
		else if (type == 'C')
		{
			cin >> m >> n;
			Matrix<char> a(m, n);
			a.transpose();
			a.show();
		}
	}
	return 0;
}
/*��Ŀ����
���һ��������ģ��Matrix��֧�������������͵����ݡ�

Ҫ�����ٰ���2����Ա����������ת�ú���transport���Լ���ӡ�������print

��дmain�������в��ԣ�������ĳ�Ա�������ת�ú������

����
��һ��������t����ʾ��t����������

�ӵڶ��п�ʼ����ÿ���������������ݡ�

���������������ͣ�I��ʾint��D��ʾdouble��C��ʾchar������������������m��n���ֱ��ʾ������к���

��������������Ԫ�أ�һ��m�У�ÿ��n������

���
���ת�ú�ľ���

��������
2
I 2 3
1 2 3
4 5 6
C 3 3
a b c
d e f
g h i
�������
1 4
2 5
3 6
a d g
b e h
c f i*/