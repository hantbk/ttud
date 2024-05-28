#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int n, b;
pii items[100]; // first: value, second: weight

// Greedy 1: Sắp xếp các đồ vật theo thứ tự không tăng của giá trị
bool compare1(pii a, pii b)
{
    return a.first > b.first;
}

int knapsack1(int capacity)
{
    sort(items, items + n, compare1);

    int final_value = 0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].second <= capacity)
        {
            final_value += items[i].first;
            capacity -= items[i].second;
        }
    }
    return final_value;
}

// Greedy 2: Sắp xếp các đồ vật theo thứ tự không giảm của trọng lượng
bool compare2(pii a, pii b)
{
    return a.second < b.second;
}

int knapsack2(int capacity)
{
    sort(items, items + n, compare2);

    int final_value = 0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].second <= capacity)
        {
            final_value += items[i].first;
            capacity -= items[i].second;
        }
    }
    return final_value;
}

// Greedy 3: Sắp xếp các đồ vật theo thứ tự không tăng của giá trị một đơn vị trọng lượng (C[i]/W[i)
bool compare3(pii a, pii b)
{
    return (1.0 * a.first / a.second) > (1.0 * b.first / b.second);
}

int knapsack3(int capacity)
{
    sort(items, items + n, compare3);

    int final_value = 0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].second <= capacity)
        {
            final_value += items[i].first;
            capacity -= items[i].second;
        }
    }
    return final_value;
}

int main()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].first >> items[i].second;
    }

    int max1 = knapsack1(b);
    int max2 = knapsack2(b);
    int max3 = knapsack3(b);

    cout << "Greedy 1: " << max1 << endl;
    cout << "Greedy 2: " << max2 << endl;
    cout << "Greedy 3: " << max3 << endl;

    // Greedy 4: Tổng hợp lời giải của các thuật toán tham lam trước đó
    int max4 = max(max(max1, max2), max3);
    cout << "Greedy 4: " << max4 << endl;

    return 0;
}
