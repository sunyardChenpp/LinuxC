#pragma once
#include <iostream>
#include <string>
using namespace std;


//删去链表中总乘积值为10的连续节点
//链表 head ，反复删去链表中由 总乘积 值为 10 的连续节点组成的序列，直到不存在这样的序列为止，需
//考虑各种特殊情况。
//返回最终链表结果。
//head = [-2, 5, -1, -10, 1, -1, 10, 2, 2, 2, 5, 5] //示例链表
/**
* Definition for singly-linked list.
* struct ListNode {
* int val;
* ListNode *next;
* ListNode() : val(0), next(nullptr) {}
* ListNode(int x) : val(x), next(nullptr) {}
* ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}	
};

class Solution
{
public:
	ListNode* createLinkedList(int arr[], int n);
	void printLinkedList(ListNode* head);
	ListNode* removeSublists(ListNode* head);
	void test();
};