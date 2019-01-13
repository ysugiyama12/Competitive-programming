#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
#define printa2(x,m,n) for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ cout << x[i][j] << " ";} cout << endl;}
#define INF (1e9)
typedef long long ll;
typedef struct{
    int x;
    int y;
} P;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W;
    int a[510][510];
    cin >> H >> W;
    rep(i,0,H){
        rep(j,0,W){
            cin >> a[i][j];
        }
    }
    int y = 0; int x = 0;
    vector<P> pos;
    while(y != H - 1 || x != W - 1){
        P p = {x,y};
        pos.push_back(p);
        if(y == H-1){
            if(x % 2 == 0){
                x++;
            }else{
                y--;
            }
        }else if(y == 0){
            if(x % 2 == 0){
                y++;
            }else{
                x++;
            }
        }else if(x % 2 == 0){
            y++;
        }else{
            y--;
        }
    }
    P lst = {W-1, H-1};
    pos.push_back(lst);
    rep(i,0,pos.size()-1){
        int px = pos[i].x;
        int py = pos[i].y;
        int px_n = pos[i+1].x;
        int py_n = pos[i+1].y;
        if(a[py][px] % 2 == 1){
            cout << py+1 << " " << px+1 << " " << py_n+1 << " " << px_n+1 << endl;
            a[py][px]--;
            a[py_n][px_n]++;
        }
    }

    // int even_count = 0;
    // int odd_count = 0;
    // rep(i,0,H){
    //     rep(j,0,W){
    //         if(a[i][j] != 0){
    //             if(a[i][j] % 2 == 0){
    //                 even_count++;
    //             }else{
    //                 odd_count++;
    //             }
    //         }
    //     }
    // }

    // int ans = 0;
    // if(odd_count % 2 == 0){
    //     ans = even_count + (odd_count/2);
    // }else{
    //     ans = even_count + (odd_count-1)/2;
    // }
    // print(ans);
    // vector<P> xx;
    // int mh = min(W,H);
    // int cnt = 0;
    // while(mh > 0){
    //     rep(j,cnt, W-cnt){
    //         P p = {cnt, j};
    //         xx.push_back(p);
    //     }
    //     rep(j, cnt+1, H-cnt){
    //         P p = {j, W-cnt-1};
    //         xx.push_back(p);
    //     }
    //     if(mh != 1){
    //         rep(j,cnt+1, W-cnt){
    //             P p = {H-cnt-1, W - 1 - j};
    //             xx.push_back(p);
    //         }
    //         rep(j, cnt+1, H-cnt - 1){
    //             P p = {H - 1 - j, cnt};
    //             xx.push_back(p);
    //         }

    //     }

    //     mh -= 2;
    //     cnt++;
    // }
    // rep(i,0,xx.size()){
    //     cout << xx[i].x << " " << xx[i].y << endl;
    // // }
    // bool is_print = false;
    // bool is_first = false;
    // int ans_num = 0;
    // rep(i,0,xx.size()){
    //     int ypos = xx[i].x;
    //     int xpos = xx[i].y;
    //     if(a[ypos][xpos] != 0 && a[ypos][xpos] % 2 == 1 && is_first == false && odd_count % 2 == 1){
    //         is_first = true;
    //         continue;
    //     }
    //     if(odd_count % 2 == 0 || (odd_count % 2 == 1 && is_first == true)){

    //         if(a[ypos][xpos] != 0 && a[ypos][xpos] % 2 == 1 && is_print == false){
    //             // cout << ypos << " " << xpos << " ";
    //             is_print = true;
    //         }else if(a[ypos][xpos] != 0 && a[ypos][xpos] % 2 == 1 && is_print == true){
    //             // cout << ypos << " " << xpos << " " << endl;
    //             ans_num++;
    //             is_print = false;
    //         }else if(is_print == true){
    //             // cout << ypos << " " << xpos << endl;
    //             ans_num++;
    //             // cout << ypos << " " << xpos << " ";
    //         }
    //     }

    // }
    // print(ans_num);
    // is_print = false;
    // is_first = false;
    // rep(i,0,xx.size()){
    //     int ypos = xx[i].x;
    //     int xpos = xx[i].y;
    //     if(a[ypos][xpos] != 0 && a[ypos][xpos] % 2 == 1 && is_first == false && odd_count % 2 == 1){
    //         is_first = true;
    //         continue;
    //     }
    //     if(odd_count % 2 == 0 || (odd_count % 2 == 1 && is_first == true)){

    //         if(a[ypos][xpos] != 0 && a[ypos][xpos] % 2 == 1 && is_print == false){
    //             cout << ypos+1 << " " << xpos+1 << " ";
    //             is_print = true;
    //         }else if(a[ypos][xpos] != 0 && a[ypos][xpos] % 2 == 1 && is_print == true){
    //             cout << ypos+1 << " " << xpos+1  << endl;
    //             is_print = false;
    //         }else if(is_print == true){
    //             cout << ypos+1 << " " << xpos+1 << endl;
    //             cout << ypos+1 << " " << xpos+1 << " ";
    //         }
    //     }

    // }

}
