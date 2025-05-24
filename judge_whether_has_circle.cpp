#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class arcnode
{
public:
    int adjver;
    arcnode *next;
    arcnode(int a)
    {
        adjver = a;
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
    int n, e;
    adjgraph(int n, int e)
    {
        this->n = n;
        this->e = e;
        hlist.resize(n);
    }

    void addedge(int from, int to)
    {
        arcnode *newnode = new arcnode(to);
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
        for (const auto &t : v1)
        {
            int from = t[0]-1;
            int to = t[1]-1;
            addedge(from, to);
        }
    }

    bool hascircle()
    {
        vector<int> v1(n, 0);
        queue<int> q1;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            arcnode *p = hlist[i].firstarc;
            while (p)
            {
                int w = p->adjver;
                v1[w]++;
                p = p->next;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (v1[i] == 0)
            {
                q1.push(i);
                count++;
            }
        }
        while (!q1.empty())
        {
            int m = q1.front();
            q1.pop();
            arcnode *p = hlist[m].firstarc;
            while (p)
            {
                int w = p->adjver;
                v1[w]--;
                if (v1[w]==0)
                {
                    q1.push(w);
                    count++;
                }
                p = p->next;
            }
        }
        if (count != n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    adjgraph g(n, e);
    vector<vector<int>> v1(e);
    for (int i = 0; i < e; i++)
    {
        int from, to;
        cin >> from >> to;
        v1[i].push_back(from);
        v1[i].push_back(to);
    }
    g.creategraph(v1);
    bool res = g.hascircle();
    if (res)
    {
        cout << "Yes" << endl;
        return 0;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}