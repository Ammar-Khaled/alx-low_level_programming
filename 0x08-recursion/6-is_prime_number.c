



int is_prime(int n, int cur_test_number = (3))
{
	if (n == 2)
		return (1);

	if (n % 2 == 0 || n <= 1)
		return (0);

	if (cur_test_number == n)
		return (1);

	if (n % cur_test_number == 0)
		return (0);

	return is_prime(n, cur_test_number + 2);
}