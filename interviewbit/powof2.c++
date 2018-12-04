int fun(string s1){
    int l = s1.length();
    int temp;
    long long int num=0;
    for(int i=0; i<l; i++){
        temp = s1[i]-'0';
        num +=temp * pow(10,(l-1-i));
        
    }
    
    if(num & (num-1)){
        return 0;
    }
    
    else 
        return 1;
}


int Solution::power(string A) {
    

    
    string s1="",s2="";
    int f=0,s=1,t,rem=0;
    s2=A;
    int l = A.length();
    
    if(l==1){
        t= A[0]-'0';
        if(t<2)
            return 0;
    }
    while(s){
        s1=s2;
        s2="";
        l=s1.length();
        
        
        if(l==1 && s1[0]=='0'){
            break;
        }
        
        if(l<=16){
            f=fun(s1);
            
            return f;
        }
        rem =0;
        for(int i=0; i<l; i++){
            t= s1[i] - '0';
            t = rem*10 + t;
            if(s2.length()==0 && (t/2)==0)
                s2 = "";
            else
                s2 += to_string(t/2);
            rem = t%2;
            if(i==(l-1) && rem!=0)
                return 0;
            if(l==1 && rem ==0)
                s2="0";
        }
    }
    
    return 1;
    
}
