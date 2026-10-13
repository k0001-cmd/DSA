void deleteEnd()
{
          if(head==NULL){
            printf("Not");
            return;
           }

          if(head->next==NULL)
          {
             free(head);
              head=NULL;
              return;
}
struct Node * current = head;
while(current->next->next!=Null)
{
current=current->next;
}
free(current->next);
current->next=Null;




void search(int key)                           //key = 50
{
struct node * current = head;
int position = 1;
while(current!=Null)
{
if(current->data==key)
{
printf("Fpund at %d ",position);
return;
}

current = current->next;
position++;
}
printf("not found");
}

              
