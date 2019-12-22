
int size(char *ptr)
{
    //variable used to access the subsequent array elements.
    int offset = 0;
    //variable that counts the number of elements in your array
    int count = 0;

    //While loop that tests whether the end of the array has been reached
    while (*(ptr + offset) != '\0')
    {
        //increment the count variable
        ++count;
        //advance to the next element of the array
        ++offset;
    }
    //return the size of the array
    return count;
}

char *_strcpy(char *d, char *s){
   char *saved = d;
   while ((*d++ = *s++) != '\0');

   return saved;
}

char* _strcat(char* destination, const char* source, int num)
{
	int i, j;
	for (i = 0; destination[i] != '\0'; i++);
	for (j = 0; source[j] != '\0' && j < num; j++)
		destination[i + j] = source[j];
	destination[i + j] = '\0';
	return destination;
}

int _strcmp(const char* s1, const char* s2)
{
    const unsigned char *p1 = ( const unsigned char * )s1;
    const unsigned char *p2 = ( const unsigned char * )s2;

    while ( *p1 && *p1 == *p2 ) ++p1, ++p2;

    return ( *p1 > *p2 ) - ( *p2  > *p1 );
}
char* append(char*s, char c) {
    char new[size(s)+2];
    _strcpy(new, s);
    new[size(s)+1] = c;
    new[size(s)+2] = '\0';

    s = new;
     return s;
}
