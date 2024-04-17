/*
    Cho số tiền N, tìm số tờ tiền ít nhất để trả lại N
    Ví dụ: N = 123
    Kết quả: 1 tờ 100, 1 tờ 20, 3 tờ 1 
    
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 5

int c[MAX] = {100, 25, 10, 5, 1};
int a[MAX], n;

int main() {
    cout<< "N = "; cin>>n;
    for (int i = 0; i < MAX; i++)
    {
        a[i] = n / c[i];
        cout<< "So xu "<<c[i]<<": "<<a[i]<<endl;
        n = n - c[i] * a[i];
    }
    
    return 0;
}