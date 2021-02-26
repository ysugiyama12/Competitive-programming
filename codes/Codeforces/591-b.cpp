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
    ll Q;
    cin >> Q;
    while(Q--){
        ll N;
        cin >> N;
        vector<ll> a(N);
        rep(i,0,N) cin >> a[i];
        a = compress(a, N);
        // printa(a, N);
        ll max_val = 0;
        rep(i,0,N) max_val = max(max_val, a[i]);
        vector<ll> top(N+1, -1), back(N+1, -1);
        rep(i,0,N){
            if(top[a[i]] == -1){
                top[a[i]] = i;
            }
        }
        rrep(i,N-1,0){
            if(back[a[i]] == -1){
                back[a[i]] = i;
            }
        }
        vector<ll> sum(N+2, 0);
        rep(i,0,max_val-1){
            if(back[i+1] < top[i+2]){
                // print(i);
                sum[i+1] = 1;
            }
        }
        rep(i,0,N+1) sum[i+1] += sum[i];
        // printa(sum, N+1);
        ll ans = 0;
        rep(i,1,max_val+1){
            if(sum[i] - sum[i-1] == 0) continue;
            ll lv = i, rv = max_val+1;
            while(rv - lv > 1){
                ll mid = (rv + lv) / 2;
                ll v = sum[mid] - sum[i-1];
                // print(v);
                if(mid - i + 1 == v){
                    lv = mid;
                }else{
                    rv = mid;
                }
            }
            // print(lv, rv);
            ans = max(ans, lv - i+1);
        }
        ans = max_val - (ans+1);
        print(ans);
    }
    

}