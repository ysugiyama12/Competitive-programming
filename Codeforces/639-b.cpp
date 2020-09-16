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
struct UnionFind {
private:
    ll N;
    vector<ll> parent;
    vector<ll> num;
    vector<ll> diff_weight;

public:
    UnionFind(ll n){
        N = n;
        rep(i,0,N) parent.push_back(i);
        rep(i,0,N) num.push_back(1);
        rep(i,0,N) diff_weight.push_back(0);
    }

    ll root(ll x){
        if(x == parent[x]){
            return x;
        }else{
            ll r = root(parent[x]);
            diff_weight[x] += diff_weight[parent[x]];
            return parent[x] = r;
        }
    }

    void unite(ll a, ll b, ll w = 0){
        w += weight(a); w -= weight(b);
        a = root(a); b = root(b);
        if(a == b) return;
        parent[b] = a;
        ll sum = num[a] + num[b];
        num[a] = sum;
        num[b] = sum;
        diff_weight[b] = w;
    }

    bool same(ll a, ll b){ return root(a) == root(b);}
    
    ll sz(ll x){ return num[root(x)];}

    ll weight(ll x){
        root(x);
        return diff_weight[x];
    }

    ll diff(ll a, ll b){
        return weight(b) - weight(a);
    }
};
UnionFind uf(1000010);
ll N,M;

ll get(ll i, ll j){
    return i * M + j;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    string S[1010];
    rep(i,0,N) cin >> S[i];
    ll dn[4] = {1,-1,0,0};
    ll dm[4] = {0,0,1,-1};
    map<int,int> mp;
    rep(i,0,N){
        rep(j,0,M){
            if(S[i][j] == '.') continue;
            rep(k,0,4){
                ll ii = i + dn[k];
                ll jj = j + dm[k];
                if(ii >= 0 && ii < N && jj >= 0 && jj < M){
                    if(S[i][j] == '#' && S[ii][jj] == '#'){
                        uf.unite(get(i,j), get(ii,jj));
                        // print(i,j, ii, jj);
                    }
                }
            }
        }
    }
    rep(i,0,N){
        rep(j,0,M){
            if(S[i][j] == '#'){
                mp[uf.root(get(i,j))]++;
            }
        }
    }
    ll ans = mp.size();
    bool ok = true;
    rep(i,0,N){
        ll cnt = 0;
        rep(j,0,M-1){
            if(S[i][j] == '#' && S[i][j+1] == '.') cnt++;
        }
        if(S[i][M-1] == '#') cnt++;
        if(cnt != 1) ok = false;
    }


    rep(i,0,N){
        ll cnt = 0;
        rep(j,0,M){
            if(S[i][j] == '#') cnt++;
        }
        if(cnt == 0){

        }
    }
    if(not ok){
        print(-1);
    }else{
        print(ans);
    }



    

}