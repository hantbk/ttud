#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, m;
int a[1009];
int b[1009];

int intersec(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]) res++;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; 
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        cin >> m;
        for(int i = 1; i <= m; i++) cin >> b[i];
        cout << intersec() << endl;
    }

    return 0;
}