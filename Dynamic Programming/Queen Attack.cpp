bool isvalid(int x, int y, int m, int n){
	return x>=0 && y>=0 && x<m && y<n;
}

typedef vector<vector<vector<bool>>> vvvb;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;

void fill_has_queen(int m, int n, vvvb& has_queen, vector<string>& A){
	int dx[] = {-1,-1,-1,0,1,1,1,0};
	int dy[] = {-1,0,1,1,1,0,-1,-1};

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			for(int k:{0,1,7}){
				int newx = i+dx[k], newy = j+dy[k];
				if(isvalid(newx, newy, m, n) && has_queen[newx][newy][k])
					has_queen[i][j][k] = has_queen[newx][newy][k];
				has_queen[i][j][k] = (has_queen[i][j][k] || A[i][j] == '1');
			}
		}
	}

	for(int i=0; i<m; i++){
		for(int j=n-1; j>=0; j--){
			for(int k:{2, 3}){
				int newx = i+dx[k], newy = j+dy[k];
				if(isvalid(newx, newy, m, n) && has_queen[newx][newy][k]){
					has_queen[i][j][k] = has_queen[newx][newy][k];
				}
				has_queen[i][j][k] = (has_queen[i][j][k] || A[i][j] == '1');
			}
		}
	}

	for(int i=m-1; i>=0; i--){
		for(int j=0; j<n; j++){
			for(int k:{5, 6}){
				int newx = i+dx[k], newy = j+dy[k];
				if(isvalid(newx, newy, m, n) && has_queen[newx][newy][k]){
					has_queen[i][j][k] = has_queen[newx][newy][k];
				}
				has_queen[i][j][k] = (has_queen[i][j][k] || A[i][j] == '1');
			}
		}
	}

	for(int i=m-1; i>=0; i--){
		for(int j=n-1; j>=0; j--){
			for(int k:{4}){
				int newx = i+dx[k], newy = j+dy[k];
				if(isvalid(newx, newy, m, n) && has_queen[newx][newy][k]){
					has_queen[i][j][k] = has_queen[newx][newy][k];
				}
				has_queen[i][j][k] = (has_queen[i][j][k] || A[i][j] == '1');
			}
		}
	}
}

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
	int m = A.size(), n = A[0].size();
    
	vector<vector<int>> ans(m, vector<int>(n, 0));
	vvvb has_queen(m, vvb(n, vb(8, false)));
	fill_has_queen(m, n, has_queen, A);
    
	int dx[] = {-1,-1,-1,0,1,1,1,0};
	int dy[] = {-1,0,1,1,1,0,-1,-1};
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<8; k++){
				int newx = i+dx[k], newy = j+dy[k];
				if(isvalid(newx, newy, m, n) && has_queen[newx][newy][k])
					ans[i][j]++;
			}
		}
	}
    
	return ans;
}