// 191307026 Onur Akyıldız

#include <iostream>
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
	if (kök!=NULL)//boş değil ise
	{
		if (veri < kök->veri)//eklenecek eleman kökten küçük ise sola eklenir
		{	
			kök->sol = ekle(kök->sol, veri);
			cout << "kökün soluna eleman eklendi : " << kök->sol->veri << endl;
		}
		else if((veri > kök->veri))//eklenen veri kökten büyük ise sağa yazılır
		{
			kök->sağ = ekle(kök->sağ, veri);
			cout << "kökün sağına eleman eklendi : " << kök->sağ->veri << endl;
		}
	}
	else//boş ise
	{		
		kök = newtree(veri);//ilk kök oluştu buna göre if bloğunun içi çalışır
        cout << "başa eleman eklendi : " << kök->veri<<endl;	
	}
	return kök;
}

void postorder(Btree* kök)//soldan başla sağa geç köke uğra yazdır
{
	if (kök != NULL)
	{
		postorder(kök->sol);
		postorder(kök->sağ);
		cout << kök->veri << "  ";
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
	

void inorder(Btree* kök)//sola git köke uğra sağa geç yazdır
{
	if (kök != NULL)
	{
		inorder(kök->sol);
		cout << kök->veri << "  ";
		inorder(kök->sağ);
	}
}

void mirror(Btree* kök)
{
	Btree* temp= new Btree;
	mirror(kök->sol);
	mirror(kök->sağ);
	temp = kök->sol;
	kök->sol = kök->sağ;
	kök->sağ = temp;
}
int main()
{
	setlocale(LC_ALL, "turkish");
	int seçim, veri;
	Btree* kök = NULL;
	do
	{
		cout << "1-ağaca veri eklemek\n";
		cout << "2-ağacın dallarını aynalamak(sonra inorder yazdırır)\n";
		cout << "3-ağacı preorder, inorder,postorder şekilde sıralamak\n";
		cout << "4-çıkış\n";
		cout << "istediğiniz işlem için önündeki numarayı giriniz\n";
		cin >> seçim;
		cout << endl;

		switch (seçim)
		{
		case 1:
			cout<<"veri ekleme seçildi\n";
			cout << "eklemek istediğiniz veriyi giriniz : ";
			cin >> veri;
			kök=ekle(kök, veri);
			break;
		case 2:
			cout << "aynalamak seçildi\n";
			mirror(kök);
			cout << "inorder ile yazdırma : ";
			inorder(kök);//sol kök sağ normalde ama mirrror yapıdığından sağ kök sol olur
			cout << endl;
			break;
		case 3:
			cout << "ağacı yazdırma seçildi\n";
			cout << "preorder ile yazdırma : ";
			preorder(kök);
			cout << endl;
			cout << "inorder ile yazdırma : ";
			inorder(kök);
			cout << endl;
			cout << "postorder ile yazdırma : ";
			postorder(kök);
			cout << endl;
			break;
		case 4:
			cout << "çıkış yapılıyor\n";
			break;
		default:
			cout << "geçersiz seçim\n";
			break;
		}
	} while (seçim!=4);

	return 0;
}