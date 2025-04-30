// #include<iostream>
// #include<queue>
// #include<algorithm>
// using namespace std;

// class btnode
// {
// public:
//     char data;
//     btnode *lchild;
//     btnode *rchild;
//     btnode(char d)
//     {
//         data = d;
//         lchild = nullptr;
//         rchild = nullptr;
//     }
// };

// btnode* createmytree(const string&s)
// {
//     int i = 1;
//     btnode *root = nullptr;
//     root = new btnode(s[0]);
//     queue<btnode *> q;
//     q.push(root);
//     int n = s.length();
//     while(!q.empty()&&i<n)
//     {
//         btnode *cur = q.front();
//         q.pop();
//         if(isalpha(s[i]))
//         {
//             cur->lchild = new btnode(s[i]);
//             q.push(cur->lchild);
//         }
//         i++;
//         if(i<n&&isalpha(s[i]))
//         {
//             cur->rchild = new btnode(s[i]);
//             q.push(cur->rchild);
//         }
//         i++;
//     }
//     return root;
// }

// void traverse_level(btnode*root)
// {
//     queue<btnode *> q;
//     q.push(root);
//     while(!q.empty())
//     {
//         btnode *cur = q.front();
//         q.pop();
//         if(cur)
//         {
//             cout << cur->data << " ";
//             if(cur->lchild)
//             {
//                 q.push(cur->lchild);
//             }
//             if(cur->rchild)
//             {
//                 q.push(cur->rchild);
//             }
//         }
//     }
//     cout << endl;
// }

// int main()
// {
//     string s;
//     cin >> s;
//     btnode *root = createmytree(s);
//     traverse_level(root);
//     return 0;
// }