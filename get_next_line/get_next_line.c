#include "get_next_line.h"


char *get_next_line(int fd)
{
    int i = 0;
    static char buffer[BUFFER_SIZE + 1];
    static int read_bytes = 0;
    static int index = 0;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = malloc(sizeof(char) * BUFFER_SIZE + 1);
    while (1)
    {
        if (index >= read_bytes)
        {
            read_bytes = read(fd, &buffer, BUFFER_SIZE);
            if (read_bytes == 0)
                break ;
            index = 0;
        }

        line[i++] = buffer[index];
        if (buffer[index] == '\n')
        {
            index++;
            break; 
        }
        index++;
    }
    if (read_bytes == 0 && i == 0)
        return (free(line), NULL);
    line[i] = '\0';
    return (line);
}