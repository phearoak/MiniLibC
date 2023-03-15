/*
** EPITECH PROJECT, 2022
** MINILIBC
** File description:
** main
*/

#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <criterion/criterion.h>

Test(exo_00, test_main_n1)
{
    void *handle;
    size_t  (*my_strlen)(char *);

    handle = dlopen("../libasm.so", RTLD_LAZY);
    *(void **)(&my_strlen)      = dlsym(handle, "strlen");

    dlerror();
    cr_assert_eq(my_strlen(""),             strlen(""));
    cr_assert_eq(my_strlen("Hello"),        strlen("Hello"));
    cr_assert_eq(my_strlen("World!"),       strlen("World!"));
    cr_assert_eq(my_strlen("Hello World!"), strlen("Hello World!"));
}

Test(exo_00, test_main_n2)
{
    void *handle;
    char*   (*my_strchr)(char *, char);
    handle = dlopen("../libasm.so", RTLD_LAZY);
    *(void **)(&my_strchr)      = dlsym(handle, "strchr");
    dlerror();

    cr_assert_str_eq(my_strchr("Hello World!", 'o'),    strchr("Hello World!", 'o'));
    cr_assert_str_eq(my_strchr("Hello World!", '!'),    strchr("Hello World!", '!'));
    cr_assert_str_eq(my_strchr("Hello World!", 'H'),    strchr("Hello World!", 'H'));
    cr_assert_str_eq(my_strchr("Hello World!", ' '),    strchr("Hello World!", ' '));
    cr_assert_str_eq(my_strchr("Hello World!", '\0'),   strchr("Hello World!", '\0'));
}

Test(exo_00, test_main_n3)
{
    void *handle;
    char*   (*my_strrchr)(char *, char);
    handle = dlopen("../libasm.so", RTLD_LAZY);
    *(void **)(&my_strrchr)      = dlsym(handle, "strrchr");
    dlerror();

    cr_assert_str_eq(my_strrchr("Hello World!", 'o'),   strrchr("Hello World!", 'o'));
    cr_assert_str_eq(my_strrchr("Hello World!", '!'),   strrchr("Hello World!", '!'));
    cr_assert_str_eq(my_strrchr("Hello World!o", 'o'),  strrchr("Hello World!o", 'o'));
    cr_assert_str_eq(my_strrchr("Hello World!o", '\0'), strrchr("Hello World!o", '\0'));
}

Test(exo_00, test_main_n4)
{
    void *handle;
    int     (*my_strcmp)(char *, char *);
    handle = dlopen("../libasm.so", RTLD_LAZY);
    *(void **)(&my_strcmp)      = dlsym(handle, "strcmp");
    dlerror();

    cr_assert_eq(my_strcmp("Hello World!", "o") <= 0,               strcmp("Hello World!", "o") <= 0);
    cr_assert_eq(my_strcmp("Hello World!", "hello") <= 0,           strcmp("Hello World!", "hello") <= 0);
    cr_assert_eq(my_strcmp("Hello World!", "Hello World!") <= 0,    strcmp("Hello World!", "Hello World!") <= 0);
    cr_assert_eq(my_strcmp("Hello World!", "Hello World!!") <= 0,   strcmp("Hello World!", "Hello World!!") <= 0);
}

Test(exo_00, test_main_n5)
{
    void *handle;
    int     (*my_strncmp)(char *, char *, int);
    handle = dlopen("../libasm.so", RTLD_LAZY);
    *(void **)(&my_strncmp)      = dlsym(handle, "strncmp");
    dlerror();

    cr_assert_eq(my_strncmp("Hello World!", "o", 5),                strncmp("Hello World!", "o", 5));
    cr_assert_eq(my_strncmp("Hello World!", "Hello", 4),            strncmp("Hello World!", "Hello", 4));
    cr_assert_eq(my_strncmp("Hello World!", "Hello Wo", 7),         strncmp("Hello World!", "Hello Wo", 7));
    cr_assert_eq(my_strncmp("Hello World!", "Hello You", 7),        strncmp("Hello World!", "Hello You", 7));
    cr_assert_eq(my_strncmp("Hello World!", "Hello World!", 5),     strncmp("Hello World!", "Hello World!", 5));
    cr_assert_eq(my_strncmp("Hello World!", "Hello World!!", 5),    strncmp("Hello World!", "Hello World!!", 5));
}

Test(exo_00, test_main_n6)
{
    void *handle;
    int     (*my_strcasecmp)(char *, char *);
    handle = dlopen("../libasm.so", RTLD_LAZY);
    *(void **)(&my_strcasecmp)      = dlsym(handle, "strcasecmp");
    dlerror();

    cr_assert_eq(my_strcasecmp("hhh", "HHH") < 0,               strcasecmp("hhh", "HHH") < 0);
    cr_assert_eq(my_strcasecmp("hHh", "HhH") < 0,               strcasecmp("hHh", "HhH") < 0);
    cr_assert_eq(my_strcasecmp("Hello World!", "o") < 0,        strcasecmp("Hello World!", "o") < 0);
    cr_assert_eq(my_strcasecmp("Hello World!", "A") < 0,        strcasecmp("Hello World!", "A") < 0);
    cr_assert_eq(my_strcasecmp("o", "Hello World!") < 0,        strcasecmp("o", "Hello World!") < 0);
    cr_assert_eq(my_strcasecmp("A", "Hello World!") < 0,        strcasecmp("A", "Hello World!") < 0);
    cr_assert_eq(my_strcasecmp("Hello ", "Hello World!") < 0,   strcasecmp("Hello ", "Hello World!") < 0);
    cr_assert_eq(my_strcasecmp("Hello World!", "Hello ") < 0,   strcasecmp("Hello World!", "Hello ") < 0);
}

Test(exo_00, test_main_n7)
{
    void *handle;
    char*   (*my_strpbrk)(char *, char *);
    handle = dlopen("../libasm.so", RTLD_LAZY);
    *(void **)(&my_strpbrk)      = dlsym(handle, "strpbrk");
    dlerror();

    cr_assert_str_eq(my_strpbrk("Hello World!", "o"),       strpbrk("Hello World!", "o"));
    cr_assert_str_eq(my_strpbrk("o", "Hello World!"),       strpbrk("o", "Hello World!"));
    cr_assert_str_eq(my_strpbrk("Hello ", "Hello World!"),  strpbrk("Hello ", "Hello World!"));
    cr_assert_str_eq(my_strpbrk("Hello World!", "Hello "),  strpbrk("Hello World!", "Hello "));
}

Test(exo_00, test_main_n8)
{
    void *handle;
    size_t (*my_strcspn)(char *, char *);
    handle = dlopen("../libasm.so", RTLD_LAZY);
    *(void **)(&my_strcspn)      = dlsym(handle, "strcspn");
    dlerror();

    cr_assert_eq(my_strcspn("Hello World!", "\0"),      strcspn("Hello World!", "\0"));
    cr_assert_eq(my_strcspn("Hello World!", "ZSF!l"),   strcspn("Hello World!", "ZSF!l"));
    cr_assert_eq(my_strcspn("Hello World!", "Hello "),  strcspn("Hello World!", "Hello "));
    cr_assert_eq(my_strcspn("Hello ", "Hello World!"),  strcspn("Hello ", "Hello World!"));
}

Test(exo_00, test_main_n9)
{
    void *handle;
    char *(*my_strstr)(char *, char *);
    handle = dlopen("../libasm.so", RTLD_LAZY);
    *(void **)(&my_strstr)      = dlsym(handle, "strstr");
    dlerror();

    cr_assert_str_eq(my_strstr("\0", "\0"),                     strstr("\0", "\0"));
    cr_assert_str_eq(my_strstr("\0azerty", "\0"),               strstr("\0azerty", "\0"));
    cr_assert_str_eq(my_strstr("\0", "\0azer"),                 strstr("\0", "\0azer"));
    cr_assert_str_eq(my_strstr("\0azer", "\0azer"),             strstr("\0azer", "\0azer"));
    cr_assert_str_eq(my_strstr("Hello World!", " "),            strstr("Hello World!", " "));
    cr_assert_str_eq(my_strstr("Hello World!", "!"),            strstr("Hello World!", "!"));
    cr_assert_str_eq(my_strstr("Hello World!", "\0"),           strstr("Hello World!", "\0"));
    cr_assert_str_eq(my_strstr("Hello World!", "lo "),          strstr("Hello World!", "lo "));
    cr_assert_str_eq(my_strstr("Hello World!", "Hello "),       strstr("Hello World!", "Hello "));
    cr_assert_str_eq(my_strstr("Hello World!", "ello World"),   strstr("Hello World!", "ello World"));
    cr_assert_str_eq(my_strstr("Hello World!", "Hello World!"), strstr("Hello World!", "Hello World!"));
}

Test(exo_00, test_main_n10)
{
    void *handle;
    void *(*my_memset)(char *, int, size_t);
    handle = dlopen("../libasm.so", RTLD_LAZY);
    *(void **)(&my_memset)      = dlsym(handle, "memset");
    dlerror();

    char *my_1 = malloc(sizeof(char) * 10);
    char *lib_1 = malloc(sizeof(char) * 10);
    char *my_2 = malloc(sizeof(char) * 10);
    char *lib_2 = malloc(sizeof(char) * 10);
    char *my_3 = malloc(sizeof(char) * 10);
    char *lib_3 = malloc(sizeof(char) * 10);
    char *my_4 = malloc(sizeof(char) * 10);
    char *lib_4 = malloc(sizeof(char) * 10);
    char *my_5 = malloc(sizeof(char) * 10);
    char *lib_5 = malloc(sizeof(char) * 10);

    my_memset(my_1, 'a', 10);
    my_memset(my_2, 'b', 10);
    my_memset(my_3, 'c', 10);
    my_memset(my_4, 'd', 10);
    my_memset(my_5, 'e', 10);
    memset(lib_1, 'a', 10);
    memset(lib_2, 'b', 10);
    memset(lib_3, 'c', 10);
    memset(lib_4, 'd', 10);
    memset(lib_5, 'e', 10);

    cr_assert_str_eq(my_1, lib_1);
    cr_assert_str_eq(my_2, lib_2);
    cr_assert_str_eq(my_3, lib_3);
    cr_assert_str_eq(my_4, lib_4);
    cr_assert_str_eq(my_5, lib_5);

    my_memset(my_1, 'z', 3);
    my_memset(my_2, 'y', 6);
    my_memset(my_3, 'x', 1);
    my_memset(my_4, 'w', 9);
    my_memset(my_5, 'v', 4);
    memset(lib_1, 'z', 3);
    memset(lib_2, 'y', 6);
    memset(lib_3, 'x', 1);
    memset(lib_4, 'w', 9);
    memset(lib_5, 'v', 4);

    cr_assert_str_eq(my_1, lib_1);
    cr_assert_str_eq(my_2, lib_2);
    cr_assert_str_eq(my_3, lib_3);
    cr_assert_str_eq(my_4, lib_4);
    cr_assert_str_eq(my_5, lib_5);
}

Test(exo_00, test_main_n11)
{
    void *handle;
    void *(*my_memcpy)(char *, char *, size_t);
    handle = dlopen("../libasm.so", RTLD_LAZY);
    *(void **)(&my_memcpy)      = dlsym(handle, "memcpy");
    dlerror();

    char *memcpy_src_my = malloc(sizeof(char) * 13);
    char *memcpy_dest_my = malloc(sizeof(char) * 13);
    char *memcpy_src_lib = malloc(sizeof(char) * 13);
    char *memcpy_dest_lib = malloc(sizeof(char) * 13);

    for (int i = 0; i < 13; i++) memcpy_src_my[i] = 'a';
    for (int i = 0; i < 13; i++) memcpy_dest_my[i] = 'b';
    for (int i = 0; i < 13; i++) memcpy_src_lib[i] = 'a';
    for (int i = 0; i < 13; i++) memcpy_dest_lib[i] = 'b';

    my_memcpy(memcpy_src_my, memcpy_dest_my, 5);
    memcpy(memcpy_src_lib, memcpy_dest_lib, 5);
    cr_assert_str_eq(memcpy_src_my, memcpy_src_lib);
}