#include <everything.h>
using namespace std;

class Solution {
public:
  ListNode *reverseList(ListNode *head) {

    ListNode *prev = nullptr;

    while (head != nullptr) {
      ListNode *temp = head->next;
      head->next = prev;
      prev = head;
      head = temp;
    }
    return prev;
  }
  ListNode *reverseListbyR(ListNode *head) {
    // using recursion

    ListNode *newHead = head;

    if (head->next != NULL) {
      newHead = reverseListbyR(head->next);
      head->next->next = head;
    }
    head->next = nullptr;
    return newHead;
  }
};

int main(void) { Solution obj; }
