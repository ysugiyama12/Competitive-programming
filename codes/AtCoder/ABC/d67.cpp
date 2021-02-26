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
int N;
int a[100010], b[100010];
int dto1[100010]={}, dtoN[100010]={};
vector<int> edge[100010];

void dfs1(int v, int p, int d){
    dto1[v] = d;
    for(auto &e : edge[v]){
        if(p == e) continue;
        dfs1(e, v, d+1);
    }
}

void dfs2(int v, int p, int d){
    dtoN[v] = d;
    for(auto &e : edge[v]){
        if(p == e) continue;
        dfs2(e, v, d+1);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i,0,N-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        edge[a[i]].push_back(b[i]);
        edge[b[i]].push_back(a[i]);
    }

    dfs1(0, -1, 0);
    dfs2(N-1, -1, 0);
    int ans_1 = 0;
    int ans_2 = 0;

    rep(i,0,N){
        if(dto1[i] <= dtoN[i]){
            ans_1++;
        }else{
            ans_2++;
        }
    }
    if(ans_1 > ans_2){
        print("Fennec");
    }else{
        print("Snuke");
    }


}
