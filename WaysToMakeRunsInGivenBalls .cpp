
#include <bits/stdc++.h> 
using namespace std; 
#define mod 1000000007 
#define RUNMAX 721
#define BALLMAX 121
#define WICKETMAX 12

int CountWays(int r, int b, int l, int R, int B, int W, int dp[RUNMAX][BALLMAX][WICKETMAX]) { 
	if (l >= W) return 0; 
	if (r > R) return 0; 
	if (b <= B && r == R) return 1; 
	if (b == B) return 0; 
	if (dp[r][b][l] != -1) return dp[r][b][l]; 
	int ans = 0; 

	// If scored 0 run 
	ans += CountWays(r, b + 1, l, R, B, W, dp); 
	ans = ans % mod; 

	// If scored 1 run 
	ans += CountWays(r + 1, b + 1, l, R, B, W, dp); 
	ans = ans % mod; 

	
	// If scored 4 runs 
	ans += CountWays(r + 4, b + 1, l, R, B, W, dp); 
	ans = ans % mod; 

	// If scored 6 runs 
	ans += CountWays(r + 6, b + 1, l, R, B, W, dp); 
	ans = ans % mod; 

	// If scored no run and lost a wicket 
	ans += CountWays(r, b + 1, l + 1, R, B, W, dp); 
	ans = ans % mod; 

	
	return dp[r][b][l] = ans%mod; 
} 

int main() { 
	int R;
  	int B=120, W=11;
  	cin>>R;
	int dp[RUNMAX][BALLMAX][WICKETMAX]; 
	// int dp[R+1][B+1][W+1];
	memset(dp, -1, sizeof dp); 
	cout << CountWays(0, 0, 0, R, B, W, dp); 
	return 0; 
} 
