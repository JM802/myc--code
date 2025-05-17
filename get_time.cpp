#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
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
    arcnode()
    {
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
    int e;
    int n;
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
        e++;
    }
    void creategraph(vector<vector<int>> v1)
    {
        for (auto &edge : v1)
        {
            int from = edge[0] - 1;
            int to = edge[1] - 1;
            int weight = edge[2];
            addedge(from, to, weight);
        }
    }

    int gettime(int k)
    {
        vector<bool> visited(n, false);
        vector<int> dis(n, INT_MAX);
        int src = k - 1;
        dis[src] = 0;
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
                if (!visited[v] && (w + dis[u] < dis[v]))
                {
                    dis[v] = w + dis[u];
                }
                p = p->next;
            }
        }
        int maxtime = 0;
        for (const auto &m : dis)
        {
            if (m == INT_MAX)
            {
                return -1;
            }
            else
            {
                maxtime = max(m, maxtime);
            }
        }
        return maxtime;
    }
};

int main()
{
    ifstream ifs("in.txt");
    int n, k;
    ifs >> n >> k;
    vector<vector<int>> v1;
    int u, v, w;
    while (ifs >> u >> v >> w)
    {
        v1.push_back({u, v, w});
    }
    adjgraph g(n);
    g.creategraph(v1);
    int res = g.gettime(k);
    cout << res << endl;
    ifs.close();
    return 0;
}
