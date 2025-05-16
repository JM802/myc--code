#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<string> res;
class arcnode
{
public:
    int adjver;
    int weight;
    arcnode *next;
    arcnode(int v, int w)
    {
        adjver = v;
        weight = w;
        next = nullptr;
    }
};

class hnode
{
public:
    char data;
    arcnode *firstarc;
    hnode()
    {
        firstarc = nullptr;
    }
};

class adjgraph
{
public:
    vector<hnode> hlist;
    int n, e;
    adjgraph(int n1)
    {
        n = n1;
        e = 0;
        hlist.resize(n1);
        for (int i = 0; i < n1; i++)
        {
            hlist[i].firstarc = nullptr;
        }
    }

    void addedge(int from, int to, int weight)
    {
        arcnode *newnode = new arcnode(to, weight);
        if (!hlist[from].firstarc)
        {
            hlist[from].firstarc = newnode;
        }
        else
        {
            arcnode *p = hlist[from].firstarc;
            while (p->next)
            {
                p = p->next;
            }
            p->next = newnode;
        }
        e++;
    }

    void creategraph(vector<vector<int>> v1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v1[i][j] != 0 && v1[i][j] != INT_MAX)
                {
                    addedge(i, j, v1[i][j]);
                }
            }
        }
    }

    void display()
    {
        arcnode *p = nullptr;
        for (int i = 0; i < n; i++)
        {
            printf("[%d,%c]", i, hlist[i].data);
            p = hlist[i].firstarc;
            while (p)
            {
                printf("->[%d,%d]", p->adjver, p->weight);
                p = p->next;
            }
            cout << endl;
        }
    }
};

void dfs(adjgraph &g, int v, vector<bool> &visited, vector<string> &path, string &s)
{
    if (visited[v])
    {
        return;
    }
    visited[v] = true;
    s += g.hlist[v].data;
    if (s.length() == g.n)
    {
        path.push_back(s);
    }
    arcnode *p = g.hlist[v].firstarc;
    while (p)
    {
        int w = p->adjver;
        if (!visited[w])
        {
            dfs(g, w, visited, path, s);
        }
        p = p->next;
    }
    visited[v] = false;
    s.pop_back();
    return;
}

int main()
{
    int n1;
    cin >> n1;
    adjgraph g(n1);
    for (int i = 0; i < n1; i++)
    {
        char da;
        cin >> da;
        g.hlist[i].data = da;
    }
    vector<vector<int>> v1(n1, vector<int>(n1));
    vector<bool> visited(n1, false);
    vector<string> path;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            int num;
            cin >> num;
            v1[i][j] = num;
        }
    }
    g.creategraph(v1);
    string currentPath = "";
    dfs(g, 0, visited, path, currentPath);
    for (const auto &m : path)
    {
        cout << m << endl;
    }
    return 0;
}