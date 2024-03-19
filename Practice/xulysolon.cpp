#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e+7
#define INF 1e+18
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    unsigned long long a,b,c,a0,a1,b0,b1,c0,c1;
    cin>>a>>b;
    
    a0 = a%10;
    a1 = (a - a0)/10;
    b0 = b%10;
    b1 = (b - b0)/10;
    c0 = (a0 + b0)%10;
    c1 = (a0 + b0 -c0)/10;
    c1 = a1 + b1 + c1;
    if (c1 > 0) cout<<c1;
    cout<<c0;

    return 0;
}
