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

bool is_maxbit(ll bit, ll k){
    ll val = (1LL<<(k+1));
    if(bit < val){
        return true;
    }else{
        return false;
    }
    
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll A[100010];
    rep(i,0,N) cin >> A[i];
    sort(A, A+N, greater<ll>());
    ll bit_all[62] = {};
    ll bit_red[62] = {}, bit_blue[62] = {};
    rep(k,0,61){
        rep(i,0,N){
            if((A[i]>>k) & 1){
                bit_red[k]++;
                bit_all[k]++;
            }
        }
    }
    multiset<ll> red, blue;
    rep(i,0,N) red.insert(A[i]);
    rrep(k,60,0){
        if(bit_all[k] == 0) continue;
        if(bit_red[k] % 2 == 1 && bit_blue[k] % 2 == 1) continue;
        // print(bit_red[k]);
        
        if(bit_all[k] % 2 == 0){ // 2 4
          if(bit_red[k] == 0){
            //   print(k);
              ll v = -1;
              for(auto &e: blue){
                  if(k == 0) print(e);
                  if((e>>k) & 1){
                      v = e;
                      break;
                  }
              }
            //   print(v);
              if(is_maxbit(v, k)){
                  auto itr = blue.find(v);
                //   blue.erase(itr);
                  rep(j,0,61){
                      if((v>>j) & 1){
                          bit_red[j]++;
                          bit_blue[j]--;
                      }
                  }
              }else{
                  ll amari = v - v % (1LL<<(k+1));
                  for(auto &e: red){
                      if(e == amari){
                          auto itr = blue.find(v);
                          auto itr2 = red.find(amari);
                          blue.erase(itr); red.erase(itr2);
                            rep(j,0,61){
                                if((v>>j) & 1){
                                    bit_red[j]++;
                                    bit_blue[j]--;
                                }
                                if((amari>>j) & 1){
                                    bit_red[j]--;
                                    bit_blue[j]++;
                                }
                            }
                          break;
                      }
                  }

              }
          }else{
              ll v = -1;
              for(auto &e: red){
                  if((e>>k) & 1){
                      v = e;
                      break;
                  }
              }
            //   if(k == 2) print(v);
              if(is_maxbit(v, k)){
                  auto itr = red.find(v);
                  red.erase(itr);
                  rep(j,0,61){
                      if((v>>j) & 1){
                          bit_red[j]--;
                          bit_blue[j]++;
                      }
                  }
              }else{
                  ll amari = v - v % (1LL<<(k+1));
                  for(auto &e: blue){
                      if(e == amari){
                          auto itr = red.find(v);
                          auto itr2 = blue.find(amari);
                          red.erase(itr); blue.erase(itr2);
                            rep(j,0,61){
                                if((v>>j) & 1){
                                    bit_red[j]--;
                                    bit_blue[j]++;
                                }
                                if((amari>>j) & 1){
                                    bit_red[j]++;
                                    bit_blue[j]--;
                                }
                            }
                          break;
                      }
                  }

              }

          }
        }

    }
    ll ans = 0;
    ll v1 = 0, v2 = 0;
    for(auto &e: red){
        v1 ^= e;
    }
    for(auto &e: blue){
        v2 ^= e;
    }
    ans = v1+v2;
    print(ans);

    
}