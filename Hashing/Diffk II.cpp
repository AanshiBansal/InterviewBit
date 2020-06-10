//Given an array A of integers and another non negative integer k, 
//find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_set<int>s;
    for(int i=0;i<A.size();i++){
        if(s.find(B+A[i])!=s.end()||s.find(-B+A[i])!=s.end())
        return 1;
        s.insert(A[i]);
    }
    return 0;
}
