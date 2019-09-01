/*** author: yuji9511 ***/
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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
ll N,B0,B1,B2;
ll L[35][35], R[35][35];
ll ans[35][35] = {};
struct BIT{
    int dat[ 35 ][ 35 ];
    void update(int x, int y, int v){
        x++; y++;
        for(int i = x; i < N; i += i & -i)
            for(int j = y; j < N; j += j & -j)
                dat[ i ][ j ] += v;
    }
    int qsum(int x, int y){
        int res = 0;
        for(int i = x; i > 0; i -= i & -i)
            for(int j = y; j > 0; j -= j & -j)
                res += dat[ i ][ j ];
        return res;
    }
    int qsum(int x0, int y0, int x1, int y1){
        x0++; y0++; x1++; y1++;
        return qsum( x1, y1 ) - qsum( x0 - 1, y1 ) - qsum( x1, y0 - 1 ) + qsum( x0 - 1, y0 - 1 );
    }

    int get(int x, int y){
        x++; y++;
        return dat[x][y];
    }
} bit;

ll calc2(ll v1, ll v2){
    ll res = 0;
    rep(i,0,N){
        rep(j,i,N){
            ll v = bit.qsum(v1, i, v1, j);
            if(v == B0){
                res += B0;
            }else if(v == B1){
                res += B1;
            }else{
                res += B2;
            }
        }
    }
    rep(i,0,N){
        rep(j,i,N){
            ll v = bit.qsum(i, v2, j, v2);
            if(v == B0){
                res += B0;
            }else if(v == B1){
                res += B1;
            }else{
                res += B2;
            }
        }
    }
    return res;
}

ll calc(ll v1, ll v2){
    ll res = 0;
    rep(i,0,N){
        rep(j,i,N){
            ll tmp = 0;
            rep(k,i,j+1){
                tmp += ans[v1][k];
            }
            if(tmp == B0){
                res += B0;
            }else if(tmp == B1){
                res += B1;
            }else if(tmp == B2){
                res += B2;
            }
        }
    }
    rep(i,0,N){
        rep(j,i,N){
            ll tmp = 0;
            rep(k,i,j+1){
                tmp += ans[k][v2];
            }
            if(tmp == B0){
                res += B0;
            }else if(tmp == B1){
                res += B1;
            }else if(tmp == B2){
                res += B2;
            }
        }
    }
    return res;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> B0 >> B1 >> B2;
    rep(i,0,N){
        rep(j,0,N){
            cin >> L[i][j];
        }
    }
    rep(i,0,N){
        rep(j,0,N){
            cin >> R[i][j];
        }
    }
    rep(i,0,N){
        rep(j,0,N){
            ll v = R[i][j] - L[i][j] + 1;
            ll tt = rand() % v;
            ans[i][j] = tt + L[i][j];
        }
    }
    rep(i,0,N){
        rep(j,0,N){
            bit.update(i,j,ans[i][j]);
        }
    }

    rep(t,0,10000){
        ll v1 = rand() % 30;
        ll v2 = rand() % 30;
        ll val_def = INF;
        val_def = calc2(v1,v2);
        ll val2 = -INF, val3 = -INF;
        if(bit.get(v1,v2) < R[v1][v2]){
            bit.update(v1,v2,1);
            val2 = calc2(v1,v2);
            bit.update(v1,v2,-1);
        }
        if(bit.get(v1,v2) > L[v1][v2]){
            bit.update(v1,v2,-1);
            val3 = calc2(v1,v2);
            bit.update(v1,v2,1);
        }
        ll res = max(val_def, max(val2, val3));
        if(res == val_def){
            continue;
        }else if(res == val2){
            bit.update(v1,v2,1);
        }else{
            bit.update(v1,v2,-1);
        }

    }
    rep(i,0,N){
        rep(j,0,N){
            cout << bit.get(i,j) << " \n"[j==N-1];
        }
    }

    
}