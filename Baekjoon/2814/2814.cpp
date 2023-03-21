#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/2814
ll che[40001] ={0,};
vector<ll> prime;
void getChe(ll num) {
    for (int i = 2; i <= num; i++) {
        che[i] = i;
    }
    for (int i = 2; i <= num; i++) { 
        if (che[i] == 0) 
            continue;
        for (int j = i + i; j <= num; j += i) {
            che[j] = 0;
        }
    }
}
void getPrime(ll num){
    for(int i = 2;i<=num;i++){
        if(che[i])
            prime.push_back(i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,p;
    cin >> n >> p;
    getChe(31608);
    getPrime(31608);
    if(p > 31607){
        if(n == 1)
            cout << p;
        else
            cout << 0;
        return 0;
    }
    else{
        if(n==1)
        {
            cout << p;
            return 0;
        }
    }
    ll l = p*p;
    ll r = 1e9+1;
    ll mid = 0;
    ll size = prime.size();
    ll sum = 0;

    while(l <= r){
        mid = (l+r)/2;
        sum = mid / p;
        for(int i = 0;prime[i] < p && prime[i]*p<=mid;i++){
            sum -= mid / (prime[i]*p);
            for(int j = 0;j<i && prime[j] * prime[i] * p <= mid;j++){
                sum += mid / (prime[i]*prime[j]*p);
                for(int j2 = 0;j2<j && prime[j2]*prime[j]*prime[i]*p<=mid;j2++){
                    sum -= mid/(prime[i]*prime[j]*prime[j2]*p);
                    for(int j3=0;j3<j2&&prime[j3]*prime[j2]*prime[j]*prime[i]*p<=mid;j3++){
                        sum += mid / (prime[i]*prime[j]*prime[j2]*prime[j3]*p);
                        for(int j4=0;j4<j3&&prime[j4]*prime[j3]*prime[j2]*prime[j]*prime[i]*p<=mid;j4++){
                            sum -= mid / (prime[i]*prime[j]*prime[j2]*prime[j3]*prime[j4]*p);
                            for(int j5=0;j5<j4&&prime[j5]*prime[j4]*prime[j3]*prime[j2]*prime[j]*prime[i]*p<=mid;j5++){
                                sum += mid / (prime[i]*prime[j]*prime[j2]*prime[j3]*prime[j4]*prime[j5]*p);
                                for(int j6=0;j6<j5&&prime[j6]*prime[j5]*prime[j4]*prime[j3]*prime[j2]*prime[j]*prime[i]*p<=mid;j6++){
                                    sum -= mid / (prime[i]*prime[j]*prime[j2]*prime[j3]*prime[j4]*prime[j5]*prime[j6]*p);
                                        for(int j7=0;j7<j6&&prime[j7]*prime[j6]*prime[j5]*prime[j4]*prime[j3]*prime[j2]*prime[j]*prime[i]*p<=mid;j7++){
                                        sum += mid / (prime[i]*prime[j]*prime[j2]*prime[j3]*prime[j4]*prime[j5]*prime[j6]*prime[j7]*p);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(sum < n)
            l = mid+1;
        else if(sum > n)
            r = mid - 1;
        else break;
    }
    if(mid > 1000000000){
        cout << 0;
        return 0;
    }
    mid = (mid / p) * p;
    while(1){
        sum = mid/p;
        for(int i = 0;prime[i] < p && prime[i]*p<=mid;i++){
            sum -= mid / (prime[i]*p);
            for(int j = 0;j<i && prime[j] * prime[i] * p <= mid;j++){
                sum += mid / (prime[i]*prime[j]*p);
                for(int j2 = 0;j2<j && prime[j2]*prime[j]*prime[i]*p<=mid;j2++){
                    sum -= mid/(prime[i]*prime[j]*prime[j2]*p);
                    for(int j3=0;j3<j2&&prime[j3]*prime[j2]*prime[j]*prime[i]*p<=mid;j3++){
                        sum += mid / (prime[i]*prime[j]*prime[j2]*prime[j3]*p);
                        for(int j4=0;j4<j3&&prime[j4]*prime[j3]*prime[j2]*prime[j]*prime[i]*p<=mid;j4++){
                            sum -= mid / (prime[i]*prime[j]*prime[j2]*prime[j3]*prime[j4]*p);
                            for(int j5=0;j5<j4&&prime[j5]*prime[j4]*prime[j3]*prime[j2]*prime[j]*prime[i]*p<=mid;j5++){
                                sum += mid / (prime[i]*prime[j]*prime[j2]*prime[j3]*prime[j4]*prime[j5]*p);
                                for(int j6=0;j6<j5&&prime[j6]*prime[j5]*prime[j4]*prime[j3]*prime[j2]*prime[j]*prime[i]*p<=mid;j6++){
                                    sum -= mid / (prime[i]*prime[j]*prime[j2]*prime[j3]*prime[j4]*prime[j5]*prime[j6]*p);
                                        for(int j7=0;j7<j6&&prime[j7]*prime[j6]*prime[j5]*prime[j4]*prime[j3]*prime[j2]*prime[j]*prime[i]*p<=mid;j7++){
                                        sum += mid / (prime[i]*prime[j]*prime[j2]*prime[j3]*prime[j4]*prime[j5]*prime[j6]*prime[j7]*p);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(sum == n) 
            mid -= p;
        else 
            break;
    }
    mid += p;
    cout << mid;
	return 0;
}
