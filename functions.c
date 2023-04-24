int print_char(va_list args)
{
    char c = va_arg(args, int);

    write(STDOUT_FILENO, &c, 1);
    return 1;
}
int print_str(va_list args)
{
    const char* s = va_arg(args, const char*);
    int len = strlen(s);

    write(STDOUT_FILENO, str, len);
    return len;
}

int print_int(va_list args)
{
    int n = va_arg(args, int);
    char buffer[16];
    int i, count = 0;

	if (list == NULL)
		return -1;
    if (n < 0) {
	    write(STDOUT_FILENO, '-', 1);
        n = -n;
	count++;
    }
    for (i = 0; i < n; i++)
    {
	buffer[i++] = '0' + (n % 10);
        n /= 10;

    }
    while (i > 0)
    {
	    write(STDOUT_FILENO, buffer[--i], 1);
		    count++;
    }
    return count;
}

