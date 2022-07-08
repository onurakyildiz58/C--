//Onur Akyıldız 191307026

#include <iostream>
#include<climits> 
 #include <vector>
using namespace std;

void swap( int* x, int* y );
class MaxHeap
{
    int* veri; 
    int kapasite; 
    int heapboyut; 
public:
    MaxHeap(int kapasite);
    void MaxHeapify(int);
    int ebeveyn(int i) { return (i - 1) / 2; }
    int sol(int i) { return ((2 * i) + 1); }
    int sağ(int i) { return ((2 * i) + 2); }
    int extractMax();
    void decreaseKey(int i, int new_val); 
    int getMax() { return veri[0]; }
    void deleteKey(int i);
    void insertKey(int k);
};
MaxHeap::MaxHeap(int cap)
{
    heapboyut = 0;
    kapasite = cap;
    veri = new int[cap];
}
void MaxHeap::insertKey(int key)
{
    if (heapboyut == kapasite)
    {
        cout << "ağaç doludur...\n";
        return;
    }

    heapboyut++;
    int i = heapboyut - 1;
    veri[i] = key;
    while (i != 0 && veri[ebeveyn(i)] < veri[i])
    {
        swap(&veri[i], &veri[ebeveyn(i)]);
        i = ebeveyn(i);
    }
}
void MaxHeap::decreaseKey(int i, int newkey)
{
    veri[i] = newkey;
    while (i != 0 && veri[ebeveyn(i)] < veri[i])
    {
        swap(&veri[i], &veri[ebeveyn(i)]);
        i = ebeveyn(i);
    }
}
void MaxHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMax();
}
void MaxHeap::MaxHeapify(int i)
{
    int l = sol(i);
    int r = sağ(i);
    int smallest = i;
    if (l < heapboyut && veri[l] < veri[i])
        smallest = l;
    if (r < heapboyut && veri[r] < veri[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&veri[i], &veri[smallest]);
        MaxHeapify(smallest);
    }
}
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    //15,7,12,28,36,1,37,13,4,25,3,9,27,2,5,16
    MaxHeap h(15);
    h.insertKey(7);
    h.insertKey(12);
    h.deleteKey(28);
    h.insertKey(36);
    h.insertKey(1);
    h.insertKey(37);
    h.insertKey(13);
    h.insertKey(4);
    h.insertKey(25);
    h.insertKey(3);
    h.insertKey(9);
    h.insertKey(27);
    h.insertKey(2);
    h.insertKey(5);
    h.insertKey(16);
    
   // cout << "kök düğüm : " << "37";
    //h.deleteKey(37);
   
    cout << h.getMax() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMax();



	return 0;
}
