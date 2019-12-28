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
ll N,S,K;
ll X[1010], Y[1010], C[1010];
ll P[1010][110];
bool is_tie[1010][1010] = {};
vector<lpair> tree[1010];
vector<ll> child[110];
vector<lpair> edge;
ll result[1010][110] = {};
ll visit[1010] = {};
ll visit_now[1010] = {};
ll now = 0;
bool failed[1010] = {};
vector<ll> v_ok;
map<lpair, ll> edge_used;
ll Ki[1010];

ll get_dist(ll n1, ll n2){
    return (X[n1] - X[n2]) * (X[n1] - X[n2]) + (Y[n1] - Y[n2]) * (Y[n1] - Y[n2]);
}
bool check2[1010] = {};
vector<ll> new_visit;

void dfs(ll cur, ll cur_G){
    // print(cur,cur_G);
    result[now][cur] = cur_G;
    if(not visit[cur_G]){
        new_visit.push_back(cur_G);
    }
    visit[cur_G] = true;
    visit_now[cur_G] = true;
    ll idx = 0;
    ll sz = tree[cur_G].size();
    for(auto &e: child[cur]){
        while(1){
            ll to = tree[cur_G][idx].first;
            if(not visit_now[to]){
                if(not visit[to] || (visit[to] && edge_used[{cur_G, to}])){
                    break;
                }
            }
            idx++;
            if(idx == sz) break;
        }
        // while(visit[tree[cur_G][idx].first]){
        //     idx++;
        //     if(idx == sz) break;
        // }
        if(idx == sz){
            failed[now] = true;
            // print("failed", now, Ki[now]);
            break;
        }
        edge_used[{cur_G, tree[cur_G][idx].first}]++;
        edge_used[{tree[cur_G][idx].first, cur_G}]++;
        dfs(e, tree[cur_G][idx].first);
        idx++;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> S;
    rep(i,0,N){
        cin >> X[i] >> Y[i] >> C[i];
    }
    rep(i,0,S){
        cin >> Ki[i];
        rep(j,0,Ki[i]-1){
            cin >> P[i][j];
            P[i][j]--;
        }
    }
    rep(i,0,N){
        rep(j,i+1,N){
            if((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) <= (C[i] + C[j]) * (C[i] + C[j])){
                is_tie[i][j] = true;
                is_tie[j][i] = true;
            }
        }
    }
    rep(i,0,N){
        rep(j,0,N){
            if(is_tie[i][j]){
                tree[i].push_back({j, C[j]});
                tree[j].push_back({i, C[i]});
            }
        }
    }
    rep(i,0,N){
        sort(tree[i].begin(), tree[i].end(), [&](lpair l1, lpair l2){
            return C[l1.first] > C[l2.first];
            // return get_dist(i, l1.first) < get_dist(i, l2.first);
        });
    }
    vector<ll> vo(S);
    iota(vo.begin(), vo.end(), 0);
    sort(vo.begin(), vo.end(), [&](ll l1, ll l2){
        return Ki[l1] < Ki[l2];
    });
    vector<ll> point(N);
    iota(point.begin(), point.end(), 0);
    sort(point.begin(), point.end(), [&](ll l1, ll l2){
        return C[l1] > C[l2];
    });

    ll max_score = 0, max_idx = 0;
    rep(st,0,1){
        ll start = point[st];
        rep(i,0,N){
            visit[i] = false;
            failed[i] = false;
        }
        edge_used.clear();
        for(auto &i: vo){
            now = i;
            rep(j,0,Ki[i]){
                child[j].clear();
            }
            rep(j,0,Ki[i]-1){
                child[P[i][j]].push_back(j+1);
            }
            new_visit.clear();
            rep(j,0,N){
                visit_now[j] = false;
            }
            dfs(0, start);
            if(failed[i]){
                for(auto &e: new_visit) visit[e] = false;
            }
        }
        ll score = N;
        rep(i,0,N){
            if(failed[i]) score--;
        }
        if(max_score < score){
            max_score = score;
            max_idx = start;
        }
        // print(score, start, C[start]);
    }
    rep(i,0,N){
        visit[i] = false;
        failed[i] = false;
    }
    // rep(i,0,N){
    //     if(not visit[i]){
    //         print("not visit", i);
    //     }
    // }
    edge_used.clear();
    ll idx = 0;
    for(auto &i: vo){
        now = i;
        rep(j,0,Ki[i]){
            child[j].clear();
        }
        rep(j,0,Ki[i]-1){
            child[P[i][j]].push_back(j+1);
        }
        // new_visit.clear();
        rep(j,0,N){
            visit_now[j] = false;
        }
        dfs(0, max_idx);
        // if(failed[i]){
        //     for(auto &e: new_visit){
        //         visit[e] = false;
        //     }
        // }
        // if(idx > 400){
        //     max_idx = tree[max_idx][0].first;
        // }
        // print(idx,failed[i], Ki[i]);
        idx++;
    }
    // vector<ll> visit_arr;
    // rep(i,0,N){
    //     if(visit[i]) visit_arr.push_back(i);
    // }

    // rep(i,0,N){
    //     if(not visit[i]){
    //         print("not visit", i);
    //     }
    // }
    
    // ll score = N;
    // rep(i,0,N){
    //     if(failed[i]) score--;
    // }
    // if(max_score < score){
    //     max_score = score;
    //     print(max_score);
    // }

    ll cnt = N;
    rep(i,0,S){
        if(failed[i]){
            // print("failed", i, Ki[i]);
            cnt--;
            rep(j,0,Ki[i]){
                result[i][j] = j;
            }
        }
    }
    print(cnt);
    rep(i,0,S){
        if(not failed[i]){
            rep(j,0,Ki[i]-1){
                ll prt = P[i][j];
                ll cld = j+1;
                ll v1 = result[i][prt], v2 = result[i][cld];
                if(v1 > v2) swap(v1,v2);
                edge.push_back({v1,v2});
            }
        }
    }
    sort(edge.begin(), edge.end());
    edge.erase(unique(edge.begin(), edge.end()), edge.end());

    // output
    bool is_print = false;
    ll M = edge.size();
    if(is_print) print(M);
    bool check[1010] = {};
    rep(i,0,M){
        if(is_print) print(edge[i].first + 1, edge[i].second + 1);
        check[edge[i].first] = true;
        check[edge[i].second] = true;
    }
    rep(i,0,S){
        rep(j,0,Ki[i]){
            if(is_print) cout << result[i][j] + 1 << " \n"[j==Ki[i]-1];
        }
    }

}
