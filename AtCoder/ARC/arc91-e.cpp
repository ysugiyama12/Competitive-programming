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
    ll N,Q;
    cin >> N >> Q;
    ll A[100010];
    rep(i,0,N) cin >> A[i];
    ll X[100010];
    rep(i,0,Q) cin >> X[i];
    vector<ll> pos;
    ll sum[100010] = {};
    rep(i,0,N) sum[i+1] = sum[i] + A[i];
    ll sum_odd[100010] = {}, sum_even[100010] = {};
    rep(i,0,N){
        if(i % 2 == 0){
            sum_even[i+1] += sum_even[i] + A[i];
            sum_odd[i+1] += sum_odd[i];
        }else{
            sum_even[i+1] += sum_even[i];
            sum_odd[i+1] += sum_odd[i] + A[i];
        }
    }

    rrep(i,N-2,0){
        ll diff = N - i - 1;
        ll p1 = i, p2 = p1 - diff;
        if(p2 < 0) break;
        ll v = (A[p2] + A[p1])/2 + 1;
        pos.push_back(v); 
    }
    reverse(pos.begin(), pos.end());
    // printa(pos, pos.size());
    ll sz = pos.size();
    rep(i,0,Q){
        ll p = upper_bound(pos.begin(), pos.end(), X[i]) - pos.begin();
        ll num = sz - p + 1;
        ll taka = sum[N] - sum[N-num];
        ll s = N - num*2 - 1;
        // print(taka);
        if(s < 0){
            print(taka);
        }else{
            if(s % 2 == 0){
                taka += sum_even[s+1];
            }else{
                taka += sum_odd[s+1];
            }
            print(taka);

        }


    }


    

}