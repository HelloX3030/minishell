/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:25:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/01/16 16:28:41 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_isprint(int c);
char				*ft_itoa(int n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strchr(const char *s, int c);
void				ft_putstr_fd(char *s, int fd);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalnum(int c);
size_t				ft_strlen(const char *s);
void				ft_putchar_fd(char c, int fd);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strdup(const char *s);
int					ft_atoi(const char *str);
char				*ft_strtrim(char const *s1, char const *set);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_tolower(int c);
void				ft_bzero(void *s, size_t n);
int					ft_toupper(int c);
int					ft_isdigit(int c);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putendl_fd(char *s, int fd);
void				*ft_calloc(size_t nmemb, size_t size);
char				**ft_split(char const *s, char c);
int					ft_isalpha(int c);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_isascii(int c);
void				*ft_memchr(const void *s, int c, size_t n);

// Bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_lstsize(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);

// ft_printf
int					ft_printf(const char *s, ...);
char				*get_next_line(int fd);

// custom functions
void				ft_printstr_fd(char *str, int fd);
bool				ft_aisi(char *str);
bool				ft_aish(char *str);
uint32_t			ft_atocolor(const char *str);
unsigned int		ft_htoi(char *str);
bool				ft_in_charset(char c, char *set);
void				ft_free_strs(char **strs);
void				ft_print_strs(char **str, int insertion);
void				ft_free_ints(int **ints, int width);
int					ft_abs(int n);
int					ft_max(int a, int b);
int					ft_abs_max(int a, int b);
void				ft_remove_c(char *str, char *set);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_write_byte(char c);
void				ft_write_bytes(char *bytes, int size);

#endif
