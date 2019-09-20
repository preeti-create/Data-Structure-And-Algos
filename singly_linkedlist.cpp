#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
class linked_list
{
    public:
    struct node *temp,*n,*head;
    linked_list()
    {
        head=NULL;
        temp=NULL;
    }
    void add_node_end(int i)
    {
        n=new node;
        n -> data = i;
        n -> next = NULL;
        if(head == NULL)
        {
            temp=n;
            head=n;
        }
        else
        {
            temp -> next = n;
            temp= temp -> next;
        }
    }
    void add_node_begin(int i)
    {
        struct node *temp;
        n=new node;
        n -> data = i;
        n -> next = NULL;
        if(head == NULL)
        {
            temp=n;
            head=n;
        }
        else
        {
            temp = head;
            head = n;
            n -> next = temp;
        }
    }
    void position(int i,int pos)
    {
        n = new node;
        n -> data = i;
        temp = head;
        int j=1;
        while( j < pos-1)
        {
            temp = temp -> next ;
            j++;
        }
        n -> next = temp -> next;
        temp -> next = n;
    }
    void delet(int pos)
    {
        temp=head;
        if(pos==1){
            head = temp->next;
            delete temp;
        }
        else
        {
            int i;
            for(i=0;i<pos-2;i++){
                temp=temp->next;
            }
            struct node *del = temp->next;
            temp->next=del->next;
            delete del;
        }
    }
    void display()
    {
        node *n;
        n=head;
        while(n!=NULL)
        {
            cout<< n -> data <<"->";
            n=n -> next;
        }
            
    }
};
int main() {
	int n,i;                     
	cin>>n;
	linked_list a;
	while(n!=0)
	{
	    cin>>i;
	    a.add_node_end(i);
	    n--;
	}
	int strt,no;                 
	cin>>no;
	while(no!=0)
	{
	    cin>>strt;
	    a.add_node_begin(strt);
	    no--;
	}
	int pos,k;
	cin>>pos>>k;
	a.position(k,pos);
	int dele;
	cin>>dele;
	a.delet(dele);
	a.display();
	
	return 0;
}
