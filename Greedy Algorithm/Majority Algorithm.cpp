//Given an array of size n, find the majority element.
//The majority element is the element that appears more than floor(n/2) times.
//You may assume that the array is non-empty and the majority element always exist in the array.
int Solution::majorityElement(const vector<int> &A) {
    int a = A.size();
    int r= a/2 + 1;
    unordered_map<int,int>mp;
    for(int i=0;i<a;i++){
        if(mp.find(A[i])==mp.end())
        mp[A[i]]=0;
        mp[A[i]]++;
        if(mp[A[i]]==r)
        return A[i];
    }
}
//Moore's Voting Algorithm could be used to solve in O(n) time and O(1) space.
