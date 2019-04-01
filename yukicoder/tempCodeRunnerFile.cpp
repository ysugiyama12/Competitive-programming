    // rep(i,0,N) pq.push(make_pair(dist1[i], i));
    // rep(i,0,N) pq.push(make_pair(dist2[i], i));
    // ll is_visit[100010] = {};
    // ll max_length[100010] = {};
    // while(!pq.empty()){
    //     lpair l1 = pq.top();
    //     pq.pop();
    //     is_visit[l1.second] = 1;
    //     for(auto &e: tree[l1.second]){
    //         if(dist[e.first] > dist[l1.second] + e.second){
    //            if(!is_visit[e.first]){
    //                 dist[e.first] = dist[l1.second] + e.second;
    //                 max_length[e.first] = max(max_length[l1.second], e.second);
    //                 pq.push(make_pair(dist[e.first], e.first));
    //             }                
    //         }
    //     } 
    // }
    // printa(dist, N);
    // printa(max_length, N);