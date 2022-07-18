bool ispowerof2(string a, int b = 2){
	if(a == "1")
        return false;
    
    while(a.size()!=1 || a.back() != '1'){
		
        if( (a.back()-'0')%2==1)
            return false;

		string quotient = "";
		int rem = 0, j = 0;
		for(int i=0; i<(int)a.size(); i++){
			rem = rem*10 + (a[i]-'0');
			if(rem < b){
				if(i!=0)
					a[j++] = '0';
			}
			else{
				a[j++] = char(rem/b+'0');
				rem = rem - (rem/2)*2;
			}
		}
		a.resize(j);
	}
	return true;
}

int Solution::power(string A) {
    return ispowerof2(A);
}
