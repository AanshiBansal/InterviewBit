//There are N children standing in a line. Each child is assigned a rating value.
//You are giving candies to these children subjected to the following requirements:
//1. Each child must have at least one candy.
//2. Children with a higher rating get more candies than their neighbors.
//What is the minimum candies you must give?
int Solution::candy(vector<int> &A) {
    if(A.size()==0)
    return 0;
    int sol=0;
    vector<int>ans(A.size());
    ans[0]=1;
    for(int i=1;i<A.size();i++){
            if(A[i]>A[i-1])
            ans[i]=ans[i-1]+1;
            else
            ans[i]=1;
    }
    for(int i=A.size()-2;i>=0;i--){
        if(A[i]>A[i+1])
        ans[i]=max(ans[i],ans[i+1]+1);
    }
    for(int i=0;i<A.size();i++)
        sol+=ans[i];
    return sol;
}
