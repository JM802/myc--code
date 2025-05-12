// #include <iostream>
// #include <vector>
// #include <string>
// #include <queue>
// #include <algorithm>
// #include <map>
// #include <fstream>
// #include <sstream>
// using namespace std;

// class btnode
// {
// public:
//     char data;
//     btnode *lchild;
//     btnode *rchild;
//     btnode(char c)
//     {
//         data = c;
//         lchild = nullptr;
//         rchild = nullptr;
//     }
// };

// btnode *createmytree(int n, vector<vector<char>> v1)
// {
//     btnode *root = nullptr;
//     btnode *cur, *curl, *curr;
//     map<char, btnode *> nodemaps;
//     if (!isalpha(v1[0][0]))
//     {
//         return nullptr;
//     }
//     else
//     {
//         btnode *x = new btnode(v1[0][0]);
//         root = x;
//         nodemaps[v1[0][0]] = x;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (isalpha(v1[i][0]))
//         {
//             if (nodemaps.find(v1[i][0]) == nodemaps.end())
//             {
//                 cur = new btnode(v1[i][0]);
//                 nodemaps[v1[i][0]] = cur;
//             }
//             else
//             {
//                 cur = nodemaps[v1[i][0]];
//             }
//         }
//         if (isalpha(v1[i][1]))
//         {
//             if (nodemaps.find(v1[i][1]) == nodemaps.end())
//             {
//                 curl = new btnode(v1[i][1]);
//                 nodemaps[v1[i][1]] = curl;
//             }
//             else
//             {
//                 curl = nodemaps[v1[i][1]];
//             }
//             cur->lchild = curl;
//         }
//         if (isalpha(v1[i][2]))
//         {
//             if (nodemaps.find(v1[i][2]) == nodemaps.end())
//             {
//                 curr = new btnode(v1[i][2]);
//                 nodemaps[v1[i][2]] = curr;
//             }
//             else
//             {
//                 curr = nodemaps[v1[i][2]];
//             }
//             cur->rchild = curr;
//         }
//     }
//     return root;
// }

// void leveltravanse(btnode *root)
// {
//     queue<btnode *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         btnode *cur = q.front();
//         q.pop();
//         cout << cur->data << " ";
//         if (cur->lchild)
//         {
//             q.push(cur->lchild);
//         }
//         if (cur->rchild)
//         {
//             q.push(cur->rchild);
//         }
//     }
// }

// void getdepth(btnode *root, int depth, int &result)
// {
//     if (!root)
//     {
//         return;
//     }
//     depth++;
//     if (!root->lchild && !root->rchild)
//     {
//         result = max(depth, result);
//     }
//     getdepth(root->lchild, depth, result);
//     getdepth(root->rchild, depth, result);
//     depth--;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<char>> v1(n);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             char data;
//             cin >> data;
//             v1[i].push_back(data);
//         }
//     }
//     btnode *root = createmytree(n, v1);
//     leveltravanse(root);
//     int result = 0;
//     getdepth(root, 0, result);
//     cout << endl;
//     cout << result << endl;
//     return 0;
// }