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
    ll N;
    cin >> N;
    ll a[10010], b[10010];
    rep(i,0,N) cin >> a[i];
    rep(i,0,N) cin >> b[i];
    bool ok = true;
    ll cnt1 = 0;
    ll diff = 0;
    rep(i,0,N){
        diff += b[i] - a[i];
    }
    if(diff < 0){
        ok = false;
    }
    rep(i,0,N){
        if(b[i] < a[i]){
            cnt1 += (a[i] - b[i]);
            b[i] = a[i];
        }else if((b[i] - a[i]) % 2 == 1){
            cnt1++;
            b[i]++;
        }
    }
    if(cnt1 > diff){
        ok = false;
    }
    ll cnt2 = 0;
    rep(i,0,N){
        cnt2 += (b[i] - a[i]) / 2;
    }
    if(cnt2 > diff){
        ok = false;
    }
    if(diff - cnt1 != (diff - cnt2) * 2) ok = false;
    if(ok){
        print("Yes");
    }else{
        print("No");
    }
}
