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
node* kthnodeformEnd(node*head,int k)
{
    node*slow = head;
    node*fast = head;
    int jump = k;
    while(jump > 0 )
    {
        fast = fast->next;
        jump--;
    }
    while(fast!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
//recursion and backtracking palindrome or not 
bool ispalindrome(node*&left , node*&right)
{
    if(right == NULL) return true;
    bool isp = ispalindrome(left,right->next);
    if(isp == false) return false;
    bool isp1 = (left->data == right->data);
    left = left->next;
    return isp1;
    
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
    if(ispalindrome(head,head)) cout<<"true"<<endl;
    else cout<<"false"<<endl;

}