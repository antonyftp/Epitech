/*
** EPITECH PROJECT, 2018
** CPE_BSQ_bootstrap_2018
** File description:
** Convert char to int
*/

int my_atoi(char *str)
{
    int nb = 0;
    int i = 0;
    int count_sub = 0;

    if (str[0] == '-') {
        count_sub++;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - 48);
        i++;
    }
    if (count_sub == 1)
    nb = nb * -1;
    return (nb);
}
