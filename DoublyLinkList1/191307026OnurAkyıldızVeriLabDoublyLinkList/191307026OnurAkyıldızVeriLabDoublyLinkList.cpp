//onur akyıldız 191307026

#include <iostream>
using namespace std;

struct öğrenci 
{
	int numara;
	string ad;
	string cinsiyet;
	struct öğrenci* prev = NULL;
	struct öğrenci* next = NULL;
};
struct öğrenci* baş = NULL;
struct öğrenci* son = NULL;

void ekle(string ad, string cinsiyet, int num)
{
	cout << "eleman eklendi\n";
	struct öğrenci* a = new öğrenci;
	a->ad = ad;
	a->cinsiyet = cinsiyet;
	a->numara = num;
	if (baş == NULL)
	{
		baş = a;
		son = a;
		baş->prev = NULL;
		son->next = NULL;
	}
	else
	{
		son->next = a;
		a->prev = son;
		son = a;
		son->next = NULL;
	}
}

void arayaekle(string ad, string cinsiyet, int num, int referans)
{
	öğrenci* t,*temp;
	temp = new öğrenci;
	t = baş;
	while (t->numara != referans)//referans aldığımız numarayı bulduk yani bu nuara dan önce eklenicek
	{
		t = t->next;
	}
	temp->ad = ad;
	temp->cinsiyet = cinsiyet;
	temp->numara = num;
	if (t->next==NULL)
	{
		t->next = temp;
		temp->next = NULL;
		temp->prev = t;
	}
	else
	{
		temp->next = t->next;
		temp->next->prev = temp;
		t->next = temp;
		temp->prev = t;
	}
	cout << "eklenen öğrencinin adı:  " << temp->ad << endl;
}

void sil(int silineceknumara)
{
	öğrenci* temp = new öğrenci;
	öğrenci* temp2 = new öğrenci;
	öğrenci* onceki = NULL;
	öğrenci* sonraki = NULL;
	if (baş->numara==silineceknumara)//baştaki eleman silinecek numara ise
	{
		if (baş == NULL)
		{
			cout << "liste boş\n";
		}
		else
		{
			if (baş->next==NULL)//tek düğüm var ise
			{
				delete baş;
				baş = NULL;
			}
			else
			{
				baş = baş->next;
				delete baş;
				baş = temp;
			}
		}			
	}
	temp = baş;
	while (temp->next->numara != silineceknumara)
	{
		temp = temp->next;
	}
	if (temp->next==NULL)
	{
		if (baş==NULL)
		{
			cout << "liste boş\n";
		}
		else
		{
			if (baş->next==NULL)//tek eleman ise direkt sil
			{
				delete baş;
				baş = NULL;
			}
			else
			{
				temp = baş->next;
				while (temp->next->next != NULL)
				{
					temp = temp->next;
				}
				temp2 = temp;
				delete temp->next;
				temp2->next = NULL;
			}
		}
	}
	onceki = temp;
	sonraki = temp->next->next;
	free(temp->next);
	onceki->next = sonraki;
}

void yazdır()
{
	struct öğrenci* temp = baş;
	while (temp->next!=NULL)
	{
		cout << temp->ad<<"  ";
		cout << temp->cinsiyet << "  ";
		cout << temp->numara << "  ";
		cout << endl;
		temp = temp->next;
	}
	cout << temp->ad << "  ";
	cout << temp->cinsiyet << "  ";
	cout << temp->numara << "  ";
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "turkish");

	ekle("onur", "erkek", 1);
	ekle("berk", "erkek", 2);
	ekle("şeyda", "kız", 3);
	ekle("batu", "erkek", 4);
	
	yazdır();
	cout << endl;

    arayaekle("utku", "erkek", 5, 1);
	arayaekle("merve", "kız", 6,2);

	yazdır();
	cout << endl;

	sil(5);
	sil(3);

	yazdır();
	
	return 0;
}