//A number can be broken into different contiguous sub-subsequence parts. 
//Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245 3245. 
//And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
int Solution::colorful(int A) {
    string num=to_string(A);
    unordered_set<long long>s;
    for(int i=0;i<num.size();i++){
        long long mul=1;
        for(int j=i;j<num.size();j++){
            mul*=num[j]-'0';
            if(s.find(mul)==s.end())
            s.insert(mul);
            else
            return 0;
        }
    }
    return 1;
}
