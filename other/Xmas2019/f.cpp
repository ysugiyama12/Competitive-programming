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
ll sum[1010][1010] = {};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H,W;
    cin >> H >> W;
    string S[1010];
    rep(i,0,H){
        cin >> S[i];
    }
    rep(i,0,H){
        rep(j,0,W){
            if(S[i][j] == '.') sum[i+1][j+1] = 1;
        }
    }
    rep(i,0,H+1){
        rep(j,0,W+1){
            sum[i][j+1] += sum[i][j];
        }
    }
    rep(j,0,W+1){
        rep(i,0,H+1){
            sum[i+1][j] += sum[i][j];
        }
    }
    ll cnt = 0;
    vector<ll> tate[1010], yoko[1010];
    rep(i,0,H){
        rep(j,0,W){
            if(S[i][j] == '.'){
                cnt++;
            }
            tate[j].push_back(i);
            yoko[i].push_back(j);
        }
    }

    if(cnt == 0){
        print(0);
        return 0;
    }
    // [i, i+H/2]
    rep(i,0,H/2+1){
        rep(j,0,W/2+1){
            ll v = sum[i+H/2][j+W/2] - sum[i+H/2][j] - sum[i][j+W/2] + sum[i][j];
            if(v == cnt){
                print(1);
                return 0;
            }
        }
    })
    rep(i,0,H/2+1){
        rep(j,0,W/2+1){

        }
    }



    

}