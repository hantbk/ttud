#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[1009];
int F[1009]; // F[i] la tong lon nhat cua day con ket thuc tai a[i]

void dp(){
    int res = -INF;
    F[1] = a[1]; // truong hop co 1 phan tu
    for(int i = 2; i <= n; i++) F[i] = max(a[i], F[i-1] + a[i]);
    for(int i = 1; i <= n; i++) res = max(res, F[i]);
    cout<<res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i =1; i <= n; i++) cin>>a[i];
    dp();

    return 0;
}