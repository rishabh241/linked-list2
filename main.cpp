#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
int data;
struct node *next;
}*first=nullptr,*second=nullptr,*third=nullptr;
/**< CREATE THE LINKED LIST */
void create(int a[],int n){
struct node *t,*last;
first=new struct node;
first->data=a[0];
first->next=nullptr;
last=first;
for(int i=1;i<n;i++){
    t=new struct node;
    t->data=a[i];
    t->next=nullptr;
    last->next=t;
    last=t;

}
}
void create2(int b[],int m){
struct node *t,*last;
second=new struct node;
second->data=b[0];
second->next=nullptr;
last=second;
for(int i=1;i<m;i++){
    t=new struct node;
    t->data=b[i];
    t->next=nullptr;
    last->next=t;
    last=t;
}
}

void display(struct node *p){
while(p!=nullptr){
    cout<<p->data<<" ";
    p=p->next;
}cout<<endl;
}
/**< FIND THE TOTAL NUMBER OF ELEMENTS */
int countin(struct node *p){
    int num=0;
while(p!=0){
    num++;
    p=p->next;
}return num;
}
int rcountin(struct node *p){
if(p){
    return rcountin(p->next)+1;
}else{
return 0;
}
}
/**< FINDING SUM OF ELEMENTS */
int sum(struct node *p){
int sum=0;
while(p){
    sum=sum+p->data;
    p=p->next;
}
return sum;
      }
