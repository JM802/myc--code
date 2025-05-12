// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// using namespace std;

// class btnode
// {
// public:
//     char data;
//     btnode*lchild;
//     btnode *rchild;
//     btnode(char c)
//     {
//         data = c;
//         lchild = nullptr;
//         rchild = nullptr;
//     }
// };

// btnode* createmytree(const string&s)
// {
//     btnode *root=nullptr;
//     if(!isalpha(s[0]))
//     {
//         return nullptr;
//     }
//     int n = s.length();
//     vector<btnode *> v1(n, nullptr);
//     for (int i = 0; i < n;i++)
//     {
//         if(isalpha(s[i]))
//         {
//             v1[i] = new btnode(s[i]);
//         }
//     }
//     root = v1[0];
//     for (int i = 0; i < n;i++)
//     {
//         if(v1[i])
//         {
//             if((2*i+1<n)&&v1[2*i+1])
//             {
//                 v1[i]->lchild = v1[2 * i + 1];
//             }
//             if((2*i+2<n)&&v1[2*i+2])
//             {
//                 v1[i]->rchild = v1[2 * i + 2];
//             }
//         }
//     }
//     return root;
// }


// int getdepth(btnode*root)
// {
//     if(!root)
//     {
//         return 0;
//     }
//     else
//     {
//         int left = getdepth(root->lchild);
//         int right = getdepth(root->rchild);
//         return 1 + max(left, right);
//     }
// }

// int main()
// {
//     string s;
//     cin >> s;
//     btnode *root = createmytree(s);
//     int result = getdepth(root);
//     cout << result << endl;
//     return 0;
// }