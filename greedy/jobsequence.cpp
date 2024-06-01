#include <bits/stdc++.h>
using namespace std;
#define MAX 1000009

int n;
int d[MAX];
int p[MAX];
int a[MAX]; // Mảng a lưu vị trí của công việc

bool cmp(int i, int j)
{
    return p[i] > p[j];
}

void greedy()
{

    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }

    // Sắp xếp công việc theo thứ tự giảm dần của profit
    sort(a, a + n, cmp);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, d[a[i]]);
    }

    vector<int> schedule(maxDeadline, -1);

    int totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int jobIndex = a[i];
        int deadline = d[jobIndex];
        int profit = p[jobIndex];

        for (int t = deadline - 1; t >= 0; t--)
        {
            if (schedule[t] == -1)
            {
                schedule[t] = profit;
                totalProfit += profit;
                break;
            }
        }
    }

    cout << totalProfit << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i] >> p[i];
    }

    greedy();

    return 0;
}
