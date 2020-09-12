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
//length of a loop in a linked list(Floyd's Cycle algorithm)
int isloop(node*&head)
{
    node*slow = head;
    node*fast = head;
    bool loop = false ;
    while(fast!= NULL && fast->next != NULL && slow!= NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            loop = true;
            break;
        }
    }
    int count = 0;
    if(loop)
    {
        while(fast == slow)
        {
            slow = slow->next;
            fast = fast->next;
            count++;
        }
    }
    return count ;
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
    cout<<isloop(head)<<endl;
   

}