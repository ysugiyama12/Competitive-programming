#include <bits/stdc++.h>
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x1,y1;
    ll x2,y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    ll N;
    string S;
    cin >> N;
    cin >> S;
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    ll sum_x[100010] = {},  sum_y[100010] = {};
    rep(i,0,N){
        if(S[i] == 'U'){
            sum_y[i+1] = sum_y[i] + 1;
            sum_x[i+1] = sum_x[i];

        }else if(S[i] == 'D'){
            sum_y[i+1] = sum_y[i] - 1;
            sum_x[i+1] = sum_x[i];
            
        }else if(S[i] == 'R'){
            sum_x[i+1] = sum_x[i] + 1;
            sum_y[i+1] = sum_y[i];

        }else{
            sum_x[i+1] = sum_x[i] - 1;
            sum_y[i+1] = sum_y[i];

        }
    }
    ll lv = 0, rv = INF;
    while(rv - lv > 1){
        ll mid = (rv + lv) / 2;
        ll v = mid / N;
        ll amari = mid % N;
        ll ddx = v * sum_x[N] + sum_x[amari];
        ll ddy = v * sum_y[N] + sum_y[amari];
        // print(ddx);
        ll diff = abs(ddx+x1 - x2) + abs(ddy+y1 -y2);
        // print(diff);
        if(diff <= mid){
            rv = mid;
        }else{
            lv = mid;
        }
    }
    if(rv == INF){
        print(-1);
    }else{
        print(rv);
    }



}
