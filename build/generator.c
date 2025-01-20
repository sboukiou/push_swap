#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
	* deja_vue	- Checks if a value exists already in an array
	* @arr: Array to check
	* @value: Value to look for
	* @size: size of the array
	* Return: 0 if its found. 1 otherwise.
*/

int	deja_vue(int *arr, int value, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
			return (0);
	}
	return (1);
}

/**
	* main - Entry point
	* Generates a random set of values with a given size
	* @ac: Number of arguments provided
	* @av: Arguments.
	* Return: 0 on success
*/

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
		while (deja_vue(chunks, value, size) == 0)
			value = rand();
		chunks[i] = value;
	}
	for (int i = 0; i < size; i++)
		printf("%d ", chunks[i]);
	printf("\n");
	free(chunks);
	return (0);
}
