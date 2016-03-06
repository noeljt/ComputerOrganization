#include <stdio.h>
#include <stdlib.h>

/* Struct for each node in the linked list. */
struct node
{
   int value;
   struct node *next;
};

/* prototypes for the functions used */
void printList(struct node*);
void insertNode(struct node**, struct node**, int);
int deleteNode(struct node**, int);

/* function main begins program execution */
int main(void)
{
   /* Pointers to the first and last nodes of list are used */
   /* to facilitate insertion at the end of list */
   struct node *head, *tail;
   int i; /* To hold input value */
   int result; /* To hold result from search/delete functions */
   head = tail = NULL; /* List is initially empty. */
   printf("Enter integers into a list.\n");
   printf("Enter a value < 0 in order to stop adding to the list\n");
   printf("Enter first list value = "); /* Prompt the user for input. */
   scanf("%d", &i);
   while (i > 0)
   {
      /* Input value is positive. Insert a new node with value */
      /* of i at the end of the list. The insert_node function */
      /* may modify the values of head and tail. */
      insertNode(&head, &tail, i);
      printf("Next value = ");
      scanf("%d", &i); /* Read next value */
   }
   /* end of input - show the list */
   printList(head);
    
   printf("Enter a value to delete = "); /* Prompt the user for input. */
   scanf("%d", &i);

   result = deleteNode( &head, i );
   if( result == 1 )
   {
      printf("The item, %d, was successfully delete from the list\n",i);
      printList(head);
   }
   else
   {
      printf("Unable to delete item, %d, from the list\n",i);
   }
    
   return 0;
} /* end of main */


void insertNode (struct node **h, struct node **t, int v)
{
   /* Creates a new node with value given by parameter v */
   /* and inserts that node at the end of the list whose */
   /* first and last nodes are pointed to by *h and *t */
   /* respectively. */
   struct node *temp;
   if ((temp = (struct node *)malloc(sizeof(struct node))) == NULL)
   {
      printf("Error: Node allocation failed\n");
      exit(1); /* Stop program */
   }
   /* Space for node obtained. Copy the value v into the node */
   /* and insert the node at the end of the list. */
   temp->value = v;
   temp->next = NULL;
   if (*h == NULL) {
      /* List is currently empty. */
      *h = *t = temp;
   }
   else
   {
      /* The list is not empty. Use *t to add the node */
      /* at the end. */
      (*t)->next = temp; *t = (*t)->next;
   }
} /* end of insertNode */

void printList(struct node *h)
{
   /* Prints the values stored in the nodes of the list */
   /* pointed to by h. */
   if (h == NULL)
   {
      printf("The list is empty\n");
   }
   else
   {
      printf("Values in the list are:\n");
      while (h != NULL)
      {
         printf("%d\n", h->value);
         h = h->next;
      }
   }

} /* end of printList */

int deleteNode(struct node **h, int x)
{
   /* Deletes the the first node which contains the value x      */
   /* If there is no match, the function returns 0, 1 otherwise  */

   
   /* Deletes the the first node which contains the value given by */
   /* If there is no match, the function returns 0, 1 otherwise    */
   struct node *prev; /* pointer to previous node */
   struct node *curr; /* pointer to current node */
   struct node *temp; /* temporary node pointer */
   
   /* handle case of empty list */
   if (*h == NULL)
   {
      printf("The list is empty\n");
      return 0;
   }
   
   /* handle special case of deleting the first node */
   if( (*h)->value == x )
   {
      temp = (*h)->next;
      free(*h);
      *h = temp;
      return 1;
   }
   else
   {
      prev = *h;
      curr = (*h)->next;
      while (curr->value != x) { //find node with correct value
         if (curr->next == NULL) { //couldn't find value
            return 0;
         }
         prev = curr;
         curr = curr->next;
      }
      if (curr->next == NULL) { //handle case of last node
         free(curr);
         prev->next = NULL;
      }
      else {
         prev->next = curr->next;
         free(curr);
      }
      return 1;
   }

   /* default case - match not found */
   return 0;


} /* end of deleteNode */



