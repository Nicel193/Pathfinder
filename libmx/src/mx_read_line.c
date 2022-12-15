#include "../inc/libmx.h"

static int to_delim_len(const int fd, char delim)
{
    short sz = 0;
    int len = 0;
    char buf;
    sz = read(fd, &buf, 1);
    while (sz > 0)
    {
        if (buf == delim)
            break;

        sz = read(fd, &buf, 1);
        len++;
    }
    close(fd);
    return len;
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd)
{
    int sz = 0;
    int size = 0;
    buf_size = 0;
    if (fd == -1)
    {
        close(fd);
        return -2;
    }

    size = to_delim_len(fd, delim);
    *lineptr = mx_strnew(size);
    sz = read(fd, lineptr, size);
    close(fd);

    return size;
}

