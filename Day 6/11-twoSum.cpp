class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
  unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		int number = target - nums[i];
		if (hash.find(number) != hash.end()) {
			result.push_back(hash[number]);
			result.push_back(i);			
			return result;
		}
            hash[nums[i]] = i;
	}
	return result;
        
    }
};
