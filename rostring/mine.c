#include <unistd.h>

int skip_spaces(char *str, int i)
{
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    return (i);
}

int find_end(char *str, int i)
{
    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
        i++;
    return (i);
}

int main(int argc, char **argv)
{
    int i;
    int start;
    int end;
    int first_word_start;
    int first_word_end;
    int first_word_printed;

    i = 0;
    if (argc == 2)
    {
        i = skip_spaces(argv[1], i);
    
        first_word_start = i;
        while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            i++;
        first_word_end = i;
        while (argv[1][i])
        {
            i = skip_spaces(argv[1], i);
            start = i;
            i = find_end(argv[1], i);
            end = i;
            write(1, &argv[1][start], end - start);
            write(1, " ", 1);
        }
        write(1, &argv[1][first_word_start], first_word_end - first_word_start);
    }
    write(1, "\n", 1);
return (0);

}