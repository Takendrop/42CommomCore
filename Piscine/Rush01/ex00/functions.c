int checkleftright(char **src, char **lines)
{
    unsigned int    i;
    unsigned int    j;
    unsigned int    counter;
    unsigned char   tmp;

    i = 0;
	while (i < 4)
    {
        j = 0;
        counter = 0;
        while (j < 4)
        {
            if (lines[i][j] > tmp)
            {
                tmp = lines[i][j];
                counter++;
            }
            j++;
        }
        if (counter != src[i][0])
        {
            write(1, &i, 1);
        }
        i++;
    }
    i = 0;
	while (i < 4)
    {
        j = 3;
        counter = 0;
        while (j >= 0)
        {
            tmp = '0';
            if (lines[i][j] > tmp)
            {
                tmp = lines[i][j];
                counter++;
            }
            j--;
        }
        if (counter != src[i][1])
        {
            write(1, &i, 1);
        }
        i++;
    }
    return (0);
}


int checkupdown(char **src, char **lines)
{
    unsigned int    i;
    unsigned int    j;
    unsigned int    counter;
    unsigned char   tmp;

    i = 0;
	while (i < 4)
    {
        j = 0;
        counter = 0;
        while (j < 4)
        {
            if (lines[j][i] > tmp)
            {
                tmp = lines[j][i];
                counter++;
            }
            j++;
        }
        if (counter != src[i][0])
        {
            write(1, &i, 1);
        }
        i++;
    }
    i = 0;
	while (i < 4)
    {
        j = 3;
        counter = 0;
        while (j >= 0)
        {
            tmp = '0';
            if (lines[j][i] > tmp)
            {
                tmp = lines[j][i];
                counter++;
            }
            j--;
        }
        if (counter != src[i][1])
        {
            write(1, &i, 1);
        }
        i++;
    }
    return (0);
}