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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    while(Q--){
        ll H,N;
        cin >> H >> N;
        vector<ll> p(N+1);
        rep(i,0,N) cin >> p[i];
        // p[N] = 0;
        ll cnt = 1;
        vector<ll> v;
        rep(i,0,N-1){
            if(p[i] - p[i+1] == 1){
                cnt++;
            }else{
                v.push_back(cnt);
                cnt = 1;
            }
        }
        v.push_back(cnt);
        // printa(v, v.size());
        ll ans = 0;
        ll tt = 0;
        ll sum = 0;
        ll sz = v.size();
        rep(i,0,sz){
            sum += v[i];
            if(sum % 2 == 0){
                if(i == sz-1 && p[N-1] == 1) continue;
                ans++;
                sum++;
            }
        }
        print(ans);


    }
    

}