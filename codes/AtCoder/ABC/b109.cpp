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
    int N;
    string W[110];
    cin >> N;
    rep(i,0,N){
        cin >> W[i];
    }
    bool flg = true;
    vector<string> ww;
    ww.push_back(W[0]);
    
    rep(i,0,N-1){
        if(W[i][W[i].size()-1] == W[i+1][0]){
            bool flg_tmp = true;
            rep(j,0,ww.size()){
                if(W[i+1] == ww[j]){
                    flg_tmp = false;
                }
            }
            if(!flg_tmp){
                flg = false;
                print("No");
                return 0;
            }else{
                ww.push_back(W[i+1]);
            }

        }else{
            flg = false;
            print("No");
            return 0;
        }
        

    }
    print("Yes");

}
