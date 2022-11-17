
/*
   Assignment No.:2 B
   Name: Gaurav Tilak Marathe
   Roll No.:35046
   Title:Process Control System Call
   Problem Statement: Implement the C program in which main program accepts an array. Main program uses the FORK system call to create a new process called a child process. Parent process sorts an array . The child process uses EXECVE system call to load new program which display array in reverse order.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
//#define MAX 50


void main(int argc, char *argv[])
{
  int a[20],n,i;
 // char *c_array[20];
  pid_t pid;
  int status;
  char *ch[20];
  char *newenviron[]={NULL};
  char *newargv[20];


  printf("Enter 5 element: ");
  for(int i=0;i<5;i++)
  {
  	scanf("%d",&a[i]);
  }
  	
  	    
	for(int i=0;i<5;i++)
  	{
  		char c1[sizeof(int)];
        	snprintf(c1,sizeof(int),"%d",a[i]); //copy those 4bytes
        
        
		ch[i] = malloc(sizeof(c1)); 
		strcpy(ch[i], c1); // copy to the array of results
		
		printf("a[%d] =%s\n",i,ch[i]);
	
	}
//for(int i=0;i<5;i++)
 // {
  
//}
  newargv[0] = argv[1];
  
  for(i=0;i<5;i++)
  {
  	newargv[i+1] = ch[i];
  }	 
  newargv[7]=NULL;
  
  pid=fork();
  
   if(pid==-1)
    printf("Error on fork\n");
 
	 if(pid==0)
	 {
       //child process	   
           execve(argv[1], newargv, newenviron);
	    printf("execve is successfully executed");
	 }
	else
	 {
	 
	  printf("Parent process\n");
	  wait(&status);
	  }
 
}

//test1.c
//Displaying test1.c.


