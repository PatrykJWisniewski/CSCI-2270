#include <iostream>

using namespace std;

//----------- Define Node ---------------------------------------------------
struct Node{
      int key;
      Node *next;
};

//----------- Define Linked List ---------------------------------------------------
class LinkedList
{
  private:
    Node *head;

  public:
    LinkedList(){
    	head = NULL;
    }
    void insert_begin(int newKey);
    void insert_end(int newKey);
    int negativeSum();
    bool deleteAtIndex(int index);
  	bool deleteAtHead();
    void printList();
};

void LinkedList::insert_begin(int newKey){
  //1. ALLOCATE NODE
  Node* newNode = new Node;

  //2. PUT IN THE DATA
  newNode->key = newKey;

  //3. Make next of newNode as head
  newNode->next = head;

  //4. Change the head to newNode
  head = newNode;
}

void LinkedList::insert_end(int newKey){
  //1. ALLOCATE NODE
  Node* newNode = new Node;

  //2. PUT IN THE DATA
  newNode->key = newKey;

  //3. Make next of newNode as NULL
  newNode->next = NULL;

  //4. Check if head is not Null
  if(head == NULL){
    head = newNode;
    return;
  }

  //4. Traverse the LinkedList till end
  Node* temp = head;

  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
  return;
}

//TODO
int LinkedList::negativeSum(){
  if(head == NULL)
    return 0;

  int total = 0;
  int count = 0;

  do
  {
       if(head->key < 0)
       {
            total+= head->key;
            count++;
       }

       head = head->next;
  }
  while(head->next != NULL);

  cout<<"There is(are) "<<count<<" negative number(s) in the List"<<endl;
  return total;

}

// Use deleteAtHead to delete the first item in the list
bool LinkedList::deleteAtHead()
{
	bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

  Node *temp = head;
	head = temp->next;
	delete temp;
  isDeleted = true;

	return isDeleted;
}

//TODO
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

	Node *pres = head;

     int index = 1;
     do
     {
          if(index == n)
          {
               Node* toBeDeleated = pres->next; //Store it in a new instance
               pres->next = (pres->next)->next; //Link the current node too the one for deletion was pointing too
               delete toBeDeleated; //Delete the node;
               isDeleted = true;
               index++;
          }
          else
          {
               pres = pres->next;
               index++;
          }
     }
     while(pres->next != NULL);

	return isDeleted;
}

void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

int main()
{
	LinkedList li;
	cout<<"Adding nodes to List:"<<endl;
	// 2
	li.insert_begin(2);
	li.printList();
	// -1->2
	li.insert_begin(-1);
	li.printList();
	// -1->2->-7
	li.insert_end(-7);
	li.printList();
  // -1->2->-7->10
	li.insert_end(10);
	li.printList();
	// -1->2->-7->10->3
	li.insert_end(3);
	li.printList();
	cout<<endl;

	cout<<"Running delete function."<<endl;

	/*******************************
	Silver Problem - Implement the deleteAtIndex function
	********************************/

	cout<<"Deleting node at index: 3"<<endl;
	if(!li.deleteAtIndex(3))
	{
		cout<<"Delete failed!"<<endl;
	}
	li.printList();
	cout<<endl;

     if(!li.deleteAtHead())
	{
		cout<<"Delete failed!"<<endl;
	}
	li.printList();
	cout<<endl;


  cout<<"Get the sum of negatives"<<endl;

	/*******************************
	Gold Problem - Implement the negativeSum function
	********************************/
  int negsum;
  negsum = li.negativeSum();
  cout<<"Sum of all the negative elements is "<<negsum<<endl;

}
