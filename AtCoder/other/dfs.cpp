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
    int H,W;
    cin >> H >> W;
    string s[510];
    rep(i,0,H){
        cin >> s[i];
    }
    P start, goal;
    rep(i,0,H){
        rep(j,0,W){
            if(s[i][j] == 's'){
                start.x = j;
                start.y = i;
            }else if(s[i][j] == 'g'){
                goal.x = j;
                goal.y = i;
            }
        }
    }

    stack<P> ss;
    ss.push(start);
    int is_visit[510][510] = {};
    while(!ss.empty()){
        P pos = ss.top();
        ss.pop();
        if(pos.x < 0 || pos.x >= W || pos.y < 0 || pos.y >= H){
            continue;
        }
        if(s[pos.y][pos.x] == '#'){
            continue;
        }
        if(is_visit[pos.x][pos.y]){
            continue;
        }
        is_visit[pos.x][pos.y] = 1;
        if(pos.x == goal.x && pos.y == goal.y){
            print("Yes");
            return 0;
        }

        P n1 = {pos.x + 1, pos.y};
        ss.push(n1);
        P n2 = {pos.x - 1, pos.y};
        ss.push(n2);
        P n3 = {pos.x, pos.y + 1};
        ss.push(n3);
        P n4 = {pos.x, pos.y - 1};
        ss.push(n4);


    }
    print("No");






}
