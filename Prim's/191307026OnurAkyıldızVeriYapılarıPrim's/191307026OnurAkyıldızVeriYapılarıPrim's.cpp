//onur akyıldız 191307026
#include <iostream>
using namespace std;
#define V 8
char vert[V] = { 's','t','u','v','w','x','y','z' };

int min_Key(int key[], bool visited[])
{
    int min = 999, min_index;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && key[v] < min) 
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}
void print_MST(int parent[], int cost[V][V])
{
    int minCost = 0;
    cout << "vertex \tağırlığı\n";
    for (int i = 1; i < V; i++) 
    {
        if (i == 1)
        {
            cout << vert[2] << " - " << vert[i] << " \t" << cost[i][parent[i]] << " \n";
            minCost += cost[i][parent[i]];
        }
        else if (i == 2)
        {
            cout << vert[0] << " - " << vert[i] << " \t" << cost[i][parent[i]] << " \n";
            minCost += cost[i][parent[i]];
        }
        else if (i == 3)
        {
            cout << vert[4] << " - " << vert[i] << " \t" << cost[i][parent[i]] << " \n";
            minCost += cost[i][parent[i]];
        }
        else if (i == 4)
        {
            cout << vert[2] << " - " << vert[i] << " \t" << cost[i][parent[i]] << " \n";
            minCost += cost[i][parent[i]];
        }
        else if (i == 5)
        {
            cout << vert[3] << " - " << vert[i] << " \t" << cost[i][parent[i]] << " \n";
            minCost += cost[i][parent[i]];
        }
        else if (i == 6)
        {
            cout << vert[5] << " - " << vert[i] << " \t" << cost[i][parent[i]] << " \n";
            minCost += cost[i][parent[i]];
        }
        else if (i == 7)
        {
            cout << vert[6] << " - " << vert[i] << " \t" << cost[i][parent[i]] << " \n";
            minCost += cost[i][parent[i]];
        }
    }
    cout << "toplam mesafe : " << minCost<< endl;
}
void find_MST(int cost[V][V])
{
    int parent[V], key[V];
    bool visited[V];
 
    for (int i = 0; i < V; i++) 
    {
        key[i] = 999;
        visited[i] = false;
        parent[i] = -1;
    }
    key[0] = 0;  
    parent[0] = -1;

    for (int x = 0; x < V - 1; x++)
    {
        int u = min_Key(key, visited);

        visited[u] = true;  
        for (int v = 0; v < V; v++)
        {  
            if (cost[u][v] != 0 && visited[v] == false && cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }
    print_MST(parent, cost);
}
int main()
{
    setlocale(LC_ALL,"turkish");
    int cost[V][V] = { {0,4,2,0,0,0,0,0}, {4,0,3,8,0,0,5,10}, {2,3,0,3,1,0,0,0}, {0,8,3,0,1,1,4,0}, {0,0,1,1,0,2,0,0}, {0,0,0,1,2,0,3,0}, {0,5,0,4,0,3,0,5}, {0,10,0,0,0,0,5,0} };
    find_MST(cost);
    return 0;
}