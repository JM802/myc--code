#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

class btnode
{
public:
    int data;
    btnode *lchild;
    btnode *rchild;
    btnode(int d)
    {
        data = d;
        lchild = nullptr;
        rchild = nullptr;
    }
};

class mytree
{
public:
    btnode *root;
    mytree()
    {
        root = nullptr;
    }

    btnode *createmytree(vector<string> v1)
    {
        int n = v1.size();
        vector<btnode *> vnode;
        for (int i = 0; i < n; i++)
        {
            if (v1[i] != "null")
            {
                vnode.push_back(new btnode(stoi(v1[i])));
            }
            else
            {
                vnode.push_back(nullptr);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                root = vnode[0];
            }
            if (vnode[i])
            {
                if (2 * i + 1 < n && vnode[2 * i + 1])
                {
                    vnode[i]->lchild = vnode[2 * i + 1];
                }
                if (2 * i + 2 < n && vnode[2 * i + 2])
                {
                    vnode[i]->rchild = vnode[2 * i + 2];
                }
            }
        }
        return root;
    }

    int getdepth(btnode *r)
    {
        if (!r)
        {
            return 0;
        }
        else
        {
            int l = getdepth(r->lchild);
            int r1 = getdepth(r->rchild);
            return max(l, r1) + 1;
        }
    }

    bool judge_if_avltree()
    {
        if (!root)
        {
            return true;
        }
        queue<btnode *> q;
        q.push(root);
        while (!q.empty())
        {
            int a = 0, b = 0;
            btnode *m = q.front();
            q.pop();
            if (m->lchild)
            {
                q.push(m->lchild);
                a = getdepth(m->lchild);
            }
            else
            {
                a = 0;
            }
            if (m->rchild)
            {
                q.push(m->rchild);
                b = getdepth(m->rchild);
            }
            else
            {
                b = 0;
            }
            if (abs(a - b) > 1)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    ifstream ifs("in.txt");
    mytree t;
    vector<string> v1;
    string s;
    while (ifs >> s)
    {
        v1.push_back(s);
    }
    t.createmytree(v1);
    bool res = t.judge_if_avltree();
    ofstream ofs("out.txt");
    if (res)
    {
        ofs << "True" << endl;
    }
    else
    {
        ofs << "False" << endl;
    }
    return 0;
}