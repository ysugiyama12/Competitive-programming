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
    ll N,M;
    cin >> N >> M;
    ll A[1010], B[1010], C[1010];
    vector<lpair> tree[410];
    ll dist[410][410] = {};
    rep(i,0,N){
        rep(j,0,N){
            if(i == j){
                dist[i][j] = 0;
            }else{
                dist[i][j] = INF;
            }
        }
    }
    rep(i,0,M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
        tree[A[i]].push_back({B[i], C[i]});
        tree[B[i]].push_back({A[i], C[i]});
        dist[A[i]][B[i]] = C[i];
        dist[B[i]][A[i]] = C[i];
    }
    rep(k,0,N){
        rep(i,0,N){
            rep(j,0,N){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll K;
    cin >> K;
    ll X[410], Y[410], Z[410];
    rep(i,0,K){
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--; Y[i]--;
        dist[X[i]][Y[i]] = min(dist[X[i]][Y[i]], Z[i]);
        dist[Y[i]][X[i]] = min(dist[Y[i]][X[i]], Z[i]);
        rep(j,0,N){
            rep(k,0,N){
                dist[j][k] = min(dist[j][k], dist[j][X[i]] + dist[Y[i]][k] + Z[i]);
                dist[j][k] = min(dist[j][k], dist[j][Y[i]] + dist[X[i]][k] + Z[i]);
            }
        }
        ll res = 0;
        rep(j,0,N){
            rep(k,j+1,N){
                res += dist[j][k];
            }
        }
        print(res);
    }

    

}