/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    An input string is valid if: Open brackets must be closed by the same type of brackets. Open brackets must be closed in the correct order.
    Input: s = "()"
    Output: true
    Input: s = "()[]{}"
    Output: true
    Input: s = "(]"
    Output: false
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100000
#define ll long long
#define MOD 1000000007

stack<char> st;

bool isValid(string s) {
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if(st.empty()) return false;
            if(s[i] == ')' && st.top() != '(') return false;
            if(s[i] == '}' && st.top() != '{') return false;
            if(s[i] == ']' && st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();  // if stack is empty then return true else return false (if stack is not empty then there are some brackets which are not closed properly
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    cout << isValid(s) << endl;

    return 0;
}