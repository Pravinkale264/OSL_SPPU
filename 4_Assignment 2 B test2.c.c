/*
   Assignment No.:2 B
   Name: Gaurav Tilak Marathe
   Roll No.:35046
   Title:Process Control System Call
   Problem Statement: Implement the C program in which main program accepts an array. Main program uses the FORK system call to create a new process called a child process. Parent process sorts an array . The child process uses EXECVE system call to load new program which display array in reverse order.
*/






#include<stdio.h>
#include<stdlib.h>

void reverse(int a[20],int start,int end)
 {
 	while(start<end)
 	{
 		
 	 	int temp = a[start];
 	 	a[start]=a[end];
 	 	a[end]=temp;
 		start++;
 		end--;
 	}
 }

int main(int argc, char *argv[])
{
 int a[20],i,n;
 int num;
 
 
 for(i=1;i<6;i++)
 {
 	a[i]=atoi(argv[i]);
 	
 	printf("a[%d] =%d \n",i,a[i]);
 	
 }
 	printf("Reversing Elements \n");
 	reverse(a,1,5);
 	
 	for(i=1;i<6;i++)
 	{
 		printf("a[%d] =%d \n",i,a[i]);
 	}
 
 

 
 exit(EXIT_SUCCESS);
}

//test2.c
//Displaying test2


