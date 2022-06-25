#include <iostream>
using namespace std;
#define size 10

class stack
{
    char dizi[size];
    int tos;//top of stack

public:
    stack();
    void push(char ch);
    char pop();
    void traverse();//dizide dolaşma
};
stack::stack()
{
    cout << "stack inşaa ediliyor\n";
    tos = 0;
}
void stack::push(char ch)//eleman koyma 
{
    if (tos == size)//stack dolu mu
    {
        cout << "yığın dolu\n";
    }    
    else
    {
        dizi[tos] = ch;
        tos++;
    }
}
char stack::pop()//eleman alma
{
    if (tos == 0)//stack boş mu
    {
        cout << "yığın boş\n";
    }
    else
    {
        tos--;
        return dizi[tos];

    }
}
void stack::traverse() //elemanları listeleyip yazmak için 
{
    for (int i = 0; i < tos; i++)
    {
        cout << dizi[i] << endl;
    }
}


int main()
{
    // yığın                           kuyruktan 
    //eleman eklemek için push        eleman eklemek için add
    //eleman çıkartmak için pop       elemak çıkartmak için get
    //sıfırlamak için reset           sıfırlamak için reset
    //yığında ilk eklenen son çıkar   kuyrukta ise ilk giren ilk çıkar
    
    stack s1, s2;
    s1.push('A');
    s1.push('B');
    s1.push('C');
    s1.push('D');

    s2.push('O');
    s2.push('N');
    s2.push('U');
    s2.push('R');

    s1.traverse();
    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << s1.pop() << "\n";//ters yazılmasının sebebi ilk giren son çıkar
    }
    cout << endl;

    s2.traverse();
    cout << endl;
    
    for (int j = 0; j < 4; j++)
    {
        cout << s2.pop() << "\n";//ters yazılmasının sebebi ilk giren son çıkar
    }
    cout << endl;

    return 1903;
}