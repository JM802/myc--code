#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class arcnode
{
public:
    int adjver;
    int weight;
    arcnode *next;
    arcnode(int a, int w)
    {
        adjver = a;
        weight = w;
        next = nullptr;
    }
};

class hnode
{
public:
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
    int n;
    int e;
    adjgraph(int n1, int e1)
    {
        n = n1;
        e = e1;
        hlist.resize(n);
        for (int i = 0; i < n; i++)
        {
            hlist[i].firstarc = nullptr;
        }
    }

    void addedge(int from, int to, int w)
    {
        arcnode *newnode = new arcnode(to, w);
        arcnode *cur = hlist[from].firstarc;
        if (!cur)
        {
            hlist[from].firstarc = newnode;
        }
        else
        {
            while (cur->next)
            {
                cur = cur->next;
            }
            cur->next = newnode;
        }
    }
    void createadjgraph(vector<vector<int>> v1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v1[i][j] != 0)
                {
                    addedge(i, j, v1[i][j]);
                }
            }
        }
    }

    int getpathlen(int start, int end)
    {
        int startsrc = start - 1;
        int endsrc = end - 1;
        vector<int> dis(n, INT_MAX);
        vector<bool> visited(n, false);
        dis[startsrc] = 0;
        for (int i = 0; i < n; i++)
        {
            int u = -1;
            int mindis = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (!visited[j] && dis[j] < mindis)
                {
                    u = j;
                    mindis = dis[j];
                }
            }
            if (u == -1)
            {
                break;
            }
            visited[u] = true;
            arcnode *p = hlist[u].firstarc;
            while (p)
            {
                int v = p->adjver;
                int w = p->weight;
                if (!visited[v] && w + dis[u] < dis[v])
                {
                    dis[v] = w + dis[u];
                }
                p = p->next;
            }
        }
        for (int i = 0; i <= endsrc; i++)
        {
            if (dis[i] == INT_MAX)
            {
                return -1;
            }
        }
        return dis[endsrc];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    adjgraph g(n, m);
    vector<vector<int>> v1(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            v1[i][j] = num;
        }
    }
    g.createadjgraph(v1);
    int start, end;
    cin >> start >> end;
    int res = g.getpathlen(start, end);
    cout << res << endl;
    return 0;
}
