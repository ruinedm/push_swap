#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_duplicates(int *stack,int stack_size)
{
    int i;
    int j;

    i = 0;
    while(i < stack_size  - 1)
    {
        j = stack_size - 1;
        while(i < j)
        {
            if(stack[i] == stack[j])
                return (0);
            j--;
        }
        i++;
    }
    return(1);
}


void parser(char *argv[], int stack_size, int *new_stack)
{
    int i;
    int j;

    i = 0;
    while(i < stack_size)
    {
        new_stack[i] = atoi(argv[i + 1]);
        i++;
    }
}

int main(int argc, char *argv[])
{
    int *stack_a;
    int stack_size;

    stack_size = argc - 1;
    if(argc == 1)
    {
        printf("Error");
        return (1);
    }
    stack_a = malloc(stack_size * sizeof(int));
    if(!stack_a)
        return (1);
    parser(argv, stack_size, stack_a);
    if(!check_duplicates(stack_a, stack_size))
    {
        printf("Error");
        return (0);
    }
}