#include <stdio.h>
#include <cs50.h>

int get_height(void);
void pyramid(int height);

int main(void) 
{

	// Ask for height
	int height = get_height();
	pyramid(height); 

  // Print the thing
	
}
 
int get_height(void) 
{
	int height;
	do
	{
		height = get_int("Height: ");	
	}
	while (height < 1);
	return height;
}

void pyramid(int height)
{ 
	for (int row = 0; row < height; row++)
		{
			for (int space = 0; space < height - row - 1; space++)
				{
					printf(" ");
				}
			for (int column = 0; column <= row; column++)
				{
					printf("#");
				}
			printf("\n");
		}
}
