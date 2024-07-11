#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int n;
string p;
string a, b;
int len;

ll count_search(string &a, string &b){
    int l1 = a.size();
    int l2 = b.size();
    ll ans = 0;
    bool flag;
    for (int i = 0; i < l1; i++){
        flag = true;
        for (int j = 0; j < l2; j++){
            if (a[i + j] != b[j]){
                flag = false;
                break;
            }
        }
        ans += (flag)?1:0;
    }
    return ans;
}

void makeans(int n, ll a, ll b, ll da, ll db){
    int cnt = 0;
    while (cnt < n){
        if (cnt % 2) a += b + da;
        else b += a + db;
        cnt++;
    }
    if (cnt % 2) cout << b << endl;
    else cout << a << endl;
}

void Fibwords(){
    int ca = 1;
    while(cin >> n){
        cin >> p;
        cout << "Case " << ca++ << ": ";
        a = "0";
        b = "1";
        int cnt = 2;
        len = p.size();
        if (n == 0) {
            cout << count_search(a, p) << endl;
            continue;
        }
        if (n == 1){
            cout << count_search(b, p) << endl;
            continue;
        }
        while ((a.size() < len || b.size() < len) && cnt <= n){
            if(cnt % 2) b = a + b;
            else a = b + a;
            cnt++;
        }
        if (cnt == n + 1){
            if (cnt % 2) cout << count_search(a, p);
            else count_search(b, p);
            continue;
        }
        cnt--;
        ll s1, s2, da, db;
        string str1, str2;
        s1 = count_search(a, p);
        s2 = count_search(b, p);
        str1 = a + b;
        str2 = b + a;
        da = count_search(str1, p) - s1 - s2;
        db = count_search(str2, p) - s1 - s2;
        if (cnt % 2) makeans(n - cnt, s2, s1, da, db);
        else makeans(n - cnt, s1, s2, db, da);
    }

}

int main(int argc, const char** argv) {
    Fibwords();
    return 0;
}
