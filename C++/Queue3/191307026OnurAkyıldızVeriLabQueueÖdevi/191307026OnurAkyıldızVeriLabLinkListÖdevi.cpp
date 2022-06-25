//onur akyıldız 191307026

#include <iostream>
#include <clocale>
using namespace std;

struct node 
{
	int veri;
	struct node* next;
};

struct node* bastan_ekle(struct node* head, int veri1)
{
	if (head==NULL)
	{		
		struct node* temp= new node();
		temp->veri = veri1;
		temp->next = NULL;
		head = temp;//ilk veri olarak atandı	
	}
	else
	{
		struct node* temp = new node();
		temp->veri = veri1;
		temp->next = head;
		head = temp;		
	}
	return head;
}

struct node* sondan_ekle(struct node* head, int veri1)
{
	if (head == NULL)
	{
		struct node* temp = new node();
		temp->veri = veri1;
		temp->next = NULL;
		head = temp;//ilk veri olarak atandı
		cout << temp->veri;		
	}
	else
	{
		struct node* temp = new node();
		temp->veri = veri1;
		temp->next = NULL;
		struct node* temp2 = head;
		while (temp2->next!=NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp;		
	}
	return head;
}

struct node* aradan_ekle(struct node* head,int a, int veri1)
{
	struct node* temp = new node();
	struct node* eleman = new node();
	eleman->veri = veri1;
	temp = head;
	while (temp->next->veri != a)
	{
		temp = temp->next;
	}
	struct node* temp2 = new node();
	temp2 = temp->next;
	temp->next = eleman;
	eleman->next = temp2;
	return head;
}

void ara(struct node* head)
{
	struct node* temp = new node();
	temp = head;
	while (temp->next!=NULL)
	{
		if (temp->veri % 3 == 0)
		{
			cout << temp->veri << "\t";	
		}
		temp = temp->next;
	}
}

struct node* bastan_sil(struct node* head)
{
	if (head == NULL)
	{
		cout << "liste bos...\n";
	}
	else
	{
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			struct node* temp = head->next;
			delete head;
			head = temp;
		}
	}
	return head;
}

struct node* sondan_sil(struct node* head)
{
	if (head == NULL)
	{
		cout << "liste bos...\n";
	}
	else
	{
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			struct node* temp = head;
			while (temp->next->next!=NULL)
			{
				temp = temp->next;
			}
			struct node* temp2 = temp;
			delete temp->next;
			temp2->next = NULL;
		}
	}
	return head;
}

struct node* aradan_sil(struct node* head,int silinecek)
{
	if (head==NULL)
	{
		cout << "liste boş...\n";
	}
	else
	{
		if (head->veri==silinecek)
		{
			head = bastan_sil(head);
		}
		struct node* önceki = NULL;
		struct node* sonraki = NULL;
		struct node* temp = NULL;
		temp = head;
		while (temp->next->veri!=silinecek)
		{
			temp = temp->next;
		}
		if (temp->next==NULL)
		{
			head=sondan_sil(head);
		}

		önceki = temp;
		sonraki = temp->next->next;
		free(temp->next);
		önceki->next = sonraki;
	}
	return head;
}

void yaz(struct node * head)
{
	if (head==NULL)
	{
		cout << "liste boş...\n";
	}
	else
	{
		struct node* temp = head;
		while (temp != NULL)
		{
			cout << temp->veri << "\t";
			temp = temp->next;
		}				
	}
}

int main()
{
	struct node* head = NULL;
	setlocale(LC_ALL, "turkish");	

	cout << "başa eklendi\n";
	head = bastan_ekle(head, 49);
	head = bastan_ekle(head, 39);
	head = bastan_ekle(head, 29);
	head = bastan_ekle(head, 19);
	head = bastan_ekle(head,  9);
	yaz(head);
	cout << endl;
		
	cout << "sona eklendi\n";
	head = sondan_ekle(head, 1);
	head = sondan_ekle(head, 21);
	head = sondan_ekle(head, 31);
	head = sondan_ekle(head, 41);
	head = sondan_ekle(head, 51);
	yaz(head);
	cout << endl;
	
	cout << "araya eklendi\n";
	head = aradan_ekle(head, 1, 5);
	head = aradan_ekle(head, 1, 15);
	head = aradan_ekle(head, 1, 25);
	head = aradan_ekle(head, 1, 35);
	head = aradan_ekle(head, 1, 45);
	yaz(head);
	cout << endl;
	
	cout << endl;
	cout << "3 ile tam bölüne bilenler: \n";
	ara(head);

	cout << endl;
	cout << "baştaki ilk 3 eleman silindi\n";
	for (int i = 0; i < 3; i++)
	{
		head=bastan_sil(head);
	}	
	yaz(head);
	
	cout << endl;
	cout << "sondaki ilk 3 eleman silindi\n";
	for (int j = 0; j < 3; j++)
	{
		head = sondan_sil(head);
	}
	yaz(head);
	
	cout << endl;
	cout << "aradaki ilk 3 eleman silindi\n";
	head = aradan_sil(head, 5);
	head = aradan_sil(head, 15);
	head = aradan_sil(head, 25);
	yaz(head);

	return 0;
}