#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
vector<ll> S[55];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll M,N;
    cin >> M >> N;
    ll idx[55] = {};
    rep(i,0,M){
        cin >> idx[i];
        rep(j,0,idx[i]){
            ll tmp;
            cin >> tmp;
            S[i].push_back(tmp);
        }
        sort(S[i].begin(), S[i].end());
        S[i].erase(unique(S[i].begin(), S[i].end()), S[i].end());
    }
    bool ok = true;
    ll A[10010] = {};
    rep(i,0,N){



    }



}