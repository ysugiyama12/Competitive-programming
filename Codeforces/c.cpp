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
    ll a[2010];
    cin >> N;
    rep(i,0,N){
        cin >> a[i];
    }
    bool flg = true;
    rep(i,1,N){
        if(a[i-1] >= a[i]){
            flg = false;
        }
    }
    if(flg){
        print(0);
        return 0;
    }
    ll cnt = 0;
    vector<string> ans;
    for(int i = N-1; i >= 0; i--){
        ll amari = i;
        ll m = a[i] % N;
        if(m != amari){
            if(m < amari){
                rep(j,0,i+1){
                    a[j] += amari - m;
                }
                ans.push_back("1 " + to_string(i+1) + " " + to_string(amari-m));
                cnt++;
                // cout << 1 << " " << i+1 << " " << amari-m << endl;
            }else{
                rep(j,0,i+1){
                    a[j] += (N - m) + amari;
                }
                ans.push_back("1 " + to_string(i+1) + " " + to_string((N - m) + amari));
                cnt++;
                // cout << 1 << " " << i+1 << " " << (N - m) + amari << endl;
            }
        }
    }
    ans.push_back("2 " + to_string(N) + " " + to_string(N));
    cnt++;
    print(cnt);
    rep(i,0,ans.size()){
        print(ans[i]);
    }
    // cout << 2 << " " << N << " " << N << endl;

}
