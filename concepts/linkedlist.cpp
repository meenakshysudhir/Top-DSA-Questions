#include <everything.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node() {
    data = 0;
    next = NULL;
  }

  Node(int Data) {
    data = Data;
    next = NULL;
  }
};
class LinkedList {
  Node *head;

public:
  LinkedList() { head = NULL; }

  void insertatHead(int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
      head = newNode;
      return;
    }

    newNode->next = this->head;
    this->head = newNode;
  }

  void printLL() {
    if (head == NULL) {
      cout << "Empty Linked List" << endl;
      return;
    }
    Node *temp = this->head;
    while (temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
  }

  void reversingLL() {

    if (head == NULL) {
      cout << "Empty linked list" << endl;
      return;
    }

    Node *curr = this->head;
    while (curr != NULL) {
      curr->next->next = curr;
    }
  }
};

int main(void) {
  LinkedList list;

  list.insertatHead(1);
  list.insertatHead(2);
  list.insertatHead(3);

  cout << "Elements of the list : " << endl;
  list.printLL();
  cout << endl;
}
