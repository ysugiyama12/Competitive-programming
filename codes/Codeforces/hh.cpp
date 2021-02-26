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
    ll N, M;
    ll s[200010], a[200010];
    cin >> N;
    rep(i,0,N) cin >> s[i];
    cin >> M;
    rep(i,0,M) cin >> a[i];
    ll rank[200010] = {};
    sort(s, s+N);
    ll tt = 1;
    rank[N-1] = 1;
    rrep(i,N-2,0){
        if(s[i] != s[i+1]){
            tt++;
            rank[i] = tt;
        }else{
            rank[i] = tt;
        }
    }
    rep(i,0,M){
        ll pos = upper_bound(s, s+N, a[i]) - s;
        if(s[pos] == a[i]){
            print(rank[pos]);
        }else{
            print(rank[pos] + 1);
        }
    }
    


}
