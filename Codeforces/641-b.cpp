/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

void solve(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,0,N) cin >> A[i];
    bool exist = false;
    rep(i,0,N){
        if(A[i] == K) exist = true;
    }
    if(not exist){
        print("no");
        return;
    }
    bool ok = false, isk = false;
    if(N == 1){
        print("yes");
        return;
    }
    vector<ll> x;
    x.push_back(0);
    x.push_back(1e9+7);
    rep(i,0,N) x.push_back(A[i]);
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    ll Kx = -1;
    rep(i,0,N){
        if(A[i] == K){
            A[i] = lower_bound(x.begin(), x.end(), A[i]) - x.begin();
            Kx = A[i];
        }else{
            A[i] = lower_bound(x.begin(), x.end(), A[i]) - x.begin();
        }
    }
    
    vector<ll> fugou(N+1, 0);
    rep(i,0,N){
        if(A[i] > Kx){
            fugou[i] = 1;
        }else if(A[i] < Kx){
            fugou[i] = -1;
        }
    }
    rep(i,0,N-1){
        if(fugou[i] + fugou[i+1] == 2) ok = true;
    }

    rep(i,0,N){
        if(A[i] == Kx){
            if(i == 0){
                if(fugou[i+1] == 1) ok = true;
            }else if(i == N-1){
                if(fugou[i-1] == 1) ok = true; 
            }else{
                if(fugou[i+1] == 1 || fugou[i-1] == 1) ok = true;
            }
            if(i >= 2){
                if(fugou[i-1] == -1 && fugou[i-2] == 1) ok = true;
            }
            if(i <= N-3){
                if(fugou[i+1] == -1 && fugou[i+2] == 1) ok = true;
            }
        }
    }
    rep(i,0,N-1){
        if(fugou[i] == 0 && fugou[i+1] == 0) ok = true;
    }

    vector<int> pos;
    rep(i,0,N){
        if(fugou[i] == 0) pos.push_back(i);
    }

    ll sz = pos.size();
    vector<ll> sum(N+5, 0);
    rep(i,0,N){
        sum[i+1] = sum[i] + fugou[i];
    }

    rep(i,0,sz-1){
        ll lv = pos[i]+1;
        ll rv = pos[i+1]-1;
        ll s = sum[rv+1] - sum[lv];
        if(s == -1) ok = true;
    }
    if(pos[0] > 0 && sum[pos[0]] == 0) ok = true;
    if(pos[sz-1] < N-1 && sum[N] - sum[pos[sz-1] + 1] == 0) ok = true;


    if(ok){
        print("yes");
    }else{
        print("no");
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) solve();
}