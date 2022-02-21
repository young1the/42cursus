#include "../engine.h"

int	is_zero(double d)
{
	if (fabs(d) < EPS)
		return (1);
	else
		return (0);
}

double	deg_to_rad(double deg)
{
	double	rad;

	rad = (deg)*M_PI/180.0;
	return (rad);
}

double	rad_to_deg(double rad)
{
	double	deg;

	deg = (rad)*180.0/M_PI;
	return (deg);
}

int	get_sign(double d)
{
	if (is_zero(d))
		return (0);
	if (d > 0)
		return (1);
	else
		return (-1);
}

double	get_distance(double x0, double y0, double x1, double y1)
{
	double	dx;
	double	dy;
	double	ret;

	dx = x0 - x1;
	dy = y0 - y1;
	ret = sqrt(dx*dx + dy*dy);
	return (ret);
}
