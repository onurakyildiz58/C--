//onur akyıldız 191307026

#include <iostream>
using namespace std;

struct linklist
{
	int veri;
	struct linklist* next;
	struct linklist* prev;
};

struct linklist* head = NULL;//baş düğüm null olarak atadık

void ekle(int eleman)
{
	struct linklist* key = new linklist();
	key->veri = eleman;

	if (head==NULL)//listede eleman yok ise direkt başa ekliyor
	{
		head = key;
		head->next = NULL;//ilk eleman olduğundan next i ve prev i  null olur onları atadım
		head->prev = NULL;
		cout << "başa eleman eklendi\n";
		cout << "eklenen eleman : " << eleman << endl;
		cout << endl;
	}
	else//eğer listede elema varsa
	{
		struct linklist* temp = head;
		while (temp->next!=NULL)//son elemanı bulmak için geçici elemanın next i null olmalıdır onu buldum 
		{
			temp = temp->next;//temp++ işemi gibi bir şeet tempi arttırdık listeyi gezmesi için
		}
		temp->next = key;
		key->next = NULL;//nexti null olmalı ki son eleman olsun
		key->prev = temp;//temp burda sondan bi önceki elemanımız oldu	
		cout <<"sona eleman eklendi\n";
		cout << "eklenen eleman : " << eleman << endl;
		cout << endl;
	}
}

void listele()
{
	if (head == NULL)
	{
		cout << "liste boş...\n";
		cout << endl;
	}
	else
	{
		struct linklist* temp = head;
		cout << "listenin elemanları : ";
		while (temp->next != NULL)//son elemanı bulana kadar dönüyo bu sayede ekrana yazdırıyorum 
		{			
			cout << temp->veri << " ";
			temp = temp->next;//temp++ işemi gibi bir şey tempi arttırdık listeyi gezmesi için
		}
		cout << temp->veri << " \n";//son elemanı bulunca dögüden çıkacağı için bi kere de son elemanı yazdırdık
		cout << endl;
	}
}
void ara(int aranan)
{
	if (head==NULL)
	{
		cout << "liste boş...\n";
		cout << endl;
	}
	else
	{
		bool sonuc = true;
		struct linklist* temp = head;		
		while (temp->next != NULL)//listede gezmek için
		{			
			if (temp->veri==aranan)
			{
				sonuc = false;
				cout << "aranan eleman listede vardır...\n";
				cout << "aranan eleman : " << aranan << endl;
				cout << endl;
				break;
			}			
			temp = temp->next;
		}
		if (sonuc)
		{
			cout << "aranan veri listede yoktur...\n";
			cout << endl;
		}
	}
}

void sil(int istenen)
{
	if (head == NULL)
	{
		cout << "liste boş...\n";
		cout << endl;
	}
	else
	{
		if (head==NULL&&head->veri==istenen)//tek düğüm var ve o da silinmesi istenen elemansa siler
		{
			delete head;
			head = NULL;//eleman silindi ve baş süğüm null olarak atandı
			cout << "listeden eleman silindi...\n";
			cout << "silinen eleman : " << istenen << endl;
			cout << endl;
		}
		else
		{
			struct linklist* temp = head;
			while (temp->next != NULL)
			{
				if (temp->veri == istenen)//istediğimiz elemanı bulup silmek için yaptım
				{
					struct linklist* temp2 = temp->prev;
					struct linklist* temp3 = temp->next;//ardan sileceğimiz için bi elemanı çıkartınca yanındakilere prev ne next i atamak için oluşturdum
					delete temp;

					temp2->next = temp3;//aradan sildiğimiz için next ve prev atamalarını yaptım
					temp3->prev = temp2;
					cout << "listeden eleman silindi...\n";
					cout << "silinen eleman : " << istenen << endl;
					cout << endl;
					break;
				}
				temp = temp->next;//temp++ 
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "turkish");
	int seçim,sayi,aranan,silinen;
	
	do
	{
		cout << "1-eleman ekleme\n";
		cout << "2-eleman silme\n";
		cout << "3-listeyi yazdırma\n";
		cout << "4-listeden eleman arama\n";
		cout << "5-çıkış\n";

		cout << "istediğiniz işlem için önündeki numarayı giriniz\n";
		cout << endl;
		cin >> seçim;

		switch (seçim)
		{
		case 1:
			cout << "listeye eleman ekleme seçildi...\n";
			cout << "eklemek istediğiniz elemanı yazınız (sayı) : ";
			cin >> sayi;
			ekle(sayi);
			break;
		case 2:
			cout << "listeden eleman silme seçildi...\n";
			cout << "listeden silmekistediğiniz veriyi giriniz : ";
			cin >> silinen;
			sil(silinen);
			break;
		case 3:
			cout << "listedeki elemanları yazdırma seçildi...\n";
			listele();
			break;
		case 4:
			cout << "listede eleman arama seçildi...\n";
			cout << "listede aramak istediğiniz sayıyı giriniz : ";
			cin >> aranan;
			ara(aranan);
			break;
		case 5:
			cout << "çıkış seçildi...\n";
			cout << "çıkılıyor...\n";
			break;
		default:
			cout << "geçersiz seçim\n";
			break;
		}
	} while (seçim != 5);

	return 0;
}