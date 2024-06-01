#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

struct Treasure{
    ll x,y;
    ll c;
};

ll n;
Treasure a[MAX];
ll F[MAX]; // F[i] là tổng lượng vàng lớn nhất khi lấy đến kho i

bool compare(Treasure a, Treasure b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

void dp(){
    
    sort(a + 1, a + n + 1, compare);
    
    for(int i = 1; i <= n; i++){
        F[i] = a[i].c;

        for(int j = 1; j < i; j++){
            if(a[j].x <= a[i].x && a[j].y <= a[i].y){
                F[i] = max(F[i], F[j] + a[i].c);
            }
        }
    }
    ll res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, F[i]);
    }
    cout<<res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++) 
        cin>>a[i].x>>a[i].y>>a[i].c;

    dp();

    return 0;
}