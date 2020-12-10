#include<iostream>
using namespace std;
class CPeople
{
protected:
	string id;
	string name;
public:
	/*CPeople(string idin, string namein)
	{
		id = idin;
		name = namein;
	}*/
};

class CInternetUser :virtual public CPeople
{
protected:
	string password;
public:
	void registerUser(string namein,string idin,string passwordin)
	{
		id = idin;
		name = namein;
		password = passwordin;
	}
	int login(string idint, string passwordint)
	{
		if ((id == idint) && (password == passwordint))
			return 1;
		else
			return 0;
	}
};

class CBankCustomer :virtual public CPeople
{
protected:
	double balance;
public:
	CBankCustomer()
	{
		balance = 0;
	}
	void openAccount(string namein, string idin)
	{
		id = idin;
		name = namein;
	}
	void deposit(double d)
	{
		balance += d;
	}
	int withdraw(double w)
	{
		if (w > balance)
		{
			return 0;
		}
		else
		{
			balance -= w;
			return 1;
		}
	}
};

class CInternetBankCustomer :public CInternetUser, public CBankCustomer
{
protected:
	double CIBbalance;
	double yesterdaybalance;
	double money;
	double wmoney;
	double wyesterdaymoney;
public:
	CInternetBankCustomer()
	{
		CIBbalance = 0;
		yesterdaybalance = 0;
		money = 0;
		wmoney = 0;
		wyesterdaymoney = 0;
	}
	void calculateProfit()
	{
		money = (yesterdaybalance / 10000) * wyesterdaymoney;
		CIBbalance += money;
	}
	void print()
	{
		cout << "Name: " << name << " ID: " << id << endl;
		cout << "Bank balance: " << balance << endl;
		cout << "Internet bank balance: " << CIBbalance << endl;
		cout << endl;
	}
	void setInterest(double interest)
	{
		wmoney = interest;
	}
	int deposit(double d)
	{
		if (balance < d)
			return 0;
		else
		{
			CIBbalance += d;
			return 1;
		}
	}
	int withdraw(double w)
	{
		if (w > CIBbalance)
		{
			return 0;
		}
		else
		{
			CIBbalance -= w;
			return 1;
		}
	}
	void set()
	{
		yesterdaybalance = CIBbalance;
		wyesterdaymoney = wmoney;
	}
};

int main()
{
	int t, no_of_days, i;
	string i_xm, i_id, i_mm, b_xm, b_id, ib_id, ib_mm;
	double money, interest;
	char op_code;

	//������԰�����t
	cin >> t;
	while (t--)
	{
		//���뻥�����û�ע��ʱ���û���,id,��½����
		cin >> i_xm >> i_id >> i_mm;

		//�������п����û���,id
		cin >> b_xm >> b_id;

		//���뻥�����û���½ʱ��id,��½����
		cin >> ib_id >> ib_mm;

		CInternetBankCustomer ib_user;

		ib_user.registerUser(i_xm, i_id, i_mm);
		ib_user.openAccount(b_xm, b_id);

		if (ib_user.login(ib_id, ib_mm) == 0)  //�������û���½,��id�����벻��;�Լ����п���������id�뻥��������������id��ͬ
		{
			cout << "Password or ID incorrect" << endl;
			continue;
		}

		//��������
		cin >> no_of_days;
		for (i = 0; i < no_of_days; i++)
		{
			//�����������, ���, ������Ԫ����
			cin >> op_code >> money >> interest;
			switch (op_code)
			{
			case 'S':  
				//�����������������ʻ�����
				if (ib_user.deposit(money) == 1)
				{
					ib_user.CBankCustomer::withdraw(money);
				}
				else if (ib_user.deposit(money) == 0)
				{
					cout << "Bank balance not enough" << endl;
					continue;
				}
				break;
			case 's':
				if (ib_user.deposit(money) == 1)
				{
					ib_user.CBankCustomer::withdraw(money);
				}
				else if (ib_user.deposit(money) == 0)
				{
					cout << "Bank balance not enough" << endl;
					continue;
				}
				break;
			case 'T':  
				//�ӻ���������ת�������ʻ�
				if (ib_user.withdraw(money) == 1)
				{
					ib_user.CBankCustomer::deposit(money);
				}
				else if (ib_user.withdraw(money) == 0)
				{
					cout << "Internet bank balance not enough" << endl;
					continue;
				}
				break;
			case 't':
				if (ib_user.withdraw(money) == 1)
				{
					ib_user.CBankCustomer::deposit(money);
				}
				else if (ib_user.withdraw(money) == 0)
				{
					cout << "Internet bank balance not enough" << endl;
					continue;
				}
				break;
			case 'D':  
				//ֱ���������ʻ����

			case 'd':
				ib_user.CBankCustomer::deposit(money);
				break;
			case 'W':  
				//ֱ�Ӵ������ʻ�ȡ��
				if (ib_user.CBankCustomer::withdraw(money) == 1)
				{

				}
				else if (ib_user.CBankCustomer::withdraw(money) == 0)
				{
					cout << "Bank balance not enough" << endl;
					continue;
				}
				break;
			case 'w':
				if (ib_user.CBankCustomer::withdraw(money) == 1)
				{

				}
				else if (ib_user.CBankCustomer::withdraw(money) == 0)
				{
					cout << "Bank balance not enough" << endl;
					continue;
				}
				break;
			default:
				cout << "Illegal input" << endl;
				continue;
			}
			ib_user.setInterest(interest);
			ib_user.calculateProfit();
			ib_user.set();
			//����û���,id
			//����������
			//��������������˻����
			ib_user.print();
		}
	}

	return 0;
}/*��Ŀ����
����һ����CPeople��������ݺ���(id,char[20])������(name,char[10])�������ݳ�Ա����CPeople������������CInternetUser���CBankCustomer��,Ȼ���ٴ�CInternetUser��CBankCustomer���ؼ̳�������CInternetBankCustomer��.��CInternetUser���е�¼����(password,char[20])���Ժ�ע��register(����id, name��password)����¼login(�ж������id��password�Ƿ������ע�����ͬ)��Ա������CBankCustomer�������(balance,double)���ԺͿ���openAccount(���ÿͻ�������id)�����deposit��ȡ��withdraw�Լ�ȱʡ�Ĺ��캯����CInternetBankCustomer����������, ǰһ�����, �������棬������Ԫ�������һ����Ԫ�����5�����ݳ�Ա����Ա������ȱʡ���캯��������ȡ�������Ԫ���棬���㵱�����棬��½login(�ж������id�������Ƿ��뻥�����û�����ͬ��ͬʱ��CBankCustomer�̳е��û�������idҪ���CInternetUser�̳е���ͬ)��CInternetBankCustomer������մ��������棬��2�쿪ʼ���ܼ������棬����ȡ��������档

  �ɲ���������ʾ�������������Բ�����������ݣ�

int main()
{
int t, no_of_days, i;
char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
double money, interest;
char op_code;

//������԰�����t
     cin >> t;
     while (t--)
     {
//���뻥�����û�ע��ʱ���û���,id,��½����
        cin >> i_xm >> i_id >> i_mm;

//�������п����û���,id
        cin >> b_xm >> b_id;

//���뻥�����û���½ʱ��id,��½����
        cin >> ib_id >> ib_mm;

  CInternetBankCustomer ib_user;

      ib_user.registerUser(i_xm, i_id, i_mm);
      ib_user.openAccount(b_xm, b_id);

      if (ib_user.login(ib_id, ib_mm) == 0)  //�������û���½,��id�����벻��;�Լ����п���������id�뻥��������������id��ͬ
     {
         cout << "Password or ID incorrect" << endl;
         continue;
      }

//��������
      cin >> no_of_days;
      for (i=0; i < no_of_days; i++)
     {
      //�����������, ���, ������Ԫ����
          cin >> op_code >> money >> interest;
          switch (op_code)
         {
            case 'S':  //�����������������ʻ�����
            case 's':
               if (ib_user.deposit(money) == 0)
               {
                  cout << "Bank balance not enough" << endl;
                  continue;
               }
               break;
          case 'T':  //�ӻ���������ת�������ʻ�
          case 't':
              if (ib_user.withdraw(money) == 0)
             {
                 cout << "Internet bank balance not enough" << endl;
                 continue;
             }
             break;
          case 'D':  //ֱ���������ʻ����
          case 'd':
               ib_user.CBankCustomer::deposit(money);
              break;
          case 'W':  //ֱ�Ӵ������ʻ�ȡ��
           case 'w':
               if (ib_user.CBankCustomer::withdraw(money) == 0)
              {
                    cout << "Bank balance not enough" << endl;
                   continue;
              }
              break;
          default:
                cout << "Illegal input" << endl;
               continue;
         }
          ib_user.setInterest(interest);
          ib_user.calculateProfit();
//����û���,id
//����������
//��������������˻����
          ib_user.print();
      }
   }

return 0;
}

����
�����û�����

�����1���������û�ע��ʱ���û���,id,��½����

�����1���û����п����û���,id

�����1���������û���½ʱ��id,��½����

�����1���û���������

ѭ�������������(S,T,D,W)  ���  ������Ԫ����
......

���
�����1���û���,id
�����1���û��������
�����1�������������˻����
......

��������
2
zhangsan 1234567890 222222
zhangsan 1234567890
1234567890 222222
4
D 15000 0
s 8000 1.5
T 3000 1.55
w 2000 0
lisi 2014150000 abcdef
lisi 2014150000
2014150000 123456
�������
Name: zhangsan ID: 1234567890
Bank balance: 15000
Internet bank balance: 0

Name: zhangsan ID: 1234567890
Bank balance: 7000
Internet bank balance: 8000

Name: zhangsan ID: 1234567890
Bank balance: 10000
Internet bank balance: 5001.2

Name: zhangsan ID: 1234567890
Bank balance: 8000
Internet bank balance: 5001.98

Password or ID incorrect*/