#include "tinyprintf.h"

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

size_t my_strlen(const char *s) {
  if (!s)
    return 0;

  size_t len = 0;
  while (*s != '\0') {
    s++;
    len += 1;
  }
  return len;
}

static unsigned ureverse(char *s, int max, unsigned number) {
  for (int i = max - 1; i >= 0; i--) {
    putchar(s[i]);
    number++;
  }
  return number;
}

static unsigned umy_itoa_base(int n, int base, unsigned number) {
  int i = 0;
  char s[1024];
  while (n) {
    unsigned digit = n % base;
    if (digit >= 10)
      s[i++] = 97 + (digit - 10);
    else
      s[i++] = 48 + digit;
    n /= base;
  }

  if (i == 0)
    s[i++] = '0';
  s[i] = '\0';

  return ureverse(s, i, number);
}
int reverse(char *s, int max, int number) {
  for (int i = max - 1; i >= 0; i--) {
    putchar(s[i]);
    number++;
  }
  return number;
}

int my_itoa_base(int n, int base, int number) {
  int value = n > 0 ? n : -n;
  int i = 0;
  char s[1024];
  while (value) {
    int digit = value % base;
    if (digit >= 10)
      s[i++] = 97 + (digit - 10);
    else
      s[i++] = 48 + digit;
    value /= base;
  }

  if (i == 0)
    s[i++] = '\0';

  if (n < 0 && base == 10)
    s[i++] = '-';
  s[i] = '\0';

  return reverse(s, i, number);
}

static int Scase(char *args, int number) {
  if (args == NULL) {
    putchar('(');
    putchar('n');
    putchar('u');
    putchar('l');
    putchar('l');
    putchar(')');
  } else {
    while (*args != '\0') {
      putchar(*args);
      args++;
      number++;
    }
  }
  return number;
}

int check_format(const char *format, size_t index, va_list ap, int number) {
  int i;
  unsigned u;
  char *args;
  switch (format[index]) {
  case '%':
    putchar('%');
    number++;
    break;
  case 'd':
    i = va_arg(ap, int);
    number = my_itoa_base(i, 10, number);
    break;
  case 'u':
    u = va_arg(ap, unsigned);
    number = umy_itoa_base(u, 10, number);
    break;
  case 's':
    args = va_arg(ap, char *);
    number = Scase(args, number);
    break;
  case 'c':
    i = va_arg(ap, int);
    number++;
    putchar(i);
    break;
  case 'o':
    i = va_arg(ap, unsigned);
    number = umy_itoa_base(i, 8, number);
    break;
  case 'x':
    i = va_arg(ap, unsigned);
    number = umy_itoa_base(i, 16, number);
    break;
  default:
    putchar('%');
    putchar(format[index]);
    number++;
    break;
  }
  return number;
}

int tinyprintf(const char *format, ...) {
  va_list ap;
  va_start(ap, format);

  size_t len = my_strlen(format);
  int number = 0;
  for (size_t i = 0; i < len; i++) {
    if (format[i] == '%' && i < len - 1)
      number = check_format(format, ++i, ap, number);
    else {
      putchar(format[i]);
      number++;
    }
  }
  va_end(ap);
  fflush(stdout);
  return number;
}
