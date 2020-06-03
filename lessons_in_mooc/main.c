#include "Array.h"
#include <string.h>
int main() {
	Array *array = NULL;
	array = create_array(10);
	int i;
	for (i = 0; i < 10; i++) {
		addLast(array, i);
	}
	add(array, 1, 100);
	toString(array);
	
	return 0;
}