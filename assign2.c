#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>




void printMatrix(int** relationMatrix, int mSize);

bool isOnto(int** relationMatrix, int mSize);
bool isFunction(int** relationMatrix, int mSize);
bool isOneToOne(int** relationMatrix, int mSize);
bool isReflex(int** relationMatrix, int mSize);
bool isSym(int** relationMatrix, int mSize);
bool isTrans(int** relationMatrix, int mSize);

bool isTrans(int** relationMatrix, int mSize) {
	int i;
	for (i = 0; i < mSize; i++) {
		int j;
		for (j = 0; j < mSize; j++) {
			if (relationMatrix[i][j] == 1) {
				int k;
				for (k = 0; k < mSize; k++) {
					if (relationMatrix[j][k] == 1) {
						if (relationMatrix[i][k] == 0) {
							return false;
						}
					}
				}
			}
			int k;
			
		}
	}
	return true;
}

bool isSym(int** relationMatrix, int mSize) {
	int i;
	for (i = 0; i < mSize; i++) {
		int j;
		for (j = 0; j < mSize; j++) {
			if (relationMatrix[i][j] == 1) {
				if (relationMatrix[j][i] != 1) {
					return false;
				}
			}
		}
	}
	return true;
}

bool isReflex(int** relationMatrix, int mSize) {
	int i;
	for (i = 0; i < mSize; i++) {
		int j;
		if (relationMatrix[i][i] != 1) {
			return false;
		}
	}
	return true;
}

bool isFunction(int** relationMatrix, int mSize) {
	bool stillAFunction = false;
	int i;
	for (i = 0; i < mSize; i++) {
		
		int xcount = 0;
		int j;
		for (j = 0; j < mSize; j++) {
			//printf("relationMatrix[%d][%d] is: %d\n", i, j, relationMatrix[i][j]);
			if (relationMatrix[i][j] != 0) {
				xcount++;
				if (xcount > 1) {
					return stillAFunction;
				}
			}
		}
	}
	stillAFunction = true;
	
	return stillAFunction;
}

bool isOneToOne(int** relationMatrix, int mSize) {
	bool stillOneToOne = false;
	int i;
	for (i = 0; i < mSize; i++) {
		int j;
		for (j = 0; j < mSize; j++) {
			if(relationMatrix[i][j] != 0) {
				int k;
				for (k = j+1; k < mSize; k++) {
					if (relationMatrix[i][k] != 0) {
						return stillOneToOne;
					}
				}
				k = 0;
				for (k = i+1; k < mSize; k++) {
					if (relationMatrix[k][j] != 0) {
						return stillOneToOne;
					}
				}
			}
		}
	}
	stillOneToOne = true;
	return stillOneToOne;
}



bool isOnto(int** relationMatrix, int mSize) {
	int i;
	
	for (i = 0; i < mSize; i++) {
		int yCount = 0;
		int j;
		for (j = 0; j < mSize; j++) {
			if (relationMatrix[j][i] != 0) {
				yCount++;
				if (yCount > 1) {
					return false;
				}
			}
			//printf("relationMatrix[%d][%d]: %d\n", j, i, relationMatrix[j][i]);
		}
	}
	return true;
}

void printMatrix(int** relationMatrix, int mSize) {
	int i;
	for (i = 0; i < mSize; i++) {
		int j;
		for (j = 0; j < mSize; j++) {
			printf("[%d] ", relationMatrix[j][i]);			
		}
		printf("\n");
	}
}


int main(int argc, char* argv[]) {
    
	
	//printf("Number Of Arguments Passed: %d\n", argc);

	/*while (fgets(string, 100, stdin)) {
		text = realloc(text, strlen(text) + 1 + strlen(string));
		if (!text) {
			printf("Warning: No text\n");
			
		}
		strcat(text, string);
		printf("%s\n", string);
	}*/
	
	size_t bufsize = 32;
	int count = 0;
	int firstNum = -1;
	int** matrix = 0;

	int currentNum;
	int prevNum;

	char buffer[20];
	while (fgets(buffer, sizeof(buffer) , stdin) != NULL) {
		//printf("buffer is %s\n", buffer);
		
		//char* tempStr2 = (char*)malloc(sizeof(buffer));
		//tempStr1 = strtok(buffer, " ");
		//printf("tempStr1 is: %s\n", tempStr1);
		//printf("tempStr2 is: %s\n", tempStr2);
		
		if (firstNum == -1) {
			firstNum = atoi(buffer);	
			//printf("firstNum is: %d\n", firstNum);
			matrix = (int**)malloc(firstNum * firstNum * 2 * sizeof(int));			//allocate matrix
			int i;
			for (i = 0; i < firstNum; i++) {
				matrix[i] = (int*)calloc(firstNum, sizeof(int));
			}
		}
		else {
			char* num1S, * num2S;
			num1S = (char*)malloc(sizeof(char*));
			num2S = (char*)malloc(sizeof(char*));
			
			num1S = strtok(buffer, " ");
			num2S = strtok(NULL, " ");

			int num1, num2;

			num1 = atoi(num1S);
			num2 = atoi(num2S);

			//printf("num1 is: %d\n", num1);
			//printf("num2 is: %d\n", num2);
			//num2 = strtok(buffer, NULL);
			//printf("num2 is %s\n", num2);

			//currentNum = atoi(num1);

			matrix[num1 - 1][num2 - 1] = 1;

			
			//printf("matrix[%d][%d]: %d\n", prevNum - 1, currentNum - 1, matrix[prevNum - 1][currentNum - 1]);
			//printf("num1 is: %d & num2 is: %d\n", num1, num2);
			
			
			
		}
		//printf("tempStr1 is %s and tempStr2 is %s\n", tempStr1, tempStr2);
		//printf("tempStr1 & 2 are: %s\n", tempStr1, tempStr2);
	}
	//while (read(0, buf, sizeof(buf)) > 0) {
	//	if (isspace(buf[0])) {
	//		continue;
	//	}
	//	else {
	//		//char tempBuf = buf[0];
	//		currentNum = buf[0] - '0';		//character to integer
	//		if (firstNum == 0) {
	//			firstNum = currentNum;
	//			matrix = (int**)realloc(matrix, 2 * sizeof(int) * firstNum);
	//			int i;
	//			for (i = 0; i < firstNum; i++) {
	//				matrix[i] = (int*)malloc(2 * sizeof(int));
	//			}
	//			//printf("firstNum is: %d\n", firstNum);
	//		}
	//		else {
	//			if (isEven == true) {
	//				prevNum = currentNum;
	//				isEven = false;
	//			}
	//			else {
	//				matrix[prevNum-1][currentNum-1] = 1;
	//				//printf("matrix[%d][%d]: %d\n", prevNum-1, currentNum-1, matrix[prevNum-1][currentNum-1]);
	//				isEven = true;
	//			}
	//		}
	//	}
	//	
	//}


	
	//printf("Test\n");
	bool isRelFunction = isFunction(matrix, firstNum);
	bool isRelOnto = isOnto(matrix, firstNum);
	bool isRelOneToOne = isOneToOne(matrix, firstNum);
	bool isRelReflex = isReflex(matrix, firstNum);
	bool isRelSymmetric = isSym(matrix, firstNum);
	bool isRelTrans = isTrans(matrix, firstNum);
	
	bool isRelEqPart = isTrans(matrix, firstNum) && isReflex(matrix, firstNum) && isSym(matrix, firstNum);

	if (isRelReflex) {
		printf("Is reflexive\n");
	}
	if (isRelSymmetric) {
		printf("Is symmetric\n");
	}
	if (isRelTrans) {
		printf("Is transitive\n");
	} 
	if (isRelOnto) {
		printf("Is onto\n");
	} 
	if (isRelOneToOne) {
		printf("Is one to one\n");
	}

	if (isRelFunction) {
		printf("Is a function\n");
		if (isRelOnto) {
			printf("Function is onto\n");
		}
		if (isRelOneToOne) {
			printf("Function is one to one\n");
		}
	}
	else {
		printf("Is not function");
	}
	if (isRelEqPart) {
		printf("Is equivalence class\n");
		printf("%d classes\n", firstNum);
		printMatrix(matrix, firstNum);
	}
	else {
		printf("Is not equivalence class");
	}

	//printMatrix(matrix, firstNum);


	
	//printf("\ntext: %s\n", text);
	/*if (argc > 1) {
		
	}*/
	//will look like
	//input will be ~kgallagher/public_html/sampleprogs/func 5 3 | ~ahatfield2016/SWT2/assign2


    return 0;
}

//void create_2d_array(int size) {
//	int (*2) = (int*)calloc(size, size * size * sizeof(int));
//
//	/*int i, j, count = 0;
//	for (i = 0; i < size; i++)
//		for (j = 0; j < size; j++)
//			* (arr + i * size + j) = ++count;*/
//	int i;
//	int j;
//	for (i = 0; i < size; i++) {
//
//		for (j = 0; j < size; j++) {
//			printf("%d ", *(arr + i * size + j));
//		}
//	}
//}
