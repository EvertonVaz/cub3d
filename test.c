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


///////////////////////////////////////////////////////////////////////////////////////////////

#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

typedef uint32_t Uint32;

// Declaração do buffer
Uint32 buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

// Declaração de um ponteiro para um array de texturas
Uint32* texture[8];

// Mapa do mundo
int worldMap[MAP_HEIGHT][MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    // ...
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void initialize_textures() {
    for (int i = 0; i < 8; i++) {
        texture[i] = (Uint32*)malloc(TEX_WIDTH * TEX_HEIGHT * sizeof(Uint32));
        if (texture[i] == NULL) {
            printf("Erro ao alocar memória para a textura %d\n", i);
            exit(1);
        }
        for (int x = 0; x < TEX_WIDTH; x++) {
            for (int y = 0; y < TEX_HEIGHT; y++) {
                int xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
                int ycolor = y * 256 / TEX_HEIGHT;
                int xycolor = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;
                texture[0][TEX_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEX_WIDTH - y); //flat red texture with black cross
                texture[1][TEX_WIDTH * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
                texture[2][TEX_WIDTH * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
                texture[3][TEX_WIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
                texture[4][TEX_WIDTH * y + x] = 256 * xorcolor; //xor green
                texture[5][TEX_WIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
                texture[6][TEX_WIDTH * y + x] = 65536 * ycolor; //red gradient
                texture[7][TEX_WIDTH * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
            }
        }
    }
}

void free_textures() {
    for (int i = 0; i < 8; i++) {
        free(texture[i]);
    }
}

void init_ray(t_player *player, t_ray *ray, int x) {
    ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
    ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
    ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
    ray->map_x = (int)player->x;
    ray->map_y = (int)player->y;
    ray->hit = 0;
    if (ray->dir_x == 0)
        ray->delta_dist_x = 1e30;
    else
        ray->delta_dist_x = fabs(1 / ray->dir_x);
    if (ray->dir_y == 0)
        ray->delta_dist_y = 1e30;
    else
        ray->delta_dist_y = fabs(1 / ray->dir_y);
}

void side_dist(t_ray *ray, t_player *player) {
    if (ray->dir_x < 0) {
        ray->step_x = -1;
        ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
    } else {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
    }
    if (ray->dir_y < 0) {
        ray->step_y = -1;
        ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
    } else {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
    }
}

int hit(t_cub *cub) {
    t_ray *ray = cub->ray;
    if (ray->side_dist_x < ray->side_dist_y) {
        ray->side_dist_x += ray->delta_dist_x;
        ray->map_x += ray->step_x;
        ray->side = 0;
    } else {
        ray->side_dist_y += ray->delta_dist_y;
        ray->map_y += ray->step_y;
        ray->side = 1;
    }
    if ((ray->map_x < 0 || ray->map_x >= cub->map_width) || (ray->map_y < 0 || ray->map_y >= cub->map_height))
        return (ray->hit = 1);
    if (cub->map[ray->map_y][ray->map_x] == '1')
        ray->hit = 1;
    return (ray->hit);
}

void draw_line(t_cub *cub, int x) {
    t_ray *ray = cub->ray;
    t_player *player = cub->player;
    int texNum = cub->map[ray->map_y][ray->map_x] - 1;

    double wallX;
    if (ray->side == 0)
        wallX = player->y + ray->perp_wall_dist * ray->dir_y;
    else
        wallX = player->x + ray->perp_wall_dist * ray->dir_x;
    wallX -= floor(wallX);

    int texX = (int)(wallX * (double)TEX_WIDTH);
    if (ray->side == 0 && ray->dir_x > 0)
        texX = TEX_WIDTH - texX - 1;
    if (ray->side == 1 && ray->dir_y < 0)
        texX = TEX_WIDTH - texX - 1;

    ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
    ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
    if (ray->draw_end >= SCREEN_HEIGHT)
        ray->draw_end = SCREEN_HEIGHT - 1;

    double step = 1.0 * TEX_HEIGHT / ray->line_height;
    double texPos = (ray->draw_start - SCREEN_HEIGHT / 2 + ray->line_height / 2) * step;

    for (int y = ray->draw_start; y < ray->draw_end; y++) {
        int texY = (int)texPos & (TEX_HEIGHT - 1);
        texPos += step;
        Uint32 color = texture[texNum][TEX_HEIGHT * texY + texX];
        if (ray->side == 1)
            color = (color >> 1) & 8355711; // make color darker for y-sides
        buffer[y][x] = color;
    }
}

void drawBuffer(SDL_Renderer *renderer, Uint32 buffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
}

void raycasting(t_cub *cub) {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        init_ray(cub->player, cub->ray, x);
        side_dist(cub->ray, cub->player);
        while (hit(cub) == 0)
            continue;
        draw_line(cub, x);
    }
}

void draw_map(void *param) {
    t_cub *cub = (t_cub *)param;
    raycasting(cub);
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Raycaster", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erro ao criar a janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erro ao criar o renderizador: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    initialize_textures();

    t_cub cub;
    cub.player = malloc(sizeof(t_player));
    cub.ray = malloc(sizeof(t_ray));
    cub.map = worldMap;
    cub.map_height = MAP_HEIGHT;
    cub.map_width = MAP_WIDTH;
    cub.player->x = 22;
    cub.player->y = 12;
    cub.player->dir_x = -1;
    cub.player->dir_y = 0;
    cub.player->plane_x = 0;
    cub.player->plane_y = 0.66;

    int quit = 0;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        draw_map(&cub);
        drawBuffer(renderer, buffer);

        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));
    }

    free(cub.player);
    free(cub.ray);
    free_textures();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
