#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "pilestab.h"

int main() {

	char* mot = "abba";
	
	if (isPalindrome(mot)) {
		printf("C'est un palindrome ");
	}
	else {
		printf("Ce n'est pas un palindrome ");
	}
}