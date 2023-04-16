
#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;

    Node* head = new Node(val);
    Node* tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* rev(struct Node* head)
    {
        Node* cur=head;
        Node* prv=NULL;
        Node* nxt=NULL;
        while(cur!=NULL)
        {
           nxt=cur->next;
           cur->next=prv;
           prv=cur;
           cur=nxt;
        }
        return prv;
    }
    void insertAtEnd(struct Node* &head,struct Node* &tail,int x)
    {
        Node *temp=new Node(x);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            return;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }

    }
    struct Node* add(struct Node* first, struct Node* second)
    {
        int carry=0;
        Node *head=NULL;
        Node *tail=NULL;
        while(first!=NULL && second!=NULL)
        {
            int sum=carry+first->data+second->data;
            int digit=sum%10;
            insertAtEnd(head,tail,digit);
            carry=sum/10;
            first=first->next;
            second=second->next;
        }
          while(first!=NULL)
        {
            int sum=carry+first->data;
            int digit=sum%10;
            insertAtEnd(head,tail,digit);
            carry=sum/10;
            first=first->next;
        }
          while(second!=NULL)
        {
            int sum=carry+second->data;
            int digit=sum%10;
            insertAtEnd(head,tail,digit);
            carry=sum/10;
            second=second->next;
        }
          while(carry!=0)
        {
            int sum=carry;
            int digit=sum%10;
            insertAtEnd(head,tail,digit);
            carry=sum/10;
        }
        return head;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=rev(first);
        second=rev(second);
        Node *ans=add(first,second);
        ans=rev(ans);
        return ans;
    }
};



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;

        cin>>n;
        Node* first = buildList(n);

        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
