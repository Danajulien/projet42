#include <stdio.h>

char *ft_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] < 'Z' && str[i] >= 'A')
        {
            str[i] += 32;
        }
        i++;
    }
    return str;
}

int main()
{
    char str[] = "salut le.a REView.euSE";
    printf("Original string: %s\n", str);
    ft_strlowcase(str);
    printf("Lowercase string: %s\n", str);
    return 0;
}
