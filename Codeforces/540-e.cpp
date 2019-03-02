#include <bits/stdc++.h>
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
    ll N,K;
    cin >> N >> K;
    if(K*K - K < N){
        print("NO");
        return 0;
    }
    print("YES");
    ll cnt = 0;
    rep(diff,1,K){
        rep(i,0,K-diff){
            cout << i+1 << " " << i+1+diff << endl;
            cnt++;
            if(cnt == N) return 0;
        }
        rrep(i,K-diff-1,0){
            cout << i+1+diff << " " << i+1 << endl;
            cnt++;
            if(cnt == N) return 0;
        }
    }
}
