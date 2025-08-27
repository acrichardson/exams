// don't forget to iterate i++; everywhere
// also don't forget  - 48; to convert from ascii to numeric
// res *= s

/* this function returns 1 if the character is one 
 * of the "space" character or 0 if it is not
 */


 #include <stdio.h>s
 #include <stdlib.h>

int ft_isspace(int c)
{
    return ((c >= 9 && c <= 13) || c == 32 ? 1 : 0);
}

/* this function returns 1 if the character is a digit 0-9
 * and 0 if the character is not a digit 0-9
 */
int ft_isdigit(int c)
{
    return (c >= 48 && c <= 57 ? 1 : 0);
}

int ft_atoi(const char *str)
{
    int res = 0;
    int i = 0;
    int s = 1;

    while (ft_isspace(str[i]))
      i++;

    if(str[i] == '-')
    {
        s = -1;
        i++;
    }

    while(ft_isdigit(str[i]))
    {
        res *= 10;
        res += str[i] - 48;
        i++;
    }
    return (res *= s);
}

int main(int argc, char **argv)
{
    printf("%s\n", argv[1]);
    // ft_atoi(argv[1]);
    printf("%d\n", ft_atoi(argv[1]));
    printf("%d\n", atoi(argv[1]));
}