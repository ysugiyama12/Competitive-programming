#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)

int main(){   
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string S[310];
    cin >> N;
    rep(i,0,N) cin >> S[i];
    ll ans = 0;
    rep(i,0,N){
        bool ok = true;
        char s2[310][310];
        rep(j,0,N){
            rep(k,0,N){
                s2[j][k] = S[j][(k-i+N)%N];
            }
        }
        rep(j,0,N){
            rep(k,0,N){
                if(s2[j][k] != s2[k][j]) ok = false;
            }
        }
        if(ok) ans += N - i;
    }
    rep(i,1,N){
        bool ok = true;
        char s2[310][310];
        rep(j,0,N){
            rep(k,0,N){
                s2[j][k] = S[(j-i+N)%N][k];
            }
        }
        rep(j,0,N){
            rep(k,0,N){
                if(s2[j][k] != s2[k][j]) ok = false;
            }
        }
        if(ok) ans += N - i;
    }
    print(ans);
}
