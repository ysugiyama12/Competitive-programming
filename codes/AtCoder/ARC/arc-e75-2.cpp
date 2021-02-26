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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
struct BIT { //1-indexed
private:
    int n;
    vector<ll> bit;

public:
    BIT(vector<ll> v){
        n = v.size();
        rep(i,0,n) bit.push_back(v[i]);
    }

    ll sum(ll i){
        ll s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(ll i, ll x){
        while(i <= n){
            bit[i] += x;
            i += i & -i;
        }
    }
};

vector<ll> compress(vector<ll> v){
    ll n = v.size();
    vector<ll> v2;
    rep(i,0,n) v2.push_back(v[i]);
    sort(v2.begin(), v2.end());
    vector<ll> res;
    rep(i,0,n){
        ll pos = lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin();
        res.push_back(pos + 1); 
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    ll A[200010];
    rep(i,0,N) cin >> A[i];
    rep(i,0,N) A[i] -= K;
    vector<ll> sum(N+1, 0);
    rep(i,0,N) sum[i+1] = sum[i] + A[i];
    vector<ll> sum_compress = compress(sum);
    vector<ll> init(200010, 0);
    BIT bit(init);
    ll ans = 0;
    rep(i,0,N+1){
        ans += bit.sum(sum_compress[i]);
        bit.add(sum_compress[i], 1);
    }
    print(ans);


    
}