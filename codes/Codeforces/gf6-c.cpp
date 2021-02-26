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
    ll R,C;
    cin >> R >> C;
    ll ans[510][510] = {};
    if(R == 1 && C == 1){
        print(0);
        return 0;
    }else if(R == 1){
        rep(j,0,C){
            ans[0][j] = j+2;
        }
    }else if(C == 1){
        rep(i,0,R){
            ans[i][0] = i+2;
        }

    }else{
        rep(r,0,R){
            rep(c,0,C){
                ans[r][c] = (C+1+r) * (c+1);
            }
        }
    }
    rep(i,0,R){
        rep(j,0,C){
            cout << ans[i][j] << " \n"[j==C-1];
        }
    }
    

}