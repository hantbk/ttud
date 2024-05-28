#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n, L1, L2;
int ans;
int a[MAX];
int S[MAX];   // S[i] là tổng số vàng nếu nhà kho i là nhà kho cuối cùng được chọn
deque<int> q; // q lưu trữ các chỉ số j sao cho S(j) không tăng và là ứng cử viên để tính toán S(i)

void mining_deque()
{
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && (q.front() < i - L2))
        {
            q.pop_front();
        }
        if (i - L1 >= 1)
        {
            while (!q.empty() && S[q.back()] < S[i - L1])
            {
                q.pop_back();
            }
            q.push_back(i - L1);
        }
        if(q.empty()){
            S[i] = a[i];
        } else S[i] = a[i] + S[q.front()];
        ans = max(ans, S[i]);
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    mining_deque();

    return 0;
}