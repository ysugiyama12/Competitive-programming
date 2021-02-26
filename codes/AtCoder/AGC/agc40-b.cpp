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
    ll N;
    cin >> N;
    ll L[100010], R[100010];
    rep(i,0,N) cin >> L[i] >> R[i];
    vector<lpair> lp;
    rep(i,0,N) lp.push_back({L[i], R[i]});
    sort(lp.begin(), lp.end(), [](lpair l1, lpair l2){
        if(l1.first == l1.first){
            return l1.second < l2.second;
        }
        return l1.first < l2.first;
    });
    ll ans = 0;
    ll group1[100010] = {}, group2[100010] = {};
    ll lv = lp[0].first, rv = lp[0].second;
    group1[0] = rv - lv + 1;
    ll lv_memo1[100010] = {}, rv_memo1[100010] = {};
    lv_memo1[0] = lv;
    rv_memo1[0] = rv;
    rep(i,1,N-1){
        lv = max(lv, lp[i].first);
        rv = min(rv, lp[i].second);
        if(lv <= rv){
            group1[i] = rv - lv + 1;
        }
        lv_memo1[i] = lv;
        rv_memo1[i] = rv;
    }
    lv = lp[N-1].first; rv = lp[N-1].second;
    group2[0] = rv - lv + 1;
    ll lv_memo2[100010] = {}, rv_memo2[100010] = {};
    lv_memo2[0] = lv;
    rv_memo2[0] = rv;
    rrep(i,N-2,1){
        lv = max(lv, lp[i].first);
        rv = min(rv, lp[i].second);
        if(lv <= rv){
            group2[N-1-i] = rv - lv + 1;
        }
        lv_memo2[N-1-i] = lv;
        rv_memo2[N-1-i] = rv; 
    }
    rep(i,0,N-1){
        ans = max(ans, group1[i] + group2[N-2-i]);
    }
    rep(i,1,N-1){
        ll v1 = lp[i].second - lp[i].first + 1;
        ll lv2 = max(lv_memo1[i-1], lv_memo2[N-2-i]);
        ll rv2 = min(rv_memo1[i-1], rv_memo2[N-2-i]);
        ll res = v1;
        if(lv2 <= rv2) res += rv2 - lv2 + 1;
        ans = max(ans, res);

    }
    print(ans);



    

}