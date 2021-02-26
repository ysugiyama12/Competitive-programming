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
ll R,C,D;
ll A[1010][1010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> R >> C >> D;
    rep(i,0,R){
        rep(j,0,C){
            cin >> A[i][j];
        }
    }
    vector<ll> d[100010];
    rep(i,0,R){
        rep(j,0,C){
            d[i+j].push_back(A[i][j]);
        }
    }
    ll ans = 0;
    if(D % 2 == 0){
        rep(i,0,R+C+1){
            if(i % 2 == 0 && i <= D){
                for(auto &e: d[i]){
                    ans = max(ans, e);
                }
            }
        }
    }else{
        rep(i,0,R+C+1){
            if(i % 2 != 0 && i <= D){
                for(auto &e: d[i]){
                    ans = max(ans, e);
                }
            }
        }
    }
    print(ans);

}
