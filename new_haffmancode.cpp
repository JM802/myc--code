#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class btnode
{
public:
    int data;
    char ch;
    btnode *lchild;
    btnode *rchild;
    btnode(char c, int d)
    {
        ch = c;
        data = d;
        lchild = nullptr;
        rchild = nullptr;
    }
};

void sortmyvec(vector<btnode *> &v1)
{
    vector<btnode *> sorted;
    sorted.push_back(v1[0]);
    for (size_t i = 1; i < v1.size(); i++)
    {
        int j = 0;
        while (j < sorted.size() && sorted[j]->data < v1[i]->data)
        {
            j++;
        }
        sorted.insert(sorted.begin() + j, v1[i]);
    }
    v1 = sorted;
}

btnode *createmytree(vector<btnode *> &v1)
{
    btnode *root = nullptr;
    while (v1.size() > 1)
    {
        sortmyvec(v1);
        btnode *b1 = v1[0];
        btnode *b2 = v1[1];
        btnode *b3 = new btnode('\0', b1->data + b2->data);
        b3->lchild = b1;
        b3->rchild = b2;
        v1.erase(v1.begin(), v1.begin() + 2);
        v1.push_back(b3);
    }
    root = v1[0];
    return root;
}

vector<string> myhaffmancode(btnode *root, string st)
{
    vector<string> mycode;
    if(!root->lchild&&!root->rchild)
    {
        mycode.push_back(st);
        return mycode;
    }
    else
    {
        vector<string> leftcode = myhaffmancode(root->lchild, st + '0');
        vector<string> rightcode = myhaffmancode(root->rchild, st + '1');
        mycode.insert(mycode.end(), leftcode.begin(), leftcode.end());
        mycode.insert(mycode.end(), rightcode.begin(), rightcode.end());
    }
    return mycode;
}


int main()
{
    int n;
    cin >> n;
    vector<btnode *> v1;
    for (int i = 0; i < n;i++)
    {
        char ch;
        int data;
        cin >> ch>>data;
        btnode *t = new btnode(ch, data);
        v1.emplace_back(t);
    }
    btnode *root = createmytree(v1);
    vector<string> result = myhaffmancode(root, "");
    for_each(result.begin(), result.end(), [](string s)
             { cout << s << " "; });
    cout << endl;
    return 0;
}
