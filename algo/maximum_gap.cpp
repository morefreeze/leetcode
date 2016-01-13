class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int n(int(nums.size()));
		int pow(1);
		for (int i = 0;i < 10;++i, pow *= 10) {
			vector<int> t[10];
			for (int j = 0;j < n;++j) {
				int idx = nums[j] / pow % 10;
				t[idx].push_back(nums[j]);
			}
			nums.clear();
			for (int k = 0;k < 10;++k) {
				if (t[k].empty()) continue;
				for (auto it = t[k].begin(); it != t[k].end(); ++it) {
					nums.push_back(*it);
				}
			}
		}
		int ans(0);
		for (int j = 1;j < n;++j) {
			cout << nums[j] << " ";
			ans = max(ans, nums[j] - nums[j-1]);
		}
		return ans;
	}
};