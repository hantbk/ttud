/*
Bài toán dãy con giãn cách lớn nhất
Cho n phần tử 1,2,3,...,n nằm trên 1 đường thẳng, trong đó phần tử i nằm ở toạ độ
i và có trọng số ai. Cho 2 hằng số nguyên dương L1, L2 (L1 < L2). Hãy chọn ra
tập con các phần tử i1<i2<...<ik sao cho khoảng cách giữa 2 phần tử ij và ij+1
lớn hơn hoặc bằng L1 và nhỏ hơn hoặc bằng L2 và tổng trọng số của tập con này
lớn nhất.
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, L1, L2;
int S[MAX]; // S[i] là tổng trọng số của tập con lớn nhất của tập {1,2,...,i} thoả mãn điều kiện giãn cách
int a[MAX]; // a[i] là trọng số của phần tử i

void lss()
{
    int ans = 0;
    for (int i = 1; i <= L1; i++)
    {
        S[i] = a[i];
    }

    for (int i = L1 + 1; i <= n; i++)
    {
        for (int j = i - L2; j <= i - L1; j++)
        {
            S[i] = max(S[i], S[j] + a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, S[i]);
    }
    cout << ans << endl;
}

void lss_dq()
{
    deque<int> dq;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && dq.front() < i - L2)
            dq.pop_front();
        int j = i - L1;
        if (j >= 1)
        {
            while (!dq.empty() && S[dq.back()] < S[j])
                dq.pop_back();
            dq.push_back(j);
        }
        if (dq.empty())
        {
            S[i] = a[i];
        }
        else
        {
            S[i] = a[i] + S[dq.front()];
        }
        ans = max(ans, S[i]);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    lss();
    lss_dq();

    return 0;
}