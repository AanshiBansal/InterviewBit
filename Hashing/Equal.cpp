//Given an array A of integers, find the index of values that satisfy A + B = C + D,
//where A,B,C & D are integers values in the array
//Return the indices `A1 B1 C1 D1`, so that 
//  A[A1] + A[B1] = A[C1] + A[D1]
//  A1 < B1, C1 < D1
//  A1 < C1, B1 != D1, B1 != C1 
//If there are more than one solutions, 
//then return the tuple of values which are lexicographical smallest.
vector<int> Solution::equal(vector<int> &A) {
    vector<int>sol;
    unordered_map<int,pair<int,int> >mp;
    for(int i=0;i<A.size();i++)
    for(int j=i+1;j<A.size();j++){
        if(mp.find(A[i]+A[j])!=mp.end()){
            vector<int>ans(4);
            ans[0]=mp[A[i]+A[j]].first;
            ans[1]=mp[A[i]+A[j]].second;
            ans[2]=i;
            ans[3]=j;
            if(ans[0]<ans[2] && ans[1]!=ans[2] && ans[1]!=ans[3])
            {
                if(sol.size()==0)
                sol=ans;
                else
                sol=ans<sol?ans:sol;
            }
        }
        else
        mp[A[i]+A[j]]=make_pair(i,j);
    }
    return sol;
}
