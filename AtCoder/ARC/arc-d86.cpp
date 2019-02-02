#include <bits/stdc++.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define rrep(i,m,n) for(int i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i == n-1];}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e18)
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll a[55];
    cin >> N;
    rep(i,0,N) cin >> a[i];
    ll min_val = INF, min_pos = -1, max_val = -INF, max_pos = -1;
    rep(i,0,N){
        if(a[i] < min_val){
            min_val = a[i];
            min_pos = i;
        }
        if(a[i] > max_val){
            max_val = a[i];
            max_pos = i;
        }
    }
    vector<lpair> lp;
    if(abs(max_val) > abs(min_val)){
        rep(i,0,N){
            lp.push_back(make_pair(max_pos+1, i+1));
        }
        rep(i,0,N-1){
            lp.push_back(make_pair(i+1, i+2));
        }
    }else{
        rep(i,0,N){
            lp.push_back(make_pair(min_pos+1, i+1));
        }
        rrep(i,N-1,1){
            lp.push_back(make_pair(i+1, i));
        }
    }
    // vector<lpair> lp;
    // if(abs(max_val) > abs(min_val)){
    //     ll v = abs(max_val);
    //     rep(i,1,N){
    //         while(a[i-1] > a[i]){
    //             a[i] += v;
    //             lp.push_back(make_pair(max_pos+1, i+1));
    //         }
    //     }
    // }else{
    //     ll v = min_val;
    //     rrep(i,N-2,0){
    //         while(a[i] > a[i+1]){
    //             a[i] += v;
    //             lp.push_back(make_pair(min_pos+1, i+1));

    //         }     
    //     }
    // }
    print(lp.size());
    rep(i,0,lp.size()){
        cout << lp[i].first << " " << lp[i].second << endl;
    }
}
