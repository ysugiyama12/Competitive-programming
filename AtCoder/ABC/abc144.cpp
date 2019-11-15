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
ll s[300010], t[300010];
vector<ll> tree[610];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    rep(i,0,M){
        cin >> s[i] >> t[i];
        s[i]--; t[i]--;
        tree[s[i]].push_back(t[i]);
    }
    double ans = INF;
    rep(n,-1,N){ // n番目の部屋から出る通路を塞ぐ
        double dp[610] = {};
        bool ok = true;
        rrep(i,N-1,0){
            if(i == n){
                ll sz = tree[i].size();
                if(sz <= 1){
                    ok = false;
                    continue;
                }
                double v = 0.0;
                ll idx = -1;
                for(auto &e: tree[i]){
                    if(v < dp[e]){
                        v = dp[e];
                        idx = e;
                    }
                }
                for(auto &e: tree[i]){
                    if(idx != e) dp[i] += 1.0/(double)(sz-1) + dp[e] / (double) (sz-1);
                }


            }else{
                ll sz = tree[i].size();
                for(auto &e: tree[i]){
                    dp[i] += 1.0/(double)sz + dp[e] / (double) sz;
                }
            }
        }
        if(ok) ans = min(ans, dp[0]);
    }
    cout << setprecision(10) << ans << endl;

}