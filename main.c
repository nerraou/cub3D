#include <mlx.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;

	void *image;
	char *relative_path = "./assets/test1.xpm";
	int img_width = 400;
	int img_height = 400;

	mlx = mlx_init();
	image = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (!image)
		return 1;
	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!");
	img.img = mlx_new_image(mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,

								 &img.endian);
	my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, image, 50, 50);

	mlx_loop(mlx);
	return 0;
}