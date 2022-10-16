#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int y, x;
    int lev;
};

int main()
{
    int fd = open("./test.txt", O_WRONLY | O_TRUNC, 664);
    if (fd < 0)
    {
        printf("FILE OPEN ERROR\n");
        exit(1);
    }

    struct Node temp = {3, 5, 99};

    write(fd, (void *)&temp, sizeof(temp));

    close(fd);
    return 0;
}
