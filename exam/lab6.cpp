#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
//# define count0
struct Node {
    int data;
    struct Node* next;
}*head=NULL,*temp,*newNode;
 int count=0,i,pos;
//1. createList
	
void createList(int value) {
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data = value;
     newNode->next = NULL;

	if (head == NULL)
	{
	head = newNode;
	count++;
	}
	else
	{
	// If not empty, traverse to the end and append the new node
	temp = head;
	while(temp->next)
	 {
	    temp = temp->next;
	}
	temp->next = newNode;
	 count++;
    }

    // Print a message indicating that a node has been inserted
    printf("Node with value %d inserted.\n", value);

}
//2. Insert front 

void Insert_Front(int value) {
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data = value;
     newNode->next = NULL;

	if (head == NULL)
	{
	head = newNode;
	count++;
	}
	else
	{
	newNode->next = head;
	head=newNode;
	count++;
    }

    // Print a message indicating that a node has been inserted
    printf("Node with value %d inserted.\n", value);

}
//3. Insert end
	
void Insert_End(int value) {
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data = value;
     newNode->next = NULL;

	if (head == NULL)
{
	head = newNode;
	count++;
	}
	else
	{
	temp = head;
	while(temp->next)
	 {
	    temp = temp->next;
	}
	temp->next = newNode;
	count++;
    }

    // Print a message indicating that a node has been inserted
    printf("Node with value %d inserted.\n", value);

}
//4. Insert at a position 
	
// Function to add a node at a given position
void Insert_Position(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->data = data;
     newNode->next = NULL;
     if(head==NULL)
     {
     printf("List empty");
     }
    if (position == 1) {
//	newNode->next = head->next;
  //	head->next = newNode;
	  newNode->next = head;
	head=newNode;

	count++;
	return;
    }

    temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
	temp = temp->next;
    }

    if (temp == NULL) {
	printf("Position out of bounds.\n");
	return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    count++;
}
//5. Delete a node from front

void delete_front() {
    // Check if the list is empty
    if (head == NULL) {
	// If empty, print an error message
	printf("List is empty. Cannot delete.\n");
	return;
    }
 else
if(head->next==NULL)
{
printf("Deleted data is %d",head->data);
head=NULL;
count--;
}
else
 {
temp=head;

    head=head->next;
temp=NULL;
count--;
	return;
    }
  }

//6. Delete a node from end\n");


// Function to delete a node with a given value from the linked list
void delete_end() {
    // Check if the list is empty
    if (head == NULL) {
	// If empty, print an error message
	printf("List is empty. Cannot delete.\n");
	return;
    }
 else
if(head->next==NULL)
{
printf("Deleted data is %d",head->data);
head=NULL;
count--;
}
else
 {
temp=head;

    // Traverse the list to find the node with the specified value
    while (temp->next->next!= NULL)
     temp = temp->next;

      printf("Dleted node is %d",temp->next->data);
      temp->next=NULL;
      count--;
	return;
    }
  }

//7. Delete a node from a given position
//8. Display the list

// Function to display the linked list
void displayList() {
  if(head==NULL)
  {
    printf("\nLinked list is empty\n");
  }
    // Print the values in the linked list

//    struct Node *temp;
else
{
  printf("Linked List: ");
temp=head;
    while(temp!=NULL) {

	printf("%d->", temp->data);
	temp = temp->next;
    }
    // Print a newline at the end of the list
    printf("NULL");
}


}

//9. search\t
int search(int key)
{
int flag=0;
if(head==NULL)
printf("\nlist empty ,no nodes to search\n");
else
{
temp=head;
while(temp!=NULL)
{
if(key==temp->data)

{
flag=1;break;}
else
temp=temp->next;
}
}
return flag;
}
//11. concatenate\n

int main() {
    // Initialize the head of the linked list to NULL
//    struct Node* head = NULL;
    int choice, value,f=0,key;
clrscr();
    // Menu-driven program using a do-while loop
    do {
	// Print the menu options
	printf("\nMenu:\n");
	printf("1. createList \t");
	printf("2. Insert end \t");
	printf("3. Insert front \t");
	printf("4. Insert position \n");
	printf("5. Delete a node from front\t");
	printf("6. Delete a node from end\n");
	printf("7. Delete a node from a given position\n");
	printf("8. Display the list\t");
	printf("9. search\t");
	  printf("10. count\t");
	  printf("11. concatenate\n");
	  printf("12. exit\n");
	printf("Enter your choice: ");
	// Read the user's choice
	scanf("%d", &choice);

	// Switch statement to perform the selected operation
	switch (choice) {
	    case 1:
		// Insert a node - prompt user for value and call insertNode function
		printf("Enter the value to insert: ");
		scanf("%d", &value);
		createList(value);
		break;
	    case 2:printf("Enter the value to insert: ");
		scanf("%d", &value);
		Insert_End(value);
		break;
	    case 3:
		printf("Enter the value to insert: ");
		scanf("%d", &value);
		Insert_Front(value);
		break;

	    case 4:
		printf("Enter the value to insert: ");
		scanf("%d", &value);
printf("Enter the position\n");
scanf("%d",&pos);
		Insert_Position(value,pos);
		break;
		case 5:delete_front();break;

		case 6:delete_end();break;

	      //	case 7:delete_position();break;

		case 8:displayList();break;
		case 9:printf("\nEnter the value to search\n");
		scanf("%d",&key);
		f=search(key);
		if(f==1)
		printf("key found");
		else
		printf("Not found");
		break;
		case 10:printf("\n Number of nodes in the list is %d",count);break;
	       //	case 11:concatenate;break;
	    case 12:
		// Exit the program
		printf("Exiting the program.\n");
		break;

	    default:
		// Invalid choice - prompt user to try again
		printf("Invalid choice. Try again.\n");
	}

    } while (choice != 12);

    // Clean up the remaining nodes in the linked list
    getch();
     return 0;
    }



