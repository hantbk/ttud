#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009
#define pii pair<int, int>

int n, b;
pii items[100]; // items[i] = {value, weight}

// Greedy 1: Sort the items by value in decreasing order
bool compare1(pii a, pii b)
{
    return a.first > b.first;
}

int knapsack1(int capacity)
{

    int res = 0;

    sort(items, items + n, compare1);

    for (int i = 0; i < n; i++)
    {
        if (items[i].second <= capacity)
        {
            res += items[i].first;
            capacity -= items[i].second;
        }
    }

    return res;
}

// Greedy 2: Sort the items by weight in increasing order
bool compare2(pii a, pii b)
{
    return a.second < b.second;
}

int knapsack2(int capacity)
{

    int res = 0;

    sort(items, items + n, compare2);

    for (int i = 0; i < n; i++)
    {
        if (items[i].second <= capacity)
        {
            res += items[i].first;
            capacity -= items[i].second;
        }
    }

    return res;
}

// Greedy 3: Sort the items by value/weight in decreasing order
bool compare3(pii a, pii b)
{
    return (double)a.first / a.second > (double)b.first / b.second;
}

int knapsack3(int capacity)
{

    int res = 0;

    sort(items, items + n, compare3);

    for (int i = 0; i < n; i++)
    {
        if (items[i].second <= capacity)
        {
            res += items[i].first;
            capacity -= items[i].second;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b;
    for(int i = 0; i < n; i++)
    {
        cin >> items[i].first >> items[i].second;
    }

    int knapsack1_res = knapsack1(b);
    int knapsack2_res = knapsack2(b);
    int knapsack3_res = knapsack3(b);
    int knapsack4_res = max(knapsack1_res, max(knapsack2_res, knapsack3_res));

    cout<<"Greedy 1: "<<knapsack1_res<<"\n";
    cout<<"Greedy 2: "<<knapsack2_res<<"\n";
    cout<<"Greedy 3: "<<knapsack3_res<<"\n";
    cout<<"Greedy 4: "<<knapsack4_res<<"\n";

    return 0;
}