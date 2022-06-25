// sayı tahmin C++.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;


int main()
{
	cout << "SAYİ TAHMİN OYUNUNA HOSGELDİNİZ\n";

	int tahmin, sayi, sayaç;
	sayi = rand() % 100;// her hangi bi sayı tehamin eder ve 100 e göre mod aldığımız için 0-99 arası sayıları verir
	sayaç = 0;
	cout << "lutfen tahmininizi giriniz =\n";
	cin >> tahmin;

	while (tahmin!=sayi)
	{   
	    if (tahmin>sayi)
	      {		      
	 	      cout << "daha kucuk bi deger giriniz";
	      }
	    else
	      {		      
		      cout << "daha buyuk bi deger giriniz";
	      }
		sayaç++;
		
		cout << "lutfen tahmininizi giriniz =\n";
		cin >> tahmin;
	}
	cout << "tebrikler " << sayaç+1 << " defada bildiniz\n";
	
	return 0;
}

