//onur akyıldız 191307026
#include <iostream>
using namespace std;
#define S 7
int graf[S][S] = { {0,10,0,0,0,0,0},{0,0,0,0,0,0,18},{0,14,0,12,0,0,0},{0,0,0,0,30,0,0},{0,0,0,0,0,25,0},{0,0,0,20,0,0,0},{24,0,8,0,0,26,0} };//UZAKLIKLAR
string ilçe[S] = { "KARTEPE","İZMİT  ","DERİNCE","KÖRFEZ  ","GEBZE  ","KARAMÜRSEL","GÖLCÜK  " };//İLÇELER
int minUzaklık(int uzak[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int i = 0; i < S; i++)
	{
		if (sptSet[i] == false && uzak[i] <= min)
		{
			min = uzak[i], min_index = i;
		}
	}
	return min_index;
}
void yolyazdır(int parent[], int j)
{
	if (parent[j] == -1)
		return;
	yolyazdır(parent, parent[j]);
	cout << "->" << ilçe[j];
}
void yazdır(int uzak[], int n, int parent[])
{
	string başlangıç = "KARTEPE";
	cout << "Vertex\t\t\t\tbaşangıca olan uzaklık\t\tyol\n";
	for (int i = 0; i < S; i++)
	{
		cout << başlangıç << "->" << ilçe[i] << "\t\t" << uzak[i] << "\t\t\t\t" << başlangıç;
		yolyazdır(parent, i);
		cout << endl;
	}
}
void dijkstra(int graf[S][S], int key)
{
	int uzak[S];
	bool sptSet[S];
	int parent[S];
	for (int i = 0; i < S; i++)
	{
		parent[0] = -1;
		uzak[i] = INT_MAX;
		sptSet[i] = false;
	}
	uzak[key] = 0;
	for (int c = 0; c < S - 1; c++)
	{
		int u = minUzaklık(uzak, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < S; v++)
			if (!sptSet[v] && graf[u][v] && uzak[u] != INT_MAX && uzak[u] + graf[u][v] < uzak[v])
			{
				parent[v] = u;
				uzak[v] = uzak[u] + graf[u][v];
			}
	}
	yazdır(uzak, S, parent);
}
int main()
{
	setlocale(LC_ALL, "turkish");
	dijkstra(graf, 0);
    return 0;
}