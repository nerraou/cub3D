#include "debug.h"

void print_color(const char *message, int color)
{
	printf("%s (%d,%d,%d)\n", message, color >> 16, (color >> 8) & 0x000000FF, color & 0x000000FF);
}

void print_map(char **map_array, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		printf("%s\n", map_array[i]);
		i++;
	}
}
