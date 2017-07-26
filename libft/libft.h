/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:49:03 by vboivin           #+#    #+#             */
/*   Updated: 2017/07/26 16:49:01 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memccpy(void *dest, const void *src, \
						int tocheck, size_t amnt);
void				*ft_memchr(const void *str, int tocheck, size_t limit);
int					ft_memcmp(const void *stri1, const void \
						*stri2, size_t tocomp);
void				*ft_memcpy(void *dest, const void *src, size_t amnt);
void				*ft_memmove(void *dest, const void *src, size_t amnt);
void				*ft_memset(void *str, int chr, size_t bytes_to_set);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*free_join(char *s1, char *s2);
char				*ft_realloc(char *inp, int qty);

char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t limit);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *str, int chr);
int					strchr_int(char *input, int char_to_find);
char				*ft_strrchr(const char *str, int chr);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, \
						const char *str2, size_t tocomp);
char				*ft_strncpy(char *dest, const char *src, size_t limit);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *str);
size_t				ft_strlen(const char *str);
char				*ft_strstr(const char *big, const char *lil);
char				*ft_strnstr(const char *big, const char *lil, size_t max);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putstrn(char *str, int n);
void				ft_putendl(char *str);
void				ft_putnbr(int nbr);
void				ft_putstr_cat(char *s1, char *s2, char *s3, int ret);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr_fd(int nb, int fd);

int					ft_atoi(const char *str);
char				*ft_itoa(int nb);
char				*ft_litoa(long int nb);
void				ft_bzero(void *str, size_t bytes_to_set);
int					ft_sqrt(int nb);
int					ft_lenchar(int start, char *str, int c);
void				ft_foreach(int *tab, int length, void (*f)(int));
void				ft_swap(int *a, int *b);
unsigned int		ft_intlen(int nb);
long int			ft_lintlen(long int nb);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *alst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**		GET NEXT LINE
*/

# define BUFF_SIZE 200

typedef struct		s_mem
{
	char			*mem;
	int				fd;
	struct s_mem	*next;
}					t_mem;

int					get_next_line(int fd, char **input);

#endif
