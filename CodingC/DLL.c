#include<stdio.h>
#include<stdlib.h>

 struct node * create_node();
 void print(struct node * head);
 struct node * add_nodes(struct node * head);
/*
 struct node * add_beg(struct node * head);
 struct node * add_end(struct node * head);
 struct node * add_pos(struct node * head,int n);
*/
 struct node * del_pos(struct node * head,int n);
 struct node * del_end(struct node * head);
 struct node * del_beg(struct node * head);

struct node {
   int data;
   struct node * prv;
   struct node * next;
};

int main(){
  struct node * head=NULL;
  int i,n,a;
  printf("How many nodes r u going to enter: ");
  scanf("%d",&n);

  for(i=0;i<n;i++){
   head=add_nodes(head);

  }
 printf("Where do u want to delete....beg(1),end(2),pos(3): ");
 scanf("%d",&a);
  if(a==1)
   head=del_beg(head);
  else if (a==2)
   head=del_end(head);
  else if (a==3)
   head=del_pos(head,n);
  else
   printf("Invalid option");

/*
 printf("Where do u want to enter....beg(1),end(2),pos(3): ");
 scanf("%d",&a);
  if(a==1)
   head=add_beg(head);
  else if(a==2)
   head=add_end(head);
  else if(a==3)
   head=add_pos(head,n);
  else
   printf("Enter a valid option ");

*/
  printf("List is: ");
  print(head);

return 0;

}

struct node * create_node(){
  struct node * nn=(struct node *)malloc(sizeof(struct node));
  int data;
  printf("Enter data: ");
  scanf("%d",&data);
  nn->data=data;
  nn->next=NULL;
  nn->prv=NULL;
  return nn;
}

struct node * add_nodes(struct node * head){
  struct node * nn=create_node();
  struct node * ptr=head;
 if(head==NULL)
   head=nn;
 else{
   while(ptr->next!=NULL){
     ptr=ptr->next;
   }
  ptr->next=nn;
  nn->prv=nn;
  }

 return head;
}
/*

struct node * add_beg(struct node * head){
   struct node * nn=create_node();
   nn->prv=NULL;
   nn->next=head;
   head->prv=nn;
   head=nn;

  return head;
}

struct node * add_end(struct node * head){
  struct node * nn=create_node();
  struct node * ptr=head;
  while(ptr->next!=NULL){
    ptr=ptr->next;
  }
  ptr->next=nn;
  nn->prv=ptr;

return head;
}

struct node * add_pos(struct node * head,int n){
  struct node * nn=create_node();
  struct node * ptr=head;
  int pos,i=1;
  printf("Enter posution <=%d: ",n);
  scanf("%d",&pos);
  while(i<pos-1){
   ptr=ptr->next;
   i++;
  }
  nn->next=ptr->next;
  nn->prv=ptr;
  ptr->next->prv=nn;
  ptr->next=nn;

return head;
}

*/
void print(struct node * head){
  struct node * ptr= head;
  while(ptr!=NULL){
   printf("%d->",ptr->data);
   ptr=ptr->next;
  }
  printf("NULL");

}

struct node * del_beg(struct node * head){
  struct node * ptr=head;
  head = head->next;
  head->prv=NULL;
  free (ptr);

return head;
}

struct node * del_end(struct node * head){
  struct node * preptr,* ptr =  head;
 if(head==NULL)
     return NULL;
 else if(head->next==NULL){
    free(head);
    return NULL;
 }
 else{
  while (ptr->next!=NULL){
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=NULL;
  free(ptr);
return head;
 }

}

struct node * del_pos(struct node * head, int n){
  struct node *preptr, * ptr =head;
  int pos,i=1;
  printf("Enter position <=%d: ",n);
  scanf("%d",&pos);
 if(pos==1){
     free(ptr);
     return NULL;
 }
 else if(pos==2){
   ptr=ptr->next;
   head->next=ptr->next;
   ptr->next->prv=head;
   free(ptr);
  return head;
}
else{
  while(i<pos-1){
  ptr=ptr->next;
  i++;
  }
 preptr=ptr->prv;
 preptr->next=ptr->next;
 ptr->next->prv=preptr;
 free(ptr);
 }
  return head;


}
