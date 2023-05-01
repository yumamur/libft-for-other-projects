/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:20:44 by yumamur           #+#    #+#             */
/*   Updated: 2023/04/30 23:46:19 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/* STRUCTURE */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/* IS */
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);

/* CONVERTION */
int			ft_atoi(const char *str);
char		*ft_itoa(int n);

/* MEMORY */
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_bzero(void *str, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *str, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memset(void *str, int c, size_t n);

/* STRING */
size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strtrim(const char *s1, const char *set);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
void		ft_striteri(char *str, void (*f)(unsigned int, char*));
char		*ft_strmapi(const char *str, char (*f)(unsigned int, char));

/* ALLOCATION */
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_substr(const char *str, unsigned int start, size_t len);
char		**ft_split(const char *str, char c);

/* PRINT */
void		ft_putchar_fd(char c, int fd);
void		ft_putstr(char *str);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *str, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putmem_fd(int fd, size_t n, void *mem, const char *sep);

/* LIST */
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *newnode);
void		ft_lstadd_back(t_list **lst, t_list *newnode);
void		ft_lstadd_insert(t_list **lst, t_list *newnode);
t_list		*ft_lstfirst(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstconnect(t_list *node);
void		ft_lstdelone(t_list *node, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *node, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* UTILS */
const char	*ft_getenv(const char *envp[], const char *name);
#endif
