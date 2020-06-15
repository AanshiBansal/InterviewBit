//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    if(A.size()==0)
    return 0;
    //unordered_map does not have a hash function for pair, hence we need to write it ourselves
    unordered_map<pair<double,double>,unordered_set<int>,hash_pair >mp;
    for(int i=0;i<A.size();i++)
    for(int j=i+1;j<A.size();j++){
        double slope;
        double c;
        if(A[i]==A[j])
        {
            slope=INT_MAX;
            c=A[i];
        }
        else
        {
            slope=double(B[j]-B[i])/double(A[j]-A[i]);
            c = B[i]-slope*A[i];
        }
        if(mp[{slope,c}].find(i)==mp[{slope,c}].end())
        mp[{slope,c}].insert(i);
        if(mp[{slope,c}].find(j)==mp[{slope,c}].end())
        mp[{slope,c}].insert(j);
    }
    long unsigned int ans=1;
    for(auto itr:mp)
    ans=max(ans,itr.second.size());
    return ans;
}

