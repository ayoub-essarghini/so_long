char **map_dup(char **map,int len)
{
    char **map2;
    int i;
    i = 0;

    map2 = (char **)malloc(len * sizeof(char *));
      while (i < len)
    {
        map2[i] = map[i];
        i++;
    }
    return map2;
}