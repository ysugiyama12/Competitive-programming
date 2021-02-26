#include <bits/stdc++.h>
#include <unordered_map>
#define rep(i,m,n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
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
ll A[200010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    ll lv = 0, rv = N;
    while(rv - lv > 1){
        map<ll,ll> mp;
        ll K = (lv + rv)/2;
        bool is_ok = true;
        rep(i,1,N){
            if(A[i-1] < A[i]) continue;
            if(K == 1 && N >= 2){
                is_ok = false;
                continue;
            }
            ll pre = A[i];
            mp.erase(mp.upper_bound(pre),mp.end());
            while(mp[pre] == K-1){
                mp[pre] = 0;
                pre--;
                if(pre == 0) is_ok = false;
            }
            mp[pre]++;
        }
        if(is_ok){
            rv = K;
        }else{
            lv = K;
        }
    }
    print(rv);
}
