#include<iostream>
#include<cstring>
using namespace std;
class CTelNumber
{
	char* telnum = new char[9];
public:
	CTelNumber(char* tel)
	{
		for (int i = 0; i < 7; i++)
		{
			telnum[i] = tel[i];
		}
		telnum[8] = '\0';
	}
	CTelNumber(CTelNumber& s)
	{
		if ((s.telnum[0] == '2') || (s.telnum[0] == '3') || (s.telnum[0] == '4'))
		{
			//telnum = new char[8];
			telnum[0] = '8';
			for (int i = 1; i < 8; i++)
			{
				telnum[i] = s.telnum[i - 1];
			}
			telnum[8] = '\0';
		}
		else if ((s.telnum[0] == '5') || (s.telnum[0] == '6') || (s.telnum[0] == '7') || (s.telnum[0] == '8'))
		{
			//telnum = new char[8];
			telnum[0] = '2';
			for (int i = 1; i < 8; i++)
			{
				telnum[i] = s.telnum[i - 1];
			}
			telnum[8] = '\0';
		}
	}
	~CTelNumber()
	{
		delete[] telnum;
	}
	void print()
	{
		cout << telnum << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char* num = new char[99];
		cin >> num;
		int k = 0;
		if ((num[0] == '0') || (num[0] == '1') || (num[0] == '9'))
		{
			cout << "Illegal phone number" << endl;
		}
		else
		{
			for (int i = 0; i < 7; i++)
			{
				if ((num[i] >= '0') && (num[i] <= '9'))
				{
					k++;
				}
			}
			if ((k == 7) && (num[7] == '\0'))
			{
				CTelNumber n1(num);
				CTelNumber n2(n1);
				n2.print();
			}
			else
			{
				cout << "Illegal phone number" << endl;
			}
		}

	}
	return 0;
}
/*题目描述
定义一个电话号码类CTelNumber,包含1个字符指针数据成员,以及构造、析构、打印及拷贝构造函数。

字符指针是用于动态创建一个字符数组，然后保存外来输入的电话号码

构造函数的功能是为对象设置键盘输入的7位电话号码，

拷贝构造函数的功能是用原来7位号码的对象升位为8位号码对象,也就是说拷贝构造的对象是源对象的升级.电话升位的规则是原2、3、4开头的电话号码前面加8，原5、6、7、8开头的前面加2。

注意:电话号码只能全部是数字字符，且与上述情况不符的输入均为非法)

输入
测试数据的组数 t

第一个7位号码

第二个7位号码

......

输出
第一个号码升位后的号码

第二个号码升位后的号码

......

如果号码升级不成功，则输出报错信息，具体看示例

样例输入
3
6545889
3335656
565655
样例输出
26545889
83335656
Illegal phone number*/