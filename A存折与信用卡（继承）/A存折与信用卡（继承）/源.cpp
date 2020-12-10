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
/*题目描述
  定义一个存折类CAccount，存折类具有帐号（account, long）、姓名（name,char[10])、余额（balance,float）等数据成员，可以实现存款（deposit,操作成功提示“saving ok!”)、取款（withdraw，操作成功提示“withdraw ok!”）和查询余额（check）的操作，取款金额必须在余额范围内，否则提示“sorry! over balance!”。从存折类派生出信用卡类CCreditcard，信用卡类增加了透支限额（limit,float）一项数据成员，对取款操作进行修改，允许在限额范围内透支金额，超出范围取款提示“sorry! over limit!”。

  编写主函数，建立这两个类的对象并测试之。

 1.对于存折类，输入账号、姓名、余额后，按照查询余额、存款、查询余额、取款、查询余额的顺序调用类方法并输出。

 2.对于信用卡类，输入账号、姓名、余额、透支限额后，按照查询余额、存款、查询余额、取款、查询余额的顺序调用类方法并输出。

输入
账号 姓名 余额

存款金额

取款金额

账号 姓名 余额 透支限额

存款金额

取款金额

输出
账户余额

存款操作结果

账户余额

取款操作结果

账户余额

账户余额

存款操作结果

账户余额

取款操作结果

账户余额

样例输入
1000 Tom 1000
500
1000
2000 John 500 500
500
1501
样例输出
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