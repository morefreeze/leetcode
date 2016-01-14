class Solution {
public:
	// bucket sort, but no need sort, just keep min max of every interval
	int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) return 0;
		auto lh = minmax_element(nums.begin(), nums.end());
		int l = *lh.first, h = *lh.second;
		int gap = max(1, (h-l) / (n-1));
		int m = (h-l) / gap + 1;
		vector<int> bucket_min(m, INT_MAX);
		vector<int> bucket_max(m, INT_MIN);
		for (auto num : nums) {
			int k = (num-l) / gap;
			bucket_min[k] = min(bucket_min[k], num);
			bucket_max[k] = max(bucket_max[k], num);
		}
		int ans(bucket_max[0] - bucket_min[0]);
		int i = 0;
		while (i < m) {
			int j = i+1;
			while (j < m && bucket_min[j] == INT_MAX && bucket_max[j] == INT_MIN) ++j;
			if (j == m) break;
			ans = max(ans, bucket_min[j] - bucket_max[i]);
			i = j;
		}
		return ans;
	}
};
class RadixSolution {
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
