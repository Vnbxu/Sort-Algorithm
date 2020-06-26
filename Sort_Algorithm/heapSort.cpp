template<typename T>
void swap(vector<T>& nums, int a, int b) {
	T tmp = nums[a]; nums[a] = nums[b]; nums[b] = tmp;
}

//	构建大顶堆
template<typename T>
void heapify(vector<T>& tree, int n, int i) {
	int leftSon = 2 * i + 1, rightSon = 2 * i + 2;
	int maxValIndex = i;
	if (leftSon<n && tree[leftSon]>tree[maxValIndex])	maxValIndex = leftSon;
	if (rightSon<n && tree[rightSon]>tree[maxValIndex])	maxValIndex = rightSon;
	if (maxValIndex != i) {
		swap(tree, i, maxValIndex);
		heapify(tree, n, maxValIndex);
	}
}

template<typename T>
void buildHeap(vector<T>& tree) {
	int lastNode = tree.size() - 1;
	int nodeParent = (lastNode - 1) / 2;
	while (nodeParent >= 0) {
		heapify(tree, tree.size(), nodeParent);
		nodeParent--;
	}
}

template<typename T>
void heapSort(vector<T>& tree) {
	buildHeap(tree);
	for (int node = tree.size() - 1; node >= 0; node--) {
		swap(tree, 0, node);
		heapify(tree, node, 0);
	}
}