#include "search_algos.h"

/**
 * binary_search - searches for a value in sorted array of integers
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: the index where value is located
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, start, end;
	int middel;

	start = 0;
	end = size - 1;

	if (array == NULL)
		return (-1);
	while (start <= end)
	{
		middel = (start + end) / 2;
		printf("Searching in array: ");
		for (i = start; i <= end; i++)
		{
			if (i != end)
				printf("%d, ", array[i]);
			else
				printf("%d", array[i]);
		}
		printf("\n");
		if (array[middel] < value)
			start = middel + 1;
		else if (array[middel] > value)
			end = middel - 1;
		else
			return (middel);
	}
	return (-1);
}
