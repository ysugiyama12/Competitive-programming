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
    ll s[100010], t[100010];
    cin >> N;
    rep(i,0,N){
        cin >> s[i];
    }
    rep(i,0,N){
        cin >> t[i];
    }
    if(s[0] != t[0] || s[N-1] != t[N-1]){
        print("No");
        return 0;
    }
    ll d1[100010], d2[100010];
    rep(i,0,N-1){
        d1[i] = s[i+1] - s[i];
        d2[i] = t[i+1] - t[i];
    }
    sort(d1,d1+N-1);
    sort(d2,d2+N-1);
    rep(i,0,N-1){
        if(d1[i] != d2[i]){
            print("No");
            return 0;
        }
    }
    print("Yes");

}
