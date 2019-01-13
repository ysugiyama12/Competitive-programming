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
    ll N,A,B;
    cin >> N >> A >> B;
    ll P[110];
    rep(i,0,N){
        cin >> P[i];
    }
    sort(P, P+N);
    ll ans = 0;
    ll c1 = 0, c2 = 0, c3 = 0;
    rep(i,0,N){
        if(P[i] <= A) c1++;
        if(P[i] >= A+1 && P[i] <= B) c2++;
        if(P[i] >= B+1) c3++;
    }
    ans = min(c1, min(c2,c3));
    print(ans);
}
