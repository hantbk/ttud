/*
    Given an integer n, 
    write a program that generates all the binary sequences of length n in a lexicographic order.
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[100];

void solution() {
    for (int i = 1; i <= n; i++)
    {
        cout<<a[i];
    }
    cout<<endl;

}

void Try(int k){
    for (int i = 0; i <= 1; i++)
    {
        a[k] = i;
        if(k == n) solution();
        else Try(k+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    Try(1);

    return 0;
}