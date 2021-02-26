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
    ll N;
    ll X[1010], Y[1010];
    cin >> N;
    rep(i,0,N) cin >> X[i] >> Y[i];
    rep(i,0,N){
        if(abs(X[i]) > 15 || abs(Y[i]) > 15) return 0;
    }
    ll v = (ll)(abs(X[0]) + (ll)abs(Y[0])) % 2;
    bool ok = true;
    rep(i,1,N){
        ll tmp = (abs(X[i]) + abs(Y[i])) % 2;
        if(v != tmp) ok = false;
    }
    if(!ok){
        print(-1);
        return 0;
    }
    ll mv = (v == 0 ? 40 : 39);
    print(mv);
    rep(i,0,mv){
        cout << 1 << " \n"[i == mv-1];
    }
    rep(i,0,N){
        ll cnt = 0;
        if(X[i] >= 0){
            rep(j,0,X[i]){
                cnt++;
                cout << 'R';
            }
        }else{
            rep(j,0,abs(X[i])){
                cnt++;
                cout << 'L';
            }
        }
        if(Y[i] >= 0){
            rep(j,0,Y[i]){
                cnt++;
                cout << 'U';
            }
        }else{
            rep(j,0,abs(Y[i])){
                cnt++;
                cout << 'D';
            }
        }
        rep(i,0,(mv-cnt)/2){
            cout << "LR";
        }
        cout << endl;

    }

    
}
