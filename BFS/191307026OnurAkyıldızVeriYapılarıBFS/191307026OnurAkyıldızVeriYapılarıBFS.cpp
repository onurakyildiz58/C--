//onur akyıldız 191307026
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#include <list>
string node[6] = {"A","B","C","D","E","F"};
class Graph
{
    int V; 
    list<int>* adj;
    void DFSfonk(int v, bool ziyaretedilmiş[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int q);//queue
    void DFS(int s);//stack
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::BFS(int q)
{
    bool* ziyaretEdilmiş = new bool[V];
    for (int i = 0; i < V; i++)
    {
        ziyaretEdilmiş[i] = false;
    }

    list<int> queue;
    ziyaretEdilmiş[q] = true;
    queue.push_back(q);

    list<int>::iterator i;
    while (!queue.empty())
    {
        q = queue.front();
        if (q==0)
        {
            cout << node[q] << " ";
        }
        else if (q == 1)
        {
            cout << node[q] << " ";
        }
        else if (q == 2)
        {
            cout << node[q] << " ";
        }
        else if (q == 3)
        {
            cout << node[q] << " ";
        }
        else if (q == 4)
        {
            cout << node[q] << " ";
        }
        else if (q == 5)
        {
            cout << node[q]<<" ";
        }
      
        queue.pop_front();

        for (i = adj[q].begin(); i != adj[q].end(); ++i)
        {
            if (!ziyaretEdilmiş[*i])
            {
                ziyaretEdilmiş[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
void Graph::DFSfonk(int v, bool ziyaretedilmiş[])
{
    ziyaretedilmiş[v] = true;
    if (v == 0)
    {
        cout << node[v] << " ";
    }
    else if (v == 1)
    {
        cout << node[v] << " ";
    }
    else if (v == 2)
    {
        cout << node[v] << " ";
    }
    else if (v == 3)
    {
        cout << node[v] << " ";
    }
    else if (v == 4)
    {
        cout << node[v] << " ";
    }
    else if (v == 5)
    {
        cout << node[v] << " ";
    }

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!ziyaretedilmiş[*i])
        {
            DFSfonk(*i, ziyaretedilmiş);
        }
    }          
}
void Graph::DFS(int s)
{
    bool* ziyaret = new bool[V];
    for (int i = 0; i < V; i++)
    {
        ziyaret[i] = false;
    }
    DFSfonk(s, ziyaret);
}
int main()
{
    setlocale(LC_ALL,"turkish");
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.addEdge(4, 2);
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 2);
    g.addEdge(5, 4);

    cout << "BFS traverse B kökünden başlayarak\n";
    g.BFS(1);
    cout << endl;
    cout << endl;
    cout << "DFS traverse B kökünden başlayarak\n";
    g.DFS(1);
    cout << endl;

    return 0;
}