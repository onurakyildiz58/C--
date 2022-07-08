//onur akyıldız 191307026
#include <iostream>
#include <list>
using namespace std;

void init(int arr[][7])
{
    int i, j;
    for (i = 0; i < 7; i++)
        for (j = 0; j < 7; j++)
            arr[i][j] = 0;
}

void addEdge(int arr[][7], int src, int dest)
{
    arr[src][dest] = 1;
}
void printAdjMatrix(int arr[][7])
{
    int i, j;
    cout << "     0 - 1 - 2 - 3 - 4 - 5 - 6\n";
    cout << "  ----------------------------\n";
    for (i = 0; i < 7; i++)
    {
        cout << i<<"|";
        for (j = 0; j < 7; j++)
        {
            cout <<"   "<< arr[i][j];
        }
        cout<<"\n";
    }
}
void findindegreeoutdegree(int arr[][7])
{
    int indegree = 0, outdegree = 0,n=7;
    for (int i = 0; i < 7; i++)
    {
       
        indegree = 0;
        outdegree = 0;
        for (int j = 0; j < 7; j++)
        {
            if (arr[i][j]==1)
            {
                outdegree++;
            }
            else  if (arr[j][i]==1)
            {
                indegree++;
            }
        }
        cout << i << "\t\t" << indegree << "\t\t" << outdegree << endl; 
    }
}
int main()
{
    int adjMatrix[7][7];

    init(adjMatrix);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);
    addEdge(adjMatrix, 3, 6);
    addEdge(adjMatrix, 4, 5);
    addEdge(adjMatrix, 4, 6);
    addEdge(adjMatrix, 5, 6);
    printAdjMatrix(adjMatrix);
    cout << endl;
    cout << "vertex" << "  \t" << "indegree" << "\t" << "outdegree" << endl;
    findindegreeoutdegree(adjMatrix);
   
	return 0;
}