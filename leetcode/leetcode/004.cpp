#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums;
		nums.insert(nums.end(), nums1.begin(), nums1.end());
		nums.insert(nums.end(), nums2.begin(), nums2.end());
		sort(nums.begin(),nums.end());
		double median = nums.size() % 2 != 0 ? nums[nums.size() / 2] : (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2.0;
		return median;
	}
};

int main() {
	vector<int> nums1 = {};
	vector<int> nums2 = { 2, 3 };
	Solution sln;
	sln.findMedianSortedArrays(nums1, nums2);
	return 0;
}