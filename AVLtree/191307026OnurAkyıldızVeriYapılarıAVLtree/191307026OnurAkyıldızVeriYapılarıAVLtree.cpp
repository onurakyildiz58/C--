// 191307026 Onur Akyıldız

#include <iostream>
using namespace std;

class tree
{
public:
    int veri;
    tree* sol;
    tree* sağ;
    int yükseklik;
};
int max(int a, int b);
int max(int a, int b)//max deperi döndürür
{
    return (a > b) ? a : b;
}
int yükseklik(tree* kök)//yüksekliği döndürür
{
    if (kök == NULL)
        return 0;
    return kök->yükseklik;
}
tree* newNode(int veri)
{
    tree* r = new tree();
    r->veri = veri;
    r->sol = NULL;
    r->sağ = NULL;
    r->yükseklik = 1;
    return(r);
}
tree* sağdenge(tree* kök)//sağ açacın yüksekliğini verir
{
    tree* temp = kök->sol;
    tree* Tree2 = temp->sağ;

    temp->sağ = kök;
    kök->sol = Tree2;

    kök->yükseklik = max(yükseklik(kök->sol),yükseklik(kök->sağ)) + 1;
    temp->yükseklik = max(yükseklik(temp->sol),yükseklik(temp->sağ)) + 1;

    return temp;
}
tree* soldenge(tree* kök)//sol ağacın yüksekliğini veriri
{
    tree* temp = kök->sağ;
    tree* Tree2 = temp->sol;

    temp->sol = kök;
    kök->sağ = Tree2;
 
    kök->yükseklik = max(yükseklik(kök->sol), yükseklik(kök->sağ)) + 1;
    temp->yükseklik = max(yükseklik(temp->sol), yükseklik(temp->sağ)) + 1;
  
    return temp;
}
int treedenge(tree* kök)//dengeyi verir
{
    if (kök == NULL)
        return 0;
    return yükseklik(kök->sol) - yükseklik(kök->sağ);
}  
//ekleme
tree* insert(tree* kök, int veri)
{
    if (kök == NULL)//kök boş ise direkt ekler alttaki sorgular da BST ile aynıdır
    {
        return(newNode(veri));
    }  
    if (veri < kök->veri)
    { 
        kök->sol = insert(kök->sol, veri);
    }  
    else if (veri > kök->veri)
    {
        kök->sağ = insert(kök->sağ, veri); 
    }
    else  
    {
        return kök; 
    }
    
    kök->yükseklik = 1 + max(yükseklik(kök->sol),yükseklik(kök->sağ));

    int denge = treedenge(kök);//denge değerinini denge adlı int değere atadık

    if (denge > 1 && veri < kök->sol->veri)//denge 1,0,-1 ise denge kurulmuştur ve BST ye göre eklenir
    {
        return sağdenge(kök);
    }  
    if (denge < -1 && veri > kök->sağ->veri)
    {
        return soldenge(kök);
    }
    if (denge > 1 && veri > kök->sol->veri)
    {
        kök->sol = soldenge(kök->sol);
        return sağdenge(kök);
    }
    if (denge < -1 && veri < kök->sağ->veri)
    {
        kök->sağ = sağdenge(kök->sağ);
        return soldenge(kök);
    }
    return kök;
}
void preorder(tree* kök)
{
    if (kök!=NULL)
    {
        cout << kök->veri << "  ";
        preorder(kök->sol);
        preorder(kök->sağ);
    }
}
//silme
tree* mindeğer(tree* kök)
{
    tree* temp = kök;
    while (temp->sol != NULL)//bst olduğundan en küçük değer her zaman en solda olur
    {
        temp = temp->sol;
    }
    return temp;
}
tree* Delete(tree* kök, int veri)
{
    if (kök==NULL)
    {
        cout << "ağac boştur...\n";
    }
    if (veri < kök->veri)
    {
        kök->sol = Delete(kök->sol, veri);
    }
    else if (veri > kök->veri)
    {
        kök->sağ = Delete(kök->sağ,veri);
    }
    else
    {
        if (kök->sağ==NULL || kök->sol==NULL)//tek ya da hiç evladı olmayan node
        {
            tree* temp = kök->sol ? kök->sol : kök->sağ;// hangi dalın evlatsız olduğunu öğrenmek için
            if (temp==NULL)
            {
                temp = kök;
                kök = NULL;
            }
            else
            {
                *kök = *temp;
            }
            free(temp);
        }
        else
        {         
            tree* temp = mindeğer(kök->sağ); 
            kök->veri = temp->veri;
            kök->sağ = Delete(kök->sağ,temp->veri);
        }
    }
    if (kök==NULL)
    {
        return kök;
    }

    kök->yükseklik = 1 + max(yükseklik(kök->sol), yükseklik(kök->sağ));

    int balance = treedenge(kök);

    if (balance > 1 && treedenge(kök->sol) >= 0)
    {
        return sağdenge(kök);
    }
    if (balance > 1 && treedenge(kök->sol) < 0)
    {
        kök->sol = soldenge(kök->sağ);
        return sağdenge(kök);
    }
    if (balance < -1 && treedenge(kök->sağ) <= 0)
    {
        return soldenge(kök);
    }
    if (balance < -1 && treedenge(kök->sağ) > 0)
    {
        kök->sağ = sağdenge(kök->sağ);
        return soldenge(kök);
    }

    return kök;
}
//arama
bool arama(tree* kök, int veri)
{
    if (kök != NULL)
    {
        if (kök->veri == veri)
        {
            return kök;
            return true;
        }
        else if (kök->veri > veri)
        {
            arama(kök->sol, veri);         
        }
        else
        {
            arama(kök->sağ, veri);
        }
    }
    else
    {
        cout << "ağaçta öyle bi eleman yoktur";
        return NULL;
        return false;
    }
}
int main()
{
    setlocale(LC_ALL, "turkish");
    tree* kök = NULL;
    kök = insert(kök, 9);
    kök = insert(kök, 3);
    kök = insert(kök, 10);
    kök = insert(kök, 11);
    kök = insert(kök, 6);
    kök = insert(kök, 2);
    kök = insert(kök, 1);
    kök = insert(kök, 4);
    kök = insert(kök, 8);
    /* 
    * 
             9  
           /  \  
          3    10  
         / \    \  
        2   6    11  
       /   / \  
      1   4   8  

    */
    cout << "preorder : \n";//9  3  2  1  6  4  8  10  11
    preorder(kök);
    cout << endl;
    
    cout << "10 elemanı silinecek\n";
    kök = Delete(kök, 10);
    /*  
    * 
             3  
           /  \  
          2    9  
         /    /  \  
        1    6    11  
            / \  
           4   8 

   */
    cout << "silindikten sonra ağacın preorder çıktısı : \n";
    preorder(kök);//3  2  1  9  6  4  8  11
    cout << endl;

    int aranan;
    cout << "aramak istediğiniz elemanı giriniz : ";
    cin >> aranan;
    
    if (arama(kök, aranan) == true)
    {
        cout << "aranan eleman ağaçta bulunmaktadır \n";
    }
  
    return 0;
}