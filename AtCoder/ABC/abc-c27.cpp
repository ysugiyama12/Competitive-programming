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
    ll depth = 0;
    ll nn = N;
    while(nn > 0){
        depth++;
        nn /= 2;
    }
    ll n = 1, cnt = 0;
    if(depth % 2 == 0){
        while(n <= N){
            if(cnt % 2 == 0){
                n *= 2;
            }else{
                n *= 2;
                n += 1;
            }
            cnt++;
        }
    }else{
        while(n <= N){
            if(cnt % 2 == 0){
                n *= 2;
                n += 1;
            }else{
                n *= 2;
            }
            cnt++;
        }
    }
    if(cnt % 2 == 0){
        print("Takahashi");
    }else{
        print("Aoki");
    }
}
