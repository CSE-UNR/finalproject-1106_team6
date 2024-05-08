#define Max_Col 21
#define Max_Row 13
#define MAX_STRLENGTH 100
#include <stdio.h>

//done with Read from file
char fileName[MAX_STRLENGTH];
int rows, cols, userInput;
void menu(int rows, int cols, char image[][Max_Col]);
void editMenu(int rows, int cols, char image[][Max_Col]);
void SaveToFile(int rows, int cols, char image[][Max_Col], char fileName[MAX_STRLENGTH]);
void ReadFromFile(int rows, int cols, char image[][Max_Col], char *fileName);
//done with crop

//displays image after loading 
void displayImage(int cols, int rows, char image[][Max_Col]);
//crops image
void Crop(int rows, int cols, char image[][Max_Col]);
//dims image by 1
void Dim(int rows, int cols, char image[][Max_Col]);
//brightens image by 1
void Brighten(int rows, int cols, char image[][Max_Col]);
//loads the image from file into array
void loadImage(char *fileName, int rows, int cols, char image[][Max_Col]);
//Array with dimensions for crop function
void imageForCrop(int rows, int cols, char image[][Max_Col]);

int main()
{
	int rows = Max_Row;
	int cols = Max_Col;
	char image[Max_Row][Max_Col];
	menu(rows, cols, image);
	return 0;
}

//menu (isabel)
void menu(int rows, int cols, char image[][Max_Col] ){

	int userInput;
	char fileName[MAX_STRLENGTH];
	do{
	printf("**ERINSTAGRAM**\n1: Load image\n2: Display image\n3: Edit image\n0: Exit\n");
	printf("\nChoose from one of the options above: ");
	scanf(" %d", &userInput);
	switch(userInput){
		case 0: {
			printf("\nGoodbye!\n");
			break;
		}
		case 1: {
			//LoadImage
			printf("What is the name of the image file? ");
			scanf(" %s", fileName);
			loadImage(fileName, rows, cols, image);
			break;
		}
		case 2: {
			displayImage(cols, rows, image);
			break;
		}
		case 3: {
			editMenu(rows, cols, image);
			break;
		}
	}
	} while (userInput != 0);
}

//Editmenu (isabel)
void editMenu(int rows, int cols, char image[][Max_Col]){
	int userInput;
	char AddedfileName[MAX_STRLENGTH];
	char user2;
	printf("\n**EDITING**\n1: Crop Image\n2: Dim Image\n3: Brighten Image\n0: Return to main menu");
	printf("\nChoose from one of the options above: ");
	scanf(" %d", &userInput);
	printf("\n");
	switch(userInput){
		case 0: {
			menu(Max_Row, Max_Col, image);
			break;
		}
		case 1: {
			imageForCrop(rows, cols, image);
			Crop(Max_Row, Max_Col, image);
			printf("Save image to file? (y/n) ");
			scanf(" %c", &user2);
			switch(user2){
				case 'Y':
				case 'y': {
					printf("\nWhat do you want to name the image file? (include the extension) ");
					scanf(" %s", AddedfileName);
					SaveToFile(rows, cols, image, AddedfileName);
					break;
				}
				case 'n':
				case 'N':
					printf("\n");
					break;
			}
			break;
		}
		case 2: {
			Dim(Max_Col, Max_Row, image);
			printf("Save image to file? (y/n) ");
			scanf(" %c", &user2);
			switch(user2){
				case 'Y':
				case 'y': {
					printf("\nWhat do you want to name the image file? (include the extension) ");
					scanf(" %s", AddedfileName);
					SaveToFile(rows, cols, image, AddedfileName);
					break;
				}
				case 'n':
				case 'N':
					printf("\n");
					break;
			}
			break;
		}
		case 3: {
			Brighten(Max_Col, Max_Row, image);
			printf("Save image to file? (Y/N): ");
			scanf(" %c", &user2);
			switch(user2){
				case 'Y':
				case 'y': {
					printf("\nWhat do you want to name the image file? (include the extension) ");
					scanf(" %s", AddedfileName);
					SaveToFile(rows, cols, image, AddedfileName);
					break;
				}
				case 'n':
				case 'N':
					printf("\n");
					break;
			
		}
	}
}
}

//Display Image (isabel)
void displayImage(int cols, int rows, char image[][Max_Col]){
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
					printf("%c", image[i][j]);
		}
		printf("\n");
	}

}

//Crop image (Matthew)
void Crop(int rows, int cols, char image[][Max_Col])
{
	int topRow, bottomRow,  rightCol, leftCol;
	
	
	int height = rows;
	int width = cols; 
	printf("The image you want to crop is 12 x 21.\n");
	printf("The row and column values start in the upper lefthand corner.\n\n");
	
	printf("Which do you want to be the new left side? ");
    scanf("%d", &leftCol);
	printf("\n");

    while (leftCol < 1 || leftCol >= Max_Col) {
        printf("Invalid column value. Choose a number between 1 and %d: ", Max_Col);
        scanf("%d", &leftCol);
    }

	printf("Which column do you want to be the new right side? ");
	scanf("%d", &rightCol);
	printf("\n");

	while(rightCol <= leftCol || rightCol > width)
	{
		printf("Invalid column value. Choose a number between %d and %d", leftCol, width);
		scanf("%d", &rightCol);
	}
	
	printf("Which row do you want to be the new top? ");
	scanf("%d", &topRow);
	printf("\n");

	while(topRow < 1 || topRow > height)
	{
		printf("Invalid column value. Choose a number between %d and  %d", rightCol, height);
		scanf("%d", &topRow);
	}	
		
	printf("Which row do you want to be the new bottom? ");	
	scanf("%d", &bottomRow);
	printf("\n");

	while(bottomRow <= topRow || bottomRow > height)
	{
		printf("Invalid column value. Choose a number between %d and %d", topRow, width);
		scanf("%d", &bottomRow);
	}
	
	for(int hIndex = topRow -1; hIndex <=bottomRow-1; hIndex++)
		{
		
			for(int wIndex = leftCol-1;wIndex <= rightCol; wIndex++)
			{
				printf("%c", image[hIndex][wIndex]);
			}
			printf("\n");
		}

	cols = rightCol;
	rows = bottomRow - 1 ;

}



