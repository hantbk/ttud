#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
int C[20][20];
int mem[20][1 << 20];

// TSP(i,S) là cách sử dụng ít chi phí nhất để đi qua toàn bộ các đỉnh và quay trở về đỉnh 0, 
// nếu như hiện tại đang ở tại đỉnh i và người du lịch đã thăm tất cả các đỉnh trong S
int TSP(int i, int S){
    if(S == (1 << n) - 1) return C[i][0]; // Nếu đã đi qua tất cả các đỉnh thì quay về đỉnh 0
    if(mem[i][S] != -1) return mem[i][S]; // Nếu đã tính rồi thì lấy ra
    int res = INF;
    for(int j = 0; j < n; j++){
        if(S & (1 << j)) continue; // Nếu đã đi qua thì bỏ qua
        res = min(res, C[i][j] + TSP(j, S | (1 << j))); // Chọn đỉnh j để đi tiếp
    }
    mem[i][S] = res;
    return res;
}

void IterTrace()
{
    int i = 0, S = 1; // Bắt đầu từ đỉnh 0 và đã thăm đỉnh 0
    cout << "Đường đi tối ưu: " << 0; // In đỉnh bắt đầu
    for (int k = 1; k < n; k++)
    {
        for (int j = 0; j < n; j++)
        {
            if (S & (1 << j)) // Nếu đỉnh j đã được thăm
                continue;
            // Nếu chi phí từ đỉnh i đến đỉnh j cộng với chi phí từ đỉnh j về đỉnh xuất phát
            // là bằng với chi phí tối ưu của đỉnh i khi đã thăm các đỉnh trong S
            if (mem[i][S] == C[i][j] + mem[j][S | (1 << j)])
            {
                i = j; // Đỉnh tiếp theo là j
                S = S | (1 << j); // Đánh dấu đỉnh j đã thăm
                cout << " -> " << i; // In đỉnh j
                break;
            }
        }
    }
    cout << " -> 0" << endl; // Kết thúc đường đi tại đỉnh 0
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> C[i][j];

    memset(mem, -1, sizeof(mem));
    cout << "Chi phí tối thiểu: " << TSP(0, 1) << endl;
    IterTrace();

    return 0;
}
