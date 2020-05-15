#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// https://www.acmicpc.net/problem/2550
vector<pair<ll,ll>> dp;
vector<pair<ll,ll>> ans;
ll lower(ll start, ll end, ll target)
{
    int mid;
    while (end - start > 0){
        mid = (start + end) / 2; 
        if (dp[mid].second < target)
            start = mid + 1;
        else
            end = mid;
   }
    return end + 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    map<ll,ll> m;
    vector<ll> a(n);
    vector<pair<ll,ll>> b(n);
    for(int i = 0;i<n;i++){
        cin >> a[i];
        m[a[i]] = i+1;
    }
    for(int i = 0;i<n;i++){
        ll e;
        cin >> e;
        b[i] = {e,m[e]};
    }
    for(int i = 0;i<n;i++){
        if(dp.empty()) {
            dp.push_back(b[i]);
            ans.push_back({1,b[i].second});
        }
        else{
            if(dp.back().second < b[i].second){
                dp.push_back(b[i]);
                ans.push_back({dp.size(),b[i].second});
            }
            else{
                auto it = lower(0,dp.size()-1,b[i].second);
                ans.push_back({it,b[i].second});
                dp[it-1] = b[i];
            }
        }
    }
    stack<ll> s;
    ll len = dp.size();
    cout << dp.size() << "\n";
    for(int i = ans.size()-1;i>=0;i--){
        if(ans[i].first == len){
            s.push(ans[i].second);
            len--;
        }
        if(len == -1) break;
    }
    vector<ll> ss;
    while(!s.empty()){
        ss.push_back(a[s.top()-1]);
        s.pop();
    }
    sort(all(ss));
    for(auto k : ss){
        cout << k << " ";
    }

	return 0;
}
