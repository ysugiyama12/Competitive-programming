/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
ll tmp[10000010] = {}, _rank[1000010] = {}, sa[1000010];
ll N,K;
bool compare_sa(ll i, ll j){
    if(_rank[i] != _rank[j]) return _rank[i] < _rank[j];
    else{
        ll ri = i + K <= N ? _rank[i+K] : -1;
        ll rj = j + K <= N ? _rank[j+K] : -1;
        return ri < rj;
    }
}
void construct_sa(string S){
    N = S.size();
    rep(i,0,N+1){
        sa[i] = i;
        _rank[i] = i < N ? S[i] : -1;
    }
    for(K = 1; K <= N; K *= 2){
        sort(sa, sa+N+1, compare_sa);
        tmp[sa[0]] = 0;
        rep(i,1,N+1){
            tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
        }
        rep(i,0,N+1) _rank[i] = tmp[i];
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string T,P;
    cin >> T >> P;
    construct_sa(T);
    ll st[1000010] = {};
    rep(i,0,N){
        st[_rank[i]-1] = i;
    }
    ll lv = -1, rv = N-1;
    while(rv - lv > 1){
        ll mid = (rv + lv) / 2;
        if(P > T.substr(st[mid], P.size())){
            lv = mid;
        }else{
            rv = mid;
        }
    }
    ll idx = rv;
    // printa(st, N);
    vector<ll> ans;
    while(idx < N){
        if(P == T.substr(st[idx], P.size())){
            ans.push_back(st[idx]);
            idx++;
        }else{
            break;
        }
    }
    sort(ans.begin(), ans.end());
    rep(i,0,ans.size()) print(ans[i]);

    
    
}