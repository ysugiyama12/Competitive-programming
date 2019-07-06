#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    ll A[100010];
    cin >> N;
    rep(i,0,N) cin >> A[i];
    sort(A, A+N);
    ll cnt_plus = 0;
    rep(i,0,N){
        if(A[i] >= 0) cnt_plus++;
    }
    if(cnt_plus == N){
        if(N == 2){
            print(A[1] - A[0]);
            cout << A[1] << " " << A[0] << endl;
        }else{
            vector<lpair> ans;
            ll v = A[0];
            ans.push_back(make_pair(v, A[1]));
            v -= A[1];
            rep(i,2,N-1){
                ans.push_back(make_pair(v, A[i]));
                v -= A[i];
            }
            ans.push_back(make_pair(A[N-1], v));
            v = A[N-1] - v;
            print(v);
            rep(i,0,ans.size()){
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }

    }else if(cnt_plus == 0){
        sort(A, A+N, greater<ll>());
        if(N == 2){
            print(A[0] - A[1]);
            cout << A[0] << " " << A[1] << endl;
        }else{
            vector<lpair> ans;
            ll v = A[0];
            ans.push_back(make_pair(v, A[1]));
            v -= A[1];
            rep(i,2,N){
                ans.push_back(make_pair(v, A[i]));
                v -= A[i];
            }
            print(v);
            rep(i,0,ans.size()){
                cout << ans[i].first << " " << ans[i].second << endl;
            }

        }

    }else{
        vector<ll> plus, minus;
        rep(i,0,N){
            if(A[i] >= 0){
                plus.push_back(A[i]);
            }else{
                minus.push_back(A[i]);
            }
        }
        ll v = minus[0];
        vector<lpair> ans;
        rep(i,0,plus.size()-1){
            ans.push_back(make_pair(v, plus[i]));
            v -= plus[i];
        }
        ans.push_back(make_pair(plus[plus.size()-1], v));
        v = plus[plus.size()-1] - v;
        rep(i,1,minus.size()){
            ans.push_back(make_pair(v, minus[i]));
            v -= minus[i];
        }
        print(v);
        rep(i,0,ans.size()){
            cout << ans[i].first << " " << ans[i].second << endl;
        }



    }


    
}