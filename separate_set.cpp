// #include<iostream>
// using namespace std;

// int separate_set(int n,int k)
// {
//     if(k==0||n<k)
//     {
//         return 0;
//     }
//     if(k==1||k==n)
//     {
//         return 1;
//     }
//     else
//     {
//         return separate_set(n - 1, k - 1) + k * separate_set(n - 1, k);
//     }
// }

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     int result=separate_set(n, k);
//     cout << result << endl;
// }