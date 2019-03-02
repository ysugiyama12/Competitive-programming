#include <bits/stdc++.h>
#include <random>
typedef long long ll;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(ll i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;
double calcTime()
{
    struct::timespec getTime;
    clock_gettime(CLOCK_MONOTONIC, &getTime);
    return (getTime.tv_sec + getTime.tv_nsec*1e-9);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    double start = calcTime();
    // print(start);
    ll N;
    ll x[210], y[210];
    cin >> N;
    rep(i,0,N) cin >> x[i] >> y[i];
    
    ll dist[210][210] = {};
    rep(i,0,N){
        rep(j,0,N){
            if(i == j) continue;
            dist[i][j] = sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
            dist[j][i] = sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
        }
    }

    double ave = 0.0;
    rep(i,0,N){
        rep(j,i+1,N){
            ave += dist[i][j];
        }
    }
    double n = N * (N+1) / 2;
    ave /= n;
    double ans = INF;
    vector<ll> ans_arr;
    rep(s,0,N){
        ll is_visit[210] = {};
        is_visit[s] = 1;
        ll cnt = 0;
        vector<ll> v;
        v.push_back(s);
        ll nn = s;
        while(cnt < N-1){
            ll min_pos = -1;
            double min_val = INF;
            rep(i,0,N){
                if(is_visit[i] == 1) continue;
                if(min_val > abs(ave - dist[i][nn])){
                    min_pos = i;
                    min_val = abs(ave - dist[i][nn]);
                }
            }
            is_visit[min_pos] = 1;
            v.push_back(min_pos);
            cnt++;
        }
        double tt = 0.0;
        rep(i,0,N-1){
            tt += dist[v[i]][v[i+1]];
        }
        tt += dist[v[0]][v[N-1]];
        if(tt < ans){
            rep(i,0,N){
                ans_arr.push_back(v[i]);
            }
        }
 
    }
    // rep(i,0,N){
    //     print(ans_arr[i]);
    // }
    vector<ll> v;
    rep(i,0,N) v.push_back(ans_arr[i]);

    // vector<ll> v;
    // rep(i,0,N) v.push_back(i);
    // iter_swap(v.begin(), v.begin()+2);
    double val = INF;
    ll n_loop = 0;
    random_device seed_gen;
    mt19937 engine(seed_gen());
    double tt = 0.0;
    ave = 0.0;
    rep(i,0,N){
        ave += dist[v[i%N]][v[(i+1)%N]];
    }
    ave /= N;
    rep(i,0,N){
        tt += pow(dist[v[i%N]][v[(i+1)%N]], 2);
    }
    tt /= N;
    ll change = 0;
    while(1){
        if(n_loop % 1000 == 0){
            if(calcTime() - start >= 1.97) break;
        }
        n_loop++;
        ll n1 = engine() % N;
        ll n2 = engine() % N;
        // print(n1);
        // print(n2);
        if(n1 == n2) continue;
        ll v1 = v[n1];
        ll v2 = v[n2]; 
        double v_minus = pow(dist[v[(n1-1+N)%N]][v[n1%N]],2) + pow(dist[v[(n1+1)%N]][v[n1%N]],2) + pow(dist[v[(n2-1+N)%N]][v[n2%N]],2) + pow(dist[v[(n2+1)%N]][v[n2%N]],2);
        double v_minus_ave = dist[v[(n1-1+N)%N]][v[n1%N]] + dist[v[(n1+1)%N]][v[n1%N]] + dist[v[(n2-1+N)%N]][v[n2%N]] + dist[v[(n2+1)%N]][v[n2%N]];
        v[n1] = v2;
        v[n2] = v1;
        double v_plus = pow(dist[v[(n1-1+N)%N]][v[n1%N]],2) + pow(dist[v[(n1+1)%N]][v[n1%N]],2) + pow(dist[v[(n2-1+N)%N]][v[n2%N]],2) + pow(dist[v[(n2+1)%N]][v[n2%N]],2);
        double v_plus_ave = dist[v[(n1-1+N)%N]][v[n1%N]] + dist[v[(n1+1)%N]][v[n1%N]] + dist[v[(n2-1+N)%N]][v[n2%N]] + dist[v[(n2+1)%N]][v[n2%N]];
        // double vv = (v_plus - v_minus) / N;
        // ave += vv;
        tt += (v_plus - v_minus) / N;
        ave += (v_plus_ave - v_minus_ave) / N;
        // print2(tt, ave);

        // double tt = 0.0;
        // double ave = 0.0;
        // rep(i,0,N){
        //     ave += dist[v[i%N]][v[(i+1)%N]];
        // }
        // // ave += dist[v[0]][v[N-1]];
        // ave /= N;
        // rep(i,0,N){
        //     tt += pow(dist[v[i%N]][v[(i+1)%N]], 2);
        // }
        // // tt += pow(dist[v[0]][v[N-1]], 2);
        // tt /= N;
        double ss = tt - ave*ave;
        if(ss > val){
            // if(engine() % 10000 == 0) continue;
            v[n1] = v1;
            v[n2] = v2;
            tt -= (v_plus - v_minus) / N;
            ave -= (v_plus_ave - v_minus_ave) / N;
        }else{
            change++;
            val = ss;
        }
    }
    rep(i,0,N){
        print(v[i]);
    }
    // print(n_loop);
    // print(change);
    // print(n_loop);
    // print(n_loop);

}
