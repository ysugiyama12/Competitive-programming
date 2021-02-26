/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,P;
    cin >> N >> M >> P;
    ll A[5010], B[5010], C[5010];
    vector<lpair> tree[2510];
    rep(i,0,M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
        C[i] -= P;
        C[i] *= -1;
        tree[A[i]].push_back(make_pair(B[i], C[i]));
        tree[B[i]].push_back(make_pair(A[i], C[i]));
    }
    ll dist[2510] = {};
    rep(i,1,N) dist[i] = INF;
    rep(loop, 0, N-1){
        rep(i,0,M){
            if(dist[A[i]] == INF) continue;
            if(dist[B[i]] > dist[A[i]] + C[i]){
                dist[B[i]] = dist[A[i]] + C[i];
            }
        }
    }
    ll ans = dist[N-1];

    bool negative[2510];
    rep(i,0,N) negative[i] = false;
    rep(loop,0,N){
        rep(i,0,M){
            if(dist[A[i]] == INF) continue;
            if(dist[B[i]] > dist[A[i]] + C[i]){
                dist[B[i]] = dist[A[i]] + C[i];
                negative[B[i]] = true;
            }

            if(negative[A[i]] == true) negative[B[i]] = true;
        }
    }
    if(negative[N-1]){
        print(-1);
    }else{
        if(dist[N-1] > 0){
            print(0);
        }else{
            print(dist[N-1] * -1);
        }
    }


}