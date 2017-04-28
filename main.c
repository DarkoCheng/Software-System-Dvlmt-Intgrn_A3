/*

main file for A2 cis 2750
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listio.h"

int main(int argc, char *argv[])
{
    char * string;
    int i;
    struct returnStruct * rempReturn;
    FILE * fp;
    char * temp;
    char * filename;
    filename = malloc(sizeof(char)*10240);
    temp = malloc(sizeof(char)*102400000);

    if (argc > 2)
    {
        printf("Too many arguments supplied.\n");
        return 0;
    }
    else if (argc < 2)
    {
        printf("Too many arguments supplied.\n");
        return 0;
    }
    strcpy(filename, argv[1]);
    strcat(filename, ".html");
    fp = fopen(filename, "r");
    if (fp != NULL)
    {
        while(fgets(temp, 9999, fp) != NULL)
        {
            printf("%s", temp);
        }
        printf("\n");
        fclose(fp);
    }
    else
    {
        memset(filename, 0, 10240);
        strcpy(filename, argv[1]);
        fp = fopen(filename, "r");
        if (fp != NULL)
        {
            rempReturn = buildHeader();
            i = setName(rempReturn->header, argv[1]);
            while(fgets(temp, 99999, fp)!=NULL)
            {
                i = addString(rempReturn->header, temp);
            }
            i=processStrings(rempReturn->header);
            //i=printString(rempReturn->header);
            i=freeStructure(rempReturn->header);
            free(rempReturn);
            fclose(fp);
        }
    }
    free(temp);
    free(filename);
    return 0;
}