//load image (isabel)
void loadImage(char *fileName, int rows, int cols, char image[][Max_Col]){
	FILE *file = fopen(fileName, "r");
	if(file == NULL){
		printf("Error opening file");
	}
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				char check;
				if(fscanf(file, " %c", &check) == 1){
					switch(check){
						case '0':
							image[i][j] = ' ';
							break;
					
						case '1': 
							image[i][j] = '.';
							break;
						case '2':
							image[i][j] = 'o';
							break;
						case '3':
							image[i][j] = 'O';
							break;
						case '4':
							image[i][j] = '0';
							break;
					}
				}
			}
		}
	fclose(file);
	printf("\nImage successfully loaded!\n\n");
}

//METHOD DONE! YAAY
//Save to file (Matthew)
void SaveToFile(int rows, int cols, char image[][Max_Col], char fileName[MAX_STRLENGTH]){

FILE* fileptr = fopen(fileName, "w");


if(fileptr != NULL){

for(int CurrentRow = 0; CurrentRow < rows; CurrentRow++)
	{
		for(int CurrentCol = 0; CurrentCol < cols; CurrentCol++)
		{
				switch(image[CurrentRow][CurrentCol])
				{
					case' ':
					fprintf(fileptr, "%c", '0');
					break;
					
					case'.':
					fprintf(fileptr, "%c", '1');
					break;
					
					case'o':
					fprintf(fileptr, "%c", '2');
					break;
					
					case 'O':
					fprintf(fileptr, "%c", '3');
					break;
					
					case'0':
					fprintf(fileptr, "%c", '4');
					break;
			
				}
		
		} 
		
		fprintf(fileptr, "\n");	
	}

fclose(fileptr);
printf("\nImage Successfully saved!\n\n");
}

else 
{
printf("Unable to save file!\n");

}


}

//Dim (isabel)
void Dim(int cols, int rows, char image[][Max_Col]){
	char NewImage[Max_Row][Max_Col];
	for(int CurrentRow = 0; CurrentRow < rows; CurrentRow++)
	{
		for(int CurrentCol = 0; CurrentCol < cols; CurrentCol++)
		{
			NewImage[CurrentRow][CurrentCol] = image[CurrentRow][CurrentCol];
		}
	}

	for(int CurrentRow = 0; CurrentRow < rows; CurrentRow++)
	{
		for(int CurrentCol = 0; CurrentCol < cols; CurrentCol++)
		{
				switch(NewImage[CurrentRow][CurrentCol])
				{
					case'.':
					NewImage[CurrentRow][CurrentCol] = ' ';
					break;
					
					case'o':
					NewImage[CurrentRow][CurrentCol] = '.';
					break;
					
					case 'O':
					NewImage[CurrentRow][CurrentCol] = 'o';
					break;
					
					case'0':
					NewImage[CurrentRow][CurrentCol] = 'O';
					break;
			
				}
			
			}	
			}
			displayImage(cols, rows, NewImage);
}

//Brighten (isabel)
void Brighten(int rows, int cols, char image[][Max_Col]){

	char NewImage[Max_Row][Max_Col];
	for(int CurrentRow = 0; CurrentRow < Max_Row; CurrentRow++)
	{
		for(int CurrentCol = 0; CurrentCol < Max_Col; CurrentCol++)
		{
			NewImage[CurrentRow][CurrentCol] = image[CurrentRow][CurrentCol];
		}
	}

	for(int CurrentRow = 0; CurrentRow < Max_Row; CurrentRow++)
	{
		for(int CurrentCol = 0; CurrentCol < Max_Col; CurrentCol++)
		{
				switch(NewImage[CurrentRow][CurrentCol])
				{
					case ' ':
					NewImage[CurrentRow][CurrentCol] = '.';
					case'.':
					NewImage[CurrentRow][CurrentCol] = 'o';
					break;
					
					case'o':
					NewImage[CurrentRow][CurrentCol] = 'O';
					break;
					
					case 'O':
					NewImage[CurrentRow][CurrentCol] = '0';
					break;
				}
			
			}	
			}
				displayImage(rows, cols, NewImage);
	
		}

	void imageForCrop(int rows, int cols, char image[][Max_Col]){
		char cropImage[Max_Row][Max_Col];
		for(int CurrentRow = 0; CurrentRow < Max_Row; CurrentRow++)
		{
			for(int CurrentCol = 0; CurrentCol < Max_Col; CurrentCol++)
			{
				cropImage[CurrentRow][CurrentCol] = image[CurrentRow][CurrentCol];
			}
		}
		cropImage[0][1] = '1';
		cropImage[1][0] = '1';
		cropImage[Max_Row-1][0] = '1';
		cropImage[Max_Row-1][1] = '2';
		cropImage[0][Max_Col-1] = '1';
		cropImage[0][Max_Col-2] = '2';
		displayImage(cols, rows, cropImage);
		
	}