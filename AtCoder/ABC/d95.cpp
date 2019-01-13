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

    int N,i,j;
    ll C;
    cin >> N >> C;
    vector<ll> x(N+1);
    vector<ll> v(N+1);



    x[0] = 0;
    v[0] = 0;
    rep(i, 0, N){ 
        cin >> x[i+1] >> v[i+1];
    }

    vector<ll> a_score(N+1, 0);
    a_score[0] = 0;
    rep(i, 1, N+1){
        a_score[i] = a_score[i-1] + v[i] - (x[i] - x[i-1]);
    }

    vector<ll> b_score(N+1, 0);
    b_score[N] = v[N] - (C - x[N]);
    rep(i, 1, N){
        b_score[N  - i] = b_score[N + 1 - i] + v[N - i] - (x[N + 1 - i] - x[N - i]); 
    }

    vector<ll> score_max(N+1,0);
    score_max[0] = 0;
    rep(i, 1, N+1){
        if(a_score[score_max[i-1]] < a_score[i]){
            score_max[i] = i;
        }else{
            score_max[i] = score_max[i-1];
        }
    }
    ll max_score = 0;
    rep(i, 0, N+1){
        if(i == 0){
            int max_a = score_max[N];
            ll score = a_score[max_a];
            max_score = max(max_score, score);
        }else{
            int max_a = score_max[i-1];
            ll score = a_score[max_a] + b_score[i];
            score -= min(x[max_a], C - x[i]);
            max_score = max(max_score, score);
        }
    }
    print(max_score);

 
    //ll max_score = 0;
    //rep(i, 0, N+1){
    //    rep(j, 0, N+1){
    //        if(i < j || j == 0){
    //            ll score = 0;
    //            ll OA = x[i];
    //            ll OB = C - x[j];
    //            if (j == 0){
    //                OB = 0;
    //            }
    //            rep(k, 0, i+1){
    //                score += v[k]; 
    //            }
    //            if( j != 0){
    //                rep(k, j, N+1){
    //                    score += v[k];
    //                }
    //            }
    //            ll len = min(OA + 2 * OB, OA * 2 + OB);
    //            score -= len;
    //            max_score = max(max_score, score);
    //        }
    //    }
    //}
    //print(max_score);



}
