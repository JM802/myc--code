#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class btnode
{
public:
    char data;
    btnode *lchild;
    btnode *rchild;
    btnode(char c)
    {
        data = c;
        lchild = nullptr;
        rchild = nullptr;
    }
};

btnode*createmytree(vector<btnode*>v1,map<char,int>nodemaps,int instart,int inend,int&preindex)
{
    if(instart>inend)
    {
        return nullptr;
    }
    btnode *root = nullptr;
    if(preindex<v1.size())
    {
        root = v1[preindex++];
        int inindex = nodemaps[root->data];
        root->lchild = createmytree(v1, nodemaps, instart, inindex - 1, preindex);
        root->rchild = createmytree(v1, nodemaps, inindex + 1, inend, preindex);
    }
    return root;
}

void leveltranvans(btnode*root)
{
    queue<btnode *> q;
    q.push(root);
    while(!q.empty())
    {
        int levelsize = q.size();
        for (int i = 0; i < levelsize;i++)
        {
            btnode *cur = q.front();
            q.pop();
            if(cur)
            {
                cout << cur->data << " ";
                q.push(cur->lchild);
                q.push(cur->rchild);
            }
            else
            {
                cout << "null" << " ";
            }
        }
    }
}
int main()
{
    string prestr,instr;
    cin >> prestr>>instr;
    int n1 = prestr.size();
    vector<btnode *> v1(n1, nullptr);
    map<char, int> nodemaps;
    for (int i = 0; i < n1;i++)
    {
        v1[i] = new btnode(prestr[i]);
    }
    for (int i = 0; i < instr.size();i++)
    {
        nodemaps[instr[i]] = i;
    }
    int preindex = 0;
    btnode *root = createmytree(v1, nodemaps, 0, prestr.size()-1, preindex);
    leveltranvans(root);
    return 0;
}