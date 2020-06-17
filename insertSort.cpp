template<typename T>
void insertSort(vector<T>& nums) {
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] < nums[i - 1]) {
			T temp = nums[i];
			for (int j = i - 1; j >= 0 && nums[j] > temp; j--)
				nums[j + 1] = nums[j];
			nums[j + 1] = temp;
		}
	}
}