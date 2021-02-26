#include <bits/stdc++.h>
#include <unordered_map>
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
    ll N,M;
    ll a[100010], b[100010];
    cin >> N >> M;
    rep(i,0,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        if(a[i] > b[i]) swap(a[i], b[i]);
    }
    ll v[100010] = {};
    rep(i,0,M){
        v[a[i]]++;
        v[b[i]]--;
    }
    rep(i,0,N+2){
        v[i+1] += v[i];
    }
    bool ok = true;
    rep(i,0,N-1){
        if(v[i] % 2 != 0) ok = false;
    }
    // printa(v,N);
    if(ok){
        print("YES");
    }else{
        print("NO");
    }
}
