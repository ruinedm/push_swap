// #include "../push_swap.c"
#include <stdio.h>

void print_int_arr(int *arr, int arr_size)
{
    int i;

    i = 0;
    while(i < arr_size)
    {
        printf("OUTPUT %i: %i\n",i ,arr[i]);
        i++;
    }
}
int get_latest_index(int *arr,int arr_size, int num)
{
    int i;
    int latest_index;

    i = 0;
    while(i < arr_size)
    {
        if(arr[i] == num)
            latest_index = i;
        i++;
    }
    return latest_index;
}
int max(int *arr, int arr_size)
{
    int i;
    int max;

    i = 0;
    max = 0;
    while(i < arr_size)
    {
        if(max < arr[i])
            max = arr[i];
        i++;
    }
    return (max); 
}
int get_lis_length(void)
{
    int arr[] = {0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
    int length[12];
    int subsequence[12];
    int i;
    int temp;
    int j;
    int index;
    int value;
    int len;

    i = 1;
    j = 0;
    while(j < 12) {length[j] = 1; subsequence[j] = -1; j++;}  // Each element is an increasing subsequence of length 1 //
    j = 0;
    while(i < 12) // size - 1  iterations??? //
    {
        j = 0;
        while(j < i) // i = 3 // j = 2
        {
            if(arr[j] < arr[i])
            {
                temp = length[j] + 1; 
                if(temp >= length[i])
                {
                    length[i] = temp;
                    subsequence[i] = j;
                }
            }
            j++;
        }
        i++;
    }
    len = max(length, 12);
    int list[len];
    int x = len - 1;
    index = get_latest_index(length, 12, len);
    while(index != -1)
    {
        list[x] = arr[index];
        x--;
        index = subsequence[index];
    }

    print_int_arr(list, len);
    return len;
}

int main()
{
    printf("LIS LEN: %i\n", get_lis_length());
}
