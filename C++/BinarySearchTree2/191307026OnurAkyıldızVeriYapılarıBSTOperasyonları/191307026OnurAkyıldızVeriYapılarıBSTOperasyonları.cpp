//onur akyıldız 191307026
#include <iostream>
using namespace std;

struct tree
{
	int veri;
	struct tree* sol;
	struct tree* sağ;
};
typedef struct tree Btree;
typedef struct tree Btreetek;
typedef struct tree Btreeçift;
Btree* newtree1(int veri)
{
	Btree* r = new Btree;
	r->veri = veri;
	r->sol = NULL;
	r->sağ = NULL;
	return r;
}
Btreetek* newtree2(int veri)
{
	Btreetek* r = new Btreetek;
	r->veri = veri;
	r->sol = NULL;
	r->sağ = NULL;
	return r;
}
Btreeçift* newtree3(int veri)
{
	Btreeçift* r = new Btreeçift;
	r->veri = veri;
	r->sol = NULL;
	r->sağ = NULL;
	return r;
}
Btree* ekle1(Btree* kök, int veri)
{
	if (kök != NULL)//boş değil ise
	{
		if (veri < kök->veri)//eklenecek eleman kökten küçük ise sola eklenir
		{
			kök->sol = ekle1(kök->sol, veri);
		}
		else if ((veri > kök->veri))//eklenen veri kökten büyük ise sağa yazılır
		{
			kök->sağ = ekle1(kök->sağ, veri);
		}
	}
	else//boş ise
	{
		kök = newtree1(veri);//ilk kök oluştu buna göre if bloğunun içi çalışır
	}
	return kök;
}
Btreetek* ekle2(Btreetek* kök, int veri)
{
	if (kök != NULL)//boş değil ise
	{
		if (veri < kök->veri)//eklenecek eleman kökten küçük ise sola eklenir
		{
			kök->sol = ekle2(kök->sol, veri);
		}
		else if ((veri > kök->veri))//eklenen veri kökten büyük ise sağa yazılır
		{
			kök->sağ = ekle2(kök->sağ, veri);
		}
	}
	else//boş ise
	{
		kök = newtree2(veri);//ilk kök oluştu buna göre if bloğunun içi çalışır
	}
	return kök;
}
Btreeçift* ekle3(Btreeçift* kök, int veri)
{
	if (kök != NULL)//boş değil ise
	{
		if (veri < kök->veri)//eklenecek eleman kökten küçük ise sola eklenir
		{
			kök->sol = ekle3(kök->sol, veri);
		}
		else if ((veri > kök->veri))//eklenen veri kökten büyük ise sağa yazılır
		{
			kök->sağ = ekle3(kök->sağ, veri);
		}
	}
	else//boş ise
	{
		kök = newtree3(veri);//ilk kök oluştu buna göre if bloğunun içi çalışır
	}
	return kök;
}
Btreetek* tek = NULL;
void tekekle(Btree* kök)
{
	if (kök != NULL)
	{
		tekekle(kök->sol);
		if (kök->veri % 2 != 0)
		{
			tek = ekle2(tek, kök->veri);
		}
		tekekle(kök->sağ);
	}
}
Btreeçift* çift = NULL;
void çiftekle(Btree* kök)
{
	if (kök != NULL)
	{
		çiftekle(kök->sol);
		if (kök->veri % 2 == 0)
		{
			çift = ekle3(çift, kök->veri);
		}
		çiftekle(kök->sağ);
	}
}
bool sayıkontrol(Btree* kök)
{
	if (kök != NULL) 
	{
		sayıkontrol(kök->sol);
		if (kök->veri % 2 != 0)
		{
			return true;//tek ise
		}
		else
		{
			return false;//çift ise
		}
		sayıkontrol(kök->sağ);
	}
}
int ekle_tek(Btree* kök)
{
	if (kök!=NULL)
	{
		ekle_tek(kök->sol);
		if (sayıkontrol(kök) == true)
		{
			tek = ekle2(tek, kök->veri);
		}
		ekle_tek(kök->sağ);
	}
	else
	{
		return 0;
	}
}
int ekle_çift(Btree* kök)
{
	if (kök != NULL)
	{
		ekle_çift(kök->sol);
		if (sayıkontrol(kök) == false)
		{
			çift = ekle3(çift, kök->veri);
		}
		ekle_çift(kök->sağ);
	}
	else
	{
		return 0;
	}
}
int çarpım = 1;
bool çarpımfonk(Btree* kök, int veri)
{

	if (kök != NULL)
	{
		if (kök->veri == veri)
		{
			return 	çarpım = çarpım * kök->veri;
		}
		else if (kök->veri > veri)
		{
			çarpım = çarpım * kök->veri;
			çarpımfonk(kök->sol, veri);

		}
		else
		{
			çarpım = çarpım * kök->veri;
			çarpımfonk(kök->sağ, veri);
		}
	}
	else
	{
		return false;
	}
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
int main()
{
	setlocale(LC_ALL, "turkish");
	Btree* kök = NULL;
	int veri;
	cout << "!!!!!1 ekleyene kadar devam eder!!!!!\n";
	do
	{
		cout << "girmek istediğiniz değeri giriniz : ";
		cin >> veri;
		cout << endl;
		kök = ekle1(kök, veri);	
	} while (veri!=1);

	cout << "preorder listelenmiş hali : \n";
	preorder(kök);
	cout << endl;

	cout << "tek ağacın listelenmiş hali : \n";
	tekekle(kök);
	preorder(tek);
	cout << endl;

	cout << "çift ağacın listelenmiş hali : \n";
	çiftekle(kök);
	preorder(çift);
	cout << endl;

	cout << "gireceğiniz değerden baş köke kadar olan syaılar girilen değere eşit mi değil mi kontrol eder.";
	cout << "mesela çarpımları olacağından büyük bi sayı girmemiz lazım büyük olduğundan en sağa gider o zamna hep kökün sağındaki elemanlar çarpılır \n";
	cout << "lütfen değer giriniz : ";
	cin >> veri;
	cout << endl;
	çarpımfonk(kök, veri);
	if (veri==çarpım)
	{
		cout << "girdiğiniz değerin çarpımları mevcuttur\n";
	}
	else
	{
		cout << "girdiğiniz değerin çarpımları mevcut değildir\n";
	}

	return 0;
}