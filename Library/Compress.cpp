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

vector<ll> compress(vector<ll> x, ll n){
    // [1,n]
	vector<ll> v;
	v.push_back(-INF); v.push_back(INF);
	rep(i,0,n) v.push_back(x[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<ll> res;
	rep(i,0,n) res.push_back(lower_bound(v.begin(), v.end(), x[i]) - v.begin());
	return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> x(N);
    rep(i,0,N){
        cin >> x[i];
    }
    x = compress(x, N);
    printa(x, N);
}