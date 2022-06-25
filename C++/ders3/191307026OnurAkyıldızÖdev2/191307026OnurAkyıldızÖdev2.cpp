#include <iostream>
using namespace std;

double OrtalamaDizi(int* dizi, int ElemanSayısı)
{
	double toplam = 0,sonuç;

	for (int j = 0; j < 7; j++)
	{
		toplam = toplam + *dizi;
		dizi++;
	}
	sonuç = toplam / ElemanSayısı;
	cout << "ortalama :"<<sonuç<<endl;
	return sonuç;
}
void ArtanDizi(int* dizi)
{
	int gecici;
	for (int i = 0; i < 7; i++)
	{
		for (int j = i; j < 7; j++)
		{			
			if (dizi[i] > dizi[j])
			{
				gecici = dizi[j];
				dizi[j] = dizi[i];
				dizi[i] = gecici;
			}
		}
	}
	cout << "buyukten kucuge siralanmis hali :";
	for (int k = 0; k < 7; k++)
	{
		cout << dizi[k];			
		cout << "-";		
	}
}
	

int main()
{
	//Onur Akildiz 191307026	

	int dizi[7] = { 5,7,2,8,12,5,9 };
	int ElemanSayısı = 7;
	int* p;
	p = dizi;
	
	for (int i = 0; i < 7; i++)
	{
		cout << dizi[i] << endl;
	}
	OrtalamaDizi(p, ElemanSayısı);
	ArtanDizi(p);

	system("pause");
	return 0;
}
