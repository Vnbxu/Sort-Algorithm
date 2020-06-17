template<typename T>
void quickSort(vector<T>& nums, int start, int end) {
	if (start >= end)	return;
	int i = start, j = end;
	T base = nums[start];
	while (i < j) {
		while (i < j && nums[j] >= base)	j--;
		if (i < j)	nums[i++] = nums[j];
		while (i < j && nums[i] <= base)	i++;
		if (i < j)	nums[j--] = nums[i];
	}
	nums[i] = base;
	quickSort(nums, start, i - 1);
	quickSort(nums, i + 1, end);
}