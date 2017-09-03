/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hls.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 21:25:52 by vboivin           #+#    #+#             */
/*   Updated: 2017/09/03 23:00:46 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HLS_H
# define HLS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/param.h>
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
# define S 6
# define F 7
# define U 8
# define O 9
# define G 10
# define MAX_OPT 11

# define UID_LEN 1
# define GID_LEN 2
# define SIZ_TMP 0
# define SIZ_LEN 3
# define LNK_TMP 4
# define LNK_LEN 5
# define BLK_CNT 6
# define BLK_TMP 7
# define BLK_LEN 8
# define MAJ_TMP 9
# define MAJ_LEN 10
# define MIN_TMP 11
# define MIN_LEN 12
# define BLK_CHR 13

# define MAX_LENS 14
# define STRSIZE MAXPATHLEN

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

# define COMPARE(a, b) ((a < b) ? b : a)

/*
** TYPEDEFS
** ========
*/

typedef struct passwd	t_pass;
typedef struct group	t_grps;
typedef struct dirent	t_dirs;
typedef struct stat		t_stats;
typedef long int		t_lsi;

int						*sort(char *opt, struct dirent **inp,
						int qty, char *nam);
int						*sort_solo(char *opt, char **inp, int qty);
char					*get_opt(int ac, char **av);
void					list_dir(char *a, char *b, DIR *inp,
						int is_inp_not_null);
int						compare_stock(t_lsi *d, t_stats statf,
						char *name, char *o);
char					*getstat(struct stat statf, char *str,
						long int *lengths, char *opt);
char					*mknam(char *s1, char *s2);
long int				*len_infos(char *nam, t_dirs **fil, int qty, char *o);
void					put_total(long int blk_siz);
char					*link_symlink(char *path_nam);
int						*printd(struct dirent **file, int qty,
						char *opt, char *nam);
struct dirent			**f_ilter(char *inp);
void					append_blk(t_stats statf, char *str, t_lsi *lengths);
char					*translate_mod(int st_mode, char *str);
void					append_links(char *str, t_stats statf, t_lsi *lengths);
void					append_uid_gid(char *str, t_stats statf,
						char *opt, long int *lns);
void					append_size(char *str, t_stats statf,
						long int *lengths);
void					append_time(char *str, t_stats statf, char *opt);
void					lengths_solo(long int *lengths, char **tabs,
							char *options);
void					sort_params(char **sort, int ac, char *opt);
void					append_major_minor(t_stats statf,
							t_lsi *lengths, char *str);

#endif
