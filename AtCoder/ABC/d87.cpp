#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;
#define printaa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ for(int j = 0; j < (sizeof(x[0])/sizeof(x[0][0])); j++){ cout << x[i][j] << " ";} cout << endl;}
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
    int N,M;
    int L[200001],R[200001],D[200001];
    cin >> N >> M;
    rep(i,0,M){
        cin >> L[i] >> R[i] >> D[i];
    }
    int x[100001];
    rep(i,1,N+1){
        x[i] = INF;
    }
    vector<vector<P> > v(200001);
    rep(i,0,M){
        P tmp = {L[i],D[i]};
        P tmp2 = {R[i], -1*D[i]};
        v[R[i]].push_back(tmp);
        v[L[i]].push_back(tmp2);
    }
    int is_visit[100001] = {};
    stack<int> s;
    bool is_ok = true;
    rep(i,1,N+1){
        if(is_visit[i] == 0){
            s.push(i);
            x[i] = 0;
            while(1){
                if(s.empty()) break;
                int next = s.top();
                s.pop();
                if(is_visit[next] == 1) continue;
                is_visit[next] = 1;
                rep(j,0,v[next].size()){
                    s.push(v[next][j].x);
                    if(x[v[next][j].x] == INF){
                        x[v[next][j].x] = x[next] - v[next][j].y;
                    }
                    if(x[v[next][j].x] != INF && x[next] != INF && x[next] - x[v[next][j].x] != v[next][j].y){
                        is_ok = false;
                    }
                }

            }
        }
    }
    if(!is_ok){
        print("No");
    }else{
        print("Yes");
    }

}
