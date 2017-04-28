/*

Assignment 2 for cis 2750.
*/
#ifndef _FUNCTION_HEADER_
#define _FUNCTION_HEADER_

#define FAILURE 0
#define SUCCESS 1

struct returnStruct {
    int value;
    struct dataHeader *header;
};

struct dataHeader {
    char *name;
    int length;
    struct dataString *next;
};

struct dataString{
    char *string;
    struct dataString *next;
};

/*
In: none.
Out: the empty struct.
Function: init the dataHeader struct.
*/
struct returnStruct *buildHeader();

/*
In: struct and char*.
Out: none.
Function: set the name in the dataHeader.
*/
int setName(struct dataHeader *header, char *name);

/*
In: struct dataHeader.
Out: char*
Function: return the name in the dataHeader
*/
char * getName(struct dataHeader *header);

/*
In: struct dataHeader
Out: int
Function: return the length in the dataHeader
*/
int getLength(struct dataHeader *header);

/*
In: struct dataHeader and str string.
Out: none
Function: add string to the list in order
*/
int addString(struct dataHeader *header, char *str);

/*
In: struct header
Out: none
Function: simply print out the list in order
*/
int printString(struct dataHeader *header);

/*
In: struct dataHeader.
Out: none.
Function: follow the assignemnt to handle all strings that stored in the linked list.
*/
int processStrings(struct dataHeader *header);

/*
In: struct dataHeader.
Out: none.
Function: free all memory that allocated before.
*/
int freeStructure(struct dataHeader *header);

/*
In: string which the file name, and struct dataHeader
Out: none.
Function: write everything to a binary file.
*/
int writeStrings(char *filename, struct dataHeader * header);

/*
In: input file name.
Out: the pointer to the dataHeader struct.
Function: read the binary file and rebuild the linked list.
*/
struct returnStruct *readStrings(char *filename);

#endif
