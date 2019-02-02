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
ll cc(ll i, ll j){
    return i * 10 + j;
}
ll parent[200010];

ll root(ll x){
    if(x == parent[x]) return x;
    else return parent[x] = root(parent[x]);
}

void unite(ll a, ll b){
    a = root(a); b = root(b);
    if(a == b) return;
    parent[a] = b;
}

bool same(ll a, ll b){
    return root(a) == root(b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    char A[20][20];
    rep(i,0,10){
        rep(j,0,10){
            cin >> A[i][j];
        }
    }
    ll dh[4] = {0,0,-1,1};
    ll dw[4] = {1,-1,0,0};

    rep(h,0,10){
        rep(w,0,10){
            if(A[h][w] == 'o') continue;
            A[h][w] = 'o';
            rep(i,0,10){
                rep(j,0,10){
                    if(A[i][j] == 'o'){
                        parent[cc(i,j)] = cc(i,j);
                    }else{
                        parent[cc(i,j)] = cc(i,j);
                        // parent[cc(i,j)] = -1;
                    }
                }
            }
            rep(i,0,10){
                rep(j,0,10){
                    rep(k,0,4){
                        ll hh = i+dh[k];
                        ll ww = j+dw[k];

                        if(hh < 0 || hh >= 10 || ww < 0 || ww >= 10) continue;
                        if(A[i][j] == 'o' && A[hh][ww] == 'o'){
                            unite(cc(i,j), cc(hh,ww));
                        }
                    }
                }
            }
            map<ll,ll> mp;
            rep(i,0,10){
                rep(j,0,10){
                    if(A[i][j] == 'o'){
                        mp[root(cc(i,j))]++;
                    }
                }
            }
            if(mp.size() == 1){
                print("YES");
                return 0;
            }

            A[h][w] = 'x';

        }
    }
    print("NO");
}
