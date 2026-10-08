#include <stdio.h>

int char_is_alpha(char c);
void char_to_upper(char *c);
void char_to_lower(char *c);
int char_is_upper(char c);
int char_is_lower(char c);
int char_is_first_one(char*c, int index);
int str_lenght(char *str);

char *ft_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        
        if (char_is_alpha(str[i]) && char_is_lower(str[i]) && char_is_first_one(str, i))
        {
            char_to_upper(str + i);
        }
        else if (char_is_alpha(str[i]) && char_is_lower(str[i]))
        {
            char_to_lower(str + i);
        }
        i++;
    }
    return str;
   
}

int char_is_alpha(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int char_is_upper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int char_is_lower(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int char_is_first_one(char*c, int index)
{
    if (c[index - 1] == ' ' || c[index - 1] == '\t' || c[index - 1] == '\n' || index == 0)
        return (1);
    return (0);
}

void char_to_upper(char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

void char_to_lower(char *c)
{
    if (*c >= 'A' && *c <= 'Z')
        *c = *c + 32;
}

int main(void)
{
    char str[] ={"kiwi du bled45 25jerem star DU 13"};
    printf("phrase avant : %s", str);
    printf("\n");
    ft_strcapitalize(str);
    printf("phrase après : %s", str);
    return 0;
}
