#include <bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define minn -10000005

int a[maxn];
int N;
int maxVal[maxn];

void buildSegmentTree(int id, int L, int R)
{
    if (L == R)
    {
        maxVal[id] = a[L];
        return;
    }
    int m = (L + R) / 2;
    buildSegmentTree(2 * id, L, m);
    buildSegmentTree(2 * id + 1, m + 1, R);
    maxVal[id] = max(maxVal[2 * id], maxVal[2 * id + 1]);
}

// return the max value of a[i],...,a[j] from the node (id, L, R)
int getMaxFromNode(int id, int L, int R, int i, int j)
{
    // [L, R] and [i, j] are disjoint -> not found
    if (i > R || j < L)
        return minn;
    // [L, R] is within [i, j]
    if (i <= L && j >= R)
        return maxVal[id]; // max value is stored in the node (id, L, R)

    int m = (L + R) / 2;
    int leftChild = 2 * id, rightChild = 2 * id + 1;
    int maxLeft = getMaxFromNode(leftChild, L, m, i, j);
    int maxRight = getMaxFromNode(rightChild, m + 1, R, i, j);
    return max(maxLeft, maxRight);
}

void updateMaxFromNode(int id, int L, int R, int index, int value)
{
    // propagate from the node (id, L, R) by the update: a[index] = value;
    if (L > R)
        return;
    if (index < L || index > R)
        return; // node (id, L, R) does not manage a[index]
    if (L == R)
    {
        maxVal[id] = value;
        return;
    }
    int leftChild = 2 * id, rightChild = 2 * id + 1;
    int m = (L + R) / 2;
    updateMaxFromNode(leftChild, L, m, index, value);
    updateMaxFromNode(rightChild, m + 1, R, index, value);
    maxVal[id] = max(maxVal[leftChild], maxVal[rightChild]);
}

int getMax(int i, int j)
{
    return getMaxFromNode(1, 1, N, i, j); // Find max from the root node
}

void update(int i, int v)
{
    updateMaxFromNode(1, 1, N, i, v); // Start the propagation from the root node
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(maxVal, 0 , sizeof(maxVal));
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for(int i = 1; i <= N; i++) update(i,a[i]);
    // buildSegmentTree(1, 1, N);

    int k;
    cin >> k;
    while (k--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "get-max")
        {
            int i, j;
            cin >> i >> j;
            cout << getMax(i, j)<<endl;
        }
        if (cmd == "update")
        {
            int i, v;
            cin >> i >> v;
            a[i] = v;
            update(i, v);
        }
    }

    return 0;
}