#include <iostream>
using namespace std;


int main()
{
	int gunler;
	cout << "rastgele bir ayin kacinci ay oldugunu" << "ogrenmek icin 1-12 arasinda sayi giriniz" << endl;
	cin >> gunler;

	switch (gunler)
	{
	case 1:
		{
		cout << "ocak ayı";
		break;
		}
	case 2:
		{
		cout << "subat ayi";
		break;
		}
	case 3:
		{
		cout << "mart ayi";
		break;
		}
	case 4:
		{
		cout << "nisan ayi";
		break;
		}
	case 5:
		{
		cout << "mayis ayi";
		break;
		}
	case 6:
		{
		cout << "haziran ayi";
		break;
		}
	case 7:
		{
		cout << "temmuz ayi";
		break;
		}
	case 8:
		{
		cout << "agustos ayi";
		break;
		}
	case 9:
		{
		cout << "eylul ayi";
		break;
		}
	case 10:
		{
		cout << "ekim ayi";
		break;
		}
	case 11:
		{
		cout << "kasim ayi";
		break;
		}
	case 12:
		{
		cout << "aralik ayi";
		break;
		}
	default:
		{
		cout << "gecersiz";
		break;
		}
		return 1903;
	}
}