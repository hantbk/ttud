#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[1009];
int F[1009]; // F[i] la độ dài dãy con tăng dài nhất kết thúc tại a[i]

void dp(){
    for(int i = 1; i <= n; i++) {
        F[i] = 1; 
        for(int j = 1; j < i; j++) {
            if(a[j] < a[i]) F[i] = max(F[i], F[j] + 1);
        }
    }
    int res = 0;
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