/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
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
    ll N,P;
    cin >> N >> P;
    ll a[5010], b[5010];
    rep(i,0,N) cin >> a[i] >> b[i];
    vector<lpair> lp;
    rep(i,0,N) lp.push_back({a[i], b[i]});
    sort(lp.begin(), lp.end(), [](lpair l1, lpair l2){
        if(l1.first == l2.first){
            return l1.second > l2.second;
        }
        return l1.first < l2.first;
    });
    vector<ll> v;
    v.push_back(0);
    rep(i,0,N-1){
        if(lp[i].first != lp[i+1].first){
            v.push_back(i+1);
        }
    }
    // rep(i,0,N) print(lp[i].first, lp[i].second);
    ll ans = 0;
    for(auto &i: v){
        ll dp[2][5210] = {};
        ll pos = 0;
        rep(j,i+1,N){
            pos = ((j-i) % 2 == 0 ? 0 : 1);
            // print(pos);
            rrep(p,P,0){
                if(p - lp[j].first >= 0){
                    dp[pos][p] = max(dp[pos^1][p], dp[pos^1][p - lp[j].first] + lp[j].second);
                }else{
                    dp[pos][p] = dp[pos^1][p];
                }
            }
        }
        ll res = dp[pos][P];
        ans = max(ans, res + lp[i].second);


    }
    print(ans);




}