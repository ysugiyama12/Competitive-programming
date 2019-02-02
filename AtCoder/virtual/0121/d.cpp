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
    string S,T;
    ll q;
    ll a[100010], b[100010], c[100010], d[100010];
    cin >> S >> T;
    cin >> q;
    rep(i,0,q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--; c[i]--; d[i]--;
    }
    ll ssum[100010] = {};
    ll tsum[100010] = {};
    ll sn = S.size();
    ll tn = T.size();
    rep(i,0,sn){
        if(S[i] == 'A'){
            ssum[i+1] = ssum[i] + 1; 
        }else{
            ssum[i+1] = ssum[i] + 2;
        }
    }
    rep(i,0,tn){
        if(T[i] == 'A'){
            tsum[i+1] = tsum[i] + 1;
        }else{
            tsum[i+1] = tsum[i] + 2;
        }
    }
    rep(i,0,q){
        if((ssum[b[i]+1] - ssum[a[i]] - tsum[d[i]+1] + tsum[c[i]]) % 3 == 0){
            print("YES");
        }else{
            print("NO");
        }
    }
}
