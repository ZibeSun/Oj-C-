#include<iostream>
using namespace std;
class BaseAccount
{
protected:
	string name;
	string account;
	float balance;
public:
	BaseAccount(string n, string acc, float b)
	{
		name = n;
		account = acc;
		balance = b;
	}
	void deposit(float d)
	{
		balance += d;
	}
	void withdraw(float w)
	{
		if (w > balance)
		{
			cout << "insufficient" << endl;
		}
		else
		{
			balance -= w;
		}
	}
	void display()
	{
		cout << name << " " << account << " Balance:" << balance << endl;
	}
};
class BasePlus :public BaseAccount
{
protected:
	float limit;
public:
	BasePlus(string n, string acc, float b):BaseAccount(n,acc,b)
	{
		limit = 5000;
	}
	void deposit(float d)
	{
		if (limit < 5000)
		{
			limit += d;
			if (limit > 5000)
			{
				balance += (limit - 5000);
				limit = 5000;
			}
		}
		else
			balance += d;
	}
	void withdraw(float w)
	{
		if (w > (balance+limit))
		{
			cout << "insufficient" << endl;
		}
		else
		{
			if (w > balance)
			{
				w -= balance;
				balance = 0;
				limit -= w;
			}
			else
				balance -= w;
		}
	}
	void display()
	{
		cout << name << " " << account << " Balance:" << balance << " limit_sum:" << (5000-limit) << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string n, acc;
		float b, d1, w1, d2, w2;
		cin >> n >> acc >> b >> d1 >> w1 >> d2 >> w2;
		if (acc[1] == 'A')
		{
			BaseAccount a(n, acc, b);
			a.deposit(d1);
			a.withdraw(w1);
			a.deposit(d2);
			a.withdraw(w2);
			a.display();
		}
		else if (acc[1] == 'P')
		{
			BasePlus p(n, acc, b);
			p.deposit(d1);
			p.withdraw(w1);
			p.deposit(d2);
			p.withdraw(w2);
			p.display();
		}
	}
	return 0;
}/*��Ŀ����
ĳ���е�֧Ʊ�˻���Ϊ���࣬һ��Ϊ����֧Ʊ�˻�BaseAccount����һ��Ϊ����͸֧�������Ե�BasePlus֧Ʊ�˻���

BaseAccount֧Ʊ�˻�����Ϣ�������ͻ�����(name)���˻�(account)����ǰ����(balance)��BaseAccount֧Ʊ�˻�����ִ�еĲ������������(deposit)��ȡ��(withdraw)����ʾ�˻���Ϣ(display)��ע�⣺ȡ�����͸֧��������ʽ������Ϣ��insufficient����

BasePlus֧Ʊ�˻�������BaseAccount��������Ϣ�⣬������������Ϣ��͸֧����(limit��Ĭ��Ϊ5000)����ǰ͸֧�ܶ�(limit_sum)��BasePlus֧Ʊ�˻���ִ�еĲ�����BaseAccount��ͬ���������ֲ�����ʵ�ֲ�ͬ��(1)����ȡ�������������͸֧���޷�Χ��͸֧����������ʾ������Ϣ��insufficient�� ��(2)���ڴ�����������͸֧���������Ҫ�Ȼ���͸֧�Ĳ��֣�(3)������ʾ����������Ҫ��ʾlimit_sum�� ע�⣺������͸֧��������˻���ǰ����balance��Ϊ0��

��ʵ��BaseAccount���BasePlus�࣬����BasePlus��̳���BaseAccount�࣬ע��BaseAccount�˻�������BA��ͷ��BasePlus�˻�������BP��ͷ��

Ҫ��ֻʹ��һ������ָ�룬ָ���������Ķ���Ȼ��ʹ��ָ��������еķ�����

����
���԰������� t

��һ��������ݣ�

��һ�������˻���Ϣ������ �ʺ� ��ǰ���

�ڶ��������ĸ���������ʾ���˻���˳���ȡ���ȡ��

�ڶ���������ݣ�

.........

���
���BaseAccount����Ϣ

���BasePlus����Ϣ

��������
4
Tom BA008 1000
1000 2000 1000 1200
Bob BP009 1000
1000 2000 1000 7000
May BA001 2000
500 1000 500 1000
Lily BP002 1000
500 2000 500 3000
�������
insufficient
Tom BA008 Balance:1000
insufficient
Bob BP009 Balance:1000 limit_sum:0
May BA001 Balance:1000
Lily BP002 Balance:0 limit_sum:3000*/