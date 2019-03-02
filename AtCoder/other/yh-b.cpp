#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a[3], b[3];
    rep(i,0,3) cin >> a[i] >> b[i];
    ll cnt[5] = {};
    rep(i,0,3){
        cnt[a[i] - 1]++;
        cnt[b[i] - 1]++;
    }
    sort(cnt, cnt+4, greater<ll>());
    if(cnt[0] == 2 && cnt[1] == 2 && cnt[2] == 1 && cnt[3] == 1){
        print("YES");
    }else{
        print("NO");
    }
}