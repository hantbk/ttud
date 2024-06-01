#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
struct Job
{
    int deadline;
    int profit;
};

vector<Job> jobs;

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

void greedy()
{
    sort(jobs.begin(), jobs.end(), cmp);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);

    vector<int> schedule(maxDeadline, -1);

    int totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int deadline = jobs[i].deadline;
        int profit = jobs[i].profit;

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
    cout<<totalProfit<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    jobs.resize(n);
    for (int i = 0; i < n; i++)
        cin >> jobs[i].deadline >> jobs[i].profit;

    greedy();

    return 0;
}