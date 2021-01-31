/*** author: yuji9511 ***/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = int;
using lpair = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
const ll INF = 1e9;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
ostream& operator<<(ostream& os, lpair& h){ os << "(" << h.first << ", " << h.second << ")"; return os;}
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
vll compress(vll x){
    vll v = x;
    v.push_back(-INF);
    v.push_back(INF);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vll res;
    for(auto &e: x){
        res.push_back(lower_bound(v.begin(), v.end(), e) - v.begin());
    }
    return res;
}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
ll dp[93][93][93][93];

void solve(){
    ll H,W;
    cin >> H >> W;
    ll N;
    cin >> N;

    vll X(N), Y(N);
    rep(i,0,N){
        cin >> X[i] >> Y[i];
        X[i]--; Y[i]--;
    }
    vll vx,vy;
    vx.push_back(0); vx.push_back(H-1);
    vy.push_back(0); vy.push_back(W-1);
    rep(i,0,N){
        vx.push_back(X[i]);
        if(X[i] != 0) vx.push_back(X[i]-1);
        if(Y[i] != 0) vy.push_back(Y[i]-1);
        if(X[i] != H-1) vx.push_back(X[i]+1);
        if(Y[i] != W-1) vy.push_back(Y[i]+1);
        vy.push_back(Y[i]);
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());

    auto idx_x = [&](ll x) -> ll {
        return lower_bound(vx.begin(), vx.end(), x) - vx.begin();
    };
    auto idx_y = [&](ll x) -> ll {
        return lower_bound(vy.begin(), vy.end(), x) - vy.begin();
    };
    Fill(dp, -1);
    // printa(vx, vx.size());
    // printa(vy, vy.size());


    auto calc = [&](auto calc, ll lx, ll rx, ll ly, ll ry) -> ll {
        if(lx > rx || ly > ry) return 0;
        ll &res = dp[lx][rx][ly][ry];
        if(~res) return res;
        res = 0;
        rep(i,0,N){
            ll x = idx_x(X[i]), y = idx_y(Y[i]);
            ll val = 0;
            if(x >= lx && x <= rx && y >= ly && y <= ry){
                val = vx[rx] - vx[lx] + vy[ry] - vy[ly] + 1;
                // print(i,val);
                val += calc(calc, lx, x-1, ly, y-1);
                val += calc(calc, x+1, rx, ly, y-1);
                val += calc(calc, lx, x-1, y+1, ry);
                val += calc(calc, x+1, rx, y+1, ry);
                res = max(res, val);
            }
        }
        // print(lx,rx,ly,ry,res);
        return res;
    };

    ll ans = calc(calc, idx_x(0), idx_x(H-1), idx_y(0), idx_y(W-1));
    // print(calc(calc,2,5,1,3));
    print(ans);



}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}