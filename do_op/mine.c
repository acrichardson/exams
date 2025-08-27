// ssignment name  : do_op
// Expected files   : *.c, *.h
// Allowed functions: atoi, printf, write
// --------------------------------------------------------------------------------

// Write a program that takes three strings:
// - The first and the third one are representations of base-10 signed integers
//   that fit in an int.
// - The second one is an arithmetic operator chosen from: + - * / %

// The program must display the result of the requested arithmetic operation,
// followed by a newline. If the number of parameters is not 3, the program
// just displays a newline.

// You can assume the string have no mistakes or extraneous characters. Negative
// numbers, in input or output, will have one and only one leading '-'. The
// result of the operation fits in an int.

// Examples:

// $> ./do_op "123" "*" 456 | cat -e
// 56088$
// $> ./do_op "9828" "/" 234 | cat -e
// 42$
// $> ./do_op "1" "+" "-43" | cat -e
// -42$
// $> ./do_op | cat -e
// $

// quite clear just don't forget the break; s
#include <stdio.h>
#include <stdlib.h>
// unistd is not show in man write. where to find?
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        //program
        switch(argv[2][0])
        {
            case '+':
                printf("%d", atoi(argv[1]) + atoi(argv[3]));
                break;
            case '-':
                printf("%d", atoi(argv[1]) - atoi(argv[3]));
                break;
            case '*':
                printf("_%d", atoi(argv[1]) * atoi(argv[3]));
                break;
            case '/':
                printf("_%d", atoi(argv[1]) / atoi(argv[3]));
                break;
            case '%':
                printf("_%d", atoi(argv[1]) % atoi(argv[3]));
                break;
        }
    }
    // write actually prints it too early...
    // write(1, "\n", 1);
    printf("\n");
}














// // #include <stdio.h>
// // #include <stdlib.h>

// int main(int ac, char *av[])
// {
//     /* checking the number of arguments
//      */
//     if (ac == 4)
//     {
//         /* we then switch over the operator (av[2][0])
//          */
//         switch(av[2][0])
//         {
//             /* if the operator is + we simply make an
//              * addition and print the result to the screen
//              */
//             case '+':
//                 printf("%d", atoi(av[1]) + atoi(av[3]));
//                 break;
//             /* if the operator is - we simply make a
//              * substraction and print the result to the screen
//              */
//             case '-':
//                 printf("%d", atoi(av[1]) - atoi(av[3]));
//                 break;
//             /* if the operator is * we simply make a
//              * multiplication and print the result to the screen
//              */
//             case '*':
//                 printf("%d", atoi(av[1]) * atoi(av[3]));
//                 break;
//             /* if the operator is / we simply make a
//              * divisions and print the result to the screen
//              */            
//             case '/':
//                 printf("%d", atoi(av[1]) / atoi(av[3]));
//                 break;
//             /* if the operator is % we simply make a
//              * modulo and print the result to the screen
//              */
//             case '%':
//                 printf("%d", atoi(av[1]) % atoi(av[3]));
//                 break;
//         }
//     }
//     /* finally, we write a newline
//      */
//     printf("\n");
// }