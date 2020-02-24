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
ll calc(ll a, ll b){
    return (a | b) - b;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll a[100010];
    rep(i,0,N) cin >> a[i];
    ll cnt[65] = {};
    rep(i,0,N){
        rep(j,0,62){
            if((a[i]>>j) & 1) cnt[j]++;
        }
    }
    ll ans = -INF, max_num = -1;
    rep(i,0,N){
        ll num = 0;
        rep(j,0,62){
            if(((a[i]>>j) & 1) && cnt[j] == 1){
                num += (1LL<<j);
            } 
        }
        if(ans < num){
            ans = num;
            max_num = a[i];
        }
    }
    ll tt = 0;
    cout << max_num << " ";
    rep(i,0,N){
        if(a[i] == max_num){
            tt++;
            if(tt != 1) cout << a[i] << " \n"[i==N-1];
        }else{
            cout << a[i] << " \n"[i==N-1];
        }
    }


    

}a