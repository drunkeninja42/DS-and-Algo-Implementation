#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node* prev;
    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
void insertAttail(node *&head , int data)
{
    if(head == NULL)
    {
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next!=NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(data);
    tail->next->prev = tail;
    return;
}
void delete(node*head)
{
    if(head == NULL)
    {
        return;
    }
    node*temp = head;
    while(temp!=NULL)
    {

    }
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
void print(node *head)
{
    node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"<-->";
        temp = temp->next;
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
int main()
{
    node* head = NULL;
    cin>>head;
    cout<<head<<endl; 
}
