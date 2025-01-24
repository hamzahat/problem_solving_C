int ft_index_letter(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
        return ((letter - 'A') + 1);
    else if (letter >= 'a' && letter <= 'z')
        return ((letter -'a') + 1);
    else
        return (-1);
}
