#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << x << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
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
    cin >> H >> W;
    char s[51][51] = {};
    rep(i,0,H){
        string tmp;
        cin >> tmp;
        rep(j,0,W){
            s[i][j] = tmp[j];
        }
    }
    int count[51][51] = {0};
    rep(i,0,H){
        rep(j,0,W){
            count[i][j] = -1;
        }
    }
    int load = 0;
    rep(i,0,H){
        rep(j,0,W){
            if(s[i][j] == '.'){
                load++;
            }
        }
    }

    queue<P> q;
    P start = {0,0};
    count[0][0] = 0;
    q.push(start);
    P before = {-1, -1};
    while(1){
        if(count[H-1][W-1] != -1 || q.empty()) break;
        P p = q.front();
        q.pop();

        if(p.x+1<W && count[p.y][p.x+1] == -1 && s[p.y][p.x+1] != '#'){
            P pt = {p.x+1, p.y};
            count[p.y][p.x+1] = count[p.y][p.x] + 1;
            q.push(pt);
        }
        if(p.x-1>=0 && count[p.y][p.x-1] == -1 && s[p.y][p.x-1] != '#'){
            P pt = {p.x-1, p.y};
            count[p.y][p.x-1] = count[p.y][p.x] + 1;
            q.push(pt);
        }
        if(p.y+1<H && count[p.y+1][p.x] == -1 && s[p.y+1][p.x] != '#'){
            P pt = {p.x, p.y+1};
            count[p.y+1][p.x] = count[p.y][p.x] + 1;
            q.push(pt);
        }
        if(p.y-1>=0 && count[p.y-1][p.x] == -1 && s[p.y-1][p.x] != '#'){
            P pt = {p.x, p.y-1};
            count[p.y-1][p.x] = count[p.y][p.x] + 1;
            q.push(pt);
        }
    }
    int ans = load - count[H-1][W-1] - 1;
    if(count[H-1][W-1] == -1){
        print(-1);
    }else{
        print(ans); 
    }


}
