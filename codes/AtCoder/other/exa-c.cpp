#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    char t[200010], d[200010];
    rep(i,0,Q){
        cin >> t[i] >> d[i];
    }
    ll lv = -1, rv = N;
    while(rv - lv > 1){
        ll mid = (rv + lv) / 2;
        ll pos = mid;
        char alpha = S[mid];
        bool ok = true;
        rep(i,0,Q){
            if(t[i] == S[pos]){
                if(d[i] == 'R'){
                    pos++;
                }else{
                    pos--;
                }
                if(pos == -1){
                    ok = false;
                    break;
                }else if(pos == N){
                    break;
                }
            }
        }
        if(ok){
            rv = mid;
        }else{
            lv = mid;
        }

    }
    ll v1 = rv;
    lv = -1, rv = N;
    while(rv - lv > 1){
        ll mid = (rv + lv) / 2;
        ll pos = mid;
        char alpha = S[mid];
        bool ok = true;
        rep(i,0,Q){
            if(t[i] == S[pos]){
                if(d[i] == 'R'){
                    pos++;
                }else{
                    pos--;
                }
                if(pos == N){
                    ok = false;
                    break;
                }else if(pos == -1){
                    break;
                }
            }
        }
        if(ok){
            lv = mid;
        }else{
            rv = mid;
        }

    }
    ll v2 = lv;
    print(v2 - v1 + 1);
}