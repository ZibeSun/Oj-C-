#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;
class Robot
{
private:
	char* name=new char;
	int hp=0;
	int harm=0;
	int defense=0;
	char type='N';
	int rank=0;
public:
	Robot(char* n, char t, int l)
	{
		strcpy(name, n);
		type = t;
		rank = l;
		if (type == 'N')
		{
			hp = rank * 5;
			harm = rank * 5;
			defense = rank * 5;
		}
		else if (type == 'A')
		{
			hp = rank * 10;
			harm = rank * 5;
			defense = rank * 5;
		}
		else if (type == 'D')
		{
			hp = rank * 5;
			harm = rank * 5;
			defense = rank * 10;
		}
		else if (type == 'H')
		{
			hp = rank * 10;
			harm = rank * 5;
			defense = rank * 5;
		}
	}
	void change(char c)
	{
		type = c;
		if (type == 'N')
		{
			hp = rank * 5;
			harm = rank * 5;
			defense = rank * 5;
		}
		else if (type == 'A')
		{
			hp = rank * 10;
			harm = rank * 5;
			defense = rank * 5;
		}
		else if (type == 'D')
		{
			hp = rank * 5;
			harm = rank * 5;
			defense = rank * 10;
		}
		else if (type == 'H')
		{
			hp = rank * 50;
			harm = rank * 5;
			defense = rank * 5;
		}
	}
	void printf()
	{
		cout << name << "--" << type << "--" << rank << "--" << hp << "--" << harm << "--" << defense  << endl;
	}
};
int main()
{
	int t,sum=0;
	cin >> t;
	while (t--)
	{
		char* n=new char;
		char t,c;
		int l;
		cin >> n >> t >> l >> c;
		Robot a(n, t, l);
		a.change(c);
		a.printf();
		if (t != c)
		{
			sum++;
		}
	}
	cout << "The number of robot transform is " << sum;
}/*��Ŀ����
��дһ���������࣬���������л�������Ѫ�����˺�ֵ������ֵ�����ͺ͵ȼ�������Ѫ�����˺��ͷ����͵ȼ���������أ�
��ͨ�ͻ����ˣ�����ΪN��Ѫ�����˺��������ǵȼ���5��
�����ͻ����ˣ�����ΪA�������ǵȼ���10�����������Ժ���ͨ��һ��
�����ͻ����ˣ�����ΪD�������ǵȼ���10�����������Ժ���ͨ��һ��
�����ͻ����ˣ�����ΪH�������ǵȼ���50�����������Ժ���ͨ��һ����
�����˲�����������ӡ���������ԵĻ�ȡ�����÷��������캯�����п��ޣ�������Ҫ���б�д��

��дһ��ȫ�ֺ������ڻ����˱���ʹ�ø������ͻ������ܹ��໥ת�䡣�������������˶���ָ��ͱ����Ļ��������ͣ��������޸Ļ��������ͣ���������ص����ԡ�����������ͺͻ�����ԭ�������Ͳ�ͬ����ִ�б����ܣ�������true������������ͺ�ԭ��������ͬ����ִ�б���������false.

Ҫ���������ݳ�Ա����˽�����ԣ���C++���Ժ�����������˼�������ʵ������Ҫ��

����
��һ������t����ʾҪִ��t�λ����˱���

����ÿ���У�һ������һ�������˵����ԣ����������������͡��ȼ�����һ�������������

������������

���
ÿ����������Ļ�������Ϣ��Ҫ����û����˵Ĵ�ӡ�������������ʹ�����˲�����Ҳ���

�����������Ϊ�����ơ����͡��ȼ���Ѫ�����˺�������

���һ�����ִ�б���Ĵ���

��������
3
X001 N 5
H
X002 A 5
D
X003 D 5
D
�������
X001--H--5--250--25--25
X002--D--5--25--25--50
X003--D--5--25--25--50
The number of robot transform is 2*/