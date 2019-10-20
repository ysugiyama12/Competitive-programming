/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N;
	cin >> N;
	ll A[3010];
	rep(i,0,N) cin >> A[i];
	ll M;
	cin >> M;
	ll L[3010], R[3010], B[3010];
	rep(i,0,M){
		cin >> L[i] >> R[i] >> B[i];
	}
	ll dp[3010];
	fill(dp, dp+N+1, -INF);
	dp[0] = 0;
	rep(i,0,N){
		ll pena = A[i];
		ll sum[3010] = {};
		rep(j,0,M){
			if(L[j] <= (i+1) && (i+1) <= R[j]){
				sum[L[j]] += B[j];
			}
		}
		rep(j,0,N+1) sum[j+1] += sum[j];
		rep(j,0,i+1){
			ll attack = sum[N+1] - sum[j];
			dp[i+1] = max(dp[i+1], dp[j] + max(0LL, attack - pena));
		}
	}
	print(dp[N]);
	

}