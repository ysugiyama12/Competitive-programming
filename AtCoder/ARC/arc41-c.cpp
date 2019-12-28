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
    ll N, L;
    cin >> N >> L;
    ll x[100010];
    char d[100010];
    rep(i,0,N) cin >> x[i] >> d[i];
    vector<ll> start, end;
    start.push_back(0);
    rep(i,0,N-1){
        if(d[i] == 'L' && d[i+1] == 'R'){
            end.push_back(i);
            start.push_back(i+1);
        }
    }
    end.push_back(N-1);
    ll sz = start.size();
    ll ans = 0;
    rep(i,0,sz){
        ll v1 = start[i], v2 = end[i];
        bool is_center = false;
        ll rv = 0, lv = 0, center_val = -1;
        rep(j,v1,v2){
            if(d[j] == 'R' && d[j+1] == 'L'){
                is_center = true;
                center_val = x[j+1] - x[j] - 1;
            }
        }
        rep(j,v1,v2+1){
            if(d[j] == 'R') rv++;
            if(d[j] == 'L') lv++; 
        }
        if(is_center){
            ans += center_val * max(rv, lv);
        }
        rv = 0;
        rep(j,v1,v2){
            if(d[j] == 'R' && d[j+1] == 'R'){
                rv++;
                ans += rv * (x[j+1] - x[j] - 1);
            }
        }
        lv = 0;
        rrep(j,v2,v1+1){
            if(d[j] == 'L' && d[j-1] == 'L'){
                lv++;
                ans += lv * (x[j] - x[j-1] - 1);
            }
        }
        if(d[v1] == 'L'){
            lv++;
            ans += lv * (x[v1] - 1);
        }
        if(d[v2] == 'R'){
            rv++;
            ans += rv * (L - x[v2]);
        }
    }
    print(ans);



}