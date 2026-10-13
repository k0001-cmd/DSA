void deletePosition(int position)
{
IF(POSITION < 1 || HEAD==null)
{
printf("Not found");
return;
}
if(positio==1)
{

deletebeginning();
return;
}
struct Node * current = head;
for(int  i=1;i<position-1 && current!=Null;i++)
{
current=current->next;
}
if(current==NULL || current->Next==null)
{
printf("Invalid position");
return;
}
Struct Node * temp = current->next;
current->next=temp->next;
free(temp);
}
