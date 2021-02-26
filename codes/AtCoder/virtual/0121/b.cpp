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
    string A;
    cin >> A;
    ll N = A.size();
    ll ans = 1 + N * (N-1) / 2;
    ll cnt[30] = {};
    rep(i,0,N){
        cnt[A[i] - 'a']++;
    }
    rep(i,0,26){
        if(cnt[i] >= 2){
            ans -= cnt[i] * (cnt[i]-1)/2;
        }
    }
    print(ans);

}
