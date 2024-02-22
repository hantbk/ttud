#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b, c = "";
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (a.length() < b.length())
    {
        a += '0';
    }
    while (b.length() < a.length())
    {
        b += '0';
    }
    int check = 0;
    for (int i = 0; i < a.length(); i++)
    {
        c += (a[i] - 48 + b[i] - 48 + check) % 10 + 48;
        check = (a[i] - 48 + b[i] - 48 + check) / 10;
    }
    if (check == 1)
    {
        c += '1';
    }
    reverse(c.begin(), c.end());
    cout << c;
}