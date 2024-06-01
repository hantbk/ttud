/*
Cho N khối đá
Các khối đá đều có dạng hình hộp chữ nhật với chiều dài, rộng và cao lần lượt là Li, Wi, Hi
Một cách xây dựng tháp là một cách đặt 1 số khối đá 
Chiều cao mỗi khối đá là kích thước nhỏ nhất của 3 chiều của khối đá
Các mép của khối đá đc đặt song song với nhau sao cho không có phần nào của khối trên 
nằm ngoài phần nào của khối dưới
Hãy chỉ ra cách để xây dựng sao cho số khối đá là lớn nhất
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 1000009
#define ll long long
#define MOD 1000000009

int n;
struct Block{
    int l, w, h;
};

Block a[MAX];
int F[MAX]; // F[i] là số khối đá lớn nhất có thể xây dựng kể từ khối đá thứ i
int H[MAX]; // H[i] là chiều cao lớn nhất có thể xây dựng kể từ khối đá thứ i

// Sắp xếp các khối đá theo chiều cao giảm dần
bool cmp(Block x, Block y){
    return x.h > y.h;
}

void dp(){
    sort(a + 1, a + n + 1, cmp);

    for(int i = 1; i <= n; i++){
        F[i] = 1;
        H[i] = a[i].h;
        for(int j = 1; j < i; j++){
            if(a[j].l < a[i].l && a[j].w < a[i].w){
                F[i] = max(F[i], F[j] + 1);
                H[i] = max(H[i], H[j] + a[i].h);
            }
        }
    }
    int res = *max_element(F + 1, F + n + 1);
    int maxH = *max_element(H + 1, H + n + 1);
    cout<<res<<" "<<maxH<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].l>>a[i].w>>a[i].h;
    }
    dp();

    return 0;
}