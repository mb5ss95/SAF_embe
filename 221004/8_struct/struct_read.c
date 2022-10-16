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
    int fd = open("./test.txt", O_RDONLY, 0);
    if (fd < 0)
    {
        printf("FILE OPEN ERROR\n");
        exit(1);
    }

    struct Node temp = {0};

    read(fd, &temp, sizeof(temp));

    printf("%d %d %d\n", temp.y, temp.x, temp.lev);

    close(fd);
    return 0;
}
