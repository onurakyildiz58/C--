//onur akyıldız 191307026
#include <iostream>
#include <limits.h>
using namespace std;
#define S 6
int graf[S][S] = {{0,4,2,0,0,0},{4,0,1,5,0,0},{2,1,0,8,10,0},{0,5,8,0,2,6},{0,0,10,2,0,3},{0,0,0,6,3,0}};
string harf[S] = { "a","b","c","d","e","z" };
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
	cout << "->" << harf[j];
}
void yazdır(int uzak[],int n,int parent[])
{
	string başlangıç = "a"; 
	cout<<"Vertex\t\tbaşangıca olan uzaklık\t\tyol\n";
	for (int i = 0; i < S; i++)
	{
		cout << başlangıç << "->" << harf[i] << "\t\t" <<uzak[i] <<"\t\t\t\t"<< başlangıç;
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
	yazdır(uzak,S,parent);
}
int main()
{
	setlocale(LC_ALL, "turkish");
	
	cout << "matris : \n";
	cout << "   a	b	c	d	e	z\n";
	cout << "------------------------------------------\n";
	for (int i = 0; i < S; i++)
	{
		if (i==0)
		{
			cout << "a ";
		}
		else if (i==1)
		{
			cout << "b ";
		}
		else if (i == 2)
		{
			cout << "c ";
		}
		else if (i == 3)
		{
			cout << "d ";
		}
		else if (i == 4)
		{
			cout << "e ";
		}
		else if (i == 5)
		{
			cout << "z ";
		}
		cout << "|";
		for (int j = 0; j < S; j++)
		{
			cout <<graf[i][j];
			cout << "\t";

		}
		cout << endl;
		cout << endl;
	}

	dijkstra(graf, 0);
	
	return 0;
}