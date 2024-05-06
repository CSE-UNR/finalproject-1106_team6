
#define Max_Col 20
#define Max_Row 20
#define MAX_STRLENGTH 100
#include <stdio.h>
//done with Read from file
char fileName[MAX_STRLENGTH];
int rows, cols, userInput;
void menu(int rows, int cols, char image[][Max_Row]);

void editMenu(int rows, int cols, char image[][Max_Row]);
void SaveToFile(int rows, int cols, char image[][Max_Row], char fileName[MAX_STRLENGTH]);
void ReadFromFile(int rows, int cols, char image[][Max_Row], char *fileName);
//done with crop
void displayImage(int cols, int rows, char image[][Max_Row]);
void Crop(int rows, int cols, char image[][Max_Row]);
void Dim(int rows, int cols, char image[][Max_Row]);
void Brighten(int rows, int cols, char image[][Max_Row]);
void loadImage(char *fileName, int rows, int cols, char image[][Max_Row]);
void convert(char image[][Max_Col], int rows, int cols);

int main()
{
	int rows = Max_Row;
	
	int cols = Max_Col;
	char image[Max_Row][Max_Col];
	menu(rows, cols, image);
	

return 0;
}

void menu(int rows, int cols, char image[][Max_Row] ){

	
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
			displayImage(rows, cols, image);
			break;
		}
		case 3: {
			editMenu(rows, cols, image);
			break;
		}
	}
	} while (userInput != 0);
}

void editMenu(int rows, int cols, char image[][Max_Row]){
	int userInput;
	printf("**EDITING**\n1:Crop Image\n2:Dim Image\n3:Brighten Image\n0: Return to main menu");
	printf("\nChoose from one of the options above: ");
	scanf(" %d", &userInput);
	switch(userInput){
		case 0: {
			"";
			menu(Max_Row, Max_Col, image);
			break;
		}
		case 1: {
			Crop(Max_Row, Max_Col, image);
			break;
		}
		case 2: {
			Dim(Max_Row, Max_Col, image);
			break;
		}
		case 3: {
			Brighten(Max_Row, Max_Col, image);
			break;
		}
	}
}

void displayImage(int cols, int rows, char image[][Max_Row]){
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
					printf("%c ", image[i][j]);
			
		}
		printf("\n");
	}

}

void Crop(int rows, int cols, char image[][Max_Row])
{
	int StartHeight = 0;

	int StartWidth =0;
	
	
	int NewHeight = 2;
	int Newwidth = 2;
	
	char NewImage[StartHeight][StartWidth];
	
	for(int CurrentRow = StartHeight; CurrentRow < NewHeight; CurrentRow++)
	{
		for(int CurrentCol = StartWidth; CurrentCol < Newwidth; CurrentCol++)
		{
				NewImage[CurrentRow][CurrentCol] = image[CurrentRow][CurrentCol];
			
		
		}
	}


//just to display the array
	for(int CurrentRow = 0; CurrentRow < NewHeight; CurrentRow++)
	{
		for(int CurrentCol = 0; CurrentCol < Newwidth; CurrentCol++)
		{
					printf("%c", NewImage[CurrentRow][CurrentCol]);
			
		}
		printf("\n");
	}


printf("---\n");
}

void loadImage(char *fileName, int rows, int cols, char image[][Max_Row]){
	FILE *file = fopen(fileName, "r");
	if(file == NULL){
		printf("Error opening file");
	}
		char check;
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				if (fscanf(file, " %c", &check) == 1){
					switch(check){
					case '0':
					image[i][j] = ' ';
					break;
					
					case'1':
					image[i][j] = '.';
					break;
					
					case'2':
					image[i][j] = 'o';
					break;
					
					case '3':
					image[i][j] = 'O';
					break;
					
					case'4':
					image[i][j] = '0';
					break;
					
					default:
					image[i][j] = '?';
					break;
				}	
		
				}
			}
		}
		fclose(file);
		printf("\nFile successfully loaded!\n\n");
}

//METHOD DONE! YAAY
void SaveToFile(int rows, int cols, char image[][Max_Row], char fileName[MAX_STRLENGTH]){

FILE* fileptr = fopen(fileName, "w");


if(fileptr != NULL)
{

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

}

else 
{
printf("Unable to save file!\n");

}


}


void ReadFromFile(int cols, int rows, char image[][Max_Row], char *fileName){

rows = 0;

char fileIndex;

FILE* filePtr = fopen(fileName, "r");

if( filePtr != NULL)
{
	while(fscanf(filePtr, "%c", &fileIndex)==1)
	{	
		rows+=1;
	}
	
	
	
	
	printf("%d Row(s)\n", rows);
	
	fclose(filePtr);
	 
	 filePtr = fopen(fileName, "r");
	
	
	char Number;
	
	int CurrentCol = 0;
	
	
	for(int CurrentRow = 1; CurrentRow < rows; CurrentRow++)
	{
			CurrentCol = 0;
			
		while(Number != '\n' )
		{
		
			fscanf(filePtr,"%c",&Number);
		
			switch(Number)
				{
					case '0':
					image[CurrentRow][CurrentCol] = ' ';
					
					break;
					
					case'1':
					image[CurrentRow][CurrentCol] = '.';
					break;
					
					case'2':
					image[CurrentRow][CurrentCol] = 'o';
					break;
					
					case '3':
					image[CurrentRow][CurrentCol] = 'O';
					break;
					
					case'4':
					image[CurrentRow][CurrentCol] = '0';
					
					
					break;
					
				}	
		
		CurrentCol++;

		}
		
		
	}
	
	fclose(filePtr);
	printf("Image successfully loaded!\n");
}
else 
{
	printf("Cannot open file, Try again");
}
}

void Dim(int cols, int rows, char image[][Max_Row]){
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
					case' ':
					NewImage[CurrentRow][CurrentCol] = '0';
					break;
					
					case'.':
					NewImage[CurrentRow][CurrentCol] = '0';
					break;
					
					case'o':
					NewImage[CurrentRow][CurrentCol] = '1';
					break;
					
					case 'O':
					NewImage[CurrentRow][CurrentCol] = '2';
					break;
					
					case'0':
					NewImage[CurrentRow][CurrentCol] = '3';
					break;
			
				}
			
			}	
			}
			convert(NewImage, rows, cols);
}

void Brighten(int rows, int cols, char image[][Max_Row]){

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
					case' ':
					case'.':
					NewImage[CurrentRow][CurrentCol] = '0';
					break;
					
					case'o':
					NewImage[CurrentRow][CurrentCol] = '1';
					break;
					
					case 'O':
					NewImage[CurrentRow][CurrentCol] = '2';
					break;
					
					case'0':
					NewImage[CurrentRow][CurrentCol] = '3';
					break;
			
				}
			
			}	
			}
				convert(NewImage, rows, cols);
	
		}

	void convert(char image[][Max_Col], int rows, int cols){
		for(int i =0; i < rows; i++){
			for(int j = 0; j < cols; j++){

		switch(image[i][j])
				{
					case '0':
					image[i][j] = ' ';
					
					break;
					
					case'1':
					image[i][j] = '.';
					break;
					
					case'2':
					image[i][j] = 'o';
					break;
					
					case '3':
					image[i][j] = 'O';
					break;
					
					case'4':
					image[i][j] = '0';
					
					
					break;
					
				}
			}	
		}
		displayImage(rows, cols, image);
	}



