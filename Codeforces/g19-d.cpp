/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K;
    cin >> N >> K;
    if(K == 1){
        cout << "! 1" << endl;
        return 0;
    }
    ll target = -1, target_val = -1;
    ll change_pos = -1;
    ll types[510] = {};

    rep(q,0,N){
        vector<ll> inputs;
        if(q == 0){
            rep(i,0,K) inputs.push_back(i+1);
            cout << "? ";
            rep(i,0,K){
                cout << inputs[i];
                if(i != K-1) cout << " ";
            }
            cout << endl;
            ll pos, val;
            cin >> pos >> val;
            target = pos;
            target_val = val;
        }else if(q <= N-K){
            if(target == 1){
                change_pos = 2;
            }else{
                change_pos = 1;
            }
            types[change_pos-1] = 1;
            ll nxt = K+q-1;
            rep(i,0,K){
                if(i != change_pos-1){
                    inputs.push_back(i+1);
                }
            }
            inputs.push_back(nxt+1);
            cout << "? ";
            rep(i,0,K){
                cout << inputs[i];
                if(i != K-1) cout << " ";
            }
            cout << endl;
            ll pos,val;
            cin >> pos >> val;
            if(pos == target){
                types[nxt] = 1;
            }else{
                types[nxt] = 2;
            }
        }else if(q <= N-2){
            // print("go");
            ll nxt = 0;
            rep(i,0,K){
                if(i != target-1 && types[i] == 0){
                    nxt = i;
                    break;
                }
            }
            // print(nxt);
            rep(i,0,K){
                if(i != nxt){
                    inputs.push_back(i+1);
                }
            }
            inputs.push_back(K+1);
            cout << "? ";
            rep(i,0,K){
                cout << inputs[i];
                if(i != K-1) cout << " ";
            }
            cout << endl;
            ll pos,val;
            cin >> pos >> val;
            if(pos == target){
                types[nxt] = types[K];
            }else{
                if(types[K] == 1){
                    types[nxt] = 2;
                }else{
                    types[nxt] = 1;
                }
                // types[nxt] = (types[K] == 1 ? 2 : 1);
            }
        }else{
            // printa(types, N);
            ll cnt = 0;
            rep(i,0,K){
                if(types[i] == 1) cnt++;
            }
            rep(i,0,K){
                if(i != target-1) inputs.push_back(i+1);
            }
            inputs.push_back(K+1);
            cout << "? ";
            rep(i,0,K){
                cout << inputs[i];
                if(i != K-1) cout << " ";
            }
            cout << endl;
            ll pos,val;
            cin >> pos >> val;
            if(target_val > val){
                if(types[pos-1] == 1){
                    cout << "! " << 1+cnt << endl;
                    return 0;

                }else{
                    cout << "! " << K-cnt << endl;
                    return 0;
                }

            }else{
                if(types[pos-1] == 1){
                    cout << "! " << K-cnt << endl;
                    return 0;

                }else{
                    cout << "! " << 1+cnt << endl;
                    return 0;
                }
            }
        }


    }


}