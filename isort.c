#include <stdio.h>

#define LEN 50
#define LINE 256


void shift_element(int* arr, int i){

    int* m=arr+i;
    for(int j=i-1;j>=0;j--)
    {
        *m=*(arr+j);
        m--;
    }
}
insertion_sort(int* arr , int len)
{
    int* pointer=arr;
    int counter;
    int temp;
    for(int i=1;i<len;i++)
    {
        counter=0;
        for(int j=i;j>0;j--)
        {
            if(*(arr+i)<*(arr+j-1))
            {
                pointer=arr+j-1;
                counter++;
            } else
                break;
        }
        temp=*(arr+i);
        shift_element(pointer,counter);
        *(arr+i-counter)=temp;
    }
}
int main()
{
    int arr2[5]={4,3,2,1,0};
    insertion_sort(arr2,4);
    for (int i = 0; i <4 ; ++i) {
        printf("%d",arr2[i]);

    }
    int arr [50];
    int x;
    for(int i=0;i<50;i++)
    {
        scanf("%d",&x);
        *(arr+i)=x;
    }

    insertion_sort(arr,50);
    printf("\n");
    for(int i=0;i<49;i++)
    {
        printf("%d,",*(arr+i));
    }
    printf("%d",*(arr+49));
    return 0;
}


//     int arr[7]={8,1,0,0,3,4,2};
//    // shift_element(arr,2);
//     for(int i=0;i<7;i++)
//     {
//         printf("%d,",arr[i]);
//     }
//     insertion_sort(arr,7);
//     printf("\n");
//     for(int i=0;i<7;i++)
//     {
//         printf("%d,",arr[i]);
//     }
//     return 0;
