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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll x[500010], y[500010];
    rep(i,0,N){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    vector<lpair> lp;
    rep(i,0,N){
        lp.push_back({x[i], i});
        lp.push_back({y[i], i});
    }
    sort(lp.begin(), lp.end());
    set<lpair> st;
    ll cnt = 0;
    vector<lpair> edge;
    for(auto &e: lp){
        if(cnt >= N) break;
        bool end = false;
        if(st.count(e) != 0){
            st.erase(e);
        }else{
            ll rv = y[e.second];
            for(auto &f: st){
                if(f.first < rv){
                    edge.push_back({f.second, e.second});
                    cnt++;
                    if(cnt >= N){
                        end = true;
                        break;
                    }
                }else{
                    break;
                }
            }
            if(end) break;
            st.insert({rv, e.second});
        }
    }
    // print(edge.size());
    if(edge.size() != N-1 || cnt >= N){
        print("NO");
        return 0;
    }
    UnionFind uf(500010);
    for(auto &e: edge){
        if(uf.same(e.first, e.second)){
            print("NO");
            return 0;
        }else{
            uf.unite(e.first, e.second);
        }
    }
    print("YES");


    

}