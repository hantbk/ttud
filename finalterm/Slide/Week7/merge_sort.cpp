#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int a[100009];
int ta[100009]; // temporary array

void merge(int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    for (int k = l; k <= r; k++)
    {
        if (i > m)
        {
            ta[k] = a[j];
            j++;
        }
        else if (j > r)
        {
            ta[k] = a[i];
            i++;
        }
        else if (a[i] < a[j])
        {
            ta[k] = a[i];
            i++;
        }
        else
        {
            ta[k] = a[j];
            j++;
        }
    }

    for(int k = l; k <= r; k++)
        a[k] = ta[k];
}

void mergeSort(int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}