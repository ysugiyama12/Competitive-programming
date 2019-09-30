/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
void print() {}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail){ cout << head << " \n"[sizeof...(tail) == 0]; print(forward<Tail>(tail)...);}
lpair mp[2000010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll A[200010], B[200010];
    rep(i,0,N) cin >> A[i];
    rep(i,0,M) cin >> B[i];
    rep(i,0,2e6+1){
        mp[i] = make_pair(-1,-1);
    }
    rep(i,0,N){
        rep(j,0,M){
            ll v = A[i] + B[j];
            lpair l1 = mp[v];
            if(l1.first == -1){
                mp[v] = make_pair(i, j);
            }else{
                if(i == l1.first || j == l1.second) continue;
                cout << i << " " << j << " " << l1.first << " " << l1.second << endl;
                return 0;
            }
        }
    }
    print(-1);
}