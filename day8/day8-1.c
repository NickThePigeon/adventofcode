#include <stdio.h>
#include <stdlib.h>

#define LINES_I 10
#define LINES_I 200

int	main(void)
{
	char ***line;
	int i,j;

	line = (char ***)malloc(sizeof(char **) * LINES_I + 1);
	if (!line)
		return (1);
	line[LINES_I] = NULL;
	*line = (char **)malloc(sizeof(char *) * 3);
	(!*line)
		return (1);
	FILE	*ptr = fopen("file.txt","r");
    if (ptr == NULL)
    {
        printf("ptr:no such file.\n");
        return 0;
    }
	for (i = 0; i < NBR_I; i++)
	{
		fscanf(ptr, "%s", &nbr[i]);
	}
	return (0);
}