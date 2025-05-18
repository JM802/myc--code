#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

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
    adjgraph(int n1)
    {
        n = n1;
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

    void creategraph(vector<vector<int>> v1)
    {
        for (int i = 0; i < v1.size(); i++)
        {
            int sz = v1[i][0];
            if (sz == 0)
            {
                continue;
            }
            else
            {
                for (int j = 1; j < 2 * sz; j += 2)
                {
                    int v = v1[i][j] - 1;
                    int w = v1[i][j + 1];
                    addedge(i, v, w);
                }
            }
        }
    }

    int dijkstra(int start)
    {
        vector<int> dis(n, INT_MAX);
        vector<bool> visited(n, false);
        dis[start] = 0;
        for (int i = 0; i < n; i++)
        {
            int mindis = INT_MAX;
            int u = -1;
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
        int mymax = 0;
        for (int i = 0; i < n; i++)
        {
            if (dis[i] == INT_MAX)
            {
                return INT_MAX;
            }
            mymax = max(mymax, dis[i]);
        }
        return mymax;
    }
};

int main()
{
    ifstream ifs("in.txt");
    int n;
    ifs >> n;
    ifs.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<vector<int>> v1(n);
    string s;
    for (int i = 0; i < n; i++)
    {
        if (getline(ifs, s))
        {
            istringstream ss(s);
            int num;
            while (ss >> num)
            {
                v1[i].push_back(num);
            }
        }
    }
    adjgraph g(n);
    g.creategraph(v1);
    int bestbrocker = 0;
    int besttime = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int res = g.dijkstra(i);
        if (res < besttime)
        {
            besttime = res;
            bestbrocker = i;
        }
    }
    if (besttime == INT_MAX)
    {
        cout << "disjoint" << endl;
    }
    else
    {
        cout << bestbrocker + 1 << " " << besttime << endl;
    }
    ifs.close();
    return 0;
}
