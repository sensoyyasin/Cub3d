#include "cub3d.h"

void	raycasting(t_cub3d *img, double angle, int ray_counter)
{
	double distance_v;
	double distance_h;
	double distance;
	int dir_x = ((cos(angle * (PI / 180)) > 0) * 2) - 1; // dereceden radyana dönüştürür. Eğer açının cosinüsü pozitif ise, bu ifade 1 * 2 - 1 = 1 olarak değerlendirilir
	int dir_y = ((sin(angle * (PI / 180)) > 0) * -2) + 1; //Sinüs değeri 0'dan büyükse ışın yukarıyı gösteriyor demektir ve ((sin(açı * (PI / 180)) > 0) * -2) + 1 ifadesi -1 olarak değerlendirilir.
	//sin(90) = 1 * (-2) + 1 = -1; yukarıya bakis
	bool hitv = false;
	bool hith = false;
	distance_v = ray_vertical(img, angle, dir_x, dir_y, &hitv); //dikey
	distance_h = ray_horizontal(img, angle, dir_x, dir_y, &hith); //yatay
	if (distance_v < distance_h)
	{
		distance = distance_v;
		img->_hith = false;
		img->_hitv = true;
	}
	else
	{
		distance = distance_h;
		img->_hith = true;
		img->_hitv = false;
	}
	double original_dist = distance;
	distance = distance * fabs(cos(((img->angle * (180.0 / PI)) - angle) * (PI / 180)));
	draw_ray(distance, dir_x, dir_y, img, angle, ray_counter, original_dist);
}

double	ray_vertical(t_cub3d *img, double angle, double dir_x, double dir_y, bool *hit)
{
	//ray_vertical fonksiyonu, dikey bir ışın kullanarak haritadaki duvarların konumunu bulur.
	double vdy;
	double vdx;

	if (dir_x == -1)
		vdx = img->p_x - floor(img->p_x);
	else
		vdx = ceil(img->p_x) - img->p_x;
	vdy = fabs(tan(angle * (PI / 180)) * vdx);

	double tmp_x = vdx*dir_x;
	double tmp_y = vdy*dir_y;
	while (img->p_x + vdx*dir_x - 0.0001 >= 0 && img->p_x + vdx*dir_x - 0.0001 <= (img->max_map_width - 1)
	&& img->p_y + vdy * dir_y >= 0 && img->p_y + vdy*dir_y <= img->max_map_height) //koşulları, ışının harita dışına çıkmamasını sağlar.
	{
		// ışının başlangıç noktasından itibaren haritanın kenarlarına kadar uzanacak şekilde,
		// her adımda ışının konumunu günceller ve her adımda bir duvarın kontrolünü yapar.
		vdx = vdx + 0.0001; // satırı, ışının her adımda x koordinatında ne kadar ilerleyeceğini belirler.
		if (is_wall_v2(img->p_x + vdx * dir_x, img->p_y + vdy * dir_y, img)) //ışının yeni pozisyonunda bir duvarın olup olmadığını kontrol eder. Eğer bir duvar varsa, hit değişkenini true yapar ve duvarın konumunu tmp_x ve tmp_y değişkenlerine kaydeder.
		{
			*hit = true;
			tmp_x = vdx * dir_x;
			tmp_y = vdy * dir_y;
			break;
		}
		vdx = vdx + 1 - 0.0001; //ışının bir sonraki adımda ne kadar ilerleyeceğini belirler.
		vdy = fabs(tan(angle * (PI / 180)) * vdx); //satırı, ışının her adımda y koordinatında ne kadar ilerleyeceğini belirler.
		//angle değişkeni, ışının açısını belirler ve PI / 180 ile çarpılırak dereceden radyana dönüştürülür. tan fonksiyonu, açının tanjantını hesaplar ve fabs fonksiyonu ile mutlak değeri alınarak negatif değerler engellenir.
	}
	double distance;
	if (*hit == true)
		distance = sqrt((tmp_x*tmp_x) + (tmp_y*tmp_y));
	else
		distance = 10000;
	return (distance);
}

double ray_horizontal(t_cub3d *img, double angle, double dir_x, double dir_y, bool *hit)
{
	//verilen bir açı ve konum bilgisine göre, yatay yönde bir ışın çizerek bu ışının hangi noktalara temas ettiğini ve temas ettiği ilk duvarın konumunu hesaplar.
	double hdy;
	double hdx;

	if (dir_y == -1)
		hdy = img->p_y - floor(img->p_y);
	else
		hdy = ceil(img->p_y) - img->p_y;
	hdx = fabs(hdy / tan(angle * (PI / 180)));
	double tmp_y = hdy * dir_y;
	double tmp_x = hdx * dir_x;
	while (img->p_x + hdx * dir_x >= 0 && img->p_x + hdx * dir_x <= 33
	&& img->p_y + hdy*dir_y - 0.0001 >= 0 && img->p_y + hdy * dir_y - 0.0001 <= 13)
	{
		hdy = hdy + 0.0001;
		if (is_wall_v2(img->p_x + hdx * dir_x, img->p_y + hdy * dir_y, img))
		{
			*hit = true;
			tmp_x = hdx*dir_x;
			tmp_y = hdy*dir_y;
			break;
		}
		hdy = hdy + 1 - 0.0001;
		hdx = fabs(hdy / tan(angle * (PI / 180)));
	}

	double distance;
	if (*hit == true)
		distance = sqrt((tmp_x*tmp_x) + (tmp_y*tmp_y));
	else
		distance = 10000;
	return (distance);
}

int is_wall_v2(double x, double y, t_cub3d *img)
{
	int xX;
	int yY;

	xX = (int)floor(x);
	yY = (int)floor(y);
	return (ft_strchr("0NSEW", img->map[yY][xX]) == NULL);
}

void draw_ray(double distance, int dir_x, int dir_y, t_cub3d *img, double angle, int ray_count, double original_dist)
{
	(void)angle;
	if (img->_hith == true)
	{
		img->find_pixel = (img->ray_x - floor(img->ray_x)) * img->xpm[img->xpm_number].width;
		if(dir_y > 0)
		{
			img->xpm_number = 1;
			img->color = 0x800000;//red south
		}
		else
		{
			img->xpm_number = 0;
			img->color = 0x80FFFF66;//yellow north
		}
	}
	else if (img->_hitv == true)
	{
		img->find_pixel = (img->ray_y - floor(img->ray_y)) * img->xpm[img->xpm_number].width;
		if(dir_x > 0)
		{
			img->xpm_number = 2;
			img->color = 0x000080;//blue east
		}
		else
		{
			img->xpm_number = 3;
			img->color = 0x8066FF66;//green west
		}
	}
	_3D(img, distance, ray_count, dir_x, dir_y);
    (void)original_dist;
}

int is_wall(double x, double y, t_cub3d *img)
{
	int xX;
	int yY;

	if (x < 0 || x > img->max_x || y < 0 || y > img->max_y)
		return (1);
    xX = floor(x);
    yY = floor(y);
	if (img->map[yY][xX] != '1')
		return (0);
    return (1);
}

void _3D(t_cub3d *img, double distance, int ray_count, int dir_x, int dir_y)
{
	double	oran;
	int		(i) = 0;;
	int color;
	distance = distance * (double)img->pixel * ((double)WINDOW_HEIGHT / (double)WINDOW_WIDTH);
	oran = (((double)WINDOW_HEIGHT / 2.0) / distance) * (double)img->pixel;

	img->img_loc = img->xpm[img->xpm_number].width * (img->xpm[img->xpm_number].height / 2)
		+ img->find_pixel;
	if ((oran >= WINDOW_HEIGHT / 2.0))
		oran = WINDOW_HEIGHT / 2.0 - 1;
	//printf("oran : %f\n",oran);
	while (i <= oran && i <= (WINDOW_HEIGHT / 2.0))
	{
		//color = img->xpm[img->xpm_number].img.addr[img->img_loc + img->xpm[img->xpm_number].width
		//	* (int)((double)i * ((double)img->xpm[img->xpm_number].width / (double)(oran * 2)))];
		img->addr_game[((WINDOW_HEIGHT / 2) * WINDOW_WIDTH - ray_count) + (WINDOW_WIDTH * i)] = img->color;

		//color = img->xpm[img->xpm_number].img.addr[img->img_loc - img->xpm[img->xpm_number].width
		//	* (int)((double)i * ((double)img->xpm[img->xpm_number].width / (double)(oran * 2)))];
		img->addr_game[((WINDOW_HEIGHT / 2) * WINDOW_WIDTH - ray_count) - (WINDOW_WIDTH * i)] = img->color;
		i++;
	}
}
