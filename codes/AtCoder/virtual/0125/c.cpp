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
bool check(string s){
    bool ok = true;
    ll N = s.size();
    ll lv = 0, rv = 0;
    rep(i,0,N){
        if(s[i] == '('){
            lv++;
        }else{
            if(lv > 0){
                lv--;
            }else{
                return false;
            }
        }
    }
    if(lv == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Q;
    ll a[200010], b[200010];
    ll p[100010], x[100010], y[100010];
    cin >> N >> Q;
    rep(i,0,2*N) cin >> a[i];
    rep(i,0,2*N) cin >> b[i];
    rep(i,0,Q) cin >> p[i] >> x[i] >> y[i];
    if(N > 5 || Q > 10) return 0;
    rep(tt,0,Q){
        p[tt]--;
        ll a1 = a[p[tt]]; ll b1 = b[p[tt]];
        a[p[tt]] = x[tt]; b[p[tt]] = y[tt];
        ll ans = 0;
        rep(i,0,pow(2,2*N)){
            rep(j,0,pow(2,2*N)){
                ll ans_tmp = 0;
                string s = "", t = "";
                rep(k,0,2*N){
                    if((i>>k) & 1){
                        s += '(';
                    }else{
                        s += ')';
                    }
                }
                rep(k,0,2*N){
                    if((j>>k) & 1){
                        t += '(';
                    }else{
                        t += ')';
                    }
                }
                if(!check(s) || !check(t)) continue;
                rep(k,0,2*N){
                    if(s[k] == t[k]){
                        ans_tmp += a[k];
                    }else{
                        ans_tmp += b[k];
                    }
                }
                ans = max(ans, ans_tmp); 
            }
        }
        print(ans);
    }

}
