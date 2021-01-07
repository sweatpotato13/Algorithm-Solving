#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// http://codeforces.com/contest/1348/problem/C
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        sort(all(s));
        if(s[0] != s[k-1]){
            cout << s[k-1] << "\n";
            continue;
        }
        cout << s[0];
        if(s[k] != s[n-1]){
            for(int i = k;i<n;i++){
                cout << s[i];
            }
        }
        else{
            for(int i = 0;i<(n-1)/k;i++){
                cout << s[n-1];
            }
        }
        cout << "\n";
    }
	return 0;
}