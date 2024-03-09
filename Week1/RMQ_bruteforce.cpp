#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1000000];
int sum = 0;

void rmq(int left, int right){
    int min = 1000000;
    for (int i = left; i <= right; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    sum += min;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    while (m--)
    {
        int left,right;
        cin>>left>>right;
        rmq(left, right);
    }
    cout<<sum;
    return 0;
}