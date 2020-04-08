#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b > a){
        return gcd(b,a);
    }
    if(b == 0)
        return a;
    else return gcd(b, a%b);
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}
int solution(vector<int> arr) {
    int answer = 1;
    sort(arr.begin(), arr.end());
    for(int i = 0;i<arr.size();i++){
        answer = lcm(answer,arr[i]);
    }
    return answer;
}