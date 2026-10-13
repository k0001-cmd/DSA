void insertposition(int data,int position)
{
  if(position<1)
{
printf("Kyahsh");
return;
}
if(position == 1)
{
insertBeginning(data);
return;
}
struct node * current=head;
for(i=1;i<position-1 && current !=NULL;i++)
{
current=current->next;
}
if(current==Null)
{
printf("Invalid position");
return;
}
struct Node *newNode=malloc(sizeof(struct Node));
if(newnODE==nULL)
{
PRINTF("MEMORY ALLOCATION FAILED");
return;
}
newNode->data=data;
newNode->next=current->next;
current->next=newNode;
}
