#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll K[35];
    ll A[35][35];
    rep(i,0,N){
        cin >> K[i];
        rep(j,0,K[i]){
            cin >> A[i][j];
        }
    }
    ll m[35] = {};
    rep(i,0,N){
        rep(j,0,K[i]){
            m[A[i][j]]++;
        }
    }
    ll ans = 0;
    rep(i,1,M+1){
        if(m[i] == N) ans++;
    }
    print(ans);

}
