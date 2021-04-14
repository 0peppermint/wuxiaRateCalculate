#include <iostream>
using namespace std;

double dp[410][30];

void init(){
	//初始化
	for(int i = 0; i <= 400; ++i){
		for(int j = 0; j <= 25; ++j){
			dp[i][j] = 0.0;
		}
	}
	//先把东西准备好
	dp[1][0] = 1.0 * 75 / 100;
	dp[1][1] = 1.0 * 25 / 100;
	for(int i = 2; i <= 25; ++i){
		dp[i][i] = dp[i - 1][i - 1] * (25 - i) / 100;
		dp[i][0] = dp[i - 1][0] * 75 / 100;
	}
	for(int i = 2; i <= 400; ++i) {
		for(int j = 0; j <= 25; ++j){
			dp[i][j] = dp[i - 1][j] * (100 - (25 - j)) / 100;
			// j不可能是负数
			if(j > 0){
				dp[i][j] += dp[i - 1][j - 1] * (25 - (j - 1)) / 100;
			}
		}
	}
}
int main()
{
   init();
	cout << dp[400][25] << endl;
   return 0;
}