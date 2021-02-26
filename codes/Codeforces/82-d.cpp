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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--){
        ll N,M;
        cin >> N >> M;
        vector<ll> a(M);
        rep(i,0,M) cin >> a[i];
        ll sum = 0;
        rep(i,0,M) sum += a[i];
        if(N > sum){
            print(-1);
            continue;
        }
        sort(a.begin(), a.end());
        ll cnt[62] = {};
        rep(i,0,M){
            ll t = a[i];
            ll cc = 0;
            while(t > 0){
                cc++;
                t /= 2;
            }
            cnt[cc-1]++;
        }
        ll ans = 0;
        sum = 0;

        rep(i,0,62){
            sum += (1LL<<i) * cnt[i];
            // print(sum);
            if((N>>i)&1){
                if(sum >= (1LL<<i)){
                    sum -= (1LL<<i);
                }else{
                    ll ps = i+1;
                    while(1){
                        if(cnt[ps] > 0){
                            rrep(j,ps,i+1){
                                cnt[j]--;
                                cnt[j-1] += 2;
                                ans++;
                            }
                            break;
                        }else{
                            ps++;
                        }
                    }
                    cnt[i]--;
                }
            }
            // print(sum, (1LL<<i),ans);
        }
        print(ans);


    }
    

}