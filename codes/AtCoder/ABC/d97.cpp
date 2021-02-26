#include <iostream>
#include <vector>

using namespace std;

vector<int> par;

int root(int x){

    if (par[x] == x){
        return x;
    }else{
        par[x] = root(par[x]);
        return par[x];
    }
}

int unite(int x, int y){
    int xr = root(x);
    int yr = root(y);
    if(xr == yr){
        return 0;
    }
    par[xr] = yr;
    return 0;
}

int same(int x, int y){
    if (root(x) ==  root(y)){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int N,M,i,j;
    cin >> N >> M;
    vector<int> p;
    for(i = 0; i < N; i++){
        int k;
        cin >> k;
        p.push_back(k); 
    }
    vector<int> x;
    vector<int> y;
    par.push_back(0);
    for(i = 0; i < N; i++){
        par.push_back(i+1);
    }
    for(i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }

    for(i = 0; i < M; i++){
        unite(x[i], y[i]);
    }
    int ans = 0;
    for(i = 0; i < N; i++){
        if(same(p[i], p[p[i]-1]) == 1){
            ans += 1;
        }
    }
    cout << ans << endl;


}
