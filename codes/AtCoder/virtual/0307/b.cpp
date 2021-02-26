#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
#define INF (1e18)
ll N,M,K;
ll A[100010], B[100010];
vector<ll> tree[100010];
string S;



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    cin >> S;
    rep(i,0,M){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        tree[A[i]].push_back(B[i]);
        tree[B[i]].push_back(A[i]);
    }
    ll ans1[100010] = {};//奇数
    rep(i,0,N){
        bool ok = false;
        for(auto &e: tree[i]){
            if(S[e] == 'B'){
                ok = true;
            }
        }
        if(ok){
            ans1[i] = 0;
        }else{
            ans1[i] = 1;
        }
    }
    ll ans2[100010] = {}; // 奇数
    rep(i,0,N){
        bool ok = false;
        for(auto &e: tree[i]){
            if(S[e] == 'R'){
                ok = true;
            }
        }
        if(ok){
            ans2[i] = 1;
        }else{
            ans2[i] = 0;
        }
    }
    ll ans_even[100010] = {};
    rep(i,0,N){
        bool ok = false;
        for(auto &e: tree[i]){
            if(ans2[e] == 0){
                ok = true;
            }
        }
        if(ok){
            ans_even[i] = 0;
        }else{
            ans_even[i] = 1;
        }
    }
    if(K % 2 == 1){
        rep(i,0,N){
            if(ans1[i] == 0){
                print("First");
            }else{
                print("Second");
            }
        }
    }else{
        rep(i,0,N){
            if(ans_even[i] == 0){
                print("First");
            }else{
                print("Second");
            }
        }
    }
    // ll ans1[100010] = {};
    // rep(i,0,N){
    //     if(S[i] == 'B'){
    //         ans1[i] = 1;
    //     }else{
    //         ans1[i] = 2;
    //     }
    // }
    // ll ans2[100010] = {};
    // rep(i,0,N){
    //     bool ok = true;
    //     for(auto &e: tree[i]){
    //         if(ans1[e] != 2){
    //             ok = false;
    //         }
    //     }
    //     if(!ok){
    //         ans2[i] = 1;
    //     }else{
    //         ans2[i] = 2;
    //     }
    // }
    // if(K % 2 == 1){
    //     rep(i,0,N){
    //         if(ans2[i] == 1){
    //             print("First");
    //         }else{
    //             print("Second");
    //         }
    //     }
        
    // }else{
    //     rep(i,0,N){
    //         if(ans1[i] == 1){
    //             print("First");
    //         }else{
    //             print("Second");
    //         }
    //     }
    // }
    // rep(i,0,N){
    //     rep(k,0,2){
    //         calc(i,k);
    //     }
    // }


    
}