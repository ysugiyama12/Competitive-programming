#include <bits/stdc++.h>
#define rep(i, m, n) for(int i = m; i < (n); i++)
#define print(x) cout << (x) << endl;
#define printv(x) for(int i = 0; i < x.size(); i++){ cout << (x[i]) << " "; } cout << endl; 
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " ";} cout << endl;
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
    int N;
    int A[100001];
    cin >> N;
    rep(i,0,N){
        cin >> A[i];
    }
    int left = 0;
    int right = 0;
    int ans = 0;
    bool taste[100010];
    rep(i,0,N){
        taste[i] = false;
    }
    bool is_ok = true;
    taste[A[0]] = true;
    while(right < N){
        // cout << left << " " << right << endl;
        if(is_ok){
            ans = max(ans, right - left + 1);
            right++;
            if(right == N)break;
            if(taste[A[right]]){
                is_ok = false;
            }else{
                taste[A[right]] = true;
            }
            
        }else{
            if(left == right){
                left++;
                right++;
                if(right == N) break;
                taste[A[left-1]] = false;
                taste[A[left]] = true;
                is_ok = true;
            }else{
                if(taste[A[left]] && A[left] == A[right]){
                    is_ok = true;
                }else{
                    taste[A[left]] = false;
                }
                left++;
            }
        }
        
    }
    print(ans);


}
