    fgets(s, 99, stdin);
    if (p = strchr(s, '\n'))
        *p = '\0';