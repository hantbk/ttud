#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int m,n;
int a[MAX], t[MAX]; // a[]: luu cau hinh, t[]: luu tong cua cau hinh

void solution(int k){
    for (int i = 1; i <= k; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Try(int k){
    for (int i = a[k-1] ; i <= (n - t[k-1])/2; i++)
    {
        a[k] = i;
        t[k] = t[k-1] + i;
        Try(k+1);
    }
    if (n - t[k-1] >= a[k-1]) // Neu con du de chon 1 so nua
    {
        a[k] = n - t[k-1];
        solution(k);
    }
}

int main() {
    cin>>n;
    a[0] = 1;
    t[0] = 0;
    Try(1);
    return 0;
}