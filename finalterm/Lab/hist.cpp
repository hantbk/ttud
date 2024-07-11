#include<bits/stdc++.h>

using namespace std;

long long n;
vector<long long> vt;
vector<long long> L;
vector<long long> R;
//  Li, Ri là cột gần nhất ở bên trái/phải cột thứ i có chiều cao nhỏ hơn vt[i]

void inputVector(){
    cin >> n;
    vt.push_back(-1); // vt[0] = -1
    // Đặt lính canh ở đầu mảng (vector)
    for (long long i = 1; i <= n; i++){
        long long l;
        cin >> l;
        // Nhập các chiều dài l1, l2,..,ln
        vt.push_back(l);
        // Thêm lần lượt các li vào vector -> vt[i]
    }
    vt.push_back(-1); // vt[n+1] = -1
    // Đặt lính canh ở cuối mảng (vector)
}

void HIST(){
    while (1){
        inputVector();
        if (n == 0) return;

        // Thực hiện thuật toán, xử lý bài toán
        stack<long long> st; 
        /* ngăn xếp để thực hiện thuật toán
         ghi ra các giá trị L, R */
        
        L.resize(n+2);
        for(long long i = 1; i <= n+1; i++){
            while (!st.empty() && vt[i] < vt[st.top()]){
                L[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        R.resize(n+2);
        for (long long i = n; i >= 0; i--){
            while (!st.empty() && vt[i] < vt[st.top()]){
                R[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long result = 0;
        for (long long i = 1; i <= n; i++){
            long long dt = (L[i] - R[i] - 1)*vt[i];
            result = (dt > result) ? dt : result;
        }

        cout << result << endl;

        // Xóa mảng vector vt, L, R trước khi bắt đầu vòng lặp mới
        vt.erase(vt.begin(), vt.end());
        L.erase(L.begin(), L.end());
        R.erase(R.begin(), R.end());
    }
}

int main(int argc, const char** argv) {
    HIST();
    return 0;
}