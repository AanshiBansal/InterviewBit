//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
//Find all unique quadruplets in the array which gives the sum of target.
//Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a <= b <= c <= d)
//The solution set must be lexicographically ordered and not contain duplicate quadruplets.
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int> >sol;
    unordered_map<int,vector<pair<int,int> > >mp;
    for(int i=0;i<A.size();i++)
    for(int j=i+1;j<A.size();j++){
        if(mp.find(B-A[i]-A[j])!=mp.end()){
            for(int k=0;k<mp[B-A[i]-A[j]].size();k++){
            vector<int>ans(4);
            ans[0]=A[mp[B-A[i]-A[j]][k].first];
            ans[1]=A[mp[B-A[i]-A[j]][k].second];
            ans[2]=A[i];
            ans[3]=A[j];
                if(mp[B-A[i]-A[j]][k].first<i 
                    && mp[B-A[i]-A[j]][k].second!=i &&mp[B-A[i]-A[j]][k].second!=j)
                {
                    sort(ans.begin(),ans.end());
                    sol.push_back(ans);
                }
            }
        }
        if(mp.find(A[i]+A[j])==mp.end())
        mp[A[i]+A[j]]=*new vector<pair<int,int> >;
        mp[A[i]+A[j]].push_back(make_pair(i,j));
    }
    sort(sol.begin(),sol.end());
    vector<vector<int> >::iterator itr; 
    itr = unique(sol.begin(), sol.end()); 
    sol.resize(itr-sol.begin()); 
    return sol;
}
