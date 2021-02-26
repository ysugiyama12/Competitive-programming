#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define printp(x,n) for(int i = 0; i < n; i++){ cout << "(" << x[i].first << ", " << x[i].second << ") "; } cout << endl;
#define INF (1e9)
using namespace std;
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;
typedef struct{
    ll to;
    ll cost;
} edge;
typedef pair<ll, ll> lpair;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,W;
    ll w[110], v[110];
    cin >> N >> W;
    vector<ll> w0, w1, w2, w3;
    rep(i,0,N){
        cin >> w[i] >> v[i];
    }
    ll val = w[0];
    rep(i,0,N){
        if(w[i] == val){
            w0.push_back(v[i]);
        }else if(w[i] == val + 1){
            w1.push_back(v[i]);
        }else if(w[i] == val + 2){
            w2.push_back(v[i]);
        }else{
            w3.push_back(v[i]);
        }
    }
    ll n0 = w0.size();
    ll n1 = w1.size();
    ll n2 = w2.size();
    ll n3 = w3.size();
    ll s0[110]={}, s1[110]={}, s2[110]={}, s3[110]={};
    rep(i,0,n0){
        s0[i+1] = s0[i] + w0[i];
    }
    rep(i,0,n1){
        s1[i+1] = s1[i] + w1[i];
    }
    rep(i,0,n2){
        s2[i+1] = s2[i] + w2[i];
    }
    rep(i,0,n3){
        s3[i+1] = s3[i] + w3[i];
    }

    ll ans = 0;

    sort(w0.begin(), w0.end(), greater<ll>());
    sort(w1.begin(), w1.end(), greater<ll>());
    sort(w2.begin(), w2.end(), greater<ll>());
    sort(w3.begin(), w3.end(), greater<ll>());
    printa(w0, n0);
    printa(w1,n1);
    printa(w2,n2);
    printa(w3,n3);
    rep(i,0,n0+1){
        rep(j,0,n1+1){
            rep(k,0,n2+1){
                rep(l,0,n3+1){
                    if(val * ll(i) + (val+1) * ll(j) + (val+2) * ll(k) + (val+3) * ll(l) <= W){
                        ans = max(ans, s0[i] + s1[j] + s2[k] + s3[l]);
                    }
                }
            }
        }
    }
    print(ans);

}
