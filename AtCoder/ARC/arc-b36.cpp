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
    ll N;
    ll h[300010];
    cin >> N;
    rep(i,0,N){
        cin >> h[i];
    }
    ll cnt = 0, ans = 0;
    bool is_down = false;
    rep(i,1,N){
        if(h[i-1] < h[i]){
            if(is_down){
                cnt = 0;
                is_down = false;
            }
            cnt++;
        }else{
            is_down = true;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    print(ans+1);
}
