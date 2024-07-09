#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int a[MAX];
int N;
int maxval[MAX];

// return the max value of a[i],...,a[j] from the node (id, L, R)
int getMaxFromNode(int id, int L, int R, int i, int j)
{
    if (i > R || j < L)
        return -INF;
    if (i <= L && R <= j)
        return maxval[id];

    int mid = (L + R) / 2;
    int leftChild = 2 * id, rightChild = 2 * id + 1;
    int maxLeft = getMaxFromNode(leftChild, L, mid, i, j);
    int maxRight = getMaxFromNode(rightChild, mid + 1, R, i, j);
    return max(maxLeft, maxRight);
}

int getMax(int i, int j)
{
    return getMaxFromNode(1, 1, N, i, j);
}

// propagate from the node (id, L, R)
void updateFromNode(int id, int L, int R, int index, int value)
{
    if (L > R || index < L || index > R)
        return;
    if (L == R)
    {
        maxval[id] = value;
        return;
    }

    int leftChild = 2 * id, rightChild = 2 * id + 1;
    int mid = (L + R) / 2;
    updateFromNode(leftChild, L, mid, index, value);
    updateFromNode(rightChild, mid + 1, R, index, value);
    maxval[id] = max(maxval[leftChild], maxval[rightChild]);
}

void update(int index, int value)
{
    updateFromNode(1, 1, N, index, value);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(maxval, 0, sizeof(maxval));
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
        update(i, a[i]);

    int q;
    cin >> q;
    while (q--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "get-max")
        {
            int i, j;
            cin >> i >> j;
            cout << getMax(i, j) << endl;
        }
        else
        {
            int index, value;
            cin >> index >> value;
            a[index] = value;
            update(index, value);
        }
    }

    return 0;
}