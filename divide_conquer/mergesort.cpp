#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000000];
int ta[1000000];

// merge(begin, mid, end)
void merge(int b, int m, int e)
{
    int i = b;
    int j = m + 1;
    for (int k = b; k <= e; k++)
    {
        if (i > m)
        {
            ta[k] = a[j];
            j++;
        }
        else
        {
            if (a[i] > a[j])
            {
                ta[k] = a[j];
                j++;
            }
            else
            {
                ta[k] = a[i];
                i++;
            }
        }
    }
    for (int k = b; k <= e; k++)
        a[k] = ta[k];
}

void mergeSort(int b, int e)
{
    if (b == e)
        return;
    int m = (b + e) / 2;
    mergeSort(b, m);
    mergeSort(m + 1, e);
    merge(b, m, e);
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