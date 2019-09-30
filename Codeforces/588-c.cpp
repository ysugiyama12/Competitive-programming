/*** author: yuji9511 ***/
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
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    ll a[55], b[55];
    vector<ll> tree[10];
    rep(i,0,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    if(N != 7){
        print(M);
        return 0;
    }
    ll ans = 0;
    vector<ll> v(7);
    iota(v.begin(), v.end(), 1);
    rep(n,0,7){ // nが重なる
        vector<ll> v(6);
        iota(v.begin(), v.end(), 0);
        do{
            ll v2[7] = {};
            rep(i,0,7){
                if(n == i){
                    v2[i] = 0;
                }else if(i < n){
                    v2[i] = v[i];
                }else{
                    v2[i] = v[i-1];
                }
            }
            // printa(v2, 7);
            ll res = 0;
            map<lpair, ll> mp;
            rep(i,0,M){
                ll a1 = v2[a[i]], a2 = v2[b[i]];
                if(a1 > a2) swap(a1, a2);
                if(mp[make_pair(a1, a2)] == 0){
                    res++;
                    mp[make_pair(a1, a2)]++;
                }
            }
            ans = max(ans, res);

        }while(next_permutation(v.begin(), v.end()));

    }
    // do{
    //     rep(k,1,8){
            
    //         ll res = 0;
    //         map<lpair, ll> mp;
    //         rep(i,0,M){
    //             if(v[a[i]] != 7 && v[b[i]] != 7 && mp[make_pair(v[a[i]], v[b[i]])] == 0){
    //                 res++;
    //                 mp[make_pair(v[a[i]], v[b[i]])]++;
    //                 mp[make_pair(v[b[i]], v[a[i]])]++;
    //             }else{
    //                 if(k == 7) continue;
    //                 if(v[a[i]] == 7){
    //                     if(mp[make_pair(k, v[b[i]])] == 0){
    //                         mp[make_pair(k, v[b[i]])]++;
    //                         mp[make_pair(v[b[i]], k)]++;
    //                         res++;
    //                     }
    //                 }else{
    //                     if(mp[make_pair(k, v[a[i]])] == 0){
    //                         mp[make_pair(k, v[a[i]])]++;
    //                         mp[make_pair(v[a[i]], k)]++;
    //                         res++;
    //                     }
    //                 }

    //             }
    //         }
    //         ans = max(ans, res);
    //     }

    // }while(next_permutation(v.begin(), v.end()));
    print(ans);

}