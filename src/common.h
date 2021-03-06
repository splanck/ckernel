// common.h -- Defines typedefs and some global functions.

#ifndef COMMON_H
#define COMMON_H

// Some nice typedefs, to standardise sizes across platforms.
// These typedefs are written for 32-bit X86.
typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;
typedef          int   size_t;

void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);

void memcpy(u8int *dest, const u8int *src, u32int len);
void memset(void *dest, u8int val, u32int len);
void *memmove(void* dest, const void* src, unsigned int n);
int memcmp(const char *cs, const char *ct, size_t n);
int strcmp(char *str1, char *str2);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);

#define PANIC(msg) panic(msg, __FILE__, __LINE__);
#define ASSERT(b) ((b) ? (void)0 : panic_assert(__FILE__, __LINE__, #b))

extern void panic(const char *message, const char *file, u32int line);
extern void panic_assert(const char *file, u32int line, const char *desc);

#endif // COMMON_H
