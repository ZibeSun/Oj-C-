#include<iostream>
using namespace std;

class Employee 
{
protected:
	string name;
	int lelve;
	int year;
public:
	Employee()
	{
		lelve = 0;
		year = 0;
	}
	Employee(string n, int l, int y)
	{
		name = n;
		lelve = l;
		year = y;
	}
	virtual void Salary()
	{
		int sum;
		sum = 1000 + 500 * lelve + 50 * year;
		cout << name << ":Employee,Salary:" << sum << endl;
	}
};
class Teamleader :public Employee
{
public:
	Teamleader(string n, int l, int y) :Employee(n, l, y)
	{

	}
	virtual void Salary()
	{
		int sum;
		sum = 3000 + 800 * lelve + 100 * year;
		cout << name << ":Teamleader,Salary:" << sum << endl;
	}
};
class Manager :public Employee
{
public:
	Manager(string n, int l, int y) :Employee(n, l, y)
	{

	}
	virtual void Salary()
	{
		int sum;
		sum = 5000 + 1000 * (lelve + year);
		cout << name << ":Manager,Salary:" << sum << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string n, type;
		Employee* p;
		int l, y;
		cin >> n >> type >> l >> y;
		if (type == "Employee")
		{
			p = new Employee(n, l, y);
		}
		else if (type == "Teamleader")
		{
			p = new Teamleader(n, l, y);
		}
		else if (type == "Manager")
		{
			p = new Manager(n, l, y);
		}
		else
		{
			cout << "error position." << endl;
			continue;
		}
		if (l < 0)
		{
			cout << "error grade or year." << endl;
			continue;
		}
		if (y < 0)
		{
			cout << "error grade or year." << endl;
			continue;
		}
		p->Salary();
	}
	return 0;
}/*��Ŀ����
ĳ��˾Ա���������У�������ְλ�����𡢹������ޣ���������޶��ǷǸ�������������ʾ���󡣰��������У����캯�������㹤�ʵķ�����salary()����

Ա��ְλ��Ϊ���֣�Employee��Teamleader��Manager������ְλ������ʾ����

����ְλԱ�����������ڼ��㹤�ʵķ�����ͬ��

1. Employee��ÿ�¹��� = 1000 + 500*���� + 50*��������

2. Teamleader��ÿ�¹��� = 3000 + 800*���� + 100*��������

3. Manager��ÿ�¹��� = 5000 + 1000 * (����+��������)

���㹤�ʵķ�������ÿ��Ա���Ĺ�������

Ҫ������ͨԱ��Ϊ���࣬�鳤�;���̳л��࣬������ֻ��ʹ�û���ָ��ָ���������ö���ķ�����

����
���԰����ĸ��� t

ÿ������һ��Ա������Ϣ������������ְλ�����𡢹�������

���
�����ӦԱ������Ϣ

���д�����Ϣ�������������Ϣ����ְλ��Ϣ�뼶���������Ϣͬʱ���������ְλ������Ϣ

��������
5
zhangsan Employee 4 5
lisi Teamleader 4 5
Wangwu Manager 4 5
chenliu Precident 4 5
xiaoxiao Manager -1 5
�������
zhangsan:Employee,Salary:3250
lisi:Teamleader,Salary:6700
Wangwu:Manager,Salary:14000
error position.
error grade or year.*/