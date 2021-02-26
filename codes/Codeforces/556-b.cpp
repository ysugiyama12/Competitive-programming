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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    char C[55][55];
    rep(i,0,N){
        rep(j,0,N){
            cin >> C[i][j];
        }
    }
    ll cnt = 0;
    rep(i,0,N){
        rep(j,0,N){
            if(C[i][j] == '.') cnt++;
        }
    }
    if(cnt % 5 != 0){
        print("NO");
        return 0;
    }
    ll check[55][55] = {};
    ll dx[4] = {0,0,1,-1};
    ll dy[4] = {1,-1,0,0};
    ll cnt2 = 0;
    rep(i,0,N){
        rep(j,0,N){
            if(C[i][j] == '#') check[i][j] = 1;
        }
    }
    rep(i,1,N-1){
        rep(j,1,N-1){
            bool ok = true;
            if(check[i][j]) ok = false;
            rep(k,0,4){
                ll xx = i + dx[k];
                ll yy = j + dy[k];
                if(check[xx][yy] == 1){
                    ok = false;
                }
            }
            if(ok){
                check[i][j] = 1;
                rep(k,0,4){
                    ll xx = i + dx[k];
                    ll yy = j + dy[k];
                    check[xx][yy] = 1;                  
                }
                cnt2 += 5;
            }
        }
    }
    if(cnt == cnt2){
        print("YES");
    }else{
        print("NO");
    }

    
}