//Find the largest continuous sequence in a array which sums to zero.
vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int,int>mp;
    mp[0]=-1;
    int sum=0;
    int start;
    int end;
    int length=0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        if(mp.find(sum)!=mp.end()){
            if(i-mp[sum]>length){
                length=i-mp[sum];
                start=mp[sum]+1;
                end=i;
            }
        }
        else
        mp[sum]=i;
    }
    if(length==0)
    return *new vector<int>;
    vector<int>ans(end-start+1);
    for(int i=0;i+start<=end;i++)
    ans[i]=A[i+start];
    return ans;
}
