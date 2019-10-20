/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> lpair;
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
    ll N;
    cin >> N;
    char c[1010][1010];
    ll dh[] = {-1,-1,-1,0,0,1,1,1};
    ll dw[] = {-1,0,1,-1,1,-1,0,1};
    ll cnt[255] = {};
    while(N--){
        ll H,W;
        cin >> H >> W;
        rep(i,0,H){
            rep(j,0,W){
                if((i+j) % 3 == 0){
                    c[i][j] = 'A';
                }else if((i+j) % 3 == 1){
                    c[i][j] = 'B';
                }else{
                    c[i][j] = 'C';
                }
            }
        }
        rep(i,0,H){
            rep(j,0,W){
                rep(k,0,8){
                    ll hh = i + dh[k], ww = j + dw[k];
                    if(hh >= 0 && hh < H && ww >= 0 && ww < W){
                        cnt[c[i][j] + c[hh][ww]]++;
                    }
                }
            }
        }
        cnt['A'+'B'] /= 2;
        cnt['A'+'C'] /= 2;
        cnt['C'+'B'] /= 2;
        while(1){
            // print(cnt['A'+'B'], cnt['A'+'C'],cnt['C'+'B']);
            if(cnt['A'+'B'] == cnt['B' + 'C'] && cnt['B'+'C'] == cnt['C' + 'A']){
                break;
            }
            ll v1h = rand() % H, v1w = rand() % W;
            ll v2h = rand() % H, v2w = rand() % W;
            if(c[v1h][v1w] == c[v2h][v2w]) continue;
            rep(k,0,8){
                ll hh = v1h + dh[k], ww = v1w + dw[k];
                if(hh >= 0 && hh < H && ww >= 0 && ww < W){
                    cnt[c[v1h][v1w] + c[hh][ww]]--;
                }
                hh = v2h + dh[k]; ww = v2w + dw[k];
                if(hh >= 0 && hh < H && ww >= 0 && ww < W){
                    cnt[c[v2h][v2w] + c[hh][ww]]--;
                }
            }
            swap(c[v1h][v1w], c[v2h][v2w]);
            rep(k,0,8){
                ll hh = v1h + dh[k], ww = v1w + dw[k];
                if(hh >= 0 && hh < H && ww >= 0 && ww < W){
                    cnt[c[v1h][v1w] + c[hh][ww]]++;
                }
                hh = v2h + dh[k]; ww = v2w + dw[k];
                if(hh >= 0 && hh < H && ww >= 0 && ww < W){
                    cnt[c[v2h][v2w] + c[hh][ww]]++;
                }
            }

        }
        print(cnt['A'+'B'], cnt['A'+'C'],cnt['C'+'B']);
        rep(i,0,H){
            rep(j,0,W){
                cout << c[i][j];
            }
            cout << endl;
        }
    }
    

}