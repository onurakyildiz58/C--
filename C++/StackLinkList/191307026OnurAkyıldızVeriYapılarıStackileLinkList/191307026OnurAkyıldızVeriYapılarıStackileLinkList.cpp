//onur akyıldız 191307026 

#include <iostream>
using namespace std;

struct yıgın
{
	int veri;
	struct yıgın* next;
};
struct stack
{
	struct yıgın* üst = NULL;//bliste kullanarak düğüm olurşturdum ve ilk düğüm adı head
	int sayac = 0;
};

bool isFull(stack* stk)
{
	return (stk->sayac == 10);//stk sayacı yani üye sayısı 10 olursa true değri döndürüp 22. satırda ifin içine girer
}
bool isEmpty(stack* stk)
{
	return (stk->sayac == 0);//aynı mantık isFull ile sadece ters işlem ile boş olduğunu öğrendk
}

void push(stack* stk, int veri2)
{
	struct yıgın* key = new yıgın();
	key->veri = veri2;//yeni aldığımız eleman için yer ayırttık

	if (isFull(stk))//isfull diye fonk oluşturduk 16. satır
	{
		cout << "yığın doludur...\n";
		cout << endl;
	}
	else if(isEmpty(stk))//true dönerse içeri grier
	{
		cout << "yığın boş...\n";
		cout << "ilk eleman ekleniyor...\n";
		stk->üst = key;
		stk->üst->next = NULL;//eklenen elemanın sonrası nulll olur
		cout << "eklenen eleman : "<<stk->üst->veri<<endl;
		stk->sayac++;
		cout << endl;		
	}
	else
	{
		key->next = stk->üst;
		stk->üst = key;
		cout << "yığına yeni eleman eklendi...\n";
		cout << "eklenen eleman :" << stk->üst->veri << endl; ;
		stk->sayac++;
		cout << endl;
	}
			
}

void pop(stack* stk)
{

	if (isEmpty(stk))
	{
		cout << "yığın boş...\n";
		cout << endl;
	}	
	else
	{
		cout << stk->üst->veri <<" değeri silindi\n";
		struct yıgın* temp = stk->üst->next;//geçiciyi en üst düğümün nexti yaptık
		delete stk->üst;//üst düğüm silindi
		stk->üst = temp;//yeni üst silinenden önceki oldu
		stk->sayac--;
		cout << endl;
	}
}
 
void traverse(stack* stk)
{
	if (isEmpty(stk))
	{
		cout << "yığın boş...\n";
		cout << endl;
	}
	else
	{
		struct yıgın* temp = stk->üst;
		cout << "yığının elemanları : ";
		while (temp->next!=NULL)//en son elemana kadar yığını gezer
		{
			cout << temp->veri<<" "; //en son eleman haric elemanları yazar
			temp = temp->next;//temp++
		}
		cout << temp->veri<<endl;//en son elemanı yazar
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "turkish");
	stack stk;
	int seçim, x;

	do
	{
		cout << "1-eleman ekleme\n";
		cout << "2-eleman silme\n";
		cout << "3-yığını yazdırma\n";		
		cout << "4-çıkış\n";

		cout << "istediğiniz işlem için önündeki numarayı giriniz\n";	
		cin >> seçim;
		cout << endl;

		switch (seçim)
		{
		case 1:
			cout << "yığına eleman ekleme seçildi...\n";
			cout << "eklemek istediğiniz elemanı yazınız (sayı) : ";
			cin >> x;
			push( &stk, x);
			break;
		case 2:
			cout << "yığından eleman silme seçildi...\n";	
			pop(&stk);
			break;
		case 3:
			cout << "yığındaki elemanları yazdırma seçildi...\n";
			traverse(&stk);
			break;		
		case 4:
			cout << "çıkış seçildi...\n";
			cout << "çıkılıyor...\n";
			break;
		default:
			cout << "geçersiz seçim...\n";
			break;
		}
	} while (seçim != 4);

	return 0;
}