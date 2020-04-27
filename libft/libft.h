/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:54:50 by jpelleti          #+#    #+#             */
/*   Updated: 2019/07/02 09:41:16 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

# define BUFF_SIZE 32
# define SPC 1 << 0
# define PLS 1 << 1
# define MNS 1 << 2
# define ZER 1 << 3
# define HST 1 << 4
# define LLL 1 << 5
# define LER 1 << 6
# define HHH 1 << 7
# define HER 1 << 8
# define LNG 1 << 9

typedef struct			s_finfo
{
	unsigned long long	mantisse:52;
	unsigned short		exponent:11;
	unsigned char		sign:1;
}						t_finfo;

typedef union			u_f_bit
{
	double			nb;
	t_finfo			s;
}						t_f_bit;

typedef struct			s_ptf
{
	int				i;
	int				w;
	int				opt;
	int				lrg_cmp;
	int				prec;
	char			c;
	char			field;
	int				arglen;
	float			f;
}						t_ptf;

typedef	struct			s_gnl
{
	int				fd;
	char			*s;
	struct s_gnl	*next;
}						t_gnl;

typedef	struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

int						get_next_line(int fd, char **line);
void					*ft_memset(void *b, int c, size_t len);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strdup(const char *src);
size_t					ft_strlen(const char *str);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
						size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t len);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s, const char *d);
char					*ft_strnstr(const char *s, const char *d, size_t len);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char*));
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char *s1, char *s2, int s_free);
char					*ft_strtrim(char const *s);
void					ft_iswap(int *a, int *b);
char					*ft_strcrev(char *str);
int						ft_intlen(long long n, int base);
int						ft_mesure_wor(const char *s, char sep);
int						ft_mesure_let(const char *s, char sep, int count);
char					**ft_cut_words(const char *s, char c, char **res);
char					**ft_strsplit(char const *s, char c);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
char					*ft_itoa(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(const char *s, int fd);
void					ft_putendl_fd(const char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_putnbr_base(long long n, int base, int opt);
int						ft_unsigned_nblen(unsigned long long n, int base);
void					ft_putnbr_unsigned_base(unsigned long long int n,
						unsigned int base, int opt);
unsigned long long		ft_power(unsigned long long nb, int pow);
int						ft_printf(const char *fmt, ...);
int						parser(const char *fmt, t_ptf *stt);
void					ft_bzero_stt(t_ptf *stt);
void					find_fct(t_ptf *stt, va_list ap);
void					place_field(t_ptf *stt, int i);
int						find_alph(t_ptf *stt, va_list ap);
void					write_count(const char *fmt, t_ptf *stt, int len);
void					find_num1(t_ptf *stt, va_list ap);
long long int			d_conv_misc(t_ptf *stt, va_list ap);
unsigned long long int	u_conv_misc(t_ptf *stt, va_list ap);
long long int			o_conv_misc(t_ptf *stt, va_list ap);
void					find_num2(t_ptf *stt, va_list ap);
unsigned long long int	hex_conv_misc(t_ptf *stt, va_list ap);
long double				f_conv_misc(t_ptf *stt, va_list ap);
void					ft_calc_ent(char *str, t_f_bit u);
void					ft_calc_dec(char *str, t_f_bit u);
void					ft_add_string(char *str, char *add);
void					ft_add_string_dec(char *str, char *add, int offset);
void					f_prec(char *str, int i);
char					*ft_str_power_dec(char *str, int pow);
char					*ft_str_power(char *str, int pow);
int						ft_offset(int i);
void					unblank_offset(char *str, int offset);
int						check_float(t_ptf *stt, t_f_bit u);
void					ft_print_float(t_ptf *stt, t_f_bit u, char *str, int i);
void					ft_write_sign(int n, t_ptf *stt);
int						ft_abs(int nb);

#endif
