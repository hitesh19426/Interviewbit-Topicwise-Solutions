int Solution::solve(int a, int b) {
    a--, b--;

    int dx[] = {1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1};
    int ans = 0;

    for(int i=0; i<4; i++){
        int x = a, y = b;
        while(true){
            x += dx[i];
            y += dy[i];
            if(x>=0 && y>=0 && x<8 && y<8)
                ans++;
            else
                break;
        }
    }

    return ans;
}
