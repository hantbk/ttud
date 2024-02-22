#include<bits/stdc++.h>
using namespace std;

string s;
int arr[26] = {1,2,3,
               1,2,3,
               1,2,3,
               1,2,3,
               1,2,3,
               1,2,3,4,
               1,2,3,
               1,2,3,4     
               };

void solve(){
    string s;
    getline(cin,s);
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            sum+=1;
        }
        else sum += arr[s[i]-'a'];
    }
    cout<<sum<<"\n";
}

int main() {

    int n;
    cin >> n;
    getline(cin,s);
    while (n--)
    {
        solve();
    }
    return 0;
}