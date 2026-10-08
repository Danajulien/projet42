#include <stdio.h>

int str_lenght(char *str)
{
    int i = 1;

    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int main(void)
{
    char phrase[] = "Comment ca se passe ta piscine reviewer du futur ?";
    printf("la taille c'est : %i", str_lenght(phrase));
    return 0;
}