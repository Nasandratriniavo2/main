#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presence.h"

void openFile(FILE** file) //Open the file
{
    *file=fopen("l1.csv","r+");
   
    if(file==NULL)
    {
        printf("Error->Open the file\n");
        exit(1);
    }
} 

int studentNumber(FILE* file) //Count number of the students in the file
{
    int count;
    char line[100];
    while(fgets(line,100,file)!=NULL)
        count++;
    rewind(file);
    return(count);
}

data* allocation(int studentsNumbers) //
{
    data* students=NULL;
    students=(data*)malloc(studentsNumbers*sizeof(data));
    return(students);
}


void getData(FILE* file, data students[])
{
    int number,i=0,j=0,name,surname, n;
    char num[4]; 
    char** splitted;
    char line[100];
    char date[100];
    printf("Enter the date:\nPS:The format is like:MM-DD-YYYY:");
    fgets(date,100,stdin);
    while(!feof(file))
    {
        while(!feof(file))
        {
            fgets(line,100,file);
            
            if(occurence(line,':')==3)
            {
                splitted = split(line);
                students[i].number=atoi(splitted[0]);
                students[i].name=splitted[1];
                students[i].surname=splitted[2];            
                students[i].check=splitted[3];
                i++;
            }
            else if(occurence(line,':')==0)
            {
                students[i].date=line;
                    
                if(strcmp(students[i].date,date)==0)
                {
                    splitted=split(line);
                    students[i].check=splitted[3];
                    n = i;
                    break;
                }
                else
                    i++;                 
            }
        }
    } 

    for(j=n;j<n+75;j++)
        printf("%s",students[j].check);
    
    for(int i=1; i<75 ; i++)
        printf("%d %s %s %s\n", students[i].number,students[i].name,students[i].surname,students[i].check);
}   

char** split(char* str)
{
    char** splitted;
    int i,j=0,k=0,size;
    size=occurence(str,':');
    splitted = (char**) malloc((size+1)*sizeof(char*));

    for(int i=0; i<size+1; i++)
        splitted[i] = (char*) malloc(100*sizeof(char));

    for(i=0; i<strlen(str); i++)
    {
        if(str[i] != ':')
           splitted[j][k++] = str[i];

        else
        {
            j++;
            k=0;
        } 
    }      

    return(splitted);    
}

int occurence(char str[], char ch){
    int c=0;

    for(int i=0; i<strlen(str); i++){
        if(str[i] == ch)
            c++;
    }
    return(c);
}

void getDate(data* students)
{
    int i=0;
    
}
