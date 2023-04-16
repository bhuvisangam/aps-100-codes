/*Given a linked list and positions m and n. Reverse the linked list from position m to n.*/
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


class Solution
{
    public:
    Node* rev(Node* start,Node* end)
    {
        Node*cur=start;
        Node* nxt=NULL;
        Node* prv=NULL;
        while(cur!=end)
        {
            nxt=cur->next;
            cur->next=prv;
            prv=cur;
            cur=nxt;
        }
        return prv;
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        Node* prevStart=NULL;
        Node* start=head;
        Node* end=NULL;
        Node* nxtEnd=head;
        if(head==NULL || head->next==NULL)
        return head;
        int c=1;
        while(c<m)
        {
            prevStart=start;
            start=start->next;
            c++;
        }
        c=0;
        while(c<n)
        {
            end=nxtEnd;
            nxtEnd=nxtEnd->next;
            c++;
        }
        Node *ans=rev(start,nxtEnd);
         if(m==1)
        {
            head=ans;
            start->next=nxtEnd;
        }
        else{
        prevStart->next=ans;
        start->next=nxtEnd;}
        return head;
    }
};

void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}



        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
