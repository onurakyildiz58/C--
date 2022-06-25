//onur akyıldız 191307026

#include <iostream>
#include<conio.h>
#include <clocale>
using namespace std;

struct sıra
{
	int veri;
	sıra* next;
};
class queue
{
	sıra * front,* rear;
public:
	queue()
	{front = NULL; rear = NULL;}
	void insert();
	void Delete();
	void Display();
};

void queue::insert()
{
	struct sıra* temp = new sıra();//temp oluşturdum elemanı tutsun diye
	cout << "sıraya eklemek istediğiniz veriyi giriniz : ";
	cin >> temp->veri;
	temp->next = NULL;//eklediğimizin sonu null olmalıdır
	cout << endl;
	if (rear==NULL)//sonun null olması demek boş olması demektir
	{
		rear = temp;//eklediğimiz eleman ön ve arkaya atandı
		front = temp;
		cout << endl;
	}
	else
	{
		rear->next = temp;//hazırdan en az bir elemn varsa onun yanına geldi
		rear = temp;
		cout << endl;
	}
}

void queue::Delete()
{
	if (front != NULL)
	{
		struct sıra* temp = front;
		cout << "silinen eleman : " << front->veri << endl;//önden sileceğimiz içim (fifo) front->veri silimdi
		front=front->next;
		delete temp;		
		if (front==NULL)//ön null olurda bütün elemanlar silinmiş demektir
		{
			cout << "sırada eleman kalmadı...\n";
			rear == NULL;
		}
		cout << endl;
	}
	else
	{
		cout << "sıra boş...\n";
		cout << endl;
	}
}
void queue::Display()
{
	struct sıra* temp = front;
	cout << "sıranın elemanları : ";
	while (temp!=NULL)//null u bulana kadar geziyor ve yazıdırıyor temp->veri sayesinde
	{
		cout << temp->veri<<" ";
		temp = temp->next;		
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "turkish");
	
	int seçim;
	queue obj;
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
			obj.insert();
			break;
		case 2:
			cout << "kuyruktan eleman silme seçildi...\n";
			obj.Delete();
			break;
		case 3:
			cout << "kuyruktaki elemanları listeleme seçildi...\n";
			obj.Display();
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