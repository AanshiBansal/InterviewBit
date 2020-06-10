//There are N Mice and N holes are placed in a straight line.
//Each hole can accomodate only 1 mouse.
//A mouse can stay at his position, move one step right from x to x + 1, or move one step left from x to x - 1. 
//Any of these moves consumes 1 minute.
//Assign mice to holes so that the time when the last mouse gets inside a hole is minimized.
int Solution::mice(vector<int> &A, vector<int> &B) {
    int size=A.size();
    if(size==0)
    return 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int ans=0;
    for(int i=0;i<size;i++)
    ans=max(ans,abs(A[i]-B[i]));
    return ans;
}
