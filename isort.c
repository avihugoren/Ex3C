#include <stdio.h>

#define LEN 50


void shift_element(int* arr, int i){

    int* ptr_element=arr+i;//pointing to  the last element that need to move
    //for loop that runs from the last element and move each element one cell to the right
    for(int j=i-1;j>=0;j--)
    {
        *ptr_element=*(arr+j);
        ptr_element--;
    }
}
void insertion_sort(int* arr , int len)
{
    int* pointer=arr;
    int counter;//count how many elements needs to shift
    int temp;
    for(int i=1;i<len;i++)
    {
        counter=0;
        //for loop that insert arr[i] into his place on the sorted array from index 0 to i and how many elements need to get shifted
        for(int j=i;j>0;j--)
        {
            if(*(arr+i)<*(arr+j-1))
            {
                pointer=arr+j-1;//the place where arr[i] will be inserted
                counter++;//how many elements need to get shifted
            } else
                break;
        }
        temp=*(arr+i);//copy the value of arr[i]
        shift_element(pointer,counter);//shifting the elements
        *(arr+i-counter)=temp;//insert arr[i] to this place in the sorted array
    }
}
int main()
{
    int arr [50];
    int input;
    //for loop that gets 50 numbers from the user
    for(int i=0;i<50;i++)
    {
        scanf("%d",&input);
        *(arr+i)=input;//insert the value that taken from the user into the array
    }

    insertion_sort(arr,50);//sort the array
    //for loop that print the sorted array
    for(int i=0;i<49;i++)
    {
        printf("%d,",*(arr+i));
    }
    printf("%d",*(arr+49));
    return 0;
}



