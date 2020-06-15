/*
	Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
	If the fractional part is repeating, enclose the repeating part in parentheses.
	Example :
	Given numerator = 1, denominator = 2, return "0.5"
	Given numerator = 2, denominator = 1, return "2"
	Given numerator = 2, denominator = 3, return "0.(6)"
*/
string Solution::fractionToDecimal(int num1, int num2) {
    long long A=num1;
    long long B=num2;
    if(A==0)
    return "0";
    int sign=1;
    if(A<0 ^ B<0)
    {
        A=abs(A);
        B=abs(B);
        sign*=-1;
    }
    long long r= A%B;
    long long q= A/B;
    string ans= to_string(q);
    if(r==0)
    return (sign==-1)?"-"+ans:ans;
    ans.append(".");
    unordered_map<int,int>hash;
    vector<int>rem;
    while(r!=0 && hash.find(r)==hash.end()){
        A=r*10;
        q=A/B;
        hash[r]=q;
        rem.push_back(r);
        r=A%B;
    }
    if(r==0){
        for(int i=0;i<rem.size();i++)
        ans.append(to_string(hash[rem[i]]));
        return (sign==-1)?"-"+ans:ans;
    }
    for(int i=0;i<rem.size();i++)
    {
        if(rem[i]==r)
        ans.append("(");
        ans.append(to_string(hash[rem[i]]));
    }
    ans.append(")");
    return (sign==-1)?"-"+ans:ans;
}
