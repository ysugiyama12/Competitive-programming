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
ll H,W;
string S[410];
ll checked[410][410] = {};
ll parent[200010];

ll root(ll x){
    if(x == parent[x]){
        return x;
    }else{
        return parent[x] = root(parent[x]);
    }
}

void unite(ll a, ll b){
    a = root(a);
    b = root(b);
    if(a == b){
        return;
    }
    parent[a] = b;
}

bool same(ll a, ll b){
    return root(a) == root(b);
}
ll cc(ll h, ll w){
    return w + h*W;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    rep(i,0,H){
        cin >> S[i];
    }
    rep(i,0,H){
        rep(j,0,W){
            parent[cc(i,j)] = cc(i,j);
        }
    }
    rep(i,0,H){
        rep(j,0,W){
            if(S[i][j] == '.'){
                if(i != 0){
                    if(S[i-1][j] == '#') unite(cc(i,j), cc(i-1,j));
                }
                if(i != H-1){
                    if(S[i+1][j] == '#') unite(cc(i,j), cc(i+1,j));
                }
                if(j != 0){
                    if(S[i][j-1] == '#') unite(cc(i,j), cc(i,j-1));
                }
                if(j != W-1){
                    if(S[i][j+1] == '#') unite(cc(i,j), cc(i,j+1));
                }
            }else{
                if(i != 0){
                    if(S[i-1][j] == '.') unite(cc(i,j), cc(i-1,j));
                }
                if(i != H-1){
                    if(S[i+1][j] == '.') unite(cc(i,j), cc(i+1,j));
                }
                if(j != 0){
                    if(S[i][j-1] == '.') unite(cc(i,j), cc(i,j-1));
                }
                if(j != W-1){
                    if(S[i][j+1] == '.') unite(cc(i,j), cc(i,j+1));
                }
            }
        }
    }
    map<ll,ll> mp1, mp2;
    rep(i,0,H){
        rep(j,0,W){
            ll roots = root(cc(i,j));
            if(S[i][j] == '#'){
                mp1[roots]++;
            }else{
                mp2[roots]++;
            }
        }
    }
    ll ans = 0;
    for(auto &e: mp1){
        ll pos = e.first;
        ll val = e.second;
        ans += val * mp2[pos];
    }
    print(ans);
}
