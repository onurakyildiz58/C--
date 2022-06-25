#include <iostream>
#include <math.h>
using namespace std;

int cevre(int x, int y)
{
    return (2 * x) + (2 * y);
}
int alan(int x, int y)
{
    return x * y;
}
float ortalama(float i, float j)
{
    return(i + j) / 2;
}

int main()
{
    //Onur Akyıldız 191307026

    //1-Kullanıcının seçimine göre toplama veya çıkarma işlemi yapan programı yazınız
    cout << "**********************TOPLAMA VE CIKARMA ISLEMLERS**********************\n";
    int a, b, d;
    d = 0;
    string c;
    cout << "islem belirleyiniz(+ icin toplam - icin fark yaziniz) \n";
    cin >> c;

    if (c == "toplam")
    {
        cout << "birinci ve ikinci sayiyi belirleyin\n";
        cin >> a >> b;
        d = a + b;
        cout << "toplamin sonucu =" << d << endl;
    }
    else if (c == "fark")
    {
        cout << "birinci ve ikinci sayiyi belirleyin\n";
        cin >> a >> b;
        d = a - b;
        cout << "farkin sonucu =" << d << endl;
    }
    
    // 2-Klavyeden girilen sayıya ve seçime göre matemtiksel işlemleri yapan programı yazınız.1:Karekok, 2 : Kare, 3 : Mutlak Deger
    cout << "**********************MATEMATIKSEL ISLEMLER**********************\n";
    int k, z;
    cout << "bi sayi giriniz\n";
    cin >> z;
    cout << "islemi seciniz(1=karekok 2=kare ussu 3=mutlak deger)\n";
    cin >> k;
    if (k == 1)
    {
        cout << "karekok islemi\n";
        cout << "karekok sonucu =" << sqrt(z) << endl;
    }
    else if (k == 2)
    {
        cout << "kare ussu alma islemi\n";
        cout << "us alma sonucu =" << pow(z, 2) << endl;
    }
    else if (k == 3)
    {
        cout << "mutlak deger alma islemi\n";
        cout << "mutlak sonucu =" << fabs(z) << endl;
    }

    //3-Klavyeden -1 girilene kadar, girilen sayıların ortalamalarını gösteren programı yazınız
    cout << "**********************ORTALAMA**********************\n";
    int t, u, sayac;
    float f;
    f = 0;
    sayac = 0;
    t = 0;
    u = 0;
    cout << "bir sayi giriniz\n";
    do
    {
        cin >> t;
        u = u + t;
        sayac++;

    } while (t != -1);
    sayac--;
    u++;
    f = u / sayac;
    cout << f << endl;

    //4-Klavyeden girilen rakamlari farkli 4 basamakli sayinin basamaklarini bulan programı C++ ile yazınız. Sayi 4 basamakli olmazsa hata verecek! Sayının rakamlari farkli olmazsa hata verecek!
    cout << "**********************BASAMAK BULMA**********************\n";
    int p, e, binler, yuzler, onlar, birler,sayac2;
    binler = 0;
    yuzler = 0;
    onlar = 0;
    birler = 0;
    e = 0;
    sayac2 = 0;
    cout << "4 basamakli ve rakamlari farkli bi sayi giriniz\n";
    cin >> p;
    int q, w;
    q = p;
    w = p;
    do
    {  
        sayac2++;
        w = w / 10;
    } while (w);
    
    if (sayac2==4)
    {
       cout << "girilen basamak sayisi =" << sayac2 << endl;
       int m = fabs(q);
       binler = m / 1000;
       yuzler = (m % 1000) / 100;
       onlar = (m % 100) / 10;
       birler = m % 10;
         if (binler == yuzler)
         {
            cout << "hatali sayi girimi\n";
         }
         else if (onlar == birler)
         {
             cout << "hatali sayi girimi\n";
         }
         else if (binler == birler)
         {
             cout << "hatali sayi girimi\n";
         }
         else if (onlar == yuzler)
         {
             cout << "hatali sayi girimi\n";
         }
         else if (onlar == binler)
         {
             cout << "hatali sayi girimi\n";
         }
         else if (yuzler == birler)
         {
              cout << "hatali sayi girimi\n";
         }
       cout << "binler =" << binler << endl;
       cout << "yuzler =" << yuzler << endl;
       cout << "onlar =" << onlar << endl;
       cout << "birler =" << birler << endl;
    }
         else
         {
               cout << "sayi 4 basamakli degildir\n";
         } 

    //5-C++ ile Fonksiyon kullanarak Vize ve Final notu girilen öğrencinin ortalamasını hesaplayınız.
    cout << "**********************VIZE VE FINAL**********************\n";
    float vize, final;
    cout << "ogrencnin final notunu giriniz\n";
    cin >> final;
    cout << "ogrencnin vize notunu giriniz\n";
    cin >> vize;
    ortalama(vize, final);
    cout << "ogrencinin ortalaması =" << ortalama(vize, final) << endl;

    //6-C++ ile Fonksiyon kullanarak dikdörtgen alan ve çevre hesaplayan örneği oluşturunuz
    cout << "**********************ALAN VE CEVRE**********************\n";
    float x, y;
    cout << "dikdortgen icin iki kenari giriniz\n";
    cin >> x >> y;
    cevre(x, y);
    alan(x, y);

    cout << "cevre = " << cevre(x, y) << endl;
    cout << "alan = " << alan(x, y) << endl;

    return 1903;
}
