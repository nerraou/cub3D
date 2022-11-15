#include "libft.h"

char *ft_strctrim(const char *str, char c)
{
    size_t len;

    while (*str && *str == c)
        str++;
    len = ft_strlen(str);
    if (len == 0)
        return (ft_strdup(""));
    len--;
    while (str[len] == c)
        len--;
    return (ft_substr(str, 0, len + 1));
}
