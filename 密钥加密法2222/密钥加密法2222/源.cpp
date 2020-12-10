#include<iostream>
using namespace std;
/*char* jm(char* p, char* q)
{
	int i = 0;
	char* s[100];
	while (*(p + i) != '\0')
	{
		if (*(q + i) != '\0')
		{
			*(s + i) = *(p + i) + (*(q + i) - 48);
			i++;
		}
		else if (*(q + i) == '\0')
		{
			int  k = 0;
			*(s + i) = *(p + i) + (*(q + k) - 48);
			k++;
		}
	}
	return s;
}*/
int main()
{
	int t;
	char a[999], b[999],s[999];
	char* p, * q;
	cin >> t;
	while (t--)
	{
		cin >> a;
		cin >> b;
		p = a;
		q = b;
		int i = 0,k=0;
		while (*(p + i) != '\0')
		{
			if (*(q + i) != '\0')
			{
				if ((*(p + i) >= 65) && (*(p + i) <= 90))
					s[k] = *(p + i) + (*(q + i) - 48)-26 * (((*(p + i) + *(q + i) - 48) - 65) / 26);
				else if ((*(p + i) >= 97) && (*(p + i) <= 122))
					s[k] = *(p + i) + (*(q + i) - 48)-26 * (((*(p + i) + *(q + i) - 48) - 97) / 26);
				i++;
				k++;
			}
			else if (*(q + i) == '\0')
			{
				/*q = q - i;
				if ((*(p + i) >= 65) && (*(p + i) <= 90))
					s[k] = *(p + i) + (*(q + i) - 48)-26 * (((*(p + i) + *(q + i) - 48) - 65) / 26);
				else if ((*(p + i) >= 97) && (*(p + i) <= 122))
					s[k] = *(p + i) + (*(q + i) - 48)-26 * (((*(p + i) + *(q + i) - 48) - 97) / 26);
				i++;*/

				p = p + i;
				i = 0;
			}
		}
		s[k] = '\0';
		cout << s << endl;
	}
	return 0;
}