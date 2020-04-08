using namespace std;
typedef long long ll;

ll GCD(int a,int b){
    if(b > a) return GCD(b, a);
	if(b == 0)
		return a;
	else return GCD(b, a%b);
}
long long solution(int w,int h)
{
	ll answer = (ll)w * (ll)h;
	answer = answer - (ll)w - (ll)h + GCD(w,h);
	return answer;
}