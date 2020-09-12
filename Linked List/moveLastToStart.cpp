#include<iostream>
#include<vector>
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
//move the last element to start
node* connect(node*&head)
{
    node*temp = head;
    node* prev=NULL;
    while(temp->next!=NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    temp->next = head;
    prev->next = NULL;
    head = temp;
    return head;
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

int main()
{
    node *head = NULL;
    cin>>head;
    cout<<head<<endl;
    head = connect(head);
    cout<<head<<endl;
}