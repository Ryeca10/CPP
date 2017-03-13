//Lab 11.1

#include <stdio.h>
#include <String.h>
#define NAME_MAX 20
#define ADD_MAX 30
#define PEOPLE 5

//function protypes
void collectInfo(char stringName[][20], char stringAddress[][30], int zipArray[10], int yearsArray[10], size_t nameMax, size_t addMax, size_t ppl);
void displayInfo(char stringName[][20], char stringAddress[][30], int zipArray[10], int yearsArray[10], size_t nameMax, size_t addMax, size_t ppl);

//Function main.
int main(void)
{
    char name[PEOPLE][NAME_MAX] = {{0}, {'\0'}};
    char address[PEOPLE][ADD_MAX] = {{0}, {'\0'}};
    int zipCodeArray[PEOPLE][NAME_MAX] = {{0},{0}};
    int ageArray[PEOPLE][NAME_MAX] = {{0}, {0}};
    
    collectInfo(name, address, zipCodeArray, ageArray, NAME_MAX, ADD_MAX, PEOPLE);  //calling function.

    displayInfo(name, address, zipCodeArray, ageArray, NAME_MAX, ADD_MAX, PEOPLE);  //calling function.
    
    
    return 0;
}

//Function to collect all information.
void collectInfo(char stringName[][20], char stringAddress[][30], int zipArray[], int yearsArray[], size_t nameMax, size_t addMax, size_t ppl)
{
    int i = 0;
    
    for(i = 0; i < 4; i++)
    {   
        printf("\nEnter name %d: ", i+1);
        fgets(stringName[i], nameMax, stdin);      //to write user input into stringName[i]
        printf("Enter address %d: ", i+1);
        fgets(stringAddress[i], addMax, stdin);    //to write user input into stringAddress[i]
        
        printf("Enter zipcode %d: ", i+1);      //here I'm having difficulty writing the user input int the zipArray, it prints out an address or error code.
        scanf("%d", &zipArray[i]);
        printf("Enter age of person %d: ", i+1);
        scanf("%d", &yearsArray[i]);
        
        //printf("%s%20s%20d%20d\n", stringName[i], stringAddress[i], zipArray[i], yearsArray[i]);  //A printf statement to test if the input is being stored correctly.
        fflush(stdin);
        
    }
}

//Function to display all information.
void displayInfo(char stringName[][20], char stringAddress[][30], int zipArray[], int yearsArray[], size_t nameMax, size_t addMax, size_t ppl)
{
    char tempArray;
    
    int i;
    printf("\n%s %20s %20s %20s\n", "Name", "Address", "Zipcode", "Age\n");
    
    for (i=0 ;  i < 4 ; i++)
        printf("%s%20s%20d%20d\n", stringName[i], stringAddress[i], zipArray[i], yearsArray[i]); 
 
}

/*
 Write a program to collect the following information for 5 people:
 - name (maximum length is 20 characters)
 - address (maximum length is 30 characters)
 - zip code
 - age
 
 - main() – defines variables
 call function #1 to collect all information (before displaying it)
 call function #2 to display information
 
 - function #1 – prompt and get the following information from the user
 for all 5 people
 - function #2 – display information formattted as a table without using tabs
 
 example:

 Name                 Address                             Zipcode      Age
 Bugs Bunny       123 Carrot Lane                   92618        10
 
 Challenge work:
 Sort the output by the name.
 */

/*
 A few hints for those who are still wrestling with it:
 - You need to use arrays, and a couple of them need to be multi-dimensional
 - Remember a name is a string, a string is an array of chars, and you need to
 keep track of 5 of them before you display them
 - Same goes for the addresses
*/