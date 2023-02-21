void sum_fib(void)
{
int n1 = 1, n2 = 2, n = n1 + n2;
long sum = 2;
while (n <= 4000000 && n % 2 == 0)
{
	sum += n;
	n1 = n2;
	n2 = n;
	n = n1 + n2;
}
printf("%l\n", sum);
}
