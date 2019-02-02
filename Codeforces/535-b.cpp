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
    ll n;
    ll d[200];
    cin >> n;
    rep(i,0,n) cin >> d[i];
    sort(d,d+n);
    cout << d[n-1] << " ";
    map<ll, ll> mp;
    ll v = d[n-1];
    mp[v]++;
    rrep(i,n-2,0){
        if(v % d[i] != 0){
            print(d[i]);
            return 0;
        }else{
            if(mp[d[i]] == 1){
                print(d[i]);
                return 0;
            }else{
                mp[d[i]]++;
            }
        }
    }


}
