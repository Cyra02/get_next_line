#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define BUFFER_SIZE 400


int new_line(char *s)
{
    unsigned int i;
    if(!s)
        return (-1);

    while(s[i] != '\n' && s[i] != '\0')
        i++;
    if(s[i] != '\0')
        return (-1);
    return (i);
    
}

char join (char *s1, char *s2)
{
     
}

char *get_next_line(int fd)
{
    char *buffer;
    char *line;
    int leido = 1;
    static char *buff;


    buffer = malloc(BUFFER_SIZE + 1);
    if(BUFFER_SIZE <= 0 || fd < 0 || !buffer )
        return (0);
    while(new_line(buff) == -1)
    {
        leido = read(fd, buffer, BUFFER_SIZE);
        if(leido <= 0)
            break;
        buffer[leido] = '\0';
        buff = join(buff, buffer);
        
    }
    free(buffer);

    if(leido == -1)
        return (0);
    

    return (line);

}






int main ()
{
    int fd;

    fd = open("ejemplo.txt", O_RDONLY );
    printf("contenido %d",fd);
    return(0);
}
