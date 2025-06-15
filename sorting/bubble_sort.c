#include<stdio.h>
int main(){
    int arr[]={3,5,1,0,33,44,22,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++){
        int flag=1;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            flag=0;
        }
        if(flag) break;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}