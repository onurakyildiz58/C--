//onur akyıldız 191307026

#include <iostream>
#include <queue>
using namespace std;

struct tree
{
	int veri;
	struct tree* sol;
	struct tree* sağ;
};
typedef struct tree Btree;
Btree* newtree(int veri)
{
	Btree* r = new Btree;
	r->veri = veri;
	r->sol = NULL;
	r->sağ = NULL;
	return r;
}
Btree* ekle(Btree* kök, int veri)
{
	if (kök != NULL)//boş değil ise
	{
		if (veri < kök->veri)//eklenecek eleman kökten küçük ise sola eklenir
		{
			kök->sol = ekle(kök->sol, veri);
		}
		else if ((veri > kök->veri))//eklenen veri kökten büyük ise sağa yazılır
		{
			kök->sağ = ekle(kök->sağ, veri);
		}
	}
	else//boş ise
	{
		kök = newtree(veri);//ilk kök oluştu buna göre if bloğunun içi çalışır
	}
	return kök;
}
void preorder(Btree* kök)//kökten başla sola git sağa git yazdır
{
	if (kök != NULL)
	{
		cout << kök->veri << "  ";
		preorder(kök->sol);
		preorder(kök->sağ);
	}
}
Btree* sil(Btree* kök, int istenen)
{
	Btree* temp, * temp1;
	if (kök == NULL)
	{
		cout << "ağaç boştur\n";
		return NULL;
	}
	if (kök->veri == istenen)
	{
		if (kök->sağ==kök->sol)
		{
			free(kök);
			return NULL;
		}
		else
		{
			if (kök->sol == NULL)
			{
				temp = kök->sağ;
				free(kök);
				return temp;
			}
			else if (kök->sağ == NULL)
			{
				temp = kök->sağ;
				free(kök);
				return temp;
			}
			else
			{
				temp = temp1 = kök->sağ;
				while (temp->sol != NULL)
				{
					temp = temp->sol;
				}
				temp->sol = kök->sol;
				free(kök);
				return temp1;
			}
		}
	}
	else if (kök->veri < istenen)
	{
		kök->sağ = sil(kök->sağ, istenen);
	}
	else
	{
		kök->sol = sil(kök->sol, istenen);
	}
	return kök;
}
Btree* bul(Btree* kök, int aranan)
{
	if (kök != NULL)
	{
		if (kök->veri == aranan)
		{
			return kök;
		}
		else if (kök->veri > aranan)
		{
			bul(kök->sol, aranan);
		}
		else
		{
			bul(kök->sağ, aranan);
		}
	}
	else
	{
		cout << "ağaçta öyle bi eleman yoktur";
		return NULL;
	}

}
int max(Btree* kök)//ağaçtaki max değeri bulur
{
	while (kök->sağ != NULL)
	{
		kök = kök->sağ;
	}
	return kök->veri;
}
int min(Btree* kök)//ağaçtaki min değeri bulur
{
	while (kök->sol != NULL)
	{
		kök = kök->sol;
	}
	return kök->veri;
}
Btree* newTree(Btree* kök)
{
	if (kök == NULL)
	{
		return NULL;
	}
	Btree* temp = newtree(kök->veri);
	temp->sol = newTree(kök->sol);
	temp->sağ = newTree(kök->sağ);
	return temp;
}
queue<int> y;
int sayıekle(Btree* kök,int min,int max)
{
	if (!kök)
	{
		return 0;
	}
	if (kök->veri == max && kök->veri == min)
	{
		return 1;
	}
	if (kök->veri <= max && kök->veri >= min)
	{
		y.push(kök->veri);
		return 1 + sayıekle(kök->sol, min, max) + sayıekle(kök->sağ, min, max);
	}
	else if (kök->veri < min)
	{
		return sayıekle(kök->sağ, min, max);
	}
	else
	{
		return sayıekle(kök->sol, min, max);
	}
}

int main()
{
	//50, 28, 46, 80, 47, 96, 14, 10, 68, 20, 34, 71, 61, 41, 82, 64, 13, 18, 27, 95, 74, 81, 11, 36
	setlocale(LC_ALL, "turkish");
	int aranan,min=60,max=70;
	
	Btree* kök = NULL, * m = NULL, * n = NULL;
	kök = ekle(kök, 50);
	kök = ekle(kök, 28);
	kök = ekle(kök, 46);
	kök = ekle(kök, 80);
	kök = ekle(kök, 47);
	kök = ekle(kök, 96);
	kök = ekle(kök, 14);
	kök = ekle(kök, 10);
	kök = ekle(kök, 68);
	kök = ekle(kök, 20);
	kök = ekle(kök, 34);
	kök = ekle(kök, 71);
	kök = ekle(kök, 61);
	kök = ekle(kök, 41);
	kök = ekle(kök, 82);
	kök = ekle(kök, 64);
	kök = ekle(kök, 13);
	kök = ekle(kök, 18);
	kök = ekle(kök, 27);
	kök = ekle(kök, 95);
	kök = ekle(kök, 74);
	kök = ekle(kök, 81);
	kök = ekle(kök, 11);
	kök = ekle(kök, 36);


	cout << "preorder : ";
	preorder(kök);
	cout << endl;

    cout << "aramak istediğiniz değeri giriniz : ";
	cin >> aranan;
	cout << "değerin adresi : " << kök<<endl;
	bul(kök, aranan);
	cout << endl;

	sayıekle(kök, min, max);
	int data = y.front();
	cout << "60 ile 70 arası ilk değer : " << data << endl;
	m = newTree(kök);
	sil(kök,data);
	cout << data << " silindi\n";
	cout << "preorder : ";
	preorder(kök);
	cout << endl;

	cout << "oluşan yeni ağaç : ";
	n = bul(m, data);
	kök = newTree(n);
	preorder(kök);
	cout << endl;

	return 0;
}