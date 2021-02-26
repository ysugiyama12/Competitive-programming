#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,D,K;
    ll L[10010], R[10010];
    ll S[110], T[110];
    cin >> N >> D >> K;
    rep(i,0,D){
        cin >> L[i] >> R[i];
    }
    rep(i,0,K){
        cin >> S[i] >> T[i];
    }
    rep(i,0,K){
        ll l[10010] = {}, r[10010] = {};
        bool is_set = false;
        rep(j,0,D){
            if(!is_set){
                if(S[i] >= L[j] && S[i] <= R[j]){
                    l[j] = L[j];
                    r[j] = R[j];
                    is_set = true;
                }
            }else{
                if((L[j] <= l[j-1] && R[j] >= l[j-1]) || (L[j] <= r[j-1] && R[j] >= r[j-1])){
                    l[j] = min(l[j-1], L[j]);
                    r[j] = max(r[j-1], R[j]);
                }else{
                    l[j] = l[j-1];
                    r[j] = r[j-1];
                }
            }
            // cout << l[j] << " " << r[j] << endl;
            if(S[i] >= l[j] && S[i] <= r[j] && T[i] >= l[j] && T[i] <= r[j]){
                print(j+1);
                break;
            }
        }
    }
}
