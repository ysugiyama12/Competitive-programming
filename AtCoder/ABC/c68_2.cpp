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
int N,M;
using namespace std;
int a[200010], b[200010];
vector<int> edge[200010];
int is_visit[200010] = {};
ll d[200010] = {};
void dijkstra(int start, int goal){
    rep(i,0,N){
        d[i] = 1e9;
    }
    d[start] = 0;
    while(1){
        int min = 1e9, target = -1;
        rep(i,0,N){
            if(!is_visit[i] && min > d[i]){
                min = d[i];
                target = i;
            }
        }
        if(target == -1){
            return;
        }
        is_visit[target] = 1;
        if(target == goal) return;

        for(auto &e : edge[target]){
            if(!is_visit[e]){
                if(d[e] > d[target] + 1){
                    d[e] = d[target] + 1;
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i,0,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        edge[a[i]].push_back(b[i]);
        edge[b[i]].push_back(a[i]);
    }
    dijkstra(0, N-1);
    if(d[N-1] == 2){
        print("POSSIBLE");
    }else{
        print("IMPOSSIBLE");
    }

}
