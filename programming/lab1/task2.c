#include <stdio.h>

typedef struct {
	char str[4];
	int num;
    /*а надо 
    char str[5];
	int num;
	так как массиву не зватало ячеек памяти(4 буквы + знак конца массива)
	он занимал отнимал ее у следущией переменной, что приводило к уменьшению ее на 1		
	*/
} NumberRepr;

void format(NumberRepr* number) {
	sprintf(number->str, "%4d", number->num);
}

int main() {
	NumberRepr number = { .num = 1025 };
	format(&number);
	printf("str: %s\n", number.str);
	printf("num: %d\n", number.num);
	return 0;
}

