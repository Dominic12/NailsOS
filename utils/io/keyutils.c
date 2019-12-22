int getdelim(char **lineptr, int *n, int delim) {
    char *cur_pos, *new_lineptr;
    int new_lineptr_len;
    int c;


    cur_pos = *lineptr;
    for (;;) {
        c = get_ascii_char(get_input_keycode());

        print_char(c);
            new_lineptr_len = *n * 2;
            cur_pos = new_lineptr + (cur_pos - *lineptr);
            *lineptr = new_lineptr;
            *n = new_lineptr_len;
        

        *cur_pos++ = (char)c;

        if (c == delim)
            break;
    }

    *cur_pos = '\0';
    return (int)(cur_pos - *lineptr);
}