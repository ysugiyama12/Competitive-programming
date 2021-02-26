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
string S, T;
bool checked(int i, int sl, int tl){
    bool flg = true;
    rep(j,i,i + tl){
        if(S[j] != T[j - i] && S[j] != '?'){
            flg = false;
        }
    }
    return flg;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S >> T;
    int sl = S.size();
    int tl = T.size();
    if(tl > sl){
        print("UNRESTORABLE");
        return 0;
    }
    string ans = "";
    rep(i,0,sl - tl + 1){
        if(checked(i, sl, tl)){
            string tt = "";
            rep(j,0,sl){
                if(j < i || j >= i + tl){
                    tt += S[j];
                }else{
                    tt += T[j - i];
                }
                
            }
            string tt2 = "";
            rep(j,0,sl){
                if(tt[j] == '?'){
                    tt2 += 'a';
                }else{
                    tt2 += tt[j];
                }
            }
            if(ans == ""){
                ans = tt2;
            }else if(strcmp(ans.c_str(), tt.c_str()) > 0){
                ans = tt2;

            }
        }
        

    }
    if(ans == ""){
        print("UNRESTORABLE");
    }else{
        print(ans);
    }

}
