string Solution::intToRoman(int num) {
    string romans[] = {"I","IV","V","IX","X","XL", "L","XC","C","CD", "D","CM","M"};
    int values[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    
    string ans = "";
    for(int i=12; i>=0; i--){
        while(values[i] <= num){
            num -= values[i];
            ans += romans[i];
        }
    }
    
    return ans;
}
