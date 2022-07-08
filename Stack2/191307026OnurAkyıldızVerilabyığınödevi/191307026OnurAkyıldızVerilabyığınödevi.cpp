//onu akyıldız 191307026

#include <iostream>
using namespace std;

class stack
{
	int veri[10];
	int top = 0;
public:
	stack();
	void push(int a);
	int pop();
	void traverse();
};
stack::stack()
{
	cout << "stack inşaa ediliyor\n";
	top = 0;
}
void stack::push(int a)//eleman koyma 
{
    if (top == 10)//stack dolu mu
    {
        cout << "yığın taştı...\n";		
    }
    else
    {
        veri[top] = a;
        top++;
    }
}
int stack::pop()//eleman alma
{
    if (top == 0)//stack boş mu
    {
        cout << "yığın boş\n";		
    }
	else
	{
		top--;
		cout << "silinen veri :" << veri[top] << endl;
		cout << endl;
		return veri[top];
	}
}
void stack::traverse() //elemanları listeleyip yazmak için 
{
    for (int i = 0; i < top; i++)
    {
        cout << veri[i] << endl;
    }
}
//isim için ayrı bi yığın
class yıgın
{
	string isim[100];
	int top = 0;
public:
	yıgın();
	void push(string a);
	string pop();
	void traverse();
};
yıgın::yıgın()
{
	cout << "stack inşaa ediliyor\n";
	top = 0;
}
void yıgın::push(string a)//eleman koyma 
{
	if (top == 100)//stack dolu mu
	{
		cout << "yığın taştı...\n";
	}
	else
	{
		isim[top] = a;
		top++;
	}
}
string yıgın::pop()//eleman alma
{
	if (top == 0)//stack boş mu
	{
		cout << "yığın boş\n";
	}
	else
	{
		top--;
		cout << "silinen veri :" << isim[top] << endl;
		return isim[top];
	}
}
void yıgın::traverse() //elemanları listeleyip yazmak için 
{
	cout << "isimimin değişmiş hali: ";
	for (int i = 0; i < top; i++)
	{
		isim[1].clear();
		isim[1] = "whitestar";
		isim[0].clear();
		isim[0] = "honor";
		cout << isim[i]<<" ";
	}
}

int main()
{
	setlocale(LC_ALL, "turkish");
	stack S1;
	yıgın A1;
	int seçim = 0;
	int x = 0;
	cout << endl;

	do
	{
		cout << "1-veri ekleme" << endl;
		cout << "2-veri silme" << endl;
		cout << "3-verileri listeleme" << endl;
		cout << "4-tüm verileri silme" << endl;
		cout << "5-çıkış" << endl;
		cout << endl;
		cout << "birini seçiniz :";
		cin >> seçim;
		switch (seçim)
		{
		case 1:
			cout << "veri ekleme seçildi...\n";
			cout << "lütfen istediğiniz veriyi giriniz.\n";
			cin >> x;
			cout << "veriye eklenen eleman :" << x << endl;
			cout << endl;
			S1.push(x);
			break;
		case 2:
			cout << "veri silme seçildi...\n";
			S1.pop();
			break;
		case 3:
			cout << "verileri listeleme seçildi...\n";
			S1.traverse();
			break;
		case 4:
			cout << "verilerin hepsini silme seçildi...\n";
			cout << endl;
			for (int i = 0; i < 10; i++)
			{
				S1.pop();				
			}
			break;
		case 5:
			cout << "çıkış seçildi...\n";
			cout << "çıkılıyor...\n";
			cout << endl;
		default:
			cout << "geçersiz seçim\n";
			cout << endl;
		}

	} while (seçim != 5);
	cout << endl;
	cout << "**********************************************\n";
	cout << endl;
	
	cout << "ad soyad : onur akyıldız\n";//adımı soyadımı ingilizce yaptım (satır->92 102 arası)
	
	A1.push("onur");
	A1.push("akyıldız");
	A1.pop();//akyıldız yığından çıktı
	A1.pop();//onur yığından çıktı
	A1.push("onur");//tekrar ekledim
	A1.push("akyıldız");
	A1.traverse();
	cout << endl;
	return 0;
}