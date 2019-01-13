#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << x << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x) for(int i = 0; i < (sizeof(x)/sizeof(x[0])); i++){ cout << (x[i]) << " ";} cout << endl;

typedef long long ll;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H,W,D,Q;
    int L[100001] = {0}, R[100001] = {0};
    cin >> H >> W >> D;
    vector< vector<int> > A(301, vector<int>(301, 0));
    vector< vector<int> > Hash(100001, vector<int>(2, 0));
    rep(i,0,H){
        rep(j,0,W){
            int a;
            cin >> a;
            A[i][j] = a;
            Hash[a][0] = i;
            Hash[a][1] = j;
        }
    }

    cin >> Q;
    rep(i,0,Q){
        int l,r;
        cin >> l >> r;
        L[i] = l;
        R[i] = r; 
    }
    vector<ll> s(100001);
    rep(i,1,H*W+1){
        if(i <= D){
            s[i] = 0;
        }else{
            s[i] = s[i-D] + abs(Hash[i][0] - Hash[i-D][0]) + abs(Hash[i][1] - Hash[i-D][1]);
        }
    }

    rep(i,0,Q){
        print(s[R[i]] - s[L[i]]);
        //while(1){
        //    if(g > R[i]) break;
        //    ans += abs(Hash[s][0] - Hash[g][0]) + abs(Hash[s][1] - Hash[g][1]);
        //    s += D;
        //    g += D;
        //}

    }

}
