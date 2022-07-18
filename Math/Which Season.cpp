string Solution::solve(int month) {
    if(month < 1 || month > 12)
        return "Invalid";
    if(month >=3 && month <= 5)
        return "Spring";
    if(month >= 6 && month <= 8)
        return "Summer";
    if(month >= 9 && month <= 11)
        return "Autumn";
    return "Winter";
}
