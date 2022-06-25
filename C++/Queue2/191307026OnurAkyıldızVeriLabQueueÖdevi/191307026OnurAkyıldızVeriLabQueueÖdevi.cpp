//onur akyıldız 191307026

#include <iostream>
#include <time.h>
using namespace std;

int Queue[8], n = 8, ön = 0, son = 0;
void insert(int veri)
{	
	if (son == n)
	{
		cout << "kuyruk dolur\n";
		cout << endl;
	}
	else
	{			
		son++;
		Queue[son] = veri;
		cout << "eleman eklendi...\n";
		cout << "eklenen eleman :" << veri << endl;		
	}
	if (son==1)
	{
		cout << "kuyruğun doluluk oranı %12,5'tir\n";
		cout << endl;
	}
	else if (son==2)
	{
		cout << "kuyruğun doluluk oranı %25'tir\n";
		cout << endl;
	}
	else if (son == 3)
	{
		cout << "kuyruğun doluluk oranı %37,5'tir\n";
		cout << endl;
	}
	else if (son == 4)
	{
		cout << "kuyruğun doluluk oranı %50'dir\n";
		cout << endl;
	}
	else if (son == 5)
	{
		cout << "kuyruğun doluluk oranı %62,5'tir\n";
		cout << endl;
	}
	else if (son == 6)
	{
		cout << "kuyruğun doluluk oranı %75'tir\n";
		cout << endl;
	}
	else if (son == 7)
	{
		cout << "kuyruğun doluluk oranı %87,5'tir\n";
		cout << endl;
	}
	else if (son == 8)
	{
		cout << "kuyruğun doluluk oranı %100'dür\n";
		cout << endl;
	}	
}

void Delete()
{
	if (son==0)
	{
		cout << "kuyruk boştur\n";
		cout << endl;
		return;
	}
	else
	{		
		ön++;
		cout << "silinen eleman : " << Queue[ön] << endl;
		cout << endl;
	}
	//eminim daha kısa yolu vardır ama bulamadım kopya da çekmek istemedim denedim oldu
	//eğer dizi full dolu ise bi eleman çıkarılınca kaç kaldığını gösterir
	if (son == 8)
	{
		if (ön == 1)
		{
			cout << "kuyruğun doluluk oranı %87,5'tir\n";
			cout << endl;
		}
		else if (ön == 2)
		{
			cout << "kuyruğun doluluk oranı %75'tir\n";
			cout << endl;
		}
		else if (ön == 3)
		{
			cout << "kuyruğun doluluk oranı %62,5'tir\n";
			cout << endl;
		}
		else if (ön == 4)
		{
			cout << "kuyruğun doluluk oranı %50'dir\n";
			cout << endl;
		}
		else if (ön == 5)
		{
			cout << "kuyruğun doluluk oranı %37,5'tir\n";
			cout << endl;
		}
		else if (ön == 6)
		{
			cout << "kuyruğun doluluk oranı %25'tir\n";
			cout << endl;
		}
		else if (ön == 7)
		{
			cout << "kuyruğun doluluk oranı %12,5'tir\n";
			cout << endl;
		}
		else if (ön == 8)
		{
			cout << "kuyruk boşaltılmıştır\n";
			cout << endl;
		}
	}
	//eğer dizi 7 elemanlık dolu ise bi eleman çıkarılınca kaç kaldığını gösterir
	else if (son == 7)
	{
		if (ön == 1)
		{
			cout << "kuyruğun doluluk oranı %75'tir\n";
			cout << endl;
		}
		else if (ön == 2)
		{
			cout << "kuyruğun doluluk oranı %62,5'tir\n";
			cout << endl;
		}
		else if (ön == 3)
		{
			cout << "kuyruğun doluluk oranı %50'tir\n";
			cout << endl;
		}
		else if (ön == 4)
		{
			cout << "kuyruğun doluluk oranı %37,5'dir\n";
			cout << endl;
		}
		else if (ön == 5)
		{
			cout << "kuyruğun doluluk oranı %25'tir\n";
			cout << endl;
		}
		else if (ön == 6)
		{
			cout << "kuyruğun doluluk oranı %12,5'tir\n";
			cout << endl;
		}
		else if (ön == 7)
		{
			cout << "kuyruk boşaltılmıştır\n";
			cout << endl;
		}
	}
	//eğer dizi 6 elemanlık dolu ise bi eleman çıkarılınca kaç kaldığını gösterir
	else if (son == 6)
	{
		if (ön == 1)
		{
			cout << "kuyruğun doluluk oranı %62,5'tir\n";
			cout << endl;
		}
		else if (ön == 2)
		{
			cout << "kuyruğun doluluk oranı %50'tir\n";
			cout << endl;
		}
		else if (ön == 3)
		{
			cout << "kuyruğun doluluk oranı %37,5'tir\n";
			cout << endl;
		}
		else if (ön == 4)
		{
			cout << "kuyruğun doluluk oranı %25'dir\n";
			cout << endl;
		}
		else if (ön == 5)
		{
			cout << "kuyruğun doluluk oranı %12,5'tir\n";
			cout << endl;
		}
		else if (ön == 6)
		{
			cout << "kuyruk boşaltılmıştır\n";
			cout << endl;
		}
	}
    //eğer dizi 5 elemanlık dolu ise bi eleman çıkarılınca kaç kaldığını gösterir
	else if (son == 5)
	{
		if (ön == 1)
		{
			cout << "kuyruğun doluluk oranı %50'tir\n";
			cout << endl;
		}
		else if (ön == 2)
		{
			cout << "kuyruğun doluluk oranı %37,5'tir\n";
			cout << endl;
		}
		else if (ön == 3)
		{
			cout << "kuyruğun doluluk oranı %25'tir\n";
			cout << endl;
		}
		else if (ön == 4)
		{
			cout << "kuyruğun doluluk oranı %12,5'dir\n";
			cout << endl;
		}
		else if (ön == 5)
		{
			cout << "kuyruk boşaltılmıştır\n";
			cout << endl;
		}
	}
    //eğer dizi 4 elemanlık dolu ise bi eleman çıkarılınca kaç kaldığını gösterir
	else if (son == 4)
	{
		if (ön == 1)
		{
			cout << "kuyruğun doluluk oranı %37,5'tir\n";
			cout << endl;
		}
		else if (ön == 2)
		{
			cout << "kuyruğun doluluk oranı %25'tir\n";
			cout << endl;
		}
		else if (ön == 3)
		{
			cout << "kuyruğun doluluk oranı %12,5'tir\n";
			cout << endl;
		}
		else if (ön == 4)
		{
			cout << "kuyruk boşaltılmıştır\n";
			cout << endl;
		}
	}
	//eğer dizi 3 elemanlık dolu ise bi eleman çıkarılınca kaç kaldığını gösterir
	else if (son == 3)
	{
		if (ön == 1)
		{
			cout << "kuyruğun doluluk oranı %25'tir\n";
			cout << endl;
		}
		else if (ön == 2)
		{
			cout << "kuyruğun doluluk oranı %12,5'tir\n";
			cout << endl;
		}
		else if (ön == 3)
		{
			cout << "kuyruk boşaltılmıştır\n";
			cout << endl;
		}		
	}
	//eğer dizi 2 elemanlık dolu ise bi eleman çıkarılınca kaç kaldığını gösterir
	else if (son == 2)
	{
		if (ön == 1)
		{
			cout << "kuyruğun doluluk oranı %12,5'tir\n";
			cout << endl;
		}
		else if (ön == 2)
		{
			cout << "kuyruk boşaltılmıştır\n";
			cout << endl;
		}

	}
}

void Display()
{
	if (son == 0)
	{
		cout << "kuyruk bostur\n";
	}
	else
	{
		cout << "dizi elemanlari :";
		for (int i = ön; i < son; i++)
		{
			cout << Queue[i] << "  ";
		}
		cout << endl;
		cout << endl;
	}
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "turkish");
	int seçim;	
	do
	{
		cout << "1-eleman ekleme\n";
		cout << "2-eleman silme\n";
		cout << "3-kuyruğu listeleme\n";
		cout << "4-çıkış\n";
		
		cout << "istediğiniz işlem için önündeki numarayı giriniz\n";
		cout << endl;
		cin >> seçim;

		switch (seçim)
		{
		case 1:
			cout << "kuyruğa eleman ekleme seçildi...\n";			
			insert(rand() % 100 + 1);
			break;
		case 2:
			cout << "kuyruktan eleman silme seçildi...\n";
			Delete();
			break;
		case 3:
			cout << "kuyruktaki elemanları listeleme seçildi...\n";
			Display();
			break;
		case 4:
			cout << "çıkış seçildi...\n";
			cout << "çıkılıyor...\n";
			break;
		default:
			cout << "geçersiz seçim\n";
			break;
		}
	} while (seçim != 4);

	return 0;
}