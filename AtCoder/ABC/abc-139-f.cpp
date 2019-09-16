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
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    double x[110], y[110];
    rep(i,0,N) cin >> x[i] >> y[i];
    double u[110], v[110];
    rep(i,0,N){
        u[i] = x[i] + y[i];
        v[i] = x[i] - y[i];
    }
    double res = 0.0;
    double ans = 0.0;
    rep(i,0,2){
        rep(j,0,2){
            double u1[110], v1[110];
            rep(k,0,N){
                if(i == 0){
                    u1[k] = u[k];
                }else{
                    u1[k] = -u[k];
                }
                if(j == 0){
                    v1[k] = v[k];
                }else{
                    v1[k] = -v[k];
                }
            }
            double val = 0.0;
            double xx = 0.0, yy = 0.0;
            rep(k,0,N){
                vector<lpair> lp;
                if(u1[k] + v1[k] > 0){
                    val += u1[k] + v1[k];
                    xx += (u[k] + v[k]) / 2.0;
                    yy += (u[k] - v[k]) / 2.0;
                }
            }
            print2(xx,yy);
            ans = max(ans, sqrt(xx * xx + yy * yy));
            res = max(res, val);
        }
    }
    print(res);


    
}