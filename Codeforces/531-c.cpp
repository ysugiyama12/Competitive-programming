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
    ll N,x,y;
    ll a[110];
    cin >> N >> x >> y;
    rep(i,0,N){
        cin >> a[i];
    }
    sort(a, a+N);
    ll ans = 0;
    if(x > y){
        ans = N;
    }else{
        ll cnt = 0;
        rep(i,0,N){
            if(a[i] <= x){
                cnt++;
            }
        }
        ans = (cnt+1)/2;
    }
    print(ans);
}
