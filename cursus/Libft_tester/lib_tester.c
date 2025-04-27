/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulivar <tkulivar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-16 14:23:54 by tkulivar          #+#    #+#             */
/*   Updated: 2025-04-16 14:23:54 by tkulivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <bsd/string.h>
#include <stdlib.h>
#include <limits.h>

char *chk(int res) {
    if (res)
        return "\033[0;32m✓\033[0;37m";
    return "\033[0;31m✗\033[0;37m";
}

char *check_all(const int *results, int count) {
    static char result[256];
    result[0] = '\0';

    for (int i = 0; i < count; i++) {
        strcat(result, chk(results[i]));
    }

    return result;
}

static char ft_strmapi_toupper(unsigned int i, char c)
{
    return ft_toupper(c);
}
static char ft_strmapi_tolower(unsigned int i, char c)
{
    return ft_tolower(c);
}
static char ft_strmapi_alternating(unsigned int i, char c)
{
    if (i % 2 == 0)
        return ft_toupper(c);
    return ft_tolower(c);
    
}
static void ft_striteri_toupper(unsigned int i, char *str)
{
    *str = ft_toupper(*str);
}
static void ft_striteri_tolower(unsigned int i, char *str)
{
    *str = ft_tolower(*str);
}
static void ft_striteri_alternating(unsigned int i, char *str)
{
    if (i % 2 == 0)
        *str = ft_toupper(*str);
    else
        *str = ft_tolower(*str);
}

int main(void) {
    int results[] = {
        ft_isalpha('a') == 1,
        ft_isalpha('A') == 1,
        ft_isalpha('3') == 0,
        ft_isalpha('\n') == 0,
        ft_isdigit(300) == 0,
    };

    printf("ft_isalpha: \t%s\n", check_all(results, sizeof(results) / sizeof(results[0])));
    
	int results2[] = {
        ft_isdigit('a') == 0,
        ft_isdigit('A') == 0,
        ft_isdigit('3') == 1,
        ft_isdigit('\n') == 0,
        ft_isdigit(300) == 0,
    };

    printf("ft_isdigit: \t%s\n", check_all(results2, sizeof(results2) / sizeof(results2[0])));
    
	int results3[] = {
        ft_isalnum('a') == 1,
        ft_isalnum('A') == 1,
        ft_isalnum('3') == 1,
        ft_isalnum('\n') == 0,
        ft_isalnum(300) == 0,
    };

    printf("ft_isalnum: \t%s\n", check_all(results3, sizeof(results3) / sizeof(results3[0])));
    
	int results4[] = {
        ft_isascii('a') == 1,
        ft_isascii('A') == 1,
        ft_isascii('3') == 1,
        ft_isascii('\n') == 1,
        ft_isascii(300) == 0,
    };

    printf("ft_isascii: \t%s\n", check_all(results4, sizeof(results4) / sizeof(results4[0])));
    
	int results5[] = {
        ft_isprint('a') == 1,
        ft_isprint('A') == 1,
        ft_isprint('3') == 1,
        ft_isprint('\n') == 0,
        ft_isprint(300) == 0,
    };

    printf("ft_isprint: \t%s\n", check_all(results5, sizeof(results5) / sizeof(results5[0])));

    int results15[] = {
        ft_strlen("-1") == 2,
        ft_strlen("") == 0,
        ft_strlen("\302") == 1,
    };
    printf("ft_strlen: \t%s\n", check_all(results15, sizeof(results15) / sizeof(results15[0])));

    char buf1[20], buf2[20];
    int memset_results[] = {
        // Basic functionality test
        ({ char buf1[10] = {0}; char buf2[10] = {0}; 
        ft_memset(buf1, 'A', 5) == buf1 && memset(buf2, 'A', 5) == buf2 && 
        memcmp(buf1, buf2, 10) == 0; }),
        
        // Test with zero length
        ({ char buf1[10] = {0}; char buf2[10] = {0}; 
        ft_memset(buf1, 'A', 0) == buf1 && memset(buf2, 'A', 0) == buf2 && 
        memcmp(buf1, buf2, 10) == 0; }),
        
        // Test with full buffer
        ({ char buf1[10] = {0}; char buf2[10] = {0}; 
        ft_memset(buf1, 'B', 10) == buf1 && memset(buf2, 'B', 10) == buf2 && 
        memcmp(buf1, buf2, 10) == 0; }),
        
        // Test with non-ASCII value
        ({ char buf1[10] = {0}; char buf2[10] = {0}; 
        ft_memset(buf1, 128, 5) == buf1 && memset(buf2, 128, 5) == buf2 && 
        memcmp(buf1, buf2, 10) == 0; })
    };
    printf("ft_memset: \t%s\n", check_all(memset_results, sizeof(memset_results) / sizeof(memset_results[0])));

    int bzero_results[] = {
        ({ char buf1[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}; 
        char buf2[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
        ft_bzero(buf1, 5); bzero(buf2, 5);
        memcmp(buf1, buf2, 10) == 0; }),
        
        ({ char buf1[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}; 
        char buf2[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
        ft_bzero(buf1, 0); bzero(buf2, 0);
        memcmp(buf1, buf2, 10) == 0; }),
        
        ({ char buf1[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}; 
        char buf2[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
        ft_bzero(buf1, 10); bzero(buf2, 10);
        memcmp(buf1, buf2, 10) == 0; })
    };
    printf("ft_bzero: \t%s\n", check_all(bzero_results, sizeof(bzero_results) / sizeof(bzero_results[0])));

    int memcpy_results[] = {
        ({ char src[10] = "abcdefghi"; char dest1[10] = {0}; char dest2[10] = {0}; 
        ft_memcpy(dest1, src, 5) == dest1 && memcpy(dest2, src, 5) == dest2 && 
        memcmp(dest1, dest2, 10) == 0; }),
        
        ({ char src[10] = "abcdefghi"; char dest1[10] = {0}; char dest2[10] = {0}; 
        ft_memcpy(dest1, src, 0) == dest1 && memcpy(dest2, src, 0) == dest2 && 
        memcmp(dest1, dest2, 10) == 0; }),
        
        ({ char src[10] = "abcdefghi"; char dest1[10] = {0}; char dest2[10] = {0}; 
        ft_memcpy(dest1, src, 10) == dest1 && memcpy(dest2, src, 10) == dest2 && 
        memcmp(dest1, dest2, 10) == 0; }),

        ({ unsigned char src[10] = {128, 129, 130, 131, 132, 133, 134, 135, 136, 137}; 
        unsigned char dest1[10] = {0}; unsigned char dest2[10] = {0}; 
        ft_memcpy(dest1, src, 10) == dest1 && memcpy(dest2, src, 10) == dest2 && 
        memcmp(dest1, dest2, 10) == 0; })
    };
    printf("ft_memcpy: \t%s\n", check_all(memcpy_results, sizeof(memcpy_results) / sizeof(memcpy_results[0])));

    int memmove_results[] = {
        ({ char src[10] = "abcdefghi"; char dest1[10] = {0}; char dest2[10] = {0}; 
        ft_memmove(dest1, src, 5) == dest1 && memmove(dest2, src, 5) == dest2 && 
        memcmp(dest1, dest2, 10) == 0; }),
        
        ({ char src[10] = "abcdefghi"; char dest1[10] = {0}; char dest2[10] = {0}; 
        ft_memmove(dest1, src, 0) == dest1 && memmove(dest2, src, 0) == dest2 && 
        memcmp(dest1, dest2, 10) == 0; }),
        
        ({ char src[10] = "abcdefghi"; char dest1[10] = {0}; char dest2[10] = {0}; 
        ft_memmove(dest1, src, 10) == dest1 && memmove(dest2, src, 10) == dest2 && 
        memcmp(dest1, dest2, 10) == 0; }),

        ({ char buf1[20] = "abcdefghijklmnopqrs"; char buf2[20] = "abcdefghijklmnopqrs"; 
        ft_memmove(buf1, buf1 + 5, 10); memmove(buf2, buf2 + 5, 10); 
        memcmp(buf1, buf2, 20) == 0; }),

        ({ char buf1[20] = "abcdefghijklmnopqrs"; char buf2[20] = "abcdefghijklmnopqrs"; 
        ft_memmove(buf1 + 5, buf1, 10); memmove(buf2 + 5, buf2, 10); 
        memcmp(buf1, buf2, 20) == 0; })
    };
    printf("ft_memmove: \t%s\n", check_all(memmove_results, sizeof(memmove_results) / sizeof(memmove_results[0])));

    char buf3[20], buf4[20];
    int results16[] = {
        ({ memset(buf3, 0, sizeof(buf3)); memset(buf4, 0, sizeof(buf4)); 
           ft_strlcpy(buf3, "lorem ipsum dolor sit amet", 5) == strlcpy(buf4, "lorem ipsum dolor sit amet", 5) &&
           memcmp(buf3, buf4, 5) == 0; 
        }),
        ({ memset(buf3, 0, sizeof(buf3)); memset(buf4, 0, sizeof(buf4)); 
           ft_strlcpy(buf3, "lorem ipsum dolor sit amet", sizeof(buf3)) == strlcpy(buf4, "lorem ipsum dolor sit amet", sizeof(buf4)) &&
           strcmp(buf3, buf4) == 0; 
        }),
        ({ memset(buf3, 0, sizeof(buf3)); memset(buf4, 0, sizeof(buf4)); 
           ft_strlcpy(buf3, "short", 3) == strlcpy(buf4, "short", 3) &&
           memcmp(buf3, buf4, 3) == 0; 
        }),
        ({ memset(buf3, 0, sizeof(buf3)); memset(buf4, 0, sizeof(buf4)); 
           ft_strlcpy(buf3, "", sizeof(buf3)) == strlcpy(buf4, "", sizeof(buf4)) &&
           strcmp(buf3, buf4) == 0; 
        })
    };
    printf("ft_strlcpy: \t%s\n", check_all(results16, sizeof(results16) / sizeof(results16[0])));

    int results17[] = {
        ({ strcpy(buf3, "rrrrr"); strcpy(buf4, "rrrrr"); 
           ft_strlcat(buf3, "lorem ipsum", 12) == strlcat(buf4, "lorem ipsum", 12) &&
           strcmp(buf3, buf4) == 0; 
        }),
        ({ strcpy(buf3, "a"); strcpy(buf4, "a"); 
           ft_strlcat(buf3, "lorem", sizeof(buf3)) == strlcat(buf4, "lorem", sizeof(buf4)) &&
           strcmp(buf3, buf4) == 0; 
        }),

        ({ strcpy(buf3, "test"); strcpy(buf4, "test"); 
           ft_strlcat(buf3, "", sizeof(buf3)) == strlcat(buf4, "", sizeof(buf4)) &&
           strcmp(buf3, buf4) == 0; 
        }),
        ({ strcpy(buf3, ""); strcpy(buf4, ""); 
           ft_strlcat(buf3, "data", sizeof(buf3)) == strlcat(buf4, "data", sizeof(buf4)) &&
           strcmp(buf3, buf4) == 0; 
        })
    };
    printf("ft_strlcat: \t%s\n", check_all(results17, sizeof(results17) / sizeof(results17[0])));

	int results6[] = {
        ft_tolower('c') == 'c',
        ft_tolower('C') == 'c',
        ft_tolower('1') == '1',
        ft_tolower('\302') == '\302',
    };

    printf("ft_tolower: \t%s\n", check_all(results6, sizeof(results6) / sizeof(results6[0])));

	int results7[] = {
        ft_toupper('c') == 'C',
        ft_toupper('C') == 'C',
        ft_toupper('1') == '1',
        ft_toupper('\302') == '\302',
    };

    printf("ft_toupper: \t%s\n", check_all(results7, sizeof(results7) / sizeof(results7[0])));

    char    *haystack1;
    char    *haystack2;
    haystack1 = "tymur lama\0";
    haystack2 = "\0";
	int results8[] = {
        ft_strchr(haystack1, 'm') == (haystack1 + 2),
        ft_strchr(haystack1, 'x') == NULL,
        ft_strchr(haystack1, '\0') == (haystack1 + 10),
        ft_strchr(haystack2, '\0') == haystack2,
    };
    printf("ft_strchr: \t%s\n", check_all(results8, sizeof(results8) / sizeof(results8[0])));

	int results9[] = {
        ft_strrchr(haystack1, 'm') == (haystack1 + 8),
        ft_strrchr(haystack1, 'x') == NULL,
        ft_strrchr(haystack1, '\0') == (haystack1 + 10),
        ft_strrchr(haystack2, '\0') == haystack2,
    };
    printf("ft_strrchr: \t%s\n", check_all(results9, sizeof(results9) / sizeof(results9[0])));

    int results10[] = {
        ft_strncmp("hello", "hello", 13) == 0,
        ft_strncmp("hello\0", "hello", 13) == strncmp("hello\0", "hello", 13),
        ft_strncmp("hello", "hello\0", 13) == strncmp("hello", "hello\0", 13),
        ft_strncmp("hello", "hello\0", 5) == 0,
    };
    printf("ft_strncmp: \t%s\n", check_all(results10, sizeof(results10) / sizeof(results10[0])));

    char    *haystack3;
    char    *haystack4;
    haystack3 = "Hello World!";
    haystack4 = "ababacus";
    int results11[] = {
        ft_strnstr(haystack3, "Hello", 15) == haystack3,
        ft_strnstr(haystack3, "World", 15) == (haystack3 + 6),
        ft_strnstr(haystack3, "World", 11) == (haystack3 + 6),
        ft_strnstr(haystack3, "World", 5) == NULL,
        ft_strnstr(haystack3, "World", 6) == NULL,
        ft_strnstr(haystack3, "World", 10) == NULL,
        ft_strnstr(haystack4, "abacus", 10) == (haystack4 + 2),
    };
    printf("ft_strnstr: \t%s\n", check_all(results11, sizeof(results11) / sizeof(results11[0])));

    int results12[] = {
        ft_atoi("-1") == -1,
        ft_atoi("1") == 1,
        ft_atoi("0") == 0,
        ft_atoi("100") == 100,
        ft_atoi("-100") == -100,
        ft_atoi("+123") == 123,
        ft_atoi("7633125") == 7633125,
        ft_atoi("   123") == 123,
        ft_atoi(" \t\n\r\v\f 123") == 123,
        ft_atoi(" \t\n\r\v\f -123") == -123,
        ft_atoi("   123asdasf") == 123,
        ft_atoi("   123") == 123,
        ft_atoi("   123") == 123,
        ft_atoi("2147483647") == INT_MAX,
        ft_atoi("-2147483648") == INT_MIN,
        ft_atoi("  \n-2147483648") == INT_MIN,
    };
    printf("ft_atoi: \t%s\n", check_all(results12, sizeof(results12) / sizeof(results12[0])));

    char    *haystack5;
    haystack5 = "Hello World!";
    int results13[] = {
        ft_substr(NULL, 1, 15) == NULL,
        strcmp(ft_substr(haystack5, 0, 15), haystack5) == 0, //0 dif
        strcmp(ft_substr(haystack5, 0, 1), "H") == 0,
        strcmp(ft_substr(haystack5, 0, 5), "Hello") == 0,
        strcmp(ft_substr(haystack5, 6, 5), "World") == 0,
        strcmp(ft_substr(haystack5, 6, 10), "World!") == 0,
        strcmp(ft_substr(haystack5, 0, 0), "") == 0,
        strcmp(ft_substr(haystack5, 20, 0), "") == 0,
        strcmp(ft_substr(haystack5, 20, 5), "") == 0,
    };
    printf("ft_substr: \t%s\n", check_all(results13, sizeof(results13) / sizeof(results13[0])));

    char    *str6;
    char    *str7;
    char    *str8;
    str6 = "Hello";
    str7 = "World!";
    str8 = "Hello ";
    int results14[] = {
        strcmp(ft_strjoin(str6, str7), "HelloWorld!") == 0, //0 dif
        strcmp(ft_strjoin(str8, str7), "Hello World!") == 0,
        strcmp(ft_strjoin("", str7), "World!") == 0,
        strcmp(ft_strjoin(str6, ""), "Hello") == 0,
        strcmp(ft_strjoin(NULL, str7), "World!") == 0, //Just for me, not needed
        strcmp(ft_strjoin(str6, NULL), "Hello") == 0, //Just for me, not needed
    };
    printf("ft_strjoin: \t%s\n", check_all(results14, sizeof(results14) / sizeof(results14[0])));

    int results18[] = {
        strcmp(ft_strtrim("abaHello World", "ab"), "Hello World") == 0, //0 dif
        strcmp(ft_strtrim("Hello Worldbbb", "ab"), "Hello World") == 0, 
        strcmp(ft_strtrim("abaHello Worldbbb", "ab"), "Hello World") == 0, 
        strcmp(ft_strtrim("Hello World", "ab"), "Hello World") == 0,
        strcmp(ft_strtrim("ababHelloababWorldabab", "ab"), "HelloababWorld") == 0,
        strcmp(ft_strtrim("\302\n\302Hello World", "\302\n"), "Hello World") == 0,
    };
    printf("ft_strtrim: \t%s\n", check_all(results18, sizeof(results18) / sizeof(results18[0])));

    printf("ft_split: \t\033[0;34mNo Auto Test (Check Manually)\033[0;37m\n");
    // ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
    // ft_split("       lorem   ipsum     dolor   sit    amet,    consectetur   adipiscing    elit. Sed non   risus. Suspendisse    ", ' ');
    // ft_split("lorem   ipsum     dolor   sit    amet,    consectetur   adipiscing    elit. Sed non   risus. Suspendisse    ", ' ');
	// ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
	// ft_split("Hello!", ' ');

    // char **split = ft_split("hello!", ' ');
	// for(int i = 0; split[i]; i++){
	// 	printf("%s\n", split[i]);
	// 	free(split[i]);
	// }
	// free(split);

    int results19[] = {
        strcmp(ft_itoa(-1), "-1") == 0, //0 dif
        strcmp(ft_itoa(0), "0") == 0,
        strcmp(ft_itoa(1), "1") == 0,
        strcmp(ft_itoa(+1), "1") == 0,
        strcmp(ft_itoa(10), "10") == 0,
        strcmp(ft_itoa(1324324), "1324324") == 0,
        strcmp(ft_itoa(-1324324), "-1324324") == 0,
        strcmp(ft_itoa(INT_MAX), "2147483647") == 0,
        strcmp(ft_itoa(INT_MIN), "-2147483648") == 0,
    };
    printf("ft_itoa: \t%s\n", check_all(results19, sizeof(results19) / sizeof(results19[0])));

    int results20[] = {
        strcmp(ft_strmapi("Hello World!", ft_strmapi_toupper), "HELLO WORLD!") == 0,
        strcmp(ft_strmapi("Hello World!", ft_strmapi_tolower), "hello world!") == 0,
        strcmp(ft_strmapi("Hello World!", ft_strmapi_alternating), "HeLlO WoRlD!") == 0,
    };
    printf("ft_strmapi: \t%s\n", check_all(results20, sizeof(results20) / sizeof(results20[0])));

    char *str9;
    str9 = calloc(30, sizeof(char));
    int results21[] = {
        ({
            memset(str9, '\0', strlen(str9));
            strcpy(str9, "Hello World!");
            ft_striteri(str9, ft_striteri_toupper);
            printf("upper %s\n", str9);
            strcmp(str9, "HELLO WORLD!") == 0;
        }),
        ({
            memset(str9, '\0', strlen(str9));
            strcpy(str9, "Hello World!");
            ft_striteri(str9, ft_striteri_tolower);
            printf("lower %s\n", str9);
            strcmp(str9, "hello world!") == 0;
        }),
        ({
            memset(str9, '\0', strlen(str9));
            strcpy(str9, "Hello World!");
            ft_striteri(str9, ft_striteri_alternating);
            printf("alt %s\n", str9);
            strcmp(str9, "HeLlO WoRlD!") == 0;
        }),
    };
    printf("ft_striteri: \t%s\n", check_all(results21, sizeof(results21) / sizeof(results21[0])));
}
