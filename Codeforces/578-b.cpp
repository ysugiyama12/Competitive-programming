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
    ll T;
    cin >> T;
    while(T--){
        ll N,M,K;
        cin >> N >> M >> K;
        ll h[110];
        rep(i,0,N) cin >> h[i];
        bool ok = true;
        ll have = M;
        rep(i,1,N){
            if(h[i-1] > h[i]){
                have += h[i-1] - h[i];
                h[i-1] = h[i];
                have += min(h[i-1], K);
            }else{
                if(h[i] - h[i-1] <= K){
                    ll diff = h[i] - h[i-1];
                    have += min(K - diff, h[i-1]);
                }else{
                    ll amari = (h[i] - h[i-1]) - K;
                    if(amari > have){
                        ok = false;
                    }else{
                        have -= amari;
                    }
                }
            }
        }
        if(ok){
            print("YES");
        }else{
            print("NO");
        }
    } 
}