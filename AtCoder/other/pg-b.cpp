/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
#define print(x) cout << (x) << endl;
#define print2(x, y) cout << (x) << " " << (y) << endl;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll A,B,C;
    cin >> A >> B >> C;
    rep(a,0,N+1){
        ll v = M - a * A;
        if(v < 0) continue;
        if(B == C){
            if((N-a) * B == v){
                cout << a << " " << 0 << " " << N-a << endl;
                return 0;
            }
        }else{
            if(B > C){
                ll tt = v - C * (N - a);
                if(tt >= 0 && tt % (B-C) == 0){
                    ll shou = tt / (B-C);
                    if(shou >= 0 && shou <= N-a){
                        cout << a << " " << shou << " " << N-a-shou << endl;
                        return 0;
                    }
                }
            }else{
                ll tt = C * (N-a) - v;
                if(tt >= 0 && tt % (C-B) == 0){
                    ll shou = tt / (C-B);
                    if(shou >= 0 && shou <= N-a){
                        cout << a << " " << shou << " " << N-a-shou << endl;
                        return 0;
                    }
                }
            }
        }
    }
    print("-1 -1 -1");

    
}