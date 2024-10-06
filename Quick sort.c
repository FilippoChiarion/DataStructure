#include <stdio.h>
#include <stdlib.h>

int partition(int *arr,int start,int end){
    int pivot=(arr[start]+arr[end]+arr[(start+end)/2])/3;
    while(start<end){
        while(start<end && arr[start]<=pivot)
            start++;
        while(start<end && arr[end]>pivot)
            end--;
        if(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    return start;
}

void quickSort(int *arr,int start,int end){
    if(start<end){
        int pos=partition(arr,start,end);
        quickSort(arr,start,pos-1);
        quickSort(arr,pos,end);
    }
}

void printArray(int *arr,int size){
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int size,i;
    printf("How many numbers do you want to sort: ");
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++){
        printf("Value %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nOriginal array: ");
    printArray(arr,size);

    quickSort(arr,0,size-1);

    printf("\nSorted array: ");
    printArray(arr,size);

    return 0;
}
