#ifndef HLS_H
# define HLS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <dirent.h>
# include "libft.h"

/*
** DEFINED VALUES
*/

# define I 0
# define INP 1
# define CNT 2

# define A 0
# define L 1
# define REV 2
# define REC 3
# define T 4

/*
** DECLARATIONS
*/

/*
** STRUCT
*/

typedef struct 		s_dir
{
	char			*name;
	DIR				*dd;
	int				files_qty;
	struct dirent	**files;
	struct s_dir	**sub;
}					t_dir;

int					*sort(char *opt, struct dirent **inp, int qty);
char				*get_opt(int ac, char **av);
void				list_dir(char *a, char *b);

#endif
