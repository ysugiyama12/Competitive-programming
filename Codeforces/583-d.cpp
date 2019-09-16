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
string s[1000010];
bool is_visit[1000010];
ll dist[1000010] = {};
bool is_ok[1000010];
typedef struct {
    ll n;
    ll m;
    ll d;
} P;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    rep(i,0,N) cin >> s[i];
    queue<P> que;
    que.push((P){0,0,0});
    ll dn[2] = {1,0};
    ll dm[2] = {0,1};
    memset(is_visit, 0, sizeof(is_visit));
    fill(dist, dist+N*M, INF);
    while(not que.empty()){
        P p1 = que.front();
        que.pop();
        ll pos = p1.n * M + p1.m;
        if(is_visit[pos] == true) continue;
        is_visit[pos] = true;
        dist[pos] = p1.d;
        rep(k,0,2){
            ll nn = p1.n + dn[k];
            ll mm = p1.m + dm[k];
            ll p = nn * M + mm;
            if(is_visit[p] == false){
                if(nn >= 0 && nn < N && mm >= 0 && mm < M){
                    if(s[nn][mm] == '.'){
                        que.push((P){nn,mm,p1.d+1});
                    }
                }
            }
        }
    }
    // printa(dist,N*M);
    if(dist[N*M-1] == INF){
        print(0);
    }else{
        memset(is_ok, 0, sizeof(is_ok));
        memset(is_visit, 0, sizeof(is_visit));
        queue<P> qq;
        qq.push((P){N-1,M-1,0});
        while(not qq.empty()){
            P p = qq.front();
            qq.pop();
            // print2(p.n,p.m);
            ll pos = p.n * M + p.m;
            if(is_visit[pos]) continue;
            is_ok[pos] = true;
            is_visit[pos] = true;
            rep(k,0,2){
                ll nn = p.n - dn[k];
                ll mm = p.m - dm[k];
                ll pos2 = nn * M + mm;
                if(is_visit[pos2] == false){
                    // if(p.n == 2 && p.m == 3){
                    //     print2(nn,mm);
                    // }
                    if(nn >= 0 && nn < N && mm >= 0 && mm < M){
                        if(s[nn][mm] == '.'){
                            if(dist[pos2] + 1 == dist[pos]){
                                qq.push((P){nn,mm,0});
                            }
                        }
                    }
                }
            }
        }
        // printa(dist, N*M);
        // rep(i,0,N){
        //     rep(j,0,M){
        //         cout << is_ok[i*M+j] << " \n"[j==M-1];
        //     }
        // }
        // printa(is_ok, N*M);
        map<ll,ll> mp;
        rep(i,0,N*M-1){
            if(dist[i] != 0 && dist[i] != INF && is_ok[i]){
                mp[dist[i]]++;
            }
        }
        ll min_val = 2;
        for(auto &e: mp){
            min_val = min(min_val, e.second);
        }
        print(min_val);
    }

    
}