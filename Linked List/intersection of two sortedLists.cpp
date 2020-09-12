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
void intersect(node*&h1,node*&h2)
{
    node*t1 = h1;
    node*t2 = h2;
    while(h1!=NULL || h2!=NULL)
    {
        
        if(h1->data == h2->data)
        {
            t1 = h1;
            t2 = h2; 
            break;
        }
        else
        {
            if(h1->data<h2->data)
            {
                h1 = h1->next;
            }
            else h2 = h2->next;

        }
    }
    while(t1!=NULL && t2!=NULL)
    {
        cout<<t1->data<<"-->";
        t1  =t1->next;
        t2 = t2->next;
    }
    cout<<endl;   
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
    intersect(head,head1);
    
    
}