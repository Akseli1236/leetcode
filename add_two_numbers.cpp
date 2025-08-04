#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    ListNode l3(0);
    ListNode *tail = &l3;

    int reminder = 0;

    while (l1 || l2 || reminder) {
      int add = reminder;

      if (l1) {
        add += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        add += l2->val;
        l2 = l2->next;
      }
      reminder = add / 10;
      tail->next = new ListNode(add % 10);

      tail = tail->next;
    }
    return l3.next;
  }
};

ListNode *build_list(const vector<int> &vals) {
  if (vals.empty())
    return nullptr;
  ListNode *head = new ListNode(vals[0]);
  ListNode *tail = head;
  for (size_t i = 1; i < vals.size(); ++i) {
    tail->next = new ListNode(vals[i]);
    tail = tail->next;
  }
  return head;
}

void print_list(ListNode *head) {
  while (head) {
    cout << head->val;
    if (head->next)
      cout << "->";
    head = head->next;
  }
  cout << endl;
}

int main() {
  // vector<int> vals1 = {9, 9, 9, 9, 9, 9, 9};
  // ListNode *list1 = build_list(vals1);
  // vector<int> vals2 = {9, 9, 9, 9};
  // ListNode *list2 = build_list(vals2);

  vector<int> vals1 = {5, 6};
  ListNode *list1 = build_list(vals1);
  vector<int> vals2 = {5, 4, 9};
  ListNode *list2 = build_list(vals2);
  Solution solution;
  ListNode *l3 = solution.addTwoNumbers(list1, list2);
  print_list(l3);

  return 0;
}
