#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e9 + 18
#define endl "\n"

int a[100];

// Tron 2 day con: day 1 [L, m], day 2 [m + 1, R]
void merge(int a[], int l, int m, int r)
{
    vector<int> x(a + l, a + m + 1);     // Day con 1
    vector<int> y(a + m + 1, a + r + 1); // Day con 2
    int i = 0, j = 0;
    while (i < x.size() && j < y.size())
    {
        if (x[i] <= y[j])
        {
            a[l] = x[i];
            l++;
            i++;
        }
        else
        {
            a[l] = y[j];
            l++;
            j++;
        }
    }
    while (i < x.size())
    {
        a[l] = x[i];
        l++;
        i++;
    }
    while (j < y.size())
    {
        a[l] = y[j];
        l++;
        j++;
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }
    mergeSort(a, 0, n - 1);
    for (int x : a)
    {
        cout << x << " ";
    }

    return 0;
}
