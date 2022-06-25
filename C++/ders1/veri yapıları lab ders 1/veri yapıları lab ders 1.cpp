#include <iostream>
using namespace std;


void fonk(int diziyaz[])
{ 
    int dizi[10];
    for  (int y = 0; y < 10; y++)
    {      

        diziyaz[y] = rand() % 10;
        dizi[y] = pow(diziyaz[y], 2);
        cout << "diziyaz[" << y << "] =" << diziyaz[y] << endl;
        cout << "dizi[" << y << "]    =" << dizi[y] << endl;
    }
   
}
int main()
{
    //cout << "Hello World!\n";
    //int a, *b;
    //b = &a;
    //a = 10;

    //cout << "değişken :" << a << endl;
    //*b = 15;
    //cout << "değişken :" << a << endl;//a ya dokunmadan pointer ardımı ile a daki değişken değiştirilebilir
    //cout << "b :" << b << endl;
    //cout << "*b :" << *b << endl;
    //cout << "&a :" << &a << endl;

  /*  int dizi[100];
    for (int i = 0; i < 100; i++)
    {
        dizi[i] = rand() % 10+3;
        cout << "dizi["<<i<<"] =" << dizi[i] << endl;
    }*/

  /*  int dizikare[100];
    for (int j = 0; j < 100; j++)
    {
        dizikare[j] = dizi[j] * dizi[j];
        cout << "dizikare[" << j << "] =" << dizikare[j] << endl;
    }*/
  

    int dizifonk[10];
    fonk(dizifonk);
    return 1903;

}
