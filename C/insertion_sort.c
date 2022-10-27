#include<stdio.h>

int main(){
    int size,arr[100];
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    printf("Enter the array elements separated with space: ");
    for(int i=0; i<size; ++i){
        scanf("%d",&arr[i]);
    }
    for(int i=1; i<size; ++i){
        int j = i - 1;
        int flag = arr[i];
        while(j >= 0 && arr[j] > flag){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = flag;
    }
    printf("Sorted array: ");
    for(int i=0; i<size; ++i){
        printf("%d ",arr[i]);
    }
    return 0;
}
