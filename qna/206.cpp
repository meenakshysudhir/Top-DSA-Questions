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
};

int main(void) { Solution obj; }
