/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
void print() {}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail){ cout << head << " \n"[sizeof...(tail) == 0]; print(forward<Tail>(tail)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string A[310], B[310];
    rep(i,0,N) cin >> A[i];
    rep(i,0,N) cin >> B[i];
    vector<ll> vy[310];
    rep(i,0,N){
        rep(j,0,N){
            if(A[i][j] == '1'){
                vy[i].push_back(j);
            }
        }
    }
    vector<ll> vx[310];
    rep(i,0,N){
        for(auto &e: vy[i]){
            vx[e].push_back(i);
        }
    }
    ll edge[310][310] = {};
    rep(i,0,N){
        ll bit[310] = {};
        if(vx[i].size() == 0) continue;
        ll s = vx[i][0];
        rep(j,0,N){
            bit[j] = (B[s][j] == '1') ? 1 : 0;
        }
        for(auto &e: vx[i]){
            rep(j,0,N){
                if(B[e][j] == '0'){
                    bit[j] = 0;
                }
            }
        }
        rep(j,0,N){
            if(bit[j] == 1) edge[i][j] = 1;
        }
    }
    // rep(i,0,N){
    //     rep(j,0,N){
    //         if(edge[i][j]) print(i,j);
    //     }
    // }
    bool ok = true;
    rep(x,0,N){
        rep(z,0,N){
            if(B[x][z] == '1'){
                bool flg = false;
                rep(y,0,N){
                    if(A[x][y] == '1' && edge[y][z] == 1){
                        flg = true;
                    }
                }
                if(not flg) ok = false;       
            }else{
                bool flg = true;
                rep(y,0,N){
                    if(A[x][y] == '1' && edge[y][z] == 1){
                        flg = false;
                    }
                }
                if(not flg) ok = false;
            }
        }
    }
    if(ok){
        rep(i,0,N){
            rep(j,0,N){
                if(edge[i][j]) cout << '1';
                else cout << '0';
            }
            cout << endl;
        }
    }else{
        print(-1);
    }
    
}