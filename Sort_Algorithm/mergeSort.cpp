template<typename T>
void mergeSort(vector<T>& nums, int start, int end) {
	if (start >= end)	return;
	T mid = (end - start) / 2 + start;
	mergeSort(nums, start, mid);
	mergeSort(nums, mid + 1, end);

	int lenL = mid - start + 1, lenR = end - mid;
	vector<T> left(lenL, 0);
	vector<T> right(lenR, 0);
	for (int i = 0; i < lenL; i++)	left[i] = nums[start + i];
	for (int i = 0; i < lenR; i++)	right[i] = nums[mid + i + 1];
	for (int i = 0, j = 0, k = start; k < left.size() + right.size() + start; k++) {
		if (i >= left.size())	nums[k] = right[j++];
		else if (j >= right.size())	nums[k] = left[i++];
		else if (left[i] < right[j])	nums[k] = left[i++];
		else	nums[k] = right[j++];
	}
}