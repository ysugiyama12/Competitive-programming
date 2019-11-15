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
ll A[100010], B[100010];
ll AS[100010], BS[100010];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N;
  cin >> N;
  rep(i,0,N) cin >> A[i];
  rep(i,0,N) cin >> B[i];
  rep(i,0,N) AS[i] = A[i];
  rep(i,0,N) BS[i] = B[i];
  sort(AS, AS+N);
  sort(BS, BS+N);

  // bool same = true;
  rep(i,0,N){
    if(AS[i] > BS[i]){
      print("No");
      return 0;
    }
    // if(AS[i] != BS[i]) same = false;
  }
  // if(not same){
  //   print("Yes");
  //   return 0;
  // }
  bool unique = true;
  rep(i,0,N-1){
    if(A[i] <= B[i+1] && A[i+1] <= B[i]){
      unique = false; 
    }
  }
  if(not unique){
    print("Yes");
    return 0;
  }

  ll num = 0;
  map<ll,ll> mp;
  rep(i,0,N){
    mp[B[i]] = i;
  }
  map<ll,ll> mp2;
  rep(i,0,N) mp2[AS[i]] = BS[i];
  rep(i,0,N){
    if(A[i] == B[i]  && mp2[A[i]] == B[i]){
    }else{
      num++;
      ll pos = mp[A[i]];
      mp[A[i]] = i;
      mp[B[i]] = pos;
      ll tmp = B[i];
      B[i] = B[pos];
      B[pos] = tmp;
      // print(i, pos, B[i], B[pos]);
      // printa(B, N);
    }
  }
  // print(num);
  if(num >= N-1){
    print("No");
  }else{
    print("Yes");
  }



  

}