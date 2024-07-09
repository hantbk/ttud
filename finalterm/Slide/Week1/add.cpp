#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

unsigned long long a,b, a1, b1, a2, b2, c1, c2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b;
    a1 = a/10;
    a2 = a%10;
    b1 = b/10;
    b2 = b%10;
    c1 = a1 + b1 + (a2 + b2)/10;
    c2 = (a2 + b2)%10;
    if(c1 > 0) cout<<c1;
    cout<<c2;

    return 0;
}