// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------


#include "./libs/MLX42/include/MLX42/MLX42.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 1200
#define screenHeight 800

static mlx_image_t* image;

int worldMap[mapWidth][mapHeight]=\
{
  {1,1,1,1,1,1,1,1,1,1,1,1 ,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0 ,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0 ,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0 ,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0 ,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0 ,0,0,0,0,0,0,0,1,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0 ,0,0,0,0,0,0,1,1,1,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0 ,0,1,1,1,0,1,1,1,1,1,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0 ,0,1,-1,1,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0 ,0,1,-1,1,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0 ,0,1,-1,1,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1 ,1,1,-1,1,1,1,1,1,1,1,1,1}
};

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_square(int Xmap, int Ymap, int32_t color)
{
	int	x;
	int	y;
	int	square_width;
    int	square_height;
 	square_width = screenWidth / mapWidth;
	square_height = screenHeight / mapHeight;
	x = Xmap * square_width - 1;
	while (++x < square_width * (Xmap+1))
	{
		y = Ymap * square_height -1;
		while (++y < square_height * (Ymap+1))
			mlx_put_pixel(image, x, y, color);
	}
}

void	draw_map(void *param)
{
	int		Xmap_posicion;
	int		Ymap_posicion;
	int32_t	color;

	(void)param;
	Xmap_posicion = -1;
	while (++Xmap_posicion < mapWidth)
	{
		Ymap_posicion = -1;
		while (++Ymap_posicion < mapHeight)
		{
			color = ft_pixel(0, 0, 0, 255);
			if (worldMap[Xmap_posicion][Ymap_posicion] > 0)
				color = ft_pixel(255, 255, 255, 255);
			if (worldMap[Xmap_posicion][Ymap_posicion] >= 0)
				draw_square(Ymap_posicion, Xmap_posicion, color);
		}
	}

}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t x = 0; x < image->width; ++x)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				255, // R
				255, // G
				255, // B
				255  // A
			);
			mlx_put_pixel(image, x, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(void)
{
	mlx_t* mlx;

	// Gotta error check this stuff
	mlx = mlx_init(screenWidth, screenHeight, "MLX42", true);
	image = mlx_new_image(mlx, screenWidth, screenHeight);
	mlx_image_to_window(mlx, image, 0, 0);

	mlx_loop_hook(mlx, draw_map, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
