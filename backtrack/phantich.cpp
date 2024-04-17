/*
Cho số nguyên dương m và n. 
Hãy liệt kê tất cả các cách phân tích số m thành tổng của n số nguyên dương.
Input:  6 3
Output: 1 1 4
        1 2 3
        1 3 2
        1 4 1
        2 1 3
        2 2 2
        2 3 1
        3 1 2
        3 2 1
        4 1 1
*/

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