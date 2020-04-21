    // rep(i,0,np){
    //     if(mp[P[i]] == 0){
    //         if(i == np-1){
    //             mp[P[i]] = np;
    //         }else{
    //             mp[P[i]] = np-1-i;
    //         }
    //     }else{
    //         if(i == np-1){
    //             mp[P[i]] = min(mp[P[i]], np);
    //         }else{
    //             mp[P[i]] = min(mp[P[i]], np-1-i);
    //         }
    //     }
    // }
    // // for(auto &e: mp){
    // //     print(e.first, e.second);
    // // }

    // vector<ll> ret;
    // ll m = 0, i = np-1, n = nt;
    // while(m + i < n){
    //     print(m,i);
    //     if(P[i] == T[m+i]){
    //         i--;
    //         if(i == -1){
    //             // print(m,i);
    //             ret.push_back(m);
    //             m += mp[P[0]] ? mp[P[0]] : np;
    //             i = np-1;
    //         }
    //     }else{
    //         m += mp[T[m+np-1]] ? mp[T[m+np-1]] : np;
    //         i = np-1;
    //     }
    //     // print(m,i);
    // }
    // // printa(ret, ret.size());
    // for(auto &e: ret) print(e);