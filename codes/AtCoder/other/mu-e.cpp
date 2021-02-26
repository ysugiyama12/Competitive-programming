#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
ll N,M,K;
ll dist[1010][1010] = {};
ll is_visit[1010][1010] = {};
typedef struct{
    ll n;
    ll m;
    ll d;
} ee;

struct compare{
    bool operator() (ee l1, ee l2){
         return l1.d > l2.d;
    }
};

char s[1010][1010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string d;
    cin >> N >> M >> K;
    cin >> d;
    d += d;
    rep(i,0,N){
        rep(j,0,M){
            cin >> s[i][j];
        }
    }
    ll dx[4] = {0,0,1,-1};
    ll dy[4] = {1,-1,0,0};
    ll sn, sm, gn,gm;
    rep(i,0,N){
        rep(j,0,M){
            if(s[i][j] == 'S'){
                sn = i;
                sm = j;
                dist[i][j] = 0;
            }else if(s[i][j] == 'G'){
                gn = i; gm = j;
                dist[i][j] = INF;
            }else{
                dist[i][j] = INF;
            }
        }
    }
    ll pos_u[200010] = {}, pos_d[200010] = {}, pos_r[200010] = {}, pos_l[200010] = {};
    ll v = -1;
    rrep(i,2*K-1,0){
        if(d[i] == 'U'){
            v = 0;
        }else if(v != -1) v++;
        pos_u[i] = v;
    }
    v = -1;
    rrep(i,2*K-1,0){
        if(d[i] == 'D'){
            v = 0;
        }else if(v != -1) v++;
        pos_d[i] = v;
    }
    v = -1;
    rrep(i,2*K-1,0){
        if(d[i] == 'R'){
            v = 0;
        }else if(v != -1) v++;
        pos_r[i] = v;
    }
    v = -1;
    rrep(i,2*K-1,0){
        if(d[i] == 'L'){
            v = 0;
        }else if(v != -1) v++;
        pos_l[i] = v;
    }
    // printa(pos_u, K);



    priority_queue<ee, vector<ee>, compare > pq;
    rep(i,0,N){
        rep(j,0,M){
            ee tmp = {i,j,dist[i][j]};
            pq.push(tmp);
        }
    }
    while(!pq.empty()){
        ee e1 = pq.top();
        pq.pop();
        is_visit[e1.n][e1.m] = 1;
        rep(i,0,4){
            ll ny = e1.n + dy[i];
            ll mx = e1.m + dx[i];
            if(ny < 0 || ny >= N || mx < 0 || mx >= M) continue;
            if(is_visit[ny][mx]) continue;
            if(s[ny][mx] == '#') continue;
            ll amari = dist[e1.n][e1.m] % K;
            if(i == 0){
                if(pos_d[amari] == -1) continue;
                if(dist[ny][mx] > dist[e1.n][e1.m] + pos_d[amari]+1){
                    dist[ny][mx] = dist[e1.n][e1.m] + pos_d[amari]+1;
                    ee tmp = {ny, mx, dist[ny][mx]};
                    pq.push(tmp);
                }
            }else if(i == 1){
                if(pos_u[amari] == -1) continue;
                if(dist[ny][mx] > dist[e1.n][e1.m] + pos_u[amari]+1){
                    dist[ny][mx] = dist[e1.n][e1.m] + pos_u[amari]+1;
                    ee tmp = {ny, mx, dist[ny][mx]};
                    pq.push(tmp);
                }

            }else if(i == 2){
                if(pos_r[amari] == -1) continue;
                if(dist[ny][mx] > dist[e1.n][e1.m] + pos_r[amari]+1){
                    dist[ny][mx] = dist[e1.n][e1.m] + pos_r[amari]+1;
                    ee tmp = {ny, mx, dist[ny][mx]};
                    pq.push(tmp);
                }
                
            }else{
                if(pos_l[amari] == -1) continue;
                if(dist[ny][mx] > dist[e1.n][e1.m] + pos_l[amari]+1){
                    dist[ny][mx] = dist[e1.n][e1.m] + pos_l[amari]+1;
                    ee tmp = {ny, mx, dist[ny][mx]};
                    pq.push(tmp);
                }

            }

        }
    }
    if(dist[gn][gm] == INF){
        print(-1);
    }else{
        print(dist[gn][gm]);
    }
    // rep(i,0,N){
    //     rep(j,0,M){
    //         cout << dist[i][j] << " \n"[j == M-1];
    //     }
    // }


}
