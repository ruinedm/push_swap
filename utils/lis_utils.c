#include <stdio.h>
#include <stdlib.h>
#include "../push_swap.h"

void print_int_arr(int *arr, int arr_size) 
{
    int i = 0;
    while (i < arr_size) 
    {
        printf("OUTPUT %i: %i\n", i, arr[i]);
        i++;
    }
}

int get_latest_index(int *arr, int arr_size, int num) 
{
    int i = 0;
    int latest_index = -1;

    while (i < arr_size) 
    {
        if (arr[i] == num)
            latest_index = i;
        i++;
    }
    return latest_index;
}

int max(int *arr, int arr_size) 
{
    int i = 0;
    int max_value = arr[0];

    while (i < arr_size) 
    {
        if (max_value < arr[i]) 
            max_value = arr[i];
        i++;
    }
    return max_value;
}

int* get_lis(int *arr, int arr_size, int *lis_len) 
{
    int i;
    int j;
    int temp;
    int index;
    int len;
    int *length;
    int *subsequence;
    int *list;

    length = (int *)malloc(arr_size * sizeof(int));
    subsequence = (int *)malloc(arr_size * sizeof(int));
    if (!length || !subsequence) 
    {
        free(length);
        free(subsequence);
        return (NULL);
    }

    i = 1;
    j = 0;
    while (j < arr_size) 
    {
        length[j] = 1;
        subsequence[j] = -1;
        j++;
    }

    while (i < arr_size) 
    {
        j = 0;
        while (j < i) 
        {
            if (arr[j] < arr[i]) 
            {
                temp = length[j] + 1;
                if (temp >= length[i])
                {
                    length[i] = temp;
                    subsequence[i] = j;
                }
            }
            j++;
        }
        i++;
    }

    len = max(length, arr_size);
    *lis_len = len;
    list = (int *)malloc(len * sizeof(int));
    if (!list) 
    {
        free(length);
        free(subsequence);
        return (NULL);
    }

    index = get_latest_index(length, arr_size, len);
    i = len - 1;
    while (index != -1)
    {
        list[i--] = arr[index];
        index = subsequence[index];
    }

    // print_int_arr(list, len);

    free(length);
    free(subsequence);
    // free(list); 
    return (list);
}

void set_is_lis(t_node *stack, int *lis_arr, int lis_len)
{
    int i;

    i = 0;
    while(i < lis_len)
    {
        find_node(stack, lis_arr[i],FIND_BY_DATA)->is_lis = TRUE;
        i++;
    }

}
void analyze_stack(t_node *stack, int stack_size)
{
    int *copy_array;
    int lis_len;
    int *lis;

    copy_array = copy_stack_to_array(stack);
    rank_nodes(stack, stack_size);
    lis = get_lis(copy_array, stack_size, &lis_len);
    set_is_lis(stack, lis, lis_len);
    free(copy_array);
    free(lis);
}

// int main() 
// {
//     int lis_len;
//     int arr[] = {0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
//     int arr_size = sizeof(arr) / sizeof(arr[0]);
//     int *list = get_lis(arr, 12, &lis_len);
//     print_int_arr(list, lis_len);
//     return 0;
// }
