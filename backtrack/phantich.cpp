#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int m,n;
int a[MAX];

void solution(){
    for (int i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Try(int k, int p){
    if (k == n)
    {
        a[k] = m - p;
        solution();
        return;
    }
    int sum = 0;
    for (int i = 1; i <= m - p - n + k; i++)
    {
        a[k] = i;
        Try(k+1, p + i);
    }
}

int main() {
    cin>>m>>n;
    Try(1, 0);
    return 0;
}