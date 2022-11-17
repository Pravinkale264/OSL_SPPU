#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void bubble(int arr[], int n){
    int i, j , k;
    for(int i=0;i<(n-1);i++){
        for(int j=0; j<(n-i-1); j++){
            if(arr[j]>arr[j+1]){
                k = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
            }
        }
    }
}

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);

    }
}

int main(){
    pid_t id;
    int arr[20], n, i;
    printf("\nEnter the length of the array");
    scanf("%d", &n);
    printf("\n Enter the number of elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    id = fork();
    if(id==0){
        //sleep(3);
        printf("\n Sorting in child process ");
        bubble(arr, n);
        display(arr,n);

    }
    else{
        sleep(3);
        printf("\n Sorting in parent process ");
        bubble(arr, n);
        display(arr,n);
    }

    return 0;
}