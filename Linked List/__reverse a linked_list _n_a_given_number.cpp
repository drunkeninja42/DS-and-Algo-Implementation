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
void print(node *head)
{
    node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
}
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
//reverse a linked list in a given number
node* reverse_group(node*head,int key)
{  
    node*c = head;
    node*n = NULL;
    node* prev = NULL;
    int jump = 1;
    while(jump<=key)
    {
        n = c->next;
        c->next = prev;
        prev = c;
        c = n;
        jump++;
    }
    if(n!=NULL)
    head->next = reverse_group(n,key);
    return prev;
}
int main()
{
    node *head = NULL;
    cin>>head;
    cout<<head<<endl;
    int k = 2;
    node*prev = NULL;
    head = reverse_group(head,k);
    cout<<head<<endl;
}