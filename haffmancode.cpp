#include <iostream>
#include <vector>
#include <string>
using namespace std;

class btnode
{
public:
    char ch;
    int data;
    btnode *lchild;
    btnode *rchild;
    btnode(char c1, int d1)
    {
        ch = c1;
        data = d1;
        lchild = nullptr;
        rchild = nullptr;
    }
    btnode(const btnode&bm)
    {
        ch = bm.ch;
        data = bm.data;
        lchild = bm.lchild;
        rchild = bm.rchild;
    }
};

void getsorted(vector<btnode> &v1)
{
    vector<btnode> sorted;
    sorted.push_back(v1[0]);
    for (int i = 1; i < v1.size(); i++)
    {
        int j = 0;
        while (j < sorted.size() && v1[i].data >= sorted[j].data)
        {
            j++;
        }
        sorted.insert(sorted.begin() + j, v1[i]);
    }
    v1 = sorted;
}

btnode *gethaffmantree(vector<btnode> &v1)
{
    while (v1.size() > 1)
    {
        getsorted(v1);
        btnode *b1, *b2, *bt;
        b1 = new btnode(v1[0]);
        b2 = new btnode(v1[1]);
        bt = new btnode('\0', b1->data + b2->data);
        bt->lchild = b1;
        bt->rchild = b2;
        v1.erase(v1.begin(), v1.begin() + 2);
        v1.push_back(*bt);
    }
    btnode *root = new btnode(v1[0]);
    return root;
}

void gethaffmancode(btnode *root, vector<char> chars, string code, vector<string> &vs)
{
    if (root == nullptr)
    {
        return;
    }
    if (!root->lchild && !root->rchild)
    {
        for (size_t i = 0; i < chars.size(); i++)
        {
            if (root->ch == chars[i])
            {
                vs[i] = code;
                break;
            }
        }
    }
    gethaffmancode(root->lchild, chars, code + "0", vs);
    gethaffmancode(root->rchild, chars, code + "1", vs);
}

int main()
{
    int n;
    cin >> n;
    vector<char> chars;
    vector<string> vs;
    vector<btnode> v1;
    for (int i = 0; i < n; i++)
    {
        char ch;
        int data;
        cin >> ch >> data;
        chars.push_back(ch);
        btnode t(ch, data);
        v1.push_back(t);
    }
    vs.resize(chars.size() + 100);
    btnode *root = gethaffmantree(v1);
    gethaffmancode(root, chars, "", vs);
    for (int i = 0; i < vs.size();i++)
    {
        cout << vs[i];
        if(i!=vs.size()-1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}