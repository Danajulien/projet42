#include "libft.h"
#include <stdio.h>

int main(void)
{
    char dest[10] = {'A'};
    size_t ret = ft_strlcpy(dest, "coucou", 0);

    printf("retour = %zu, dest[0] = '%c'\n", ret, dest[0]);
    return (0);
}