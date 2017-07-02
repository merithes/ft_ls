#include "hls.h"

int					*sort(char *opt, struct dirent **tab, int qty)
{
	int				*outp;
	int				i;
	int				ic;
	int				cnt;

	i = -1;
	if (!(outp = malloc(sizeof(int) * (qty + 1))))
		return (NULL);
	ft_bzero(outp, sizeof(int) * (qty + 1));
	while(++i < qty)
	{
		ic = 0;
		cnt = 0;
		while (ic < qty)
		{
			if (opt && opt[REV])
				cnt += (ft_strcmp(tab[i]->d_name, tab[ic]->d_name) < 0) ? 1 : 0;
			else
				cnt += (ft_strcmp(tab[i]->d_name, tab[ic]->d_name) > 0) ? 1 : 0;
			ic++;
		}
		outp[cnt] = i;
	}
	return (outp);
}
