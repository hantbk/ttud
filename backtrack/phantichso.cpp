/*
Cho số nguyên dương n. 
Hãy liệt kê tất cả các cách phân tích n thành tổng các số nguyên dương.
Input:  6
Output: 1 1 1 1 1 1
        1 1 1 1 2
        1 1 1 3
        1 1 2 2
        1 1 4
        1 2 3
        1 5
        2 2 2
        2 4
        3 3
        6
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int m,n;
int a[MAX], t[MAX]; // a[]: luu cau hinh, t[]: luu tong cua cau hinh

void solution(int k){
    for (int i = 1; i <= k; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Try(int k){
    for (int i = a[k-1] ; i <= (n - t[k-1])/2; i++)
    {
        a[k] = i;
        t[k] = t[k-1] + i;
        Try(k+1);
    }
    if (n - t[k-1] >= a[k-1]) // Neu con du de chon 1 so nua
    {
        a[k] = n - t[k-1];
        solution(k);
    }
}

int main() {
    cin>>n;
    a[0] = 1;
    t[0] = 0;
    Try(1);
    return 0;
}