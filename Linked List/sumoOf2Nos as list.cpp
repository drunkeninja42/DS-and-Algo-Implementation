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
//sum of 2 nos as lists
node* add(node*first,node*second)
{
    node*temp;
    node*prev;
    node*res = NULL;
    int sum = 0;
    int carry;
    while(first!=NULL || second!=NULL)
    {
        if(first)
        {
            sum += carry + first->data;
        }
        else sum += 0;
        if(second)
        {
            sum += carry + second->data;
        }
        else sum += 0;
        
        carry = (sum >= 10) ? 1 : 0; 
        if(sum >= 10) sum = sum%10;
        temp = new node(sum);
        if(res == NULL)
        res = temp;
        else{
            prev->next = temp;
        }
        prev = temp;
        if(first) first = first->next;
        if(second)  second = second->next;
        
    }
    if(carry>0)
    {
        temp->next = new node(carry);
    }
    return res;
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
    node*head1 = NULL;
    cin>>head;
    cin>>head1;
    cout<<head<<endl;
    cout<<head1<<endl;
    head1 = add(head,head1);
    cout<<head1<<endl;
    
}