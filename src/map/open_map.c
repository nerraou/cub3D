#include "map.h"

int open_map(const char *path)
{
    if (!ft_strendswith(path, ".cub"))
        return (-2);
    return open(path, O_RDONLY);
}
