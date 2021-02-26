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
    ll n,m;
    ll a[310];
    cin >> n >> m;
    rep(i,0,n) cin >> a[i];
    ll l[310], r[310];
    rep(i,0,m){
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }
    ll ans = 0;
    lpair pos;
    ll cnt = 0;
    rep(i,0,n){
        rep(j,0,n){
            if(i == j) continue;
            ll max_v = a[i];
            ll min_v = a[j];
            ll cnt_tmp = 0;
            rep(k,0,m){
                if(j >= l[k] && j <= r[k]){
                    min_v--;
                    cnt_tmp++;
                    if(i >= l[k] && i <= r[k]){
                        max_v--;
                    }
                }
            }
            if(ans < max_v - min_v){
                ans = max_v - min_v;
                pos = make_pair(i,j);
                cnt = cnt_tmp;
            }

        }
    }
    print(ans);
    print(cnt);
    // print2(pos.first, pos.second);
    ll num = 0;
    rep(i,0,m){
        if(num == cnt){
            cout << endl;
            return 0;
        }
        if(pos.second >= l[i] && pos.second <= r[i]){
            cout << i+1 << " ";
            num++;
        }
    }
    cout << endl;

}
