#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("file.txt",O_RDWR); 
    while (true)
    {
        int a;
        printf("- press 1 if you want to read the next line from the text file.\n");
        printf("- press 2 if you want to shutdown the program.\n");
        scanf("%d",&a);
        if (a == 1)
        {
            char *s = get_next_line(fd);
            if (s)
                printf("%s\n",s);
            else
            {
                printf("you have reached the end of file.\n");
                break;
            }
        }
        else if (a == 2)
            break;
        else
            printf("please choose number between 1 and 2.\n");
    }
}