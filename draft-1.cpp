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

void solve(){
    ll sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    ll dx = abs(sx - gx), dy = abs(sy - gy);
    ll ans = 0;
    if(dx > 0 && dy > 0){
        ans = dx + dy;
    }else{
        if(dx == 0){
            if(sy > gy){
                if(sy % 2 == 0){
                    ans = dy + 1;
                }else{
                    ans = dy;
                }
            }else if(sy < gy){
                if(sy % 2 == 0){
                    ans = dy;
                }else{
                    ans = dy+1;
                }
            }
        }else{
            if(sx > gx){
                if(sx % 2 == 0){
                    ans = dx;
                }else{
                    if(dx == 1){
                        ans = 1;
                    }else{
                        ans = dx+1;
                    }
                }

            }else if(sx < gx){
                if(sx % 2 == 0){
                    if(dx == 1){
                        ans = 1;
                    }else{
                        ans = dx + 1;
                    }
                }else{
                    ans = dx;
                }

            }

        }
    }
    print(ans);
    // ll ans = min(dx, dy) * 2;
    // if(gy > sy){
    //     sy += min(dx,dy);
    // }else{
    //     sy -= min(dx,dy);
    // }
    // if(gx > sx){
    //     sx += min(dx,dy);
    // }else{
    //     sx -= min(dx,dy);
    // }
    // if(min(dx,dy) == dx){
    //     if(gy > sy){
    //         if(sy % 2 == 0){
    //             ans += gy - sy;
    //         }else{
    //             ans += gy - sy + 1;
    //         }
    //     }else if(gy < sy){
    //         if(sy % 2 == 0){
    //             ans += sy - gy + 1;
    //         }else{
    //             ans += sy - gy;
    //         }
    //     }
    // }else{
    //     if(gx > sx){
    //         if(sx % 2 == 0){
    //             if(gx - sx == 1){
    //                 ans += 1;
    //             }else{
    //                 ans += gx - sx + 1;
    //             }
    //         }else{
    //             ans += gx - sx;
    //         }
    //     }else if(gx < sx){
    //         if(sx % 2 == 0){
    //             ans += sx - gx;
    //         }else{
    //             if(sx - gx == 1){
    //                 ans += 1;
    //             }else{
    //                 ans += sx - gx + 1;
    //             }
    //         }
    //     }
    // }
    // print(ans);


    

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}