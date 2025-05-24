#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class btnode
{
public:
    int data;
    int index;
    int depth;
    btnode *lchild;
    btnode *rchild;
    btnode(int da, int i, int dep)
    {
        data = da;
        index = i;
        depth = dep;
        rchild = nullptr;
        lchild = nullptr;
    }
};

class bst
{
public:
    btnode *root;
    bst()
    {
        root = nullptr;
    }
    btnode *insertnode(btnode *p, int d, int i, int currentdepth)
    {
        if (p == nullptr)
        {
            p = new btnode(d, i, currentdepth);
        }
        else if (i < p->index)
        {
            p->lchild = insertnode(p->lchild, d, i, currentdepth + 1);
        }
        else if (i > p->index)
        {
            p->rchild = insertnode(p->rchild, d, i, currentdepth + 1);
        }
        else
        {
            p->data = d;
        }
        return p;
    }

    btnode *createbstree(vector<int> myindex, vector<int> mydata)
    {
        root = new btnode(mydata[0], myindex[0], 1);
        for (int i = 1; i < myindex.size(); i++)
        {
            insertnode(root, mydata[i], myindex[i], 1);
        }
        return root;
    }

    double get_success_avl()
    {
        int countv = 0;
        int countn = 0;
        queue<btnode *> q1;
        q1.push(root);
        while (!q1.empty())
        {
            int sz = q1.size();
            for (int i = 0; i < sz; i++)
            {
                btnode *p = q1.front();
                q1.pop();
                countn++;
                countv += p->depth;
                if (p->lchild)
                {
                    q1.push(p->lchild);
                }
                if (p->rchild)
                {
                    q1.push(p->rchild);
                }
            }
        }
        return double(countv) / countn;
    }

    double get_fail_avl()
    {
        int countv = 0;
        int countn = 0;
        queue<btnode *> q1;
        q1.push(root);
        while (!q1.empty())
        {
            int sz = q1.size();
            for (int i = 0; i < sz; i++)
            {
                btnode *p = q1.front();
                q1.pop();
                if (p->lchild)
                {
                    q1.push(p->lchild);
                }
                if (!p->lchild)
                {
                    countn++;
                    countv += p->depth;
                }
                if (p->rchild)
                {
                    q1.push(p->rchild);
                }
                if (!p->rchild)
                {
                    countn++;
                    countv += p->depth;
                }
            }
        }
        return double(countv) / countn;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> myindex(n);
    vector<int> mydata(n);
    for (int i = 0; i < n; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        mydata[i] = num1;
        myindex[i] = num2;
    }
    bst mytree;
    mytree.createbstree(myindex, mydata);
    double res = mytree.get_success_avl();
    double res1 = mytree.get_fail_avl();
    cout << res << " " << res1 << endl;
    return 0;
}