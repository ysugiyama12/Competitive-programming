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
    string S[110];
    cin >> N;
    ll v1 = 0, v2 = 0;
    rep(i,0,N){
        cin >> S[i];
        rep(j,0,N){
            if(S[i][j] == 'R') v1++;
            if(S[i][j] == 'B') v2++;
        }
    }
    if(v1 == v2){
        print("DRAW");
    }else if(v1 > v2){
        print("TAKAHASHI");
    }else{
        print("AOKI");
    }
}
