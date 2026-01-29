#include<stdio.h>
void main() {
    int a[100],n,i,z,j,x;
    printf("Enter a no:  ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(z=0; z<n; z++)
        scanf("%d",&a[z]);
    printf("Enter a key element: ");
    scanf("%d",&x);
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(x==a[i]+a[j])
                printf("elements are %d,%d",i,j);

        }
    }
}