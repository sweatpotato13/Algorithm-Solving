#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// https://www.acmicpc.net/problem/2568
map<ll,ll> m;
vector<pair<ll,ll>> dp;
vector<pair<ll,ll>> ans;
int lower(int start, int end, int target)
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
    for(int i = 0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        m[a] = b;
    }
    for(auto k : m){
        if(dp.empty()) {
            dp.push_back({k.first,k.second});
            ans.push_back({1,k.first});
        }
        else{
            if(dp.back().second < k.second){
                dp.push_back({k.first,k.second});
                ans.push_back({dp.size(),k.first});
            }
            else{
                auto it = lower(0,dp.size()-1,k.second);
                ans.push_back({it,k.first});
                dp[it-1] = {k.first,k.second};
            }
        }
    }
    stack<ll> s;
    ll len = dp.size();
    for(int i = ans.size()-1;i>=0;i--){
        if(ans[i].first == len){
            s.push(ans[i].second);
            len--;
        }
        if(len == -1) break;
    }
    while(!s.empty()){
        m.erase(s.top());
        s.pop();
    }
    vector<ll> left;
    for(auto k : m){   
        left.push_back(k.first);
    }
    sort(all(left));
    cout << left.size() << "\n";
    for(auto k : left){
        cout << k << "\n";
    }
	return 0;
}
