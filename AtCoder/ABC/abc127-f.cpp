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
    ll Q;
    cin >> Q;
    ll res = 0;
    priority_queue<ll, vector<ll>, less<ll> > pq_less;
    priority_queue<ll, vector<ll>, greater<ll> > pq_greater;
    ll sum_less = 0, sum_greater = 0;
    ll val = 0;
    while(Q--){
        ll q;
        cin >> q;
        if(q == 1){
            ll a,b;
            cin >> a >> b;
            res += b;
            if(pq_less.size() == 0){
                pq_less.push(a);
                sum_less += a;
            }else{
                if(pq_greater.size() == 0){
                    val += abs(pq_less.top() - a);
                    if(pq_less.top() <= a){
                        pq_greater.push(a);
                        sum_greater += a;
                    }else{
                        sum_less += a - pq_less.top();
                        sum_greater += pq_less.top();
                        pq_greater.push(pq_less.top());
                        pq_less.pop();
                        pq_less.push(a);
                    }
                }else{
                    ll v1 = pq_less.top();
                    ll v2 = pq_greater.top();
                    ll sz = pq_less.size() + pq_greater.size();
                    if(sz % 2 == 0){
                        if(a < v1 || v2 < a) val += min(abs(v1 - a), abs(a - v2));
                        if(a <= v2){
                            pq_less.push(a);
                            sum_less += a;
                        }else{
                            pq_less.push(v2);
                            pq_greater.pop();
                            pq_greater.push(a);
                            sum_less += v2;
                            sum_greater += a - v2;
                        }
                    }else{
                        val += abs(v1 - a);
                        if(a <= v1){
                            pq_greater.push(v1);
                            pq_less.pop();
                            pq_less.push(a);
                            sum_greater += v1;
                            sum_less += a - v1;
                        }else{
                            pq_greater.push(a);
                            sum_greater += a;
                        }
                    }


                }
            }

        }else{
            // print(pq_less.top(), val+res);
            ll mid = pq_less.top();
            ll ans = mid * (ll)pq_less.size() - sum_less;
            ans += sum_greater - mid * (ll)pq_greater.size();
            print(mid, ans + res);
        }
    }

}