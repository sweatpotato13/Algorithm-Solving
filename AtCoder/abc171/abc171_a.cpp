#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc171/tasks/abc171_a
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    char ch;
    cin >> ch;
    if('a' <= ch && 'z' >= ch ) cout << 'a';
    else cout << 'A';

	return 0;
}
