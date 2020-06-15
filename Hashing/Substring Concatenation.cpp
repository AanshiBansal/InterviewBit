/*
	You are given a string, S, and a list of words, L, that are all of the same length.
	Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
	Example :
	S: "barfoothefoobarman"
	L: ["foo", "bar"]
	You should return the indices: [0,9].
*/
vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int>ans;
    if(B.size()==0)
    return ans;
    int m=B.size();
    int n=B[0].size();
    int o=m*n;
    if(A.size()<o)
    return ans;
    unordered_map<string,vector<int> >mp;
    for(int i=0;i<B.size();i++)
        mp[B[i]].push_back(-1);
    int j=0;
    int start=0;
    int count=0;
    while(j<=A.size()-o){
        int i=j;
        start=j;
        count=0;
        while(i<=j+o-n){
            string help=A.substr(i,n);
            if(mp.find(help)!=mp.end()){
                int k=0;
                for(;k<mp[help].size();k++){
                    if (mp[help][k]>=start&&mp[help][k]<=i-n)
                    else
                    break;
                }
                if(k==mp[help].size())
                break;
                mp[help][k]=i;
                count++;
                i=i+n;
            }
            else
            break;
        }
        if(count==m)
        ans.push_back(start);
        j++;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            int size=itr->second.size();
            for(int i=0;i<size;i++)
            itr->second[i]=-1;
        }
    }
    return ans;
}
