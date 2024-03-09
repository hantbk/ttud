#include<bits/stdc++.h>
using namespace std;

int n;
int test = 0;
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
string sKey[12] = {
    " ", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz",
    " ", " ", " "};

void solve1(){
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

void solve2() {
    string sLine;
    getline(cin, sLine);
    int result = 0;
    for (int i = 0; i < sLine.size(); i++)
    {
        int curr = 0;
        for (int j = 0; j < 12; j++)
        {
            for (int k = 0; k < sKey[j].size(); k++)
            {
                if (sLine[i] == sKey[j][k])
                {
                    curr = k + 1;
                }
                
            }
            
        }
        result +=curr;
    }
    cout<<"Case "<<test<<" : "<<result<<endl;
}

int main() {
    cin >> n;
    getline(cin,s);
    while (n--)
    {
        test++;
        solve2();
    }
    return 0;
}