#include <iostream>
#include <vector>

int rob(std::vector<int> &nums) {
  int dp[nums.size()][2], mx = 0;
  dp[0][0] = 0;
  dp[0][1] = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    dp[i][0] = dp[i - 1][1];
    dp[i][1] = dp[i - 1][0] + nums[i];
    if (i > 1) {
      dp[i][1] = std::max(dp[i][1], dp[i - 2][0] + nums[i]);
    }
  }
  return std::max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
}

int main() {
  std::vector<int> a = {2, 7, 9, 3, 1};
  std::cout << rob(a) << '\n';
}
