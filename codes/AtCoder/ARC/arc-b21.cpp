#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,C;
    cin >> N >> C;
    ll a[110];
    rep(i,0,N){
        cin >> a[i];
    }
    ll ans = INF;
    rep(i,1,11){
        rep(j,1,11){
            if(i == j) continue;
            ll tt = 0;
            rep(k,0,N){
                if(k % 2 == 0){
                    if(a[k] != i){
                        tt += C;
                    }
                }else{
                    if(a[k] != j){
                        tt += C;
                    }
                }

            }
            ans = min(ans, tt);
        }
    }
    print(ans);
}
