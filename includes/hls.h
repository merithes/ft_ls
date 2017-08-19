#ifndef HLS_H
# define HLS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include "libft.h"

/*
** DEFINED VALUES
** ==============
*/

# define I 0
# define INP 1
# define CNT 2

# define A 0
# define L 1
# define REV 2
# define REC 3
# define T 4
# define C 5
# define MAX_OPT 7

# define UID_LEN 1
# define GID_LEN 2
# define SIZ_TMP 0
# define SIZ_LEN 3
# define LNK_TMP 4
# define LNK_LEN 5
# define BLK_CNT 6

# define MAX_LENS 8
# define STRSIZE 1080

/*
** /!\SYSTEM DEPENDANT /!\
** =======================
*/

# define NEXIST_1 MAC_NEXIST_1
# define NEXIST_2 MAC_NEXIST_2
# define NPERMS_1 MAC_NPERMS_1
# define NPERMS_2 MAC_NPERMS_2

/*
** MACs
** ====
*/
# define SIX_MONTH 15552000
# define MAC_NEXIST_1 "ft_ls: cannot access '"
# define MAC_NEXIST_2 "': no such file or directory"
# define MAC_NPERMS_1 "ft_ls: cannot open directory '"
# define MAC_NPERMS_2 "': Permission denied"


/*
** ARCH
** ====
*/


/*
** DECLARATIONS
** ============
*/

/*
** MACROS
** ======
*/

#define COMPARE(a, b) ((a < b) ? b : a)

/*
** TYPEDEFS
** ========
*/

typedef struct passwd pass;
typedef struct group grps;
typedef struct dirent dirs;
typedef struct stat stats;
typedef long int lsi;

int					*sort(char *opt, struct dirent **inp, int qty, char *nam);
char				*get_opt(int ac, char **av);
void				list_dir(char *a, char *b, DIR *inp, int is_inp_not_null);
int					compare_stock(lsi *d, stats statf, char *name, char *o);
char				*getstat(struct stat statf, char *str, long int *lengths, char *opt);
char				*mknam(char *s1, char *s2);

#endif
