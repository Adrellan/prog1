#include <stdio.h> //printf itt van (es meg sok minden)

void my_print(const char* p, const int x){ //p is "foo" and x is 7 formatumban kiirat
	printf("p is \"%s\" and x is %d\n", p, x); // %d vagy %i - int
}
int main(){
	printf("1.\n");
	printf("Hello, world!\n\n");

	printf("2.\n");
	char h[] = "Hello";
	char w[] = "World!";
	printf("%s %s\n\n", h, w); //%s formátum specifikátor (string), h és w a formázandó argumentumok

	printf("3.\n");
	my_print("foo",7);
	my_print("Robi",10);
	my_print("Bármi Áron",13);

	return 0;

}