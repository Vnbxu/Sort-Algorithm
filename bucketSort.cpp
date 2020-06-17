struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v) :val(v), next(nullptr) {};
};

void insert(vector<ListNode*>& bucket, int index, int num) {
	ListNode* cur = bucket[index]->next, * pre = bucket[index];
	while (cur && cur->val < num) {
		pre = cur;
		cur = cur->next;
	}
	ListNode* insert = new ListNode(num);
	insert->next = cur;
	pre->next = insert;
}

void mergeBucket(vector<ListNode*>& bucket,vector<int>& nums) {
	for (int i = 0, j = 0; i < bucket.size() && j < nums.size(); i++) {
		ListNode* cur = bucket[i]->next;
		while (cur != nullptr) {
			nums[j++] = cur->val;
			cur = cur->next;
		}
	}
}

void bucketSort(vector<int>& nums) {
	int minVal = nums[0], maxVal = nums[0];
	for (auto& num : nums) {
		minVal = min(minVal, num);
		maxVal = max(maxVal, num);
	}
	int bucketNum = (maxVal - minVal) / nums.size() + 1;
	vector<ListNode*> buckets(bucketNum, nullptr);
	for (auto& bucket : buckets)
		bucket = new ListNode(-1);
	for (auto& num : nums) {
		int index = (num - minVal) / nums.size();
		insert(buckets, index, num);
	}
	mergeBucket(buckets, nums);
}