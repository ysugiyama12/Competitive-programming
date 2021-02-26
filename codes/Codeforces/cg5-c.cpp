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
typedef struct {
    ll x;
    ll y;
    ll z;
    ll idx;
} P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll x[50010], y[50010], z[50010];
    rep(i,0,N) cin >> x[i] >> y[i] >> z[i];
    vector<P> v;
    rep(i,0,N) v.push_back((P){x[i],y[i],z[i], i});
    sort(v.begin(), v.end(), [](P p1, P p2){
        if(p1.x == p2.x){
            if(p1.y == p2.y){
                return p1.z < p2.z;
            }
            return p1.y < p2.y;
        }
        return p1.x < p2.x;
    });
    bool check[50010] = {};
    rep(i,0,N-1){
        if(check[i]) continue;
        if(v[i].x == v[i+1].x && v[i].y == v[i+1].y){
            check[i] = true;
            check[i+1] = true;
            print(v[i].idx+1, v[i+1].idx+1);
        }
    }
    rep(i,0,N-1){
        if(check[i]) continue;
        if(v[i].x == v[i+1].x){
            check[i] = true;
            check[i+1] = true;
            print(v[i].idx+1, v[i+1].idx+1);
        }
    }
    vector<ll> tt;
    rep(i,0,N){
        if(not check[i]) tt.push_back(v[i].idx);
    }
    rep(i,0,tt.size()/2){
        print(tt[2*i]+1, tt[2*i+1]+1);
    }



}