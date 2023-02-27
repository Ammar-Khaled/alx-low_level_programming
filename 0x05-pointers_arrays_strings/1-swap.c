/**
 * swap_int - swaps the values of two integers.
 */
void swap_int(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
