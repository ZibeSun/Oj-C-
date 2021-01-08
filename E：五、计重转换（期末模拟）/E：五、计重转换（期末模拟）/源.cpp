#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class CN; //��ǰ����
class EN; //��ǰ����
class Weight 
{ //������
protected:
	char kind[20]; //��������
	int gram; //��
public:
	Weight(const char tk[] = "no name", int tg = 0)
	{
		strcpy(kind, tk);
		gram = tg;
	}
	virtual void Print(ostream& out) = 0; //�����ͬ���͵ļ�����Ϣ
	friend ostream& operator<<(ostream& oo, Weight& a);
};
class EN : public Weight
{ //Ӣ������
protected:
	int pounds;
	int ounces;
	int tarans;
	int original;
public:
	EN(int p, int o, int t, int g, const char k[])
	{
		pounds = p;
		ounces = o;
		tarans = t;
		gram = g;
		strcpy(kind, k);
	}
	virtual void Convert(int tw)
	{
		pounds = tw / 512;
		ounces = (tw - pounds * 512) / 32;
		tarans = (tw - pounds * 512 - ounces * 32) / 2;
		gram = tw - pounds * 512 - ounces * 32 - tarans * 2;
		original = tw;
	}
	virtual void Print(ostream& out)
	{
		cout << "Ӣ������:" << pounds << "��" << ounces << "��˾" << tarans << "����" << gram << "��" << endl;
	}
	int geten()
	{
		return original;
	}
};

class CN : public Weight
{ //�й�����
protected:
	int jin;
	int liang;
	int qian;
public:
	CN(int j, int l, int q, int g, const char k[])
	{
		jin = j;
		liang = l;
		qian = q;
		gram = g;
		strcpy(kind, k);
	}
	virtual void Convert(int tw)
	{
		jin = tw / 500;
		liang = (tw - jin * 500) / 50;
		qian = (tw - jin * 500 - liang * 50) / 5;
		gram = tw - jin * 500 - liang * 50 - qian * 5;
	}
	virtual void Print(ostream& out)
	{
		cout << "�й�����:" << jin << "��" << liang << "��" << qian << "Ǯ" << gram << "��" << endl;
	}
	CN& operator=(EN& b)
	{
		Convert(b.geten());
		return *this;
	}
};
//��ȫ�ֺ�����ʽ������������������3-5��....���б�д
//���غ�����������������ostream������Weight����󣬲��������Ƕ�����������
//���غ���������ò���Weight�����Print����
ostream& operator<<(ostream& oo, Weight& a)
{
	a.Print(oo);
	return oo;
}
int main()//������
{
	int tw;
	//����һ���й����������cn
	//���������Ӧ�����Ǯ���ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind
	CN cn(0, 0, 0, 0, "�й�����");
	cin >> tw;
	cn.Convert(tw); //������Ŀ���ת���й�����
	cout << cn;

	//����Ӣ�����������en
	//���������Ӧ������˾���������ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind
	EN en(0, 0, 0, 0, "Ӣ������");
	cin >> tw;
	en.Convert(tw); //������Ŀ���ת��Ӣ������
	cout << en;
	cn = en; //��Ӣ������ת���й�����
	cout << cn;
	return 0;
}
/*��Ŀ����
Ŀǰ���ʼ���������ĵ�λ�ǿˡ��ڹŴ��������ҵļ��ص�λ�ǲ�ͬ�ġ�
�й�ʹ�ý����Ǯ����ʾ����������1��=10����1��=10Ǯ
�й����ص�λ��˵Ĺ�ϵΪ��1��=500�ˣ�1��=50�ˣ�1Ǯ=5��
Ӣ��ʹ�ð�����˾����������ʾ����������1��=16��˾��1��˾=16����
Ӣ�����ص�λ��˵Ĺ�ϵΪ��1��=512�ˣ�1��˾=32�ˣ�1����=2��
���²ο���������˳�����Weight���й����غ�Ӣ�����ض��̳��˳����ࡣ
�й������������˽����Ǯ�������ԣ���������һ������������ת��Convert��
Convert�ܹ�������Ŀ���ת���й����أ�����1234��ת��2��4��6Ǯ4�ˣ����Ұ���ֵ��������Ǯ�����ĸ�������
Ӣ�������������˰�����˾�������������ԣ�������������������
1������ת��Convert���������������ƣ�����2345��ת��4��9��˾4����1�ˣ����Ұ���ֵ�����Ӧ���ĸ�������
2�����صȼۣ���������ת���������ʵ�ֽ�Ӣ��������Ķ���ת�����й�������Ķ�������Ӣ�����������en��2��2��˾11����1�ˣ��ȼ��ڣ�ת���ɣ��й����������cn��2��2��2Ǯ1�ˣ���
����Ҫ������
1���ο������ܲ������κ��޸ģ���Ҫ��ĵط���Ӵ���
2���������������κ��޸�
�������ݴ���Ϊ��Ŀ��ƣ�������㣬ʵ�ʻ��������ǲ�ͬ�ġ�
�������������Զ�����public�����������˼���C++����ʵ������Ҫ��
----�ο�����----

class CN; //��ǰ����
class EN; //��ǰ����
class Weight{ //������
protected:
	char kind[20]; //��������
	int gram; //��
public:
	Weight (char tk[]="no name", int tg=0)
	{ strcpy(kind, tk);	
	  gram = tg;
	}
	virtual void Print(ostream & out) = 0; //�����ͬ���͵ļ�����Ϣ
};
class CN: public Weight { //�й�����
//....�ඨ�����б�д
};
class EN: public Weight { //Ӣ������
//....�ඨ�����б�д
}
//��ȫ�ֺ�����ʽ������������������3-5��....���б�д
//���غ�����������������ostream������Weight����󣬲��������Ƕ�����������
//���غ���������ò���Weight�����Print����
int main()//������
{	int tw;
//����һ���й����������cn
//���������Ӧ�����Ǯ���ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind
	CN cn(0,0,0,0, "�й�����");
	cin>>tw;
	cn.Convert(tw); //������Ŀ���ת���й�����
	cout<<cn;
	
//����Ӣ�����������en
//���������Ӧ������˾���������ˡ����ͣ����п˺������Ƕ�Ӧ��������gram��kind
	EN en(0,0,0,0,"Ӣ������");
	cin>>tw;
	en.Convert(tw); //������Ŀ���ת��Ӣ������
	cout<<en;
	cn=en; //��Ӣ������ת���й�����
	cout<<cn;
return 0;
}
����
��һ������һ�������������й�����ת�����ѿ���ת���й�����
�ڶ�������һ������������Ӣ������ת�����ѿ���ת��Ӣ�����أ������ü��صȼ۰�Ӣ������ת���й�����
���
�����������������

��������
1234
2345
�������
�й�����:2��4��6Ǯ4��
Ӣ������:4��9��˾4����1��
�й�����:4��6��9Ǯ0��*/