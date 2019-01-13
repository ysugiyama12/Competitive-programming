#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define rrep(i,m,n) for(int i = m; i >= n; i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;
bool comp(lpair l1, lpair l2){
    return (l1.first > l2.first);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll A[100010], B[100010];
    cin >> N;
    rep(i,0,N){
        cin >> A[i] >> B[i];
    }
    ll M;
    ll T[100010];
    cin >> M;
    rep(i,0,M){
        cin >> T[i];
    }
    vector<lpair> lp;
    rep(i,0,N){
        lp.push_back(make_pair(A[i], B[i]));
    }
    sort(lp.begin(), lp.end());
    // printp(lp,N);
    vector<lpair> lp2;
    rep(i,0,M){
        lp2.push_back(make_pair(T[i], i));
    }
    sort(lp2.begin(), lp2.end());
    // printp(lp2,M);
    ll idx = 0;
    ll val[100010] = {};
    rep(i,0,M){
        ll pos = lp2[i].second;
        ll times = lp2[i].first;
        while(idx < N){
            if(lp[idx].first < times){
                idx++;
            }else{
                break;
            }
        }
        if(idx == 0){
            val[pos] = lp[idx].second;
        }else if(idx == N){
            val[pos] = lp[idx-1].second + (times - lp[idx-1].first);
        }else{
            val[pos] = min(lp[idx].second, lp[idx-1].second + (times - lp[idx-1].first));
        }
        // print(times);
        // while(idx < N){
        //     if(times >= lp[idx+1].first){
        //         idx++;
        //     }else{
        //         break;
        //     }
        // }
        // if(idx == N) idx = N-1;
        // print(idx);
        // val[pos] = lp[idx].second + (times - lp[idx].first);
        // // while(idx < N){
        // //     if(times >= lp[idx].first){
        // //         idx++;
        // //     }else{
        // //         break;
        // //     }
        // // val[pos] = lp[idx-1].second + (times - lp[idx-1].first);
        // // while(lp[idx].first > times){
        // //     idx++;
        // // }
        // // val[pos] = (times - lp[idx].first) + lp[idx].second;
    }
    rep(i,0,M){
        print(val[i]);
    }

}
