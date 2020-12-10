#include<iostream>
using namespace std;
class CAccount
{
protected:
	int account;
	string name;
	float balance;
public:
	CAccount(int acc,string n,float b)
	{
		account = acc;
		name = n;
		balance = b;
	}
	void deposit(float d)
	{
		balance += d;
		cout << "saving ok!" << endl;
		cout << "balance is " << balance << endl;
	}
	void withdraw(float w)
	{
		if (w > balance)
		{
			cout << "sorry! over balance!" << endl;
			cout << "balance is " << balance << endl;
		}
		else
		{
			balance -= w;
			cout << "withdraw ok!" << endl;
			cout << "balance is " << balance << endl;
		}
	}
	void print()
	{
		cout << "balance is " << balance << endl;
	}
};

class CCreditcard:public CAccount
{
protected:
	float limit;
public:
	CCreditcard(int acc, string n, float b,float l):CAccount(acc,n,b)
	{
		limit = l;
	}
	void withdraw(float w)
	{
		if((balance + limit) < w) /*(((w > balance) && ((w < (balance + limit)||(((balance + limit) - w)<(1e-6)))))||((w < balance) || ((balance - w) < (1e-6))))*/
		{
			cout << "sorry! over limit!" << endl;
			cout << "balance is " << balance << endl;
		}
		else
		{
			balance -= w;
			cout << "withdraw ok!" << endl;
			cout << "balance is " << balance << endl;
		}
	}
};

int main()
{
		int acc1,acc2;
		string n1,n2;
		float b1,d1,w1;
		float b2, d2, w2, l;
		cin >> acc1 >> n1 >> b1 >> d1 >> w1;
		CAccount CA(acc1, n1, b1);
		CA.print();
		CA.deposit(d1);
		CA.withdraw(w1);
		cin >> acc2 >> n2 >> b2 >> l >> d2 >> w2 ;
		CCreditcard CC(acc2, n2, b2, l);
		CC.print();
		CC.deposit(d2);
		CC.withdraw(w2);
		return 0;
}
/*��Ŀ����
  ����һ��������CAccount������������ʺţ�account, long����������name,char[10])����balance,float�������ݳ�Ա������ʵ�ִ�deposit,�����ɹ���ʾ��saving ok!��)��ȡ�withdraw�������ɹ���ʾ��withdraw ok!�����Ͳ�ѯ��check���Ĳ�����ȡ�����������Χ�ڣ�������ʾ��sorry! over balance!�����Ӵ��������������ÿ���CCreditcard�����ÿ���������͸֧�޶limit,float��һ�����ݳ�Ա����ȡ����������޸ģ��������޶Χ��͸֧��������Χȡ����ʾ��sorry! over limit!����

  ��д��������������������Ķ��󲢲���֮��

 1.���ڴ����࣬�����˺š����������󣬰��ղ�ѯ������ѯ��ȡ���ѯ����˳������෽���������

 2.�������ÿ��࣬�����˺š���������͸֧�޶�󣬰��ղ�ѯ������ѯ��ȡ���ѯ����˳������෽���������

����
�˺� ���� ���

�����

ȡ����

�˺� ���� ��� ͸֧�޶�

�����

ȡ����

���
�˻����

���������

�˻����

ȡ��������

�˻����

�˻����

���������

�˻����

ȡ��������

�˻����

��������
1000 Tom 1000
500
1000
2000 John 500 500
500
1501
�������
balance is 1000
saving ok!
balance is 1500
withdraw ok!
balance is 500
balance is 500
saving ok!
balance is 1000
sorry! over limit!
balance is 1000*/