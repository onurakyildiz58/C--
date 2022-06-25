#include <iostream>
using namespace std;

int main()
{
	//başlangıç
	int a[5] = { 5,7,2,9,4 };
	char s;
	cout << "bi karakter giriniz";
	cin >> s;

	for (int i = 0; i < 5; i++)
	{
		cout << i << "\t";
		cout << a[i] << "\t";
		for (int j = 0; j < a[i]; j++)
		{
			cout << s;
		}
		cout << "\n";
	}
	//	küçükten büyüğe sıralama
	int min;
	int temp;
	for (int j = 0; j < 5; j++)
	{
		min = a[j];
		for (int i = j; i < 5; i++)
		{		
			if (min > a[i])
			{
				min = a[i];
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	for (int u = 0; u < 5; u++)
	{
		cout << a[u];
	}
	//çok boyutlu

	return 0;
}