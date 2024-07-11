#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAX = 20;

int N, M;
int c[MAX];
vector<vector<int>> A;
int course[MAX];
int maxLoadAllPeriods = 0;
int minAll = INF;
int loadOfPeriods[MAX];

void inputData()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
    }
    A.resize(N + 1);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            if (temp != 0)
                A[j].push_back(i);
        }
    }
}

bool check(int a, int i)
{
    // Kiểm tra khóa học a, kì i
    for (int j = 0; j < A[a].size(); j++)
    {
        if (course[A[a].at(j)] == i)
            return false;
    }
    return true;
}

void solution()
{
    minAll = min(minAll, maxLoadAllPeriods);
}

void TryBACP(int a)
{
    for (int i = 0; i < M; i++)
    {
        if (check(a, i))
        {
            course[a] = i; // Khóa học a chỉ định vào kì i
            loadOfPeriods[i] += c[a];
            int pre = maxLoadAllPeriods;
            maxLoadAllPeriods = max(maxLoadAllPeriods, loadOfPeriods[i]);

            if (a == N)
                solution();
            else
            {
                if (maxLoadAllPeriods < minAll)
                    TryBACP(a + 1);
            }

            maxLoadAllPeriods = pre;
            loadOfPeriods[i] -= c[a];
        }
    }
}

int main(int argc, const char **argv)
{
    inputData();
    TryBACP(0);
    cout << minAll;
    return 0;
}