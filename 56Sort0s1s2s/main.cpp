
#include <stdio.h>


void sort012(int a[], int n)
{
   int i=0;int j;
   int temp[n];
   for(j=0;j<n;j++)
   {
       if(a[j]==0)
       {
           temp[i]=0;
           i++;
       }
   }
     for(j=0;j<n;j++)
   {
       if(a[j]==1)
       {
           temp[i]=1;
           i++;
       }
   }
     for(j=0;j<n;j++)
   {
       if(a[j]==2)
       {
           temp[i]=2;
           i++;
       }
   }
   for(int k=0;k<n;k++)
   {
       a[k]=temp[k];
   }

}

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
