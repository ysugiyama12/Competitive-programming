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
    return (l1.second > l2.second);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,W;
    ll w[110], v[110];
    cin >> N >> W;
    rep(i,0,N){
        cin >> w[i] >> v[i];
    }
    ll w0 = w[0];
    vector<lpair> p1, p2, p3, p4;
    rep(i,0,N){
        if(w[i] == w0){
            p1.push_back(make_pair(w[i], v[i]));
        }else if(w[i] == w0+1){
            p2.push_back(make_pair(w[i], v[i]));
        }else if(w[i] == w0+2){
            p3.push_back(make_pair(w[i], v[i]));
        }else{
            p4.push_back(make_pair(w[i], v[i]));
        }
    }
    sort(p1.begin(), p1.end(), comp);
    sort(p2.begin(), p2.end(), comp);
    sort(p3.begin(), p3.end(), comp);
    sort(p4.begin(), p4.end(), comp);
    ll sum1[110] = {}, sum2[110] = {}, sum3[110] = {}, sum4[110] = {};
    ll n1 = p1.size();
    ll n2 = p2.size();
    ll n3 = p3.size();
    ll n4 = p4.size();
    rep(i,0,n1){
        sum1[i+1] = sum1[i] + p1[i].second;
    }
    rep(i,0,n2){
        sum2[i+1] = sum2[i] + p2[i].second;
    }
    rep(i,0,n3){
        sum3[i+1] = sum3[i] + p3[i].second;
    }
    rep(i,0,n4){
        sum4[i+1] = sum4[i] + p4[i].second;
    }
    ll ans = 0;
    rep(i,0,n1+1){
        rep(j,0,n2+1){
            rep(k,0,n3+1){
                rep(m,0,n4+1){
                    ll weigh = i * w0 + j * (w0+1) + k * (w0+2) + m * (w0+3);
                    ll val = sum1[i] + sum2[j] + sum3[k] + sum4[m];
                    if(weigh <= W){
                        ans = max(ans, val);
                    }
                }
            }
        }

    }
    print(ans);

}
