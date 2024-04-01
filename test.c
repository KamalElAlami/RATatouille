#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char *str;

    str = NULL;

    str = "kamal";
    realloc((void *)str, sizeof(char) * 6); 
}