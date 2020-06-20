char** fizzBuzz(int A, int *len1) {
    int i = 0;
    for (i = 1; i <= A; i++) {
        if (i % 15 == 0) printf("FizzBuzz ");
        else if (i % 3 == 0) printf("Fizz ");
        else if (i % 5 == 0) printf("Buzz ");
        else printf("%d ", i);
    }
    return NULL;
}a