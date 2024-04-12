#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int a[MAX], n; // Chua cau hinh hien tai

void solution(){
    for (int i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// Sinh dan tung gia tri a[1], a[2], ..., a[k]
// void Try(int k){
//     // Da sinh du
//     if(k > n) solution();
//     else { // Chua sinh xong day
//         a[k] = 0; Try(k+1);
//         a[k] = 1; Try(k+1);
//     }
// }

void Try(int k){
    for (int v = 0; v <= 1; v++)
    {
        a[k] = v;
        if(k == n) solution();
        else Try(k + 1);
    }
}

int main(){
    cin>>n;
    Try(1);
}