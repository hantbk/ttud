/*
Bài toán cặp đoạn rời nhau cực đại
Có n đoạn 1,2,3,...,n nằm trên 1 đường thẳng. Đoạn i có toạ độ đầu mút trái là ai
và toạ độ đầu mút phải là bi. Một cặp đoạn rời nhau là 2 đoạn không giao nhau.
Hãy tìm 2 đoạn rời nhau sao cho tổng độ dài của chúng là lớn nhất.
Input
5
8 12
6 11
3 9
2 5
1 4
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009
#define pii pair<int, int>

int n;
int L[MAX]; // L[i] là độ dài đoạn dài nhất có toạ độ đầu mút phải nhỏ hơn hoặc bằng j
int R[MAX]; // R[i] là độ dài đoạn dài nhất có toạ độ đầu mút trái lớn hơn hoặc bằng j

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i <= n + 1; i++)
        L[i] = R[i] = -INF;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        L[b] = max(L[b], b - a);
        R[a] = max(R[a], b - a);
    }
    for (int i = 1; i <= n; i++)
        L[i] = max(L[i - 1], L[i]);
    for (int i = n; i >= 1; i--)
        R[i] = max(R[i], R[i + 1]);

    int ans = -INF;
    for (int i = 1; i <= n - 1; i++)
        ans = max(ans, L[i] + R[i + 1]);
    if (ans == -INF)
        ans = -1;
    cout << ans;

    return 0;
}