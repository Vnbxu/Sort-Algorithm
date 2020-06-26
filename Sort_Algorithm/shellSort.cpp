template<typename T>
void shellSort(vector<T>& nums) {
	int gap = nums.size() / 2;
	while (gap >= 1) {
		for (int i = 0; i < gap; i++) {
			for (int j = i + gap, k; j < nums.size(); j += gap) {
				if (nums[j] < nums[j - gap]) {
					T temp = nums[j];
					for (k = j - gap; k >= 0 && temp < nums[k]; k -= gap)
						nums[k + gap] = nums[k];
					nums[k + gap] = temp;
				}
			}
		}
		gap /= 2;
	}
}