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
    ll N;
    cin >> N;
    bool is_ok = false;
    ll val = -1;
    rep(i,0,N+1){
        if(i * (i+1) == 2 * N){
            val = i;
            is_ok = true;
        }
    }
    if(!is_ok){
        print("No");
        return 0;
    }else{
        print("Yes");
        print(val+1);
        vector<ll> arr[500];
        ll ss = 0;
        ll gg = 1;
        rep(j,1,N+1){
            arr[ss].push_back(j);
            arr[gg].push_back(j);
            gg++;
            if(gg == val+1){
                ss++;
                gg = ss+1;
            }
        }
        rep(i,0,val+1){
            cout << val << " ";
            ll vsize = arr[i].size();
            rep(j,0,vsize){
                if(j == vsize-1){
                    cout << arr[i][j] << endl;;
                }else{
                    cout << arr[i][j] << " ";
                }
            }
        }

    }
}
