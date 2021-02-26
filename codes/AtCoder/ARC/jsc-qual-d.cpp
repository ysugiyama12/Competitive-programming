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
ll edge[510][510] = {};
void calc(ll lv, ll rv, ll d){
    if(rv - lv == 1) return;
    ll mid = (lv + rv+1) / 2;
    rep(i,lv,mid){
        rep(j,mid,rv){
            edge[i][j] = d;
            edge[j][i] = d;
        }
    }
    calc(lv, mid, 2*d);
    calc(mid, rv, 2*d);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    calc(0, N, 1);
    vector<ll> v;
    rep(i,0,N){
        rep(j,0,N){
            if(i != j) v.push_back(edge[i][j]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    rep(i,0,N){
        rep(j,0,N){
            if(i == j) continue;
            ll pos = lower_bound(v.begin(), v.end(), edge[i][j]) - v.begin();
            edge[i][j] = pos+1;
        }
    }
    rep(i,0,N-1){
        rep(j,i+1,N){
            cout << edge[i][j] << " \n"[j==N-1];
        }
    }

    
}