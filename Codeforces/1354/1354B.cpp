#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// https://codeforces.com/problemset/problem/1354/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        bool isExist[4] = {0,};
        ll cnt[4] ={0,};
        ll ans = INT_MAX;
        string s;
        cin >> s;
        for(int i = 0;i<s.length();i++){
            isExist[s[i]-'0'] = true;
        }
        if(!(isExist[1] && isExist[2] && isExist[3])){
            cout << 0 << "\n";
        }
        else if(s.length() < 3){
            cout << 0 << "\n";
        }
        else{
            ll l = 0;
            ll r = 0;
            cnt[s[0]-'0']++;
            while(l <= r && r <= s.length()-1){
                if(!(cnt[1] && cnt[2] && cnt[3])){
                    r++;
                    cnt[s[r]-'0']++;
                }
                else{
                    if(ans > r-l+1){
                        ans = r-l+1;
                    }
                    cnt[s[l]-'0']--;
                    l++;
                }
            }
            if(ans == INT_MAX){
                cout << 0 << "\n";
            }
            else{
                cout << ans << "\n";
            }
        }
    }
	return 0;
}
