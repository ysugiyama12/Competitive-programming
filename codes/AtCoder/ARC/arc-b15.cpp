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
    ll N;
    ll M[4000], m[4000];
    cin >> N;
    rep(i,0,N){
        double a,b;
        cin >> a >> b;
        M[i] = 10*a; m[i] = 10*b;
    }
    ll ans[6] = {};
    rep(i,0,N){
        if(M[i] >= 350) ans[0]++;
        if(M[i] >= 300 && M[i] < 350) ans[1]++;
        if(M[i] >= 250 && M[i] < 300) ans[2]++;
        if(m[i] >= 250) ans[3]++;
        if(m[i] < 0 && M[i] >= 0) ans[4]++;
        if(M[i] < 0) ans[5]++;
    }
    printa(ans,6);
}
