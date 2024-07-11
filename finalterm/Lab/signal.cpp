#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 200009
#define ll long long

int n, b;
int a[MAX];
int maxPrefix[MAX];
int maxSuffix[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Đọc dữ liệu đầu vào
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // Khởi tạo các mảng maxPrefix và maxSuffix
    maxPrefix[0] = -INF;
    maxSuffix[n + 1] = -INF;

    // Tính giá trị cho mảng maxPrefix
    for (int i = 1; i <= n; i++) {
        maxPrefix[i] = max(maxPrefix[i - 1], a[i]);
    }

    // Tính giá trị cho mảng maxSuffix
    for (int i = n; i >= 1; i--) {
        maxSuffix[i] = max(maxSuffix[i + 1], a[i]);
    }

    long long res = -1;

    // Tìm vị trí cắt tối ưu
    for (int i = 2; i < n; i++) {
        long long valPre = maxPrefix[i - 1] - a[i];
        long long valSuf = maxSuffix[i + 1] - a[i];
        if (valPre >= b && valSuf >= b) {
            res = max(res, valPre + valSuf);
        }
    }

    // In ra kết quả
    cout << res << endl;

    return 0;
}
