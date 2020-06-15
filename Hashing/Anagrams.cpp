//Given an array of strings, return all groups of strings that are anagrams. 
//Represent a group by a list of integers representing the index in the original list.
//1 based indexing
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string,vector<int> >mp;
    for(int i=0;i<A.size();i++){
        string help=A[i];
        sort(help.begin(),help.end());
        mp[help].push_back(i+1);
    }
    vector<vector<int> >ans;
    for(auto itr:mp)
    ans.push_back(itr.second);
    return ans;
}
