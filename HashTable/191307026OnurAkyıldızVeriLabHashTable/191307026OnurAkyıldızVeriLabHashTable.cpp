//onur akyıldız 191307026
#include <iostream>
#include <list>

using namespace std;
class Hash
{
    int veri;  
    list<int>* table;
public:
    Hash(int V); 
    void insertItem(int x);
    void deleteItem(int key); 
    int hashFunction(int x) {
        return (x % veri);
    }
    void displayHash();
    int search(int h[],int aranan);
};
Hash::Hash(int b)
{
    this->veri = b;
    table = new list<int>[veri];
}
void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}
void Hash::deleteItem(int key)
{
    int index = hashFunction(key);
    list <int> ::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) 
    {
        if (*i == key)
            break;
    }
    if (i != table[index].end())
        table[index].erase(i);
}
void Hash::displayHash()
{
    for (int i = 0; i < veri; i++)
    {
        cout << i;
        for (auto x : table[i])
            cout << "-> " << x;
        cout << endl;
    }
}
int Hash::search(int h[],int aranan)
{   
    for (int i = 0; i < 250; i++)
    {  
        if (h[i]==aranan)
        {
            cout << "aradığınız eleman hashte vardır\n";
            return 1;
        }
    }
}
int main()
{
    setlocale(LC_ALL, "turkish");
    Hash h(10);
    int hash[250];
    int sil = 0, aranan;
    srand(time(NULL));
    for (int i = 0; i < 250; i++)
    {
        int rnd = rand() % 500;//0-500 ranom üretir 250 eleman için 
        hash[i] = rnd;
        h.insertItem(hash[i]);
    }
    int n = sizeof(hash) / sizeof(hash[0]);//boyut
    cout << "elaman silinmeden önce hash\n";
    h.displayHash();
    cout << endl;

    cout << "silmek istediğiniz elemanı yazınız : ";
    cin >> sil;
    cout << "silinmek istenen eleman : " << sil << endl;
    h.deleteItem(sil);

    cout << endl;
    cout << "elaman silindikten sonra hash\n";
    h.displayHash();
    cout << endl;

    cout << "aramak istediğiniz elemanı giriniz : ";
    cin >> aranan;
   
    if ( h.search(hash,aranan)!=1)
    {
        cout << "aranan eleman hashte yoktur\n";
    }
    return 0;
}