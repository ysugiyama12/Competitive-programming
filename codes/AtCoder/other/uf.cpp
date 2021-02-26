
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
} p;

using namespace std;
int N,Q;
int P[200010], A[200010], B[200010];
int parent[200010];

int root(int x){
    if(x == parent[x]){
        return x;
    }else{
        return parent[x] = root(parent[x]);
    }
}

void unite(int a, int b){
    a = root(a);
    b = root(b);
    if(a == b){
        return;
    }
    parent[a] = b;
}

void same(int a, int b){
    if(root(a) == root(b)){
        print("Yes");
    }else{
        print("No");
    }

}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    rep(i,0,Q){
        cin >> P[i] >> A[i] >> B[i];
    }
    rep(i,0,N){
        parent[i] = i;
    }

    rep(i,0,Q){
        if(P[i] == 0){
            unite(A[i], B[i]);
        }else{
            same(A[i], B[i]);
        }

    }



}
