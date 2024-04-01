#include "./includes/backdoor.h"

void ft_perror(char *str)
{
    printf("%s\n", str);
    exit (1);
}