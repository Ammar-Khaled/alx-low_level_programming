
/**
 * _is_prime - checks if the number is prime or not
 * @n: the number
 * @cur_test_number: the current test devisor
 * Return: 1 if the input integer is a prime number, otherwise return 0.
 */
int _is_prime(int n, int cur_test_number)
{
	if (n == 2)
		return (1);

	if (n % 2 == 0 || n <= 1)
		return (0);

	if (cur_test_number == n)
		return (1);

	if (n % cur_test_number == 0)
		return (0);

	return (_is_prime(n, cur_test_number + 2));
}

/**
 * is_prime_number - checks if the number is prime or not
 * @n: the number
 * Return: 1 if the input integer is a prime number, otherwise return 0.
 */
int is_prime_number(int n)
{
	return (_is_prime(n, 3));
}
