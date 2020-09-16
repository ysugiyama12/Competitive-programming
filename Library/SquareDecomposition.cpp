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

struct SqrtDecomposition { // sum
private:
    ll N, K, sqrtN;
    vector<ll> data, bucket;

public:
    SqrtDecomposition(ll n){
        N = n;
        sqrtN = sqrt(n);
        K = (N + sqrtN - 1) / sqrtN;
        data.assign(n+10, 0);
        bucket.assign(K+10, 0);
    }

    void add(ll x, ll y){
        ll k = x / sqrtN;
        data[x] += y;
        bucket[k] += y;
    }

    // [x, y)
    ll getSum(ll x, ll y){
        ll sum = 0;
        rep(k,0,K){
            ll lv = k * sqrtN, rv = (k+1) * sqrtN;
            if(rv <= x || y <= lv) continue;
            if(x <= lv && rv <= y){
                sum += bucket[k];
            }else{
                for(ll i = max(x, lv); i < min(y, rv); i++){
                    sum += data[i];
                }
            }
        }
        return sum;
    }
};

// struct SqrtDecomposition { // min
// private:
//     ll N, K, sqrtN;
//     vector<ll> data, bucket;

// public:
//     SqrtDecomposition(ll n){
//         N = n;
//         sqrtN = sqrt(n);
//         K = (N + sqrtN - 1) / sqrtN;
//         data.assign(n+10, (1LL<<31)-1);
//         bucket.assign(K+10, (1LL<<31)-1);
//     }

//     void update(ll x, ll y){
//         ll k = x / sqrtN;
//         data[x] = y;
//         ll min_val = y;
//         for(ll i = k * sqrtN; i < (k+1) * sqrtN; i++){
//             min_val = min(min_val, data[i]);
//         }
//         bucket[k] = min_val;
//     }

//     // [x, y)
//     ll find(ll x, ll y){
//         ll min_val = INF;
//         rep(k,0,K){
//             ll lv = k * sqrtN, rv = (k+1) * sqrtN;
//             if(rv <= x || y <= lv) continue;
//             if(x <= lv && rv <= y){
//                 min_val = min(min_val, bucket[k]);
//             }else{
//                 for(ll i = max(x, lv); i < min(y, rv); i++){
//                     min_val = min(min_val, data[i]);
//                 }
//             }
//         }
//         return min_val;
//     }
// };

// struct SqrtDecomposition { // range add
// private:
//     ll N, K, sqrtN;
//     vector<ll> data, bucket;

// public:
//     SqrtDecomposition(ll n){
//         N = n;
//         sqrtN = sqrt(n);
//         K = (N + sqrtN - 1) / sqrtN;
//         data.assign(n+10, 0);
//         bucket.assign(K+10, 0);
//     }

//     void add(ll s, ll t, ll x){
//         rep(k,0,K){
//             ll lv = k * sqrtN, rv = (k+1) * sqrtN;
//             if(rv <= s || t <= lv) continue;
//             if(s <= lv && rv <= t){
//                 bucket[k] += x;
//             }else{
//                 for(ll i = max(s, lv); i < min(t, rv); i++){
//                     data[i] += x;
//                 }
//             }
//         }
//     }

//     ll get(ll x){
//         return data[x] + bucket[x / sqrtN];
//     }
// };

// struct SqrtDecomposition { // range update
// private:
//     ll N, K, sqrtN;
//     // vector<ll> data, bucket;
//     vector<ll> data;
//     vector<bool> lazyFlag;
//     vector<ll> lazyUpdate;

// public:
//     SqrtDecomposition(ll n){
//         N = n;
//         sqrtN = sqrt(n);
//         K = (N + sqrtN - 1) / sqrtN;
//         data.assign(n+10, (1LL<<31)-1);
//         lazyUpdate.assign(K+10, 0);
//         lazyFlag.assign(K+10, false);
//     }

//     void update(ll s, ll t, ll x){
//         rep(k,0,K){
//             ll lv = k * sqrtN, rv = (k+1) * sqrtN;
//             if(rv <= s || t <= lv) continue;
//             if(s <= lv && rv <= t){
//                 lazyFlag[k] = true;
//                 lazyUpdate[k] = x;
//             }else{
//                 if(lazyFlag[k]){
//                     lazyFlag[k] = false;
//                     rep(i,k * sqrtN, (k+1) * sqrtN){
//                         data[i] = lazyUpdate[k];
//                     }
//                     lazyUpdate[k] = 0;
//                 }
//                 for(ll i = max(s, lv); i < min(t, rv); i++){
//                     data[i] = x;
//                 }
//             }
//         }
//     }

