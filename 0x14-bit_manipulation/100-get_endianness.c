
/**
 * get_endianness - checks the way in which computer system store and retrieve
 * the bytes of a multi-byte data type such as
 * an integer, floating-point number, or character..
 *
 * Return: 0 if big endian (the most significant byte of the data
 * is stored first in the memory,
 * followed by the less significant bytes)
 * , or 1 if little endian (the least significant byte (LSB) of the data
 * is stored first in the memory,
 * followed by the more significant bytes.)
 */
int get_endianness(void)
{
	unsigned int n;
	char *c;

	n = 1;
	c = (char *) &n;
	return ((int) *c);
}
