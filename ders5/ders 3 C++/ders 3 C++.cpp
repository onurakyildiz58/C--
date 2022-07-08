#include <iostream>
using namespace std;


int main()
{
    // değişkenlerin bellekte tuttuüu yerler 
    int a;
    double b;
    float c;
    char d;
    int *aa;
    double *bb;
    float *cc;
    char *dd;

    cout << "int a      =" << sizeof(a) << "byte" << endl;
    cout << "double b   =" << sizeof(b) << "byte" << endl;
    cout << "float c    =" << sizeof(c) << "byte" << endl;
    cout << "char d     =" << sizeof(d) << "byte" << endl;
    cout << "\n";
    cout << "int *aa    =" << sizeof(aa) << "byte" << endl;
    cout << "double *bb =" << sizeof(bb) << "byte" << endl;
    cout << "float *cc  =" << sizeof(cc) << "byte" << endl;
    cout << "char *dd   =" << sizeof(dd) << "byte" << endl;

    int numbers[5];
    int* p;
    p = numbers;
    *p = 10;
    p++;
    *p = 20;
    p = &numbers[2];
    *p = 30;
    p = numbers + 3;
    *p = 40;
    p = numbers;
    *(p + 4) =50;
    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i] << "-";
    }
    

    return 30;
}