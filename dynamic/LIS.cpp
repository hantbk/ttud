/*
Dãy con tăng dài nhất
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int res;
int a[1001];
int F[1001]; // F[i] là độ dài dãy con tăng dài nhất mà kết thúc tại phần tử thứ i

void dp()
{
    for (int i = 1; i <= n; i++)
    {
        F[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
                F[i] = max(F[i], 1 + F[j]);
        }
    }
}

// void Trace(int i)
// {
//     if (i == 0)
//         return;
//     for (int j = 1; j < i; j++)
//     {
//         if (F[i] == 1 + F[j] && a[i] > a[j])
//         {
//             Trace(j);
//             break;
//         }
//     }
//     cout << a[i] << " ";
// }

void Trace(int i){
    for(int j = i - 1; j >=1; j--){
        if(a[j] < a[i] && F[i] == 1 + F[j]){
            Trace(j);
            break;
        }
    }
    cout<<a[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp();
    int pos = 0;
    for (int i = 1; i <= n; i++){
        if(res < F[i]){
            res = F[i];
            pos = i;
        }
    }
    cout << res<<endl;
    Trace(pos);
        
    // for (int i = 1; i <= n; i++)
    // {
    //     if (F[i] == res)
    //     {
    //         Trace(i);
    //         break;
    //     }
    // }

    return 0;
}