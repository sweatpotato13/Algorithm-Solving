#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/18119
ll cur[10001] ={0,};
ll full[10001] ={0,};
ll word[10001][26] ={0,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    ll cnt = n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<26;j++){
            word[i][j] = -1;
        }
    }
    for(int i = 0;i<n;i++){
        string s;
        cin >> s;   
        for(int j = 0;j<s.length();j++){
            word[i][s[j]-'a'] = 1;
        }
        for(int j = 0;j<26;j++){
            if(word[i][j]){
                cur[i]++;
                full[i]++;
            }
        }
    }
    for(int i = 0;i<m;i++){
        ll o;
        char x;
        cin >> o >> x;
        if(o == 1){
            for(int j = 0;j<n;j++){
                if(word[j][x-'a'] == 1){
                    word[j][x-'a'] = 0;
                    cur[j]--;
                    if(cur[j] + 1 == full[j]) cnt--;
                }
            }
        }
        else{
            for(int j = 0;j<n;j++){
                if(word[j][x-'a'] == 0){
                    word[j][x-'a'] = 1;
                    cur[j]++;
                    if(cur[j] == full[j]) cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }

	return 0;
}