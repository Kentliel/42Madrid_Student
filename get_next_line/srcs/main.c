#include <fcntl.h>     // open
#include <unistd.h>    // close
#include <stdio.h>     // printf, perror
#include <stdlib.h>    // free

char	*get_next_line(int fd);

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Uso: %s <nombre_del_archivo>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	if (line == NULL) // Verifica si hubo un error en la lectura
	{
		perror("Error al leer el archivo");
	}
	close(fd);
	return (0);
}

