/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:42:11 by kcarrero          #+#    #+#             */
/*   Updated: 2025/06/20 20:13:10 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
    int *fds;
    char **lines;
    int i;
    int all_done;
    
    if (argc < 2)
    {
        printf("Uso: %s archivo1 [archivo2 ...]\n", argv[0]);
        return (1);
    }

    // Reservar memoria para los descriptores y líneas
    fds = malloc(sizeof(int) * (argc - 1));
    lines = malloc(sizeof(char *) * (argc - 1));
    if (!fds || !lines)
    {
        perror("Error de memoria");
        return (1);
    }

    // Abrir todos los archivos
    for (i = 0; i < argc - 1; i++)
    {
        fds[i] = open(argv[i + 1], O_RDONLY);
        lines[i] = NULL;
        if (fds[i] < 0)
        {
            perror("Error al abrir archivo");
            // Cerrar los que ya estaban abiertos
            while (--i >= 0)
                close(fds[i]);
            free(fds);
            free(lines);
            return (1);
        }
    }

    printf("\n\033[1;36mLeyendo de %d archivos:\033[0m\n", argc - 1);
    printf("----------------------------\n");

    // Leer hasta que todos los archivos terminen
    do {
        all_done = 1;
        
        for (i = 0; i < argc - 1; i++)
        {
            if (fds[i] == -1) // Si ya terminó este archivo
                continue;

            lines[i] = get_next_line(fds[i]);
            if (lines[i])
            {
                printf("\033[1;33mArchivo %d\033[0m (%s): %s", 
                       i + 1, argv[i + 1], lines[i]);
                free(lines[i]);
                lines[i] = NULL;
                all_done = 0;
            }
            else
            {
                close(fds[i]);
                fds[i] = -1;
            }
        }
    } while (!all_done);

    // Limpieza final
    for (i = 0; i < argc - 1; i++)
    {
        if (lines[i])
            free(lines[i]);
        if (fds[i] != -1)
            close(fds[i]);
    }

    free(fds);
    free(lines);

    printf("\n\033[1;32mLectura completada!\033[0m\n");
    return (0);
}

