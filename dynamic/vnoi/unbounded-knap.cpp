#include <iostream>
#include <vector>
using namespace std;

long long n, w;
vector<long long> a, b, L, P;

int main()
{
    cin >> n >> w;
    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i] >> b[i];
    P = L = vector<long long>(w + 1);
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= w; j++)
      {
          if (a[i] > j)
            L[j] = P[j];
          else
              L[j] = max(P[j], L[j - a[i]] + b[i]);
        }
      P = L;
    }
    cout << L[w];
}