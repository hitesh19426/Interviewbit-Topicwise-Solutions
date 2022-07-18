int Solution::permuteStrings(string A, string B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    return A==B;
}
