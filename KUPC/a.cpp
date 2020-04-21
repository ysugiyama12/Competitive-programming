/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
vector<ll> tree[100010];
ll dist[100010] = {};
bool dia[100010] = {};
int parent[100010] = {};
int depth[100010] = {};
int next_val[25][100010] = {};
ll logN = 0;
ll N;

void dfs(ll cur, ll par, ll d){
    dist[cur] = d;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        dfs(e, cur, d+1);
    }

}

bool dfs2(ll cur, ll par, ll d){
    bool flg = false;
    for(auto &e: tree[cur]){
        if(e == par) continue;
        flg |= dfs2(e, cur, d);
    }
    if(cur == d) flg = true;
    if(flg){
        dia[cur] = true;
    }
    return flg;
}

void dfs3(ll cur, ll par, ll d){
	depth[cur] = d;
	parent[cur] = par;
	for(auto &e: tree[cur]){
		if(e == par) continue;
		dfs3(e, cur, d+1);
	}
}

ll getParent(ll cur, ll num) {
    ll p = cur;
    rrep(k,logN-1, 0){
        if(p == -1){
            break;
        }
        if((num >> k) & 1){
            p = next_val[k][p];
        }
    }
    return p;
}

ll getLCA(ll va, ll vb){
	if(depth[va] > depth[vb]){
		va = getParent(va, depth[va] - depth[vb]);
	}else if(depth[va] < depth[vb]){
		vb = getParent(vb, depth[vb] - depth[va]);
	}
	ll lv = -1, rv = N+1;
	while(rv - lv > 1){
		ll mid = (rv + lv) / 2;
		ll ta = getParent(va, mid);
		ll tb = getParent(vb, mid);
		if(ta == -1 || tb == -1){
			rv = mid;
		}else if(ta != tb){
			lv = mid;
		}else{
			rv = mid;
		}
	}
	return getParent(va, rv);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ll N;
    cin >> N;
    logN = floor(log2(N)) + 1;
    ll a[100010], b[100010];
    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    dfs(0, -1, 0);
    ll max_idx = 0, max_val = 0;

    rep(i,0,N){
        if(max_val < dist[i]){
            max_idx = i;
            max_val = dist[i];
        }
    }
    dfs(max_idx, -1, 0);
    max_val = 0;
    ll max_idx2 = 0;
    rep(i,0,N){
        if(max_val < dist[i]){
            max_idx2 = i;
            max_val = dist[i];
        }
    }
    dfs2(max_idx, -1, max_idx2);
    dfs3(max_idx, -1, 0);
    rep(i,0,N){
        next_val[0][i] = parent[i];
    }
    rep(k,0,logN){
        rep(i,0,N){
            if(next_val[k][i] == -1){
                next_val[k+1][i] = -1;
            }else{
                next_val[k+1][i] = next_val[k][next_val[k][i]];
            }
        }
    }
    // printa(dia, N);
    // print(max_idx, max_idx2);
    ll max_k = 0;
    rep(i,0,N){
        if(tree[i].size() == 1 && i != max_idx && i != max_idx2){
            ll v = getLCA(i, max_idx2);
            ll a = depth[v];
            ll b = max_val - a;
            ll x = depth[i] - depth[v];
            ll k = x + max(a,b);
            // print(a,b,x);
            // print(i, k, v);
            max_k = max(max_k, k);

        }
    }
    bool ok = true;
    rep(i,0,N){
        if(tree[i].size() == 1 && i != max_idx && i != max_idx2){
            ll v = getLCA(i, max_idx2);
            ll a = depth[v];
            ll b = max_val - a;
            ll x = depth[i] - depth[v];
            ll k = x + max(a,b);
            // print(a,b,x);
            // print(i, k, v);
            if(k == max_k){
                if(x == max(a,b) && ok == true){
                    ok = true;
                }else{
                    ok = false;
                }
            }

        }
    }
    ll ans[100010] = {};
    ans[1] = 1;
    ans[2] = 1;
    rep(i,3,N+1){
        if(i > max_k){
            ans[i] = 1;
        }else if(max_k == i){
            if(ok && i % 2 == 0){
                ans[i] = 1;
            }else{
                ans[i] = 0;
            }
        }else{
            ans[i] = 0;
        }
    }
    rep(i,1,N+1){
        cout << ans[i];
    }
    cout << endl;
    // print(max_idx, max_idx2);

    // ll diff = max_val;
    // ll ans[100010] = {};
    // memset(ans, -1, sizeof(ans));
    // rep(i,max_val+1, N+1){
    //     ans[i] = 1;
    // }
    // ans[1] = 1;
    // ans[2] = 1;
    // ll cnt = 0;
    // rep(i,0,N){
    //     if(tree[i].size() >= 3){
    //         cnt++;
    //     }
    // }
    // if(cnt >= 2){
    //     rep(i,3,max_val+1){
    //         ans[i] = 0;
    //     }
    // }else if(cnt == 0){
    //     rep(i,1,N+1){
    //         ans[i] = 1;
    //     }
    // }else{
    //     ll p = -1;
    //     rep(i,0,N){
    //         if(tree[i].size() >= 3){
    //             p = i;
    //             break;
    //         }
    //     }
    //     dfs(p, -1, 0);
    //     ll max_d = 0;
    //     rep(i,0,N){
    //         max_d = max(max_d, dist[i]);
    //     }
    //     rep(i,3,max_val+1){
    //         if(i % 2 == 1){
    //             ans[i] = 0;
    //         }else{
    //             ll half = i/2;
    //             if(max_d <= half){
    //                 ans[i] = 1;
    //             }else{
    //                 ans[i] = 0;
    //             }
    //         }
    //     }

    // }
    // rep(i,1,N+1){
    //     cout << ans[i];
    // }
    // cout << endl;



    

}