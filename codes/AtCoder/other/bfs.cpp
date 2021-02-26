#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
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
    int R,C;
    cin >> R >> C;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;
    string s[55];
    rep(i,0,R){
        cin >> s[i];
    }
    P start = {sx, sy};
    P goal = {gx, gy};
    queue<P> qq;
    qq.push(start);
    int count[55][55] = {};
    int is_visit[55][55] = {};
    while(!qq.empty()){
        P pos = qq.front();
        qq.pop();
        P n1 = {pos.x + 1, pos.y};
        if (n1.x >= 0 && n1.x < C && n1.y >= 0 && n1.y < R && s[n1.y][n1.x] == '.' && !is_visit[n1.y][n1.x]){
            count[n1.y][n1.x] = count[pos.y][pos.x] + 1;
            qq.push(n1);
            is_visit[n1.y][n1.x] = 1;
        }
        P n2 = {pos.x - 1, pos.y};
        if (n2.x >= 0 && n2.x < C && n2.y >= 0 && n2.y < R && s[n2.y][n2.x] == '.' && !is_visit[n2.y][n2.x]){
            count[n2.y][n2.x] = count[pos.y][pos.x] + 1;
            qq.push(n2);
            is_visit[n2.y][n2.x] = 1;
        }
        P n3 = {pos.x, pos.y + 1};
        if (n3.x >= 0 && n3.x < C && n3.y >= 0 && n3.y < R && s[n3.y][n3.x] == '.' && !is_visit[n3.y][n3.x]){
            count[n3.y][n3.x] = count[pos.y][pos.x] + 1;
            qq.push(n3);
            is_visit[n3.y][n3.x] = 1;
        }
        P n4 = {pos.x, pos.y - 1};
        if (n4.x >= 0 && n4.x < C && n4.y >= 0 && n4.y < R && s[n4.y][n4.x] == '.' && !is_visit[n4.y][n4.x]){
            count[n4.y][n4.x] = count[pos.y][pos.x] + 1;
            qq.push(n4);
            is_visit[n4.y][n4.x] = 1;
        }
    }
    print(count[goal.y][goal.x]);

}
