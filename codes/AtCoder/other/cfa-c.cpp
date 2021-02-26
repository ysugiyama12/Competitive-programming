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
    ll H,W;
    char a[110][110];
    cin >> H >> W;
    rep(i,0,H) rep(j,0,W) cin >> a[i][j];
    map<char, ll> mp;
    rep(i,0,H) rep(j,0,W) mp[a[i][j]]++;
    bool flg = true;
    if(H % 2 == 0 && W % 2 == 0){
        for(auto &e: mp){
            if(e.second % 4 != 0) flg = false;
        }   
    }else if(H % 2 == 0 && W % 2 != 0){
        ll cnt2 = 0;
        for(auto &e: mp){
            if(e.second % 2 != 0){
                flg = false;
            }else if(e.second % 4 != 0){
                cnt2++;
            }
        }
        if(cnt2 > H/2) flg = false;
    }else if(H % 2 != 0 && W % 2 == 0){
        ll cnt2 = 0;
        for(auto &e: mp){
            if(e.second % 2 != 0){
                flg = false;
            }else if(e.second % 4 != 0){
                cnt2++;
            }
        }
        if(cnt2 > W/2) flg = false;
    }else{
        ll cnt2 = 0, cnt1 = 0;
        for(auto &e: mp){
            if(e.second % 2 != 0){
                cnt1++;
            }else if(e.second % 4 != 0){
                cnt2++;
            }
        }
        if(cnt1 > 1) flg = false;
        if(cnt2 > W/2 + H/2) flg = false;
    }
    if(flg){
        print("Yes");
    }else{
        print("No");
    }
}
