//N light bulbs are connected by a wire.
//Each bulb has a switch associated with it, however due to faulty wiring, 
//a switch also changes the state of all the bulbs to the right of current bulb.
//Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.
//0 represents the bulb is off and 1 represents the bulb is on.
int Solution::bulbs(vector<int> &A) {
    int ans=0;
    for(int i=0;i<A.size();i++){
        if((ans+A[i])%2==0)
        ans++;
    }
    return ans;
}
