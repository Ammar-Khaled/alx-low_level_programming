/**
 * reverse_array - reverses the content of an array of integers.
 * @a: pointer to the array
 * @n: the number of elements of the array
 */
void reverse_array(int *a, int n)
{
	int i, j;
	int tmp;

	i = 0;
	j = n - 1;
	while (i <= j)
	{
		tmp = a[j];
		a[j] = a[i];
		a[i] = tmp;
		i++;
		j--;
	}
}
