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

typedef struct {
    ll lv;
    ll rv;
    ll idx;
} P;
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
    ll sa[100010], ea[100010], sb[100010], eb[100010];
    rep(i,0,N){
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
    }
    // vector<ll> ss;
    // rep(i,0,N){
    //     ss.push_back(sa[i]);
    //     ss.push_back(ea[i]);
    // }
    // ss.push_back(-INF);
    // ss.push_back(INF);
    // sort(ss.begin(), ss.end());
	// ss.erase(unique(ss.begin(), ss.end()), ss.end());
    // rep(i,0,N){
    //     sa[i] = lower_bound(ss.begin(), ss.end(), sa[i]) - ss.begin();
    //     ea[i] = lower_bound(ss.begin(), ss.end(), ea[i]) - ss.begin();
    // }

    // ss.clear();
    // rep(i,0,N){
    //     ss.push_back(sb[i]);
    //     ss.push_back(eb[i]);
    // }
    // ss.push_back(-INF);
    // ss.push_back(INF);
    // sort(ss.begin(), ss.end());
	// ss.erase(unique(ss.begin(), ss.end()), ss.end());
    // rep(i,0,N){
    //     sb[i] = lower_bound(ss.begin(), ss.end(), sb[i]) - ss.begin();
    //     eb[i] = lower_bound(ss.begin(), ss.end(), eb[i]) - ss.begin();
    // }
    vector< pair<ll, lpair > > la,lb;
    rep(i,0,N){
        la.push_back({sa[i], {i, 0}});
        la.push_back({ea[i], {i, 1}});
        lb.push_back({sb[i], {i, 0}});
        lb.push_back({eb[i], {i, 1}});
    }
    sort(la.begin(), la.end(), [](pair<ll, lpair > l1, pair<ll, lpair > l2){
        if(l1.first == l2.first){
            return l1.second > l2.second;

        }
        return l1.first < l2.first;
    });
    sort(lb.begin(), lb.end(), [](pair<ll, lpair > l1, pair<ll, lpair > l2){
        if(l1.first == l2.first){
            return l1.second > l2.second;

        }
        return l1.first < l2.first;
    });
    bool ok = true;
    rep(i,0,2*N){
        if(la[i].second != lb[i].second){
            ok = false;
        }
    }
    if(ok){
        print("YES");
    }else{
        print("NO");
    }
}