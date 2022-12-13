#include <iostream>
using namespace std;

struct Node
{
  Node(int data = 0, Node *next = nullptr) : data(data), next(next) {}
  int data;
  Node *next;
};

void pushValue(Node *&head, int data)
{
  Node *new_node = new Node(data);
  Node *last = head;
  new_node->next = NULL;
  if (head == NULL)
  {
    head = new_node;
    return;
  }
  while (last->next != NULL)
  {
    last = last->next;
  }
  last->next = new_node;
  return;
}
void removeValue(Node *&head, int data)
{

  Node *nodeToDelete;
  while (head != NULL && head->data == data)
  {
    nodeToDelete = head;
    head = head->next;
    delete (nodeToDelete);
  }

  Node *temp = head;
  if (temp != NULL)
  {
    while (temp->next != NULL)
    {
      if (temp->next->data == data)
      {
        nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete (nodeToDelete);
      }
      else
      {
        temp = temp->next;
      }
    }
  }
}

void print(Node *head)
{

  if (head == NULL and cout << endl)
    return;
  cout << head->data << ' ';
  print(head->next);
}

int main()
{
  Node *head = NULL;

  pushValue(head, 7);
  pushValue(head, 2);
  pushValue(head, 2);
  pushValue(head, 3); 
  pushValue(head, 2);
  pushValue(head, 5);
  print(head);
  removeValue(head, 2);
  print(head);
  return 0;
}