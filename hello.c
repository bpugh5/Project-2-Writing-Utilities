#include <stdio.h>

int main() {
	int x = 12;
	float y = 3.14;
	char* s = "Hello, world!";
	int i;

	printf("x is %d, y is %f\n%s\n", x, y, s);

	for (i = 0; i < 5; ++i) {
		int val = 5;
		val = val * i;
		printf("%d x 5 = %d\n", i, val);
	}
	return 0;
}