//     ll find(ll x){
//         ll k = x / sqrtN;
//         if(lazyFlag[k]){
//             lazyFlag[k] = false;
//             for(ll i = k * sqrtN; i < (k+1) * sqrtN; i++){
//                 data[i] = lazyUpdate[k];
//             }
//             lazyUpdate[k] = 0;
//             return data[x];
//         }else{
//             return data[x];
//         }
//     }
// };

// struct SqrtDecomposition { // RSQ and RAQ
// private:
//     ll N, K, sqrtN;
//     vector<ll> data, bucket, bucket2;
//     // vector<ll> data;
//     // vector<bool> lazyFlag;
//     // vector<ll> lazyUpdate;

// public:
//     SqrtDecomposition(ll n){
//         N = n;
//         sqrtN = sqrt(n);
//         K = (N + sqrtN - 1) / sqrtN;
//         data.assign(n+10, 0);
//         bucket.assign(K, 0);
//         bucket2.assign(K, 0);

//     }

//     void add(ll s, ll t, ll x){
//         rep(k,0,K){
//             ll lv = k * sqrtN, rv = (k+1) * sqrtN;
//             if(rv <= s || t <= lv) continue;
//             if(s <= lv && rv <= t){
//                 bucket[k] += x;
//             }else{
//                 for(ll i = max(s, lv); i < min(t, rv); i++){
//                     data[i] += x;
//                     bucket2[k] += x;
//                 }
//             }
//         }
//     }

//     ll getSum(ll s, ll t){
//         ll res = 0;
//         rep(k,0,K){
//             ll lv = k * sqrtN, rv = (k+1) * sqrtN;
//             if(rv <= s || t <= lv) continue;
//             if(s <= lv && rv <= t){
//                 res += bucket[k] * sqrtN + bucket2[k];
//             }else{
//                 for(ll i = max(s, lv); i < min(t, rv); i++){
//                     res += data[i] + bucket[k];
//                 }
//             }
//         }
//         return res;
//     }
// };

struct SqrtDecomposition { // RMQ and RUQ
private:
    ll N, K, sqrtN;
    // vector<ll> data, bucket;
    vector<ll> data;
    vector<bool> lazyFlag;
    vector<ll> lazyUpdate;
    vector<ll> min_bucket;

public:
    SqrtDecomposition(ll n){
        N = n;
        sqrtN = sqrt(n);
        K = (N + sqrtN - 1) / sqrtN;
        data.assign(n+10, (1LL<<31)-1);
        min_bucket.assign(K+10, (1LL<<31)-1);
        lazyUpdate.assign(K+10, 0);
        lazyFlag.assign(K+10, false);
    }

    void update(ll s, ll t, ll x){
        rep(k,0,K){
            ll lv = k * sqrtN, rv = (k+1) * sqrtN;
            if(rv <= s || t <= lv) continue;
            if(s <= lv && rv <= t){
                lazyFlag[k] = true;
                lazyUpdate[k] = x;
                min_bucket[k] = x;
            }else{
                if(lazyFlag[k]){
                    lazyFlag[k] = false;
                    rep(i,k * sqrtN, (k+1) * sqrtN){
                        data[i] = lazyUpdate[k];
                    }
                    lazyUpdate[k] = 0;
                }
                for(ll i = max(s, lv); i < min(t, rv); i++){
                    data[i] = x;
                }
                min_bucket[k] = INF;
                rep(i, k*sqrtN, (k+1)*sqrtN){
                    min_bucket[k] = min(min_bucket[k], data[i]); 
                }
            }
        }
    }

    ll find(ll s, ll t){
        ll min_val = INF;
        rep(k,0,K){
            ll lv = k * sqrtN, rv = (k+1) * sqrtN;
            if(rv <= s || t <= lv) continue;
            if(s <= lv && rv <= t){
                min_val = min(min_val, min_bucket[k]);
            }else{
                if(lazyFlag[k]){
                    lazyFlag[k] = false;
                    rep(i,k * sqrtN, (k+1) * sqrtN){
                        data[i] = lazyUpdate[k];
                    }
                    lazyUpdate[k] = 0;
                }
                for(ll i = max(s, lv); i < min(t, rv); i++){
                    min_val = min(min_val, data[i]);
                }
            }
        }
        return min_val;
    }
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    SqrtDecomposition sd(100010);
    while(Q--){
        ll c;
        cin >> c;
        if(c == 0){
            ll s,t,x;
            cin >> s >> t >> x;
            sd.update(s, t+1, x);
        }else{
            ll s,t;
            cin >> s >> t;
            print(sd.find(s, t+1));
        }
    }
}