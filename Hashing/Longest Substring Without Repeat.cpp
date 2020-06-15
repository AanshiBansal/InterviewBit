//Given a string,
//find the length of the longest substring without repeating characters.
int Solution::lengthOfLongestSubstring(string A) {
    vector<int>hash(256,-1);
    int ans=0;
    int start=0;
    int count=0;
    for(int i=0;i<A.size();i++){
        if(hash[A.at(i)]<start){
            hash[A.at(i)]=i;
            count++;
        }
        else{
            ans=max(ans,count);
            count=i-hash[A.at(i)];
            start=hash[A.at(i)]+1;
            hash[A.at(i)]=i;
        }
    }
    ans=max(ans,count);
    return ans;
}
