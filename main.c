#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>

int main()
{
    int fd = open("file.txt",O_RDWR);
    int fd2 = open("fichier.txt",O_RDWR);
    int max = 2;
    //request -> kenral->structure iondoe table 
    // while (true)
    // {
    //     int a;
    //     printf("- press 1 if you want to read the next line from the text file.\n");
    //     printf("- press 2 if you want to shutdown the program.\n");
    //     scanf("%d",&a);
    //     if (a == 1)
    //     {
    //         char *s = get_next_line(fd);
    //         if (s)
    //             printf("%s\n",s);
    //         else
    //         {
    //             printf("you have reached the end of file.\n");
    //             break;
    //         }
    //     }
    //     else if (a == 2)
    //         break;
    //     else
    //         printf("please choose number between 1 and 2.\n");
    // }
    char    *line;
    // printf("%s\n",line = get_next_line(fd));
    // free(line);
    // printf("%s\n",line = get_next_line(fd));
    // free(line);
    // printf("%s\n",line = get_next_line(fd2));
    // free(line);
    // printf("%s\n",line = get_next_line(fd2));
    // free(line);
    // printf("%s\n",line = get_next_line(fd));
    // free(line);
    // printf("%s\n",line = get_next_line(fd2));
    // free(line);
    while ((line = get_next_line(fd)) && max)
    {
        --max;
        printf("%s", line);
        free(line);
    }

    // size_t a = FOPEN_MAX;
    // printf("%zu",a);
    // // size_t maxs = SIZE_MAX;
    // ssize_t maxss = SSIZE_MAX;
    // printf("%zu\n", maxss);
}