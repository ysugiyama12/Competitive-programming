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
    ll t;
    cin >> t;
    while(t--){
        ll N;
        cin >> N;
        vector<ll> p(N);
        rep(i,0,N) cin >> p[i];
        bool ok = true;
        vector<ll> pos(N+1, 0);
        rep(i,0,N) pos[p[i]] = i;
        ll cur = pos[1];
        vector<bool> check(N+1, 0);
        check[cur] = true;
        rep(n,2,N+1){
            if(pos[n] == cur+1){
                cur = pos[n];
                check[cur] = true;
            }else{
                if(cur == N-1 || check[cur+1] == true){
                    cur = pos[n];
                    check[cur] = true;
                }else{
                    ok = false;
                    break;
                }
            }
        }
        if(ok){
            print("Yes");
        }else{
            print("No");
        }

    }
    

}