#include "libft.h"

void				ft_putstr_cat(char *s1, char *s2, char *s3, int ret)
{
	if (s1)
		ft_putstr(s1);
	if (s2)
		ft_putstr(s2);
	if (s3)
		ft_putstr(s3);
	if (ret)
		ft_putchar('\n');
}
