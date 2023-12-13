#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    for(int i = 0; i < stack_size; i++)
        printf("%i ", stack_a[i]);

}