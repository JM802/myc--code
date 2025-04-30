// #include<iostream>
// #include<vector>
// using namespace std;

// vector<vector<int>> yh(int n)
// {
//     vector<vector<int>> v1;
//     v1.resize(n);
//     for (int i = 0; i < n;i++)
//     {
//         v1[i].resize(i + 1);
//     }
//     for (int i = 0; i < n;i++)
//     {
//         v1[i][0] = 1;
//         v1[i][i] = 1;
//     }
//     for (int i = 0; i < n;i++)
//     {
//         for (int j = 1; j < i;j++)
//         {
//             v1[i][j] = v1[i - 1][j - 1] + v1[i - 1][j];
//         }
//     }
//     return v1;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> v1 = yh(n);
//     for (auto &m : v1)
//     {
//         for (auto &num : m)
//         {
//             cout << num << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }