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
int num[1010][1010] = {};
bool check[1010][1010] = {};
typedef struct {
    ll n;
    ll m;
    ll d;
} P;

void solve(){
    ll N,M,T;
    cin >> N >> M >> T;
    string S[1010];
    rep(i,0,N) cin >> S[i];
    bool itimatu = true;
    rep(i,0,N){
        rep(j,0,M-1){
            if(S[i][j] == S[i][j+1]) itimatu = false;
        }
    }
    rep(j,0,M){
        rep(i,0,N-1){
            if(S[i][j] == S[i+1][j]) itimatu = false;
        }
    }
    if(itimatu){
        rep(t,0,T){
            ll pi,pj,p;
            cin >> pi >> pj >> p;
            pi--; pj--;
            print(S[pi][pj]);
        }
        return;
    }
    rep(i,0,N){
        rep(j,0,M){
            num[i][j] = 1e9;
        }
    }

    rep(i,0,N){
        rep(j,0,M-1){
            if(S[i][j] == S[i][j+1]){
                num[i][j] = 0;
                num[i][j+1] = 0;
            }
        }
    }
    rep(j,0,M){
        rep(i,0,N-1){
            if(S[i][j] == S[i+1][j]){
                num[i][j] = 0;
                num[i+1][j] = 0;
            }
        }
    }
    queue<P> que;
    rep(i,0,N){
        rep(j,0,M){
            if(num[i][j] == 0){
                que.push({i,j,0});
            }
        }
    }
    ll dn[4] = {0,0,1,-1};
    ll dm[4] = {1,-1,0,0};
    while(not que.empty()){
        P l1 = que.front();
        que.pop();
        ll n = l1.n, m = l1.m;
        if(check[n][m]) continue;
        check[n][m] = true;
        num[n][m] = l1.d;
        rep(k,0,4){
            ll nn = n + dn[k];
            ll mm = m + dm[k];
            if(nn >= 0 && nn < N && mm >= 0 && mm < M){
                if(not check[nn][mm]){
                    que.push({nn,mm,l1.d+1});
                }
            }
        }
    }

    rep(t,0,T){
        ll pi,pj,p;
        cin >> pi >> pj >> p;
        pi--; pj--;
        ll val = num[pi][pj];
        if(p > val){
            p -= val;
            if(p % 2 == 1){
                if(S[pi][pj] == '0'){
                    print(1);
                }else{
                    print(0);
                }
            }else{
                if(S[pi][pj] == '0'){
                    print(0);
                }else{
                    print(1);
                }       
            }
        }else{
            print(S[pi][pj]);
        }
    }


    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}