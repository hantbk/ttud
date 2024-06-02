#include <bits/stdc++.h>
using namespace std;

#define MAX 1005 // Giới hạn tối đa cho số lượng thành phố

int M, N;
vector<pair<int, int>> connections;
int F[MAX][MAX]; // F[i][j] là số cầu bắc được nhiều nhất khi xét đến thành phố thứ i ở bờ Bắc và thành phố thứ j ở bờ Nam

void dp()
{
    // Khởi tạo mảng F
    for (int i = 0; i <= M; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            F[i][j] = 0;
        }
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            bool found = false;
            for (int k = 0; k < connections.size(); k++)
            {
                if (connections[k].first == i && connections[k].second == j)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                F[i][j] = F[i - 1][j - 1] + 1;
            }
            else
            {
                F[i][j] = max(F[i - 1][j], F[i][j - 1]);
            }
        }
    }

    cout << F[M][N] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    int k;
    cin >> k;
    connections.resize(k);
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        connections[i] = make_pair(u, v);
    }

    dp();

    return 0;
}