//You are given an array of N integers, A1, A2 ,…, AN and an integer K. 
//Return the of count of distinct numbers in all windows of size K.
//Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.
vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int>ans;
    if(B>A.size())
    return ans;
    unordered_map<int,int>mp;
    for(int i=0;i<B-1;i++){
        if(mp.find(A[i])==mp.end())
        mp[A[i]]=0;
        mp[A[i]]++;
    }
    int j=0;
    for(int i=B-1;i<A.size();i++){
        if(mp.find(A[i])==mp.end())
        mp[A[i]]=0;
        mp[A[i]]++;
        ans.push_back(mp.size());
        mp[A[j]]--;
        if(mp[A[j]]==0)
        mp.erase(A[j]);
        j++;
    }
    return ans;
}
