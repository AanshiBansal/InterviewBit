//Given a string S and a string T, 
//find the minimum window in S which will contain all the characters in T in linear time complexity.
//Example :
//S = "ADOBECODEBANC"
//T = "ABC"
//Minimum window is "BANC"
bool check(vector<int>&A,vector<int>&B){
    for(int i=0;i<256;i++)
    if(A[i]<B[i])
    return false;
    return true;
}
string Solution::minWindow(string A, string B) {
    if(B.size()>A.size())
    return "";
    vector<int>bHash(256,0);
    vector<int>aHash(256,0);
    for(int i=0;i<B.size();i++)
    bHash[B[i]]++;
    string ans="";
    int start=0;
    int mini=INT_MAX;
    for(int i=0;i<A.size();i++){
        aHash[A[i]]++;
        if(check(aHash,bHash)){
            while(check(aHash,bHash)){
                aHash[A[start]]--;
                start++;
            }
            if(i-start+2 < mini){
                mini=i-start+2;
                ans=A.substr(start-1,i-start+2);
            }
        } 
    }
    return ans;
}

