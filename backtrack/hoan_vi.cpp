/*
    Cho n là số nguyên dương. Hãy liệt kê tất cả các hoán vị của 1, 2, ..., n.
    Input: n
    Output: Các hoán vị của 1, 2, ..., n

*/

#include <iostream>
#define MAX 100

using namespace std;

int x[MAX], n;
bool visited[MAX];

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

bool check(int v, int k)
{
    return visited[v] == false;
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            visited[v] = true;
            if (k == n)
                solution();
            else
                Try(k + 1);
            visited[v] = false;
        }
    }
}

int main()
{
    cin >> n;

    for (int v = 1; v <= n; v++)
        visited[v] = false;
    Try(1);

    return 0;
}