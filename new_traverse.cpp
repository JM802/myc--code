#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

class btnode
{
public:
    char data;
    btnode *lchild;
    btnode *rchild;
    btnode(char d) : data(d), lchild(nullptr), rchild(nullptr) {}
};

btnode* createtree(const string&s)
{
    stack<btnode *> st;
    btnode *root=nullptr;
    bool isleft;
    btnode *p;
    for (int i = 0; i < s.size();i++)
    {
        if(isalpha(s[i]))
        {
            p = new btnode(s[i]);
            if(!root)
            {
                root = p;
            }
            else
            {
                if(isleft)
                {
                    st.top()->lchild = p;
                }
                else
                {
                    st.top()->rchild = p;
                }
            }
        }
        else if(s[i]=='(')
        {
            st.push(p);
            isleft = true;
        }
        else if(s[i]==',')
        {
            isleft = false;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}

void preorder(btnode*root)
{
    if(root)
    {
        cout << root->data << endl;
        preorder(root->lchild);
        preorder(root->rchild);
    }   
    else
    {
        return;
    }
}

int main()
{
    string s;
    cin >> s;
    btnode *root = createtree(s);
    preorder(root);
    return 0;
}
