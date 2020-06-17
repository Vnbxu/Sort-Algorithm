template<typename T>
void selectionSort(vector<T>& nums) {
	for (int i = 0; i < nums.size() - 1; i++) {
		int index = i;
		for (int j = i + 1; j < nums.size(); j++)
			if (nums[j] < nums[index])	
				index = j;
		if (index != i) {
			T temp = nums[index];
			nums[index] = nums[i];
			nums[i] = temp;
		}
	}
}