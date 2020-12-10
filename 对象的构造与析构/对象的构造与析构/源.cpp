#include<iostream>
using namespace std;
class object
{
public:
	object()
	{
		n++;
		x = n;
		cout << "Constructing object " << x << endl;
	}
	~object()
	{
		x = n;
		cout << "Destructing object " << x << endl;
		n--;
	}
protected:
	static int n;
	int x;
};

int object::n = 0;

int main()
{
	int t, n, i;
	cin >> t;
	while (t--)
	{
		cin >> n;
		object* dx = new object[n];
		delete[] dx;
	}
	return 0;
}
/*��Ŀ����
������ʾΪ�����������������в��������,�������Ķ�����������ı�д.

����
�������ݵ�����t

��һ��������n1

�ڶ���������n2

.......

���
Constructing object 1
Constructing object 2

......
Constructing object n1
Destructing object n1

......
Destructing object 2
Destructing object 1

Constructing object 1
Constructing object 2

......
Constructing object n2
Destructing object n2

......
Destructing object 2
Destructing object 1

......

��������
2
3
4
�������
Constructing object 1
Constructing object 2
Constructing object 3
Destructing object 3
Destructing object 2
Destructing object 1
Constructing object 1
Constructing object 2
Constructing object 3
Constructing object 4
Destructing object 4
Destructing object 3
Destructing object 2
Destructing object 1
��ʾ
����һ������ȫ�ֱ����Թ���������Ķ�����м��������þ�̬���ݳ�Ա*/ 
