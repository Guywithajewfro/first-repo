/*
	Edited by Daniel Nunez
	2/8/2024
	Computer Science 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{	//WORKS
	int lengthNode = 0;	//Temp var
	while (head != NULL) {	//Loops while head isn't NULL
		head = head->next;	//Goes to next node
		lengthNode++;	//Increments lengthNode
	}	//Ends while loop
	return lengthNode;	//Returns number of nodes
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{	//Should work
	//Create a empty string, add to string chars from LL, and return string
	if (head == NULL) return NULL;	//If head is NULL, return NULL
	int i = 0;
	node *temp = head;	//Temp node pointer 'temp' assigned to 'head'
	char *tempString = (char*) malloc((length(head) + 1)*sizeof(char));	//Declares a char string pointer 'tempString' and mallocs it to size 'length(head)' + 1 (+1 is for NULL terminator)
	while (head != NULL) {	//Loops while head isn't NULL
		tempString[i++] = head->letter;	//Contents of 'letter' is written to 'tempString' index i
		head = head->next;	//Head goes to next node
	}	//Ends while loop
	tempString[i] = '\0';	//Ends the string
	return tempString;	//Returns tempString
}

// inserts character to the linkedlist
// if the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{	//Should work 
	node *tempPoint = *pHead;	//Declares node pointer 'tempPoint' assigned to node pointer 'pHead'
	if (*pHead == NULL) {	
		*pHead = (node *) malloc(sizeof(node));	//Mallocs 'pHead' to size of node
		(*pHead)->letter = c;
		return;
	}
	while (tempPoint->next != NULL) {	//Recurse down list
		tempPoint = tempPoint->next;	//'tempPoint' goes to next node
	}	//Ends while loop
	tempPoint->next = (node *) malloc(sizeof(node));	//Mallocs 'tempPoint' -> next to size of node
	tempPoint->next->letter = c;	
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{	//WORKS
	node *temp = *pHead;	//Node pointer 'temp' assigned to pointer 'pHead'
	while (temp != NULL) {	//Loops while 'temp' isn't NULL
		*pHead = temp->next;
		free(temp);	//Frees memory for 'temp'
		temp = *pHead;
	}	//Ends while loop
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}