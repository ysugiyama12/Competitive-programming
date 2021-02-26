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
    ll a[100010], b[100010];
    cin >> N;
    rep(i,0,N) cin >> a[i];
    rep(i,0,N) cin >> b[i];
    sort(a,a+N);
    sort(b,b+N);
    vector<lpair> lp;
    rep(i,0,N) lp.push_back(make_pair(a[i], 0));
    rep(i,0,N) lp.push_back(make_pair(b[i], 1));
    sort(lp.begin(), lp.end());
    ll ans = 1;
    ll v1 = 0, v2 = 0;
    rep(i,0,N*2){
        if(lp[i].second == 0){
            if(v2 == 0){
                v1++;
            }else{
                ans *= v2 % MOD;
                ans %= MOD;
                v2--;
            }
        }else{
            if(v1 == 0){
                v2++;
            }else{
                ans *= v1 % MOD;
                ans %= MOD;
                v1--;
            }
        }
        // print2(v1,v2);
    }
    print(ans);
}
