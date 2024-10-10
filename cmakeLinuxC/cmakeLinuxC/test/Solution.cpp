#include "Solution.h"

ListNode* Solution::removeSublists(ListNode* head) {
	if (head == nullptr)
	{
		return nullptr;
	}
	//新创建一个链表，第一个节点值为1
	 ListNode* newHead = new ListNode(1);
	 //将新链表下一个节点指向传入的链表首节点
	 newHead->next = head;
	 //创建一个临时操作链表的变量
	 ListNode* tmpListNode = newHead;

	 while (tmpListNode->next != nullptr) {
		 //查询连续节点的序列
		 ListNode* queryListNode = tmpListNode->next;
		 long product = 1;
 
		 //查询总乘积为10的连续节点直到链表末尾
		 while (queryListNode != nullptr && product != 10) {
			 product *= queryListNode->val;
			 queryListNode = queryListNode->next;
		 }
		 //查到了就删除连续节点
		 if (product == 10) {
			 ListNode* toDelete = tmpListNode->next;
			 while (toDelete != queryListNode) {
				 ListNode* temp = toDelete;
				 toDelete = toDelete->next;
				 delete temp;
			 }
			 //将剩余节点连接上
			 tmpListNode->next = queryListNode;
			 //将链表指向第一个节点：因为连续节点删除动作后链表发生了变化所以必须重新开始扫描
			 tmpListNode = newHead;
		 }
		 else
		 {
			 //没有删除动作，从下一个节点开始查询
			 tmpListNode = tmpListNode->next;
		 }
 
	 }
	 ListNode* retHead = newHead->next;
	 delete newHead;
	 return retHead;
}
ListNode* Solution::createLinkedList(int arr[], int n) {
	ListNode* head;
	if (n != 0) {
		head = new ListNode(arr[0]); // 创建头节点
		ListNode* temp = head;
		// 遍历数组，逐个添加节点
		for (int i = 1; i < n; i++) {
			temp->next = new ListNode(arr[i]);
			temp = temp->next;
		}
	}
	return head;
}

void Solution::printLinkedList(ListNode* head) {
	if (head == nullptr)
	{
		cout << " 链表为空" << endl;
		return;
	}
	while (head != nullptr) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void Solution::test() {

	// 示例创建链表[-2, 5, -1, -10, 1, -1, 10, 2, 2, 2, 5, 5]
	int arr[] = { -2, 5, -1, -10, 1, -1, 10, 2, 2, 2, 5, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	ListNode* head = createLinkedList(arr, n);
	cout << "删除前的链表" << endl;
	// 打印链表
	printLinkedList(head);

	// 删除连续乘积为10的节点
	head = removeSublists(head);

	cout << "删除后的链表" << endl;
	// 打印链表
	printLinkedList(head);

	// 释放链表内存
	while (head != nullptr) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}

}