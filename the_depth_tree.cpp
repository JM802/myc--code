// #include<iostream>
// #include<vector>
// #include<map>
// #include<stack>
// #include<cctype>
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

// btnode* createmytree(const string&s)
// {
//     btnode *root = nullptr;
//     bool isleft=true;
//     stack<btnode *> st;
//     btnode *r;
//     for(const char& c:s)
//     {
//         if(isalpha(c))
//         {
//             r = new btnode(c);
//             if(!root)
//             {
//                 root = r;
//             }
//             else
//             {
//                 if(!st.empty())
//                 {
//                     if(isleft)
//                     {
//                         st.top()->lchild = r;
//                     }
//                     else
//                     {
//                         st.top()->rchild = r;
//                     }
//                 }
//             }
//         }
//         else if(c=='(')
//         {
//             st.push(r);
//             isleft = true;
//         }
//         else if(c==',')
//         {
//             isleft = false;
//         }
//         else
//         {
//             st.pop();
//         }
//     }
//     return root;
// }

// void getmaxdepth(int depth,btnode*root,int &result)
// {
//     if(!root)
//     {
//         return;
//     }
//     else
//     {
//         depth++;
//         if(!root->lchild&&!root->rchild)
//         {
//             result = max(result, depth);
//         }
//         getmaxdepth(depth, root->lchild, result);
//         getmaxdepth(depth, root->rchild, result);
//         depth--;
//     }
// }
// int main()
// {
//     string s;
//     cin >> s;
//     int result=0;
//     btnode*root=createmytree(s);
//     getmaxdepth(0, root, result);
//     cout << result << endl;
//     return 0;
// }