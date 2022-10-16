#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd = open("./test.txt", O_RDONLY, 0);
    if (fd < 0)
    {
        printf("FILE OPEN ERROR\n");
        exit(1);
    }

    char buf[11] = {0};

    while (1)
    {
        memset(buf, 0, 11);
        size_t i = read(fd, buf, 10);
        printf("=====READ====\n");
        printf("%s", buf);
        printf("(%lu)\n", i);
        printf("=====END====\n");

        if (i < 10)
            break;
    }

    close(fd);
    return 0;
}
