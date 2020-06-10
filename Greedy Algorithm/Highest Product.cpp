//Given an array A, of N integers A.
//Return the highest product possible by multiplying 3 numbers from the array.
int Solution::maxp3(vector<int> &A) {
    sort(A.begin(),A.end());
    int s=A.size();
    int a= A[0]*A[1]*A[s-1];
    int b= A[s-1]*A[s-2]*A[s-3];
    return max(a,b);
}
