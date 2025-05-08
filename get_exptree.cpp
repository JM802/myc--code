#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cctype>
#include <vector>
#include <iterator>
using namespace std;

class btnode
{
public:
    char data;
    btnode *left;
    btnode *right;
    btnode(char c)
    {
        data = c;
        left = nullptr;
        right = nullptr;
    }
};

int getprior(char c1)
{
    if (c1 == '*' || c1 == '/')
    {
        return 2;
    }
    else if (c1 == '+' || c1 == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

btnode *createmytree(const string &s)
{
    stack<char> operators;
    stack<btnode *> oprands;
    for (char c : s)
    {
        if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                char r = operators.top();
                operators.pop();
                btnode *right1 = oprands.top();
                oprands.pop();
                btnode *left1 = oprands.top();
                oprands.pop();
                btnode *cur = new btnode(r);
                cur->left = left1;
                cur->right = right1;
                oprands.push(cur);
            }
            operators.pop();
        }
        else if (isalnum(c))
        {
            oprands.emplace(new btnode(c));
        }
        else
        {
            while (!operators.empty() && operators.top() != '(' && getprior(operators.top()) >= getprior(c))
            {
                char r = operators.top();
                operators.pop();
                btnode *right1 = oprands.top();
                oprands.pop();
                btnode *left1 = oprands.top();
                oprands.pop();
                btnode *cur = new btnode(r);
                cur->left = left1;
                cur->right = right1;
                oprands.push(cur);
            }
            operators.push(c);
        }
    }
    while (!operators.empty())
    {
        char r = operators.top();
        operators.pop();
        btnode *right1 = oprands.top();
        oprands.pop();
        btnode *left1 = oprands.top();
        oprands.pop();
        btnode *cur = new btnode(r);
        cur->left = left1;
        cur->right = right1;
        oprands.push(cur);
    }
    return oprands.top();
}

int getval(btnode *root)
{
    if (!root)
    {
        return 0;
    }
    if (isdigit(root->data))
    {
        return (root->data - '0');
    }
    else if (isalpha(root->data))
    {
        return static_cast<int>(root->data);
    }
    else
    {
        int l = getval(root->left);
        int r = getval(root->right);
        switch (root->data)
        {
        case '+':
            return l + r;
            break;
        case '-':
            return l - r;
            break;
        case '*':
            return l * r;
            break;
        case '/':
            return l / r;
            break;
        }
    }
}

vector<char> reverseleveltraverse(btnode *root)
{
    queue<btnode *> q;
    q.push(root);
    vector<char> result;
    while (!q.empty())
    {
        btnode *cur = q.front();
        q.pop();
        result.push_back(cur->data);
        if (cur->left)
        {
            q.push(cur->left);
        }
        if (cur->right)
        {
            q.push(cur->right);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int getlevelval(const vector<char> &result)
{
    queue<int> q;
    for (char c : result)
    {
        if (isalnum(c))
        {
            if (isdigit(c))
            {
                q.push(c - '0');
            }
            if (isalpha(c))
            {
                q.push(static_cast<int>(c));
            }
        }
        else
        {
            int a = q.front();
            q.pop();
            int b = q.front();
            q.pop();
            switch (c)
            {
            case '+':
                q.push(b + a);
                break;
            case '-':
                q.push(b - a);
                break;
            case '*':
                q.push(b * a);
                break;
            case '/':
                q.push(b / a);
                break;
            }
        }
    }
    return q.front();
}

int main()
{
    string s;
    cin >> s;
    btnode *root = createmytree(s);
    int result1 = getval(root);
    cout << result1 << endl;
    vector<char> res = reverseleveltraverse(root);
    for_each(res.begin(), res.end(), [](char c)
             { cout << c; });
    cout << endl;
    int result2 = getlevelval(res);
    cout << result2 << endl;
    return 0;
}