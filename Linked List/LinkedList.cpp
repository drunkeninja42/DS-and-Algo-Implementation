#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    //constructor
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
int len(node*head)
{
    node*temp = head;
    int sum = 0;
    while(temp!=NULL)
    {
        sum++;
        temp = temp->next;
    }
    return sum;
}
void insertAthead(node *&head,int data)
{
    node *n = new node(data);
    n->next = head;
    head = n;
}
void insertAttail(node*&head,int val)
{
    if(head==NULL)
    {
        head = new node(val);     
        return;
    }
    node*tail = head;
    while(tail->next!=NULL)
    {
        tail = tail->next;
    } 
    tail->next = new node(val);
    return; 
}
void inserAtmiddle(node*&head,int val,int pos)
{
    if(pos==0)
    {
        insertAthead(head,val);
    }
    else
    {
        int jump = 1;
        node*temp = head;
        while(jump<pos)
        {
            temp = temp->next;
            jump++;
        }
       node*n = new node(val);
       n->next = temp->next;
       temp->next = n;
    }
}
void print(node *head)
{
    node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
}
bool search(node *&head,int key)
{
    if(head==NULL)
    {
        return false;
    }
    if(head->data == key) return true;
    return search(head->next,key);
}
/*node * recureverse(node*&head)
{
    if(head->next == NULL|| head==NULL)
    {
        return head;
    }
    node*C = head;
    node*smallHead = recureverse(head->next);
    C->next->next = C;
    C->next = NULL;
    return smallHead;
}*/
/*node* middle(node*&head)
{
    if(head->next == NULL||head == NULL) return NULL;
    node*fast = head->next;
    node*slow = head;
    while(fast->next!=NULL && fast!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}*/
void buildList(node *&head)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        insertAttail(head,data);
        cin>>data;
    }
}
/*node* provide(node *head,int k)
{
    if(head == NULL)
    return NULL;
    while(head!=NULL)
    {
        if(head->data == k) return head;
        head = head->next;
    }
    return NULL;
}*/
/*void reverse(node *&head)
{
    node *C = head;
    node *N;
    node *P = NULL;
    while(C!=NULL)
    {
        N = C->next;
        C->next = P;
        P = C;
        C = N;  
    }
    head = P;
}*/
istream& operator>>(istream &is,node *&head)
{
    buildList(head);
    return is;
}
ostream& operator<<(ostream &os,node*head)
{
    print(head);
    return os;
   
}

int main()
{
    node *head = NULL;
    //buildList(head);
    //print(head);
    /*if(search(head,4))
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }*/
    cin>>head;
    cout<<head<<endl;
    //cout<<provide(head,5)->data<<endl;
    //reverse(head);
    //head = recureverse(head);
    //cout<<head<<endl;
    //node*mid = middle(head);
    //cout<<mid->data;
}