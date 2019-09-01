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
inline ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M,Q;
    cin >> N >> M >> Q;
    ll v2 = gcd(N, M);
    while(Q--){
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sy--; ey--;
        if(sx == 1 && ex == 1){
            ll v = N / v2;
            if(sy / v == ey / v){
                print("YES");
            }else{
                print("NO");
            }
        }else if(sx == 2 && ex == 2){
            ll v = M / v2;
            if(sy / v == ey / v){
                print("YES");
            }else{
                print("NO");
            }
        }else if(sx == 1 && ex == 2){
            ll va = N / v2;
            ll vb = M / v2;
            if(sy / va == ey / vb){
                print("YES");
            }else{
                print("NO");
            }     
        }else{
            ll va = N / v2;
            ll vb = M / v2;
            if(sy / vb == ey / va){
                print("YES");
            }else{
                print("NO");
            }    
        }
        

    }

    
}