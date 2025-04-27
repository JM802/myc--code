// #include <iostream>
// #include <vector>
// #include <string>
// #include <fstream>
// #include <sstream>
// #include <queue>
// #include <algorithm>
// using namespace std;

// class btnode
// {
// public:
//     int data;
//     btnode *lchild;
//     btnode *rchild;
//     btnode *parent;
//     btnode(int d)
//     {
//         data = d;
//         lchild = nullptr;
//         rchild = nullptr;
//         parent = nullptr;
//     }
// };

// btnode *createtree(const string &input)
// {
//     vector<btnode *> nodes;
//     istringstream ss(input.substr(1, input.length() - 2));
//     string token;
//     while (getline(ss, token, ','))
//     {
//         if (token == "#")
//         {
//             nodes.push_back(nullptr);
//         }
//         else
//         {
//             nodes.push_back(new btnode(stoi(token)));
//         }
//     }
//     int n = nodes.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (nodes[i])
//         {
//             if (2 * i + 1 < n)
//             {
//                 nodes[i]->lchild = nodes[2 * i + 1];
//                 if (nodes[2 * i + 1])
//                 {
//                     nodes[2 * i + 1]->parent = nodes[i];
//                 }
//             }
//             if (2 * i + 2 < n)
//             {
//                 nodes[i]->rchild = nodes[2 * i + 2];
//                 if (nodes[2 * i + 2])
//                 {
//                     nodes[2 * i + 2]->parent = nodes[i];
//                 }
//             }
//         }
//     }
//     return nodes[0];
// }

// btnode *findtarget(btnode *root, int target)
// {
//     if (!root)
//     {
//         return nullptr;
//     }
//     if (root->data == target)
//     {
//         return root;
//     }
//     btnode *left = findtarget(root->lchild, target);
//     if (left)
//     {
//         return left;
//     }
//     return findtarget(root->rchild, target);
// }

// vector<int> finddistancek(btnode *target, int k)
// {
//     vector<int> result;
//     queue<pair<btnode *, int>> q;
//     q.push(make_pair(target, 0));
//     vector<btnode *> visit;
//     while (!q.empty())
//     {
//         auto [node, dis] = q.front();
//         q.pop();
//         if (find(visit.begin(), visit.end(), node) != visit.end())
//         {
//             continue;
//         }
//         visit.push_back(node);
//         if (dis == k)
//         {
//             result.push_back(node->data);
//             continue;
//         }
//         if (node->lchild)
//         {
//             q.push(make_pair(node->lchild, dis + 1));
//         }
//         if (node->rchild)
//         {
//             q.push(make_pair(node->rchild, dis + 1));
//         }
//         if (node->parent)
//         {
//             q.push(make_pair(node->parent, dis + 1));
//         }
//     }
//     return result;
// }

// int main()
// {
//     ifstream ifs("in.txt");
//     string input;
//     int target;
//     int k;
//     getline(ifs, input);
//     ifs >> target;
//     ifs >> k;
//     btnode *root = createtree(input);
//     btnode *targetnode = findtarget(root, target);
//     vector<int> result = finddistancek(targetnode, k);
//     cout << "[";
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i];
//         if (i < result.size() - 1)
//         {
//             cout << ",";
//         }
//     }
//     cout << "]";
//     cout << endl;
//     return 0;
// }
