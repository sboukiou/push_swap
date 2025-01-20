#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	not_in(int *arr, int value, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
			return (0);
	}
	return (1);
}

int main(int ac, char **av)
{
	int	value;
	int size;
	int	*chunks;

	printf("Generating value ...\n");
	size = 10;
	if (ac > 1)
		size = atoi(av[1]);
	chunks = (int *)calloc(size, sizeof(int));
	if (!chunks)
		return (0);

	for (int i = 0; i<= size; i++)
	{
		value = rand();
		while (not_in(chunks, value, size) == 0)
			value = rand();
		chunks[i] = value;
	}
	for (int i = 0; i < size; i++)
		printf("%d ", chunks[i]);
	printf("\n");
	free(chunks);
	return (0);
}
