#include<iostream>
using namespace std;
class Account
{
public:
	Account()
	{
		_accno = "0";
		_accname = "0";
		_balance = 0;
	}
	void set(string accno, string name, float balance)
	{
		_accno = accno;
		_accname = name;
		_balance = balance;
	}
	~Account()
	{

	}
	void SetInterestRate(float i)
	{
		InterstRate = i;
	}
	void Deposit(float amount)
	{
		_balance += amount;
	}
	void Wirhdraw(float amount)
	{
		_balance -= amount;
	}
	float GetBalance()
	{
		return _balance;
	}
	void Show()
	{
		cout << _accno << " " << _accname << " " ;
	}
	static int GetCount()
	{
		return count;
	}
	static float GetInterstRate()
	{
		return InterstRate;
	}
	friend void Upadate(Account& a);
private:
	static int count;
	static float InterstRate;
	string _accno, _accname;
	float _balance;
};
int Account::count = 0;
float Account::InterstRate = 0;
void Upadate(Account& a)
{
	float sum;
	sum = a._balance + a._balance * a.InterstRate;
	a._balance = sum;
	cout << sum<<" ";
}
int main()
{
	float i,sum=0;
	float balance, c, q;
	int n;
	cin >> i >> n;
	Account* p = new Account[n];
	for (int k = 0; k < n; k++)
	{
		string accno, name;
		cin >> accno >> name >> balance >> c >> q;
		p[k].set(accno, name, balance);
		p[k].SetInterestRate(i);
		p[k].Show();
		p[k].Deposit(c);
		cout << p[k].GetBalance() << " ";
		Upadate(p[k]);
		p[k].Wirhdraw(q);
		cout << p[k].GetBalance() << endl;
		sum += p[k].GetBalance();
	}
	cout << sum << endl;
}
/*��Ŀ����
�����˻���Ļ����������£�



Ҫ�����£�

ʵ�ָ������˻���

Ϊ�˻���Account����һ����Ԫ������ʵ���˻���Ϣ��Ҫ�������Ϣ�������Ϣ���=�˻����+�˻����*���ʣ�����Ԫ����������ʽΪ friend void Update(Account& a);

��main�����У�����һ��Account���͵�ָ�����飬��ÿ��ָ��ָ��̬�����Account���󣬲����ó�Ա�������Դ�ȡ���ʾ�Ⱥ������ٵ�����Ԫ�������Խ��н�Ϣ��

��ҿ��Ը���ʵ�������������������������Ҳ�����޸ĳ�Ա�����Ĳ�������

����
��1�У�����
��2�У��˻���Ŀn
��3�п�ʼ��ÿ����������һ���˻��ġ��˺š��������������������������ȡ������

���
��1�п�ʼ��ÿ�����һ���˻��������Ϣ�������˺š�������������������Ϣ��ȡ�����

���һ����������˻�����

��������
0.01
3
201501 ���� 10000 1000 2000
201502 ���� 20000 2000 4000
201503 ���� 80000 4000 6000
�������
201501 ���� 11000 11110 9110
201502 ���� 22000 22220 18220
201503 ���� 84000 84840 78840
106170*/