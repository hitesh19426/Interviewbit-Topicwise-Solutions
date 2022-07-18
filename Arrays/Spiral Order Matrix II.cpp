vector<vector<int> > Solution::generateMatrix(int n) {
    vector<vector<int>> arr(n, vector<int>(n));

    int rowstart = 0, rowend = n-1, colstart = 0, colend = n-1, k = 1;
    while(rowstart <= rowend || colstart <= colend){
        if(colstart <= colend){
            for(int i=colstart; i<=colend; i++){
                arr[rowstart][i] = k++;
            }
        }

        if(rowstart < rowend){
            for(int i=rowstart+1; i<rowend; i++){
                arr[i][colend] = k++;
            }
        }

        if(colstart < colend){
            for(int i=colend; i>=colstart; i--){
                arr[rowend][i] = k++;
            }
        }

        if(rowstart < rowend){
            for(int i=rowend-1; i>rowstart; i--){
                arr[i][colstart] = k++;
            }
        }

        rowstart++, rowend--, colstart++, colend--;
    }

    return arr;
}
