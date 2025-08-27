#include <unistd.h>


int main(int argc, char **argv)
{
    int i;
    int j;
    int last_word;

    i = 0;
    last_word = 0;
    if (argc == 2)
    {
        while (argv[1][i] != '\0')
            i++;

        while (i >= 0)
        {
            while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
                i--;
            j = i;
            while (j >= 0 && (argv[1][j] != ' ' && argv[1][j] != '\t'))
                j--;
            if (last_word)
            {
                write(1, " ", 1);
            }
            write(1, &argv[1][j + 1], i - j);
            last_word = 1;
            i = j;
        }
    }
        write(1, " ", 1);
        return (0);
}


// IF argument count is 2 (one input string)
//     SET i to the last character index of the string

//     WHILE i >= 0
//         // Skip all trailing spaces backwards
//         WHILE i >= 0 AND current character is a space/tab
//             i--

//         // Mark the end of the found word
//         SET j = i

//         // Find the start of the word (first space before the word)
//         WHILE j >= 0 AND current character is NOT a space/tab
//             j--

//         // If this isn't the first word printed, output a space
//         IF first_word flag is TRUE
//             PRINT " "

//         // Print the word from j+1 to i
//         PRINT substring from index (j+1) with length (i - j)

//         SET first_word flag to TRUE
//         SET i = j // Move i to the position before this word
// END IF

// PRINT a newline