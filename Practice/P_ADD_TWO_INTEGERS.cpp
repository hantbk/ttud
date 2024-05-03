#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

unsigned long long a, b, c, a1, a2, b1, b2, c1, c2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    a1 = a % 10;             
    b1 = b % 10;              
    c1 = (a1 + b1) % 10;      
    a2 = (a - a1) / 10;       
    b2 = (b - b1) / 10;       
    c2 = (a1 + b1 - c1) / 10; 
    c2 = a2 + b2 + c2;
    if (c2 > 0)
        cout << c2;
    cout << c1;

    return 0;
}