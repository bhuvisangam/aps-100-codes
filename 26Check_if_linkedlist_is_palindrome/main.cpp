//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node *head)
    {
        Node *prv=NULL;
        Node *cur=head;
        Node *nxt=NULL;
        while(cur!=NULL)
        {
           nxt= cur->next;
           cur->next=prv;
           prv=cur;
           cur=nxt;
        }
        Node *p=prv;
      return p;
    }
    bool isPalindrome(Node *head)
    {
        if(head->next==NULL)
        return true;
       Node *fast=head->next;
       Node *slow=head;
       while(fast != NULL && fast-> next != NULL)
       {
           fast=fast->next->next;
           slow=slow->next;
       }
       Node *temp=slow->next;
      slow->next= reverse(temp);
         Node* head1 = head;
        Node* head2 = slow -> next;

        while(head2 != NULL) {
            if(head2->data != head1->data) {
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
          temp = slow -> next;
        slow -> next = reverse(temp);
        return true;
    }
};

int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {

        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}
