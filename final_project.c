#include <stdio.h>
#include<string.h>
#include<cmath>

int main ()
{
	char str[100]; //array for source text 
	char strFileSource[100]; // array for file path
	char Base64Lookup[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
	} //array for base64 chars

	FILE *fptr; //object for working with the file

	printf ("Enter the path of the file : \n");
	scanf ("%s", strFileSource);
	fptr = fopen(strFileSource,"r");//opens file for reading
	if(fptr == NULL)//checking the existense of the file
	{
		printf("Error!");
		return 1;
	}
	fscanf(fptr,"%s", &str);//reads from the file and save the text in str
	fclose(fptr); //closes the file connection
	int arr[1024];// array for saving binary code of the text
	int elCount = 0; // binary element count
	for(int j = 0; j < strlen(str); j++)
	{
		elCount += 8;
		int tempCount = elCount;
		int b = str[j];//saves text character ASCII code in b 
		while(b > 0) // gets binary from the character ASCII code and saves it in arr
		{
			int c = b % 2;
			arr[--tempCount] = c;
			b /= 2;
		}
		while(tempCount % 8 != 0) // if th ASCII code binary is less than 8 0's should be written from the beginning
		{
			arr[--tempCount] = 0;
		}
	}
	int sum = 0;// variable for decimal value
	int powCount = 5;//variable for 2's degree
	char finalArr[1024];// array for encoded text
	int index = -1;//character position in final array
	for(int i = 0; i < elCount; i++)//if binary array element is 1 its degree of 2 is found and added to the sum
	{
		if(arr[i] == 1)
		{
			sum+=(int)pow(2,powCount);
		}
	powCount--;// for the next element the powcount must be less than previous
	if((i + 1) % 6 == 0)// if the i is 6 the character is taken and written in the final arry
		{
			finalArr[++index] = Base64Lookup[sum];
			powCount = 5;// the powcount and sum are reset
			sum = 0;
		}
	} 
	if(sum != 0)// binary element count is less than 6 and it'll find it's position index in the Base64Lookup and add it to the final arry
	{
		finalArr[++index] = Base64Lookup[sum];
	}

	while((index + 1) % 4 != 0)
	{
		finalArr[++index] = '=';
	}

	printf("\n");
	for(int i = 0; i <= index; i++)
	{
		printf("%c",finalArr[i]);
	}
	return 0;
}
