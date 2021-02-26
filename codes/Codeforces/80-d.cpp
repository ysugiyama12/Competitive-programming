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
int a[300010][9];
vector<ll> compress(vector<ll> x, ll n){
    // [1,n]
	vector<ll> v;
	v.push_back(-INF); v.push_back(INF);
	rep(i,0,n) v.push_back(x[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<ll> res;
	rep(i,0,n) res.push_back(lower_bound(v.begin(), v.end(), x[i]) - v.begin());
	return res;
}
int cnt[1024] = {};
int mp[1024] = {};
vector<int> pos[300001 * 8 + 2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    vector<ll> x;
    rep(i,0,N){
        rep(j,0,M){
            cin >> a[i][j];
            x.push_back(a[i][j]);
        }
    }
    vector<ll> xc = compress(x, M*N);
    ll max_val = 0;
    rep(i,0,N){
        rep(j,0,M){
            a[i][j] = xc[i*M+j];
            max_val = max(max_val, (ll)a[i][j]);
        }
    }

    rep(i,0,N){
        rep(j,0,M){
            pos[a[i][j]].push_back(i*M+j);
        }
    }
    ll sum = (1LL<<M)-1;

    mp[0] = N;
    rrep(i,max_val,1){
        for(auto &e: pos[i]){
            ll n = e / M;
            ll m = e % M;
            mp[cnt[n]]--;
            cnt[n] += (1LL<<m);
            mp[cnt[n]]++;
        }

        for(int bit = 0; bit < (1LL<<M); bit++){
            ll amari = (1LL<<M) - 1 - bit;
            if(mp[bit] == 0) continue;
            for(int bit_tmp = bit; ; bit_tmp = (bit_tmp - 1) & bit){
                ll bit2 = (bit_tmp | amari);
                if(mp[bit2] == 0){
                    if(bit_tmp == 0){
                        break;
                    }else{
                        continue;
                    }
                }
                if((amari & bit2) == amari){
                    ll p1 = -1, p2 = -1;
                    rep(j,0,N){
                        if(cnt[j] == bit) p1 = j;
                        if(cnt[j] == bit2) p2 = j;
                    }
                    print(p1+1, p2+1);
                    return 0;
                }
                if(!bit_tmp) break;
            }
        }
    }

}