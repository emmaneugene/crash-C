#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

/* a set of routines to illustrate insertion into, and deletion from, a linked
list using `traditional' single-level pointer techniques. The routines for 
deleting a list element, and for inserting at the front of a list are 
adapted from Kernighan and Pike's "The Practice of Programming"  pp.46 et 
seq. (Addison-Wesley 1999). The elements of the list are of type THING 
where each THING is a structure in which the `item' field holds a 
string and the `next' field holds a pointer to the next THING on the list. 

The techniques for adding a THING before the start of a list, or after the 
end of a list, are two special cases that are straightforward enough. 
However if the list elements are to be kept ordered alphabetically (say)  
the insertion of a new element needs great care to ensure that the 
NULL end-of-list marker does not get dereferenced.  

In summary the routines should be robust against:

 1) inserting/deleting to/from an empty list
 2) inserting/deleting to/from a single-element list
 3) inserting/deleting at the end of a list
 4) inserting/deleting at the front of a list - with updating of the 
    pointer to the  list head
 
The general routine `addmiddle', supplied below, is general purpose but 
it calls on 'addfront' and 'addend' in specific special cases. Note 
carefully that it does allow for duplicate list elements. 
Exercise: modify `addmiddle so that this duplication is NOT allowed.
 */


typedef struct _thing 
{ 
	char *item;
	struct _thing *next;
} THING;

THING *start = NULL;

// create new list element of type THING from the supplied text string
THING *newelement(char *text)
{
	THING *newp;
	newp = (THING *) malloc (sizeof(THING));
	newp->item = (char *)malloc(strlen(text) + 1);
        strcpy(newp->item, text);
        newp -> next = NULL;
	return newp;
}

// delelement: remove from list the first instance of an element 
// containing a given text string
// NOTE!! delete requests for elements not in the list are silently ignored 
THING *delelement(THING *head, char *text)
{
	THING *p, *prev;
	prev = NULL;
	for (p = head; p != NULL; p = p -> next) {
            if (strcmp(text, p -> item) == 0) {
		if(prev == NULL)
		   head = p-> next;
		else
		   prev -> next = p -> next;
		free(p -> item); //free off the the string field
		free(p);	// remove rest of THING
		return head;
	   }
	   prev = p;	
	}
}

/* addfront: add new THING to front of list  */
/* example usage: start = (addfront(start, newelement("burgers")); */

THING *addfront(THING *head, THING *newp)
{
	newp -> next = head;
	return newp;
}

/* addend: add new THING to the end of a list  */
/* usage example: start = (addend(start, newelement("wine")); */

THING *addend (THING *head, THING *newp)
{
	THING *p2; 	
	if (head == NULL)
		return newp;
// now find the end of list
	for (p2 = head; p2 -> next != NULL; p2 = p2 -> next)
		;
	p2 -> next = newp;
	return head;
}

// add element into middle of a list of THINGs based on alphabetical order 
// of the `item' strings within the THING structures 
THING *addmiddle (THING *head, THING *newp)
{
	BOOL found = FALSE;
	THING *p1, *p2; 	
	if (head == NULL) { //special case
//		printf("initial list was NULL\n");
		head = addfront(head, newp);
		return head;
	}
// Main loop. Use p2 to remember previous p1
	p2 = p1 = head ; 
	while (!found) {
  		if (found = strcmp(p1 -> item, newp -> item) >= 1) {
			if (p1 == head) { 
//					printf("adding at head\n");
					head = addfront(head, newp); 
					return head;
		        }
			else { //general case - insert the item
//        		        printf("General case entered\n");
				p2 -> next = newp;;
				newp -> next = p1;
				return head;
	  		}
	  	}
// match not found before end of list so insert at end 
	if  (p1 -> next == NULL) {
		head = addend(head, newp); 
		return head;
	}
// go round while loop one more time
	p2 = p1; p1 = p1 -> next; 
	
	}// end of while 
	
}



void printlist(THING **head)
// this routine uses pointer-to-pointer techniques :-)
{
	THING **tracer = head;
	while ((*tracer) != NULL) {
		printf("%s \n",(*tracer)->item);
		tracer = &(*tracer)->next;
	}
}


int main(int argc, char **argv)
{
	start = addmiddle(start, newelement("chips")); 
	start = addmiddle(start, newelement("wine")); 
	start = addmiddle(start, newelement("beer")); 
	start = addmiddle(start, newelement("pizza")); 
	start = addmiddle(start, newelement("zucchini"));
	start = addmiddle(start, newelement("burgers"));
	start = addmiddle(start, newelement("burgers"));
	start = addmiddle(start, newelement("slaw"));
	printf("\nINITIAL LIST\n");
	printlist (&start);
	delelement(start, "pizza");
	delelement(start, "zucchini");
	delelement(start, "burgers");
	printf("\nALTERED LIST\n");
	printlist(&start);
	
}
