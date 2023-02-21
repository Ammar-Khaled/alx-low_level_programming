/**
 * _isalpha - checks for alphabetic character.
 * Return: 1 if c is a letter, lowercase or uppercase and 0 otherwise
 */
int _isalpha(int c)
{
return _islower(c) || (c >= 'A' && c <= 'Z');
}