int rsum(struct node *p){
//int sum=0;
if(p){
    return sum(p->next)+p->data ;
}else{
return 0;
}

}
/**< FINDING THE MAXIMUM IN THE LIST */
int maxi(struct node *p){
int num=INT32_MIN;
while(p){
    if(num<p->data){
        num=p->data;

    }p=p->next;
}return num;
}
int rmaxi(struct node *p){
int x=0;
if(p==0)
    return INT32_MIN;
    x=rmaxi(p->next);
    return x>p->data?x:p->data;
}
/**< LINEAR SEARCH */
struct node* Lsearch(struct node *p, int key){
while(p){
    if(key==p->data){
        return p;
    }
    p=p->next;
}return 0;
}
struct node* Rlsearch(struct node *p, int key){
if(p==0){
    return nullptr;
}if(key==p->data){
return p;
}return Rlsearch(p->next,key);

}
/**< IMPROVING LINEAR SEARCH */
struct node* search(struct node* p,int key){
    node *q=nullptr;
while(p!=0){
    if(key==p->data){
        q->next=p->next;
        p->next=first;
        first=p;
        return p;
    }
    q=p;
    p=p->next;
}return nullptr;
}
/**< INSERTING IN THE LINKED LIST */
void insertion(int x,int pos){
node *t,*p;

if(pos==0){
    t=new node;
    t->data=x;
    t->next=first;
    first=t;
}else if(pos>0){
    p=first;
    t=new node;
    t->data=x;
    for(int i=0;i<pos-1;i++){
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
}
}
/**< INSERTING FROM END */
void insertlast(int x){
node *t,*last;
t=new node;
t->data=x;
t->next=nullptr;
if(first=nullptr){
    first=last=t;
}else{
   last->next=t;
   last=t;
}
}
/**< INSERTION IN SORTED LIST */
void sortInsert(int x){
node *p,*q,*t;
p=first;
q=nullptr;
t=new node;
t->data=x;
t->next=nullptr;
if(first==nullptr){
    first=nullptr;
}
while(p && p->data<x){
    q=p;
    p=p->next;
}
if(p==first){
    t->next=first;
    first=t;
}else{
t->next=q->next;
q->next=t;
}
}
/**< DELETION OF AN ELEMENT */
int deletion(int pos){
    int x;
node *p=first;
node *q=nullptr;
if(pos==1){


    p=first;
    first=first->next;
    x=first->data;
    delete p;
}else{
for(int i=0;i<pos-1;i++){
    q=p;
    p=p->next;
}
q->next=p->next;
x=p->data;
delete p;
 }return x;
}
/**< TO CHECK SORTED OR NOT */
bool ToCheckSorted(struct node *p){
p=first;
int x=-32768;
while(p){
    if(p->data<x){
        return false;
    }
    x=p->data;
    p=p->next;
}return true;
}
/**< REMOVING DUPLICATE  */
void duplicate(struct node *q){
    node *p;
 q=first;
 p=first->next;
 while(p){
 if(q->data!=p->data){
    q=p;
    p=p->next;
 }else if(q->data==p->data){
 q->next=p->next;
// x=p->data;
 delete p;
 p=q->next;
 }
}
}
/**< SORTING LINKED LIST */
void sort(struct node *p){
    p=first;
    node *q=nullptr;
    while(p){
        q=p->next;
        while(q){
            if(p->data>q->data){
                int temp=p->data;
                p->data=q->data;
                q->data=temp;
            }q=q->next;
        }p=p->next;
    }
}
/**< CONCATATING OF LINKED LIST */
void concatating(struct node *p,struct node *q){
third=q;
while(p){
    p=p->next;

}p->next=q;
}
/**< TO MERGE LINKED LIST */
void merge(struct node *p,struct node *q ){
node *last;
if(p->data<q->data){
    third=last=p;
    p=p->next;
    third->next=nullptr;
}else{
third=last=q;
q=q->next;
third->next=nullptr;
 }
}
/**< TO CHECK A LIKED LIST FOR LOOP */
int isLoop(struct node *f){
node *p;
node *q;
p=q=first;
do {

p=p->next;
q=q->next;
if(q!=nullptr){
    q=q->next;

}else{
q=nullptr;
}
}while(p&&q && p!=q);
if(p==q){
    return 1;
}else{
return 0;}
return 0;
}
/**< TO DISPLAY THE LOOP FUNCTION */
// void loopDisplay(struct node *p){
// int flag=0;
// if( p!=first || flag =0){
//         flag=1;
//     cout<<p->data<<endl;
//     loopDisplay(p->next);
// }flag=0;
// }
/**< DISPLAY THE CIRCULAR LINKED LIST */
void cirDisplay(struct node *p){
do{
    cout<<p->next<<" ";
    p=p->next;
}while(p!=first);
}
int main(){

    struct node *temp;
    struct node *t1,*t2;
    int n,m;
    int x,pos;
//    int key1,key2;
//    cin>>key1>>key2;
    cout<<"Input the length of list1"<<endl;
    cin>>n;
    int a[n];
    cout<<"input the elements of list1"<<endl;
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
//    cout<<"Input the length of list2"<<endl;
//    cin>>m;
//    int b[m];
//    cout<<"input the elements of list2"<<endl;
//    for(i=0;i<m;i++){
//        cin>>b[i];
//    }
//    cout<<"Input the data of inserting node"<<endl;
//    cin>>x;
//    cout<<"input the position of inserting node"<<endl;
//    cin>>pos;

   create(a,n);
//   create2(b,m);
//   display(first);
/**< code for check loop */
//   for(int i=0;i<n-2;i++){
//    t1=first->next;
//   }for(int i=0;i<n;i++){
//   t2=first->next;
//   }t2->next=t1;
//   display(second);
//   cout<<rcountin(first)<<endl;
//   cout<<rsum(first)<<endl;
//   cout<<rmaxi(first)<<endl;
//   temp=search(first,key1);
//   temp=search(first,key2);
//   if(temp){
//    cout<<"key "<<temp->data<<" is found"<<endl;
//   }else{
//   cout<<"key is not found"<<endl;
//   }
//   display(first);
//    insertion(x,pos);
//insertion(10,0);
//insertion(20,1);
//insertion(30,3);
//sortInsert(66);
//cout<<"the deleted element is"<<deletion(1)<<endl;
//if(ToCheckSorted(first)==true){
//    cout<<"The list is sorted"<<endl;
//}else{
//  cout<<"List is not sorted"<<endl;
//}
//    sort(first);
//concatating(first,second);
//if(isLoop(first)==1){
//    cout<<"linked list is looped:"<<endl;
//}else{cout<<"linked list is not looped"<<endl;}
//    display(first);
cirDisplay(first);

    return 0;
}
