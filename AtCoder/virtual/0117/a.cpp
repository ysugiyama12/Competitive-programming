#include <bits/stdc++.h>

#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]); if(i!=n-1) cout << " ";} cout << endl;
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    ll v1 = 200/K;
    ll cnt = 0;
    rep(i,0,v1){
        rep(j,0,v1){
            bool flg = true;
            if((i*K - 100)*(i*K - 100) + (j*K - 100)*(j*K - 100) > 10000) flg = false;
            if(((i+1)*K - 100)*((i+1)*K - 100) + (j*K - 100)*(j*K - 100) > 10000) flg = false;
            if((i*K - 100)*(i*K - 100) + ((j+1)*K - 100)*((j+1)*K - 100) > 10000) flg = false;
            if(((i+1)*K- 100)*((i+1)*K - 100) + ((j+1)*K  - 100)*((j+1)*K  - 100) > 10000) flg = false;
            if(flg) cnt++;
        }
    }
    cout << cnt << " ";
    cnt = 0;
    v1 = 300 / K;
    rep(i,0,v1){
        rep(j,0,v1){
            bool flg = true;
            if((i*K - 150)*(i*K - 150) + (j*K - 150)*(j*K - 150) > 150*150) flg = false;
            if(((i+1)*K - 150)*((i+1)*K - 150) + (j*K - 150)*(j*K - 150) > 150*150) flg = false;
            if((i*K - 150)*(i*K - 150) + ((j+1)*K - 150)*((j+1)*K - 150) > 150*150) flg = false;
            if(((i+1)*K- 150)*((i+1)*K - 150) + ((j+1)*K  - 150)*((j+1)*K  - 150) > 150*150) flg = false;
            if(flg) cnt++;
        }
    }
    cout << cnt << endl;

    
}
