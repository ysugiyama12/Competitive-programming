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
    int a[] = {1,6,8,3,6};
    auto ans = max_element(a, a+5);
    cout << *ans << endl;
    // int tt = *ans;
    // print(tt);
    // map<int, int> dic;
    // dic[-2] = 3;
    // print(dic[-2]);
    // if(dic.find(-1) == dic.end()){
    //     print("not found");
    // }else{
    //     print("found");
    //     int pos = dic.find(-1) - dic.begin();
    // }




}
