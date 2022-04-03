#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getingchar_and_addone (int* array)
{
	static char result[15];
	int count;
	int temp;
	int index = -1;
	for(int element = 0; element < 9; element++)
	{
		count = 0;
		temp = array[element];
		while(temp > 0)
       		{
			count++;
			temp /= 10;
		}
		char array1[count];
		sprintf(array1, "%d", array[element]);
		for(int number = 0; number < count; number++)
		{
			result[++index] = array1[number];
		}
	}
	
	int lastnumber = result[14] - 48;
        lastnumber++;
        char space[2];
        sprintf(space, "%d", lastnumber);
        result[14] = space[0];
	return result;
}

int main()
{
	int array[] = {1, 23, 45, 6, 7, 8, 9, 10, 1112};
	char* result = getingchar_and_addone(array);
	int digitArray[15];
        for(int digit = 0; digit < 15; digit++)
        {
                digitArray[digit] = result[digit] - 48;
        }
        printf("%d", digitArray[0]);
        for(int element = 1; element < 15; element++)
        {
                printf(",%d", digitArray[element]);
        }
}

