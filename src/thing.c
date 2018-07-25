#include <SDL2/SDL.h>
#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

void multiply_by_sixteen(int* a) {
	*a = *a * 16;
}

void doing_array_stuff() {

	int j, k;
	j = 2;
	k = 3;
	int asdf = add(j, k);

	int m = 17;
	multiply_by_sixteen(&m);

	int some_array_of_integers[] = {
		1,
		123,
		4,
		15,
		13,
	};

	for (int i = 0; i < 5; ++i) {
		printf("%d\n", some_array_of_integers[i]);
	}

	printf("---\n");

	int int_array[17];

	for (int i = 0; i < 17; ++i) {
		int_array[i] = i * 3;
	}

	for (int i = 0; i < 17; ++i) {
		printf("%d\n", int_array[i]);
	}

	// THE NAME OF AN ARRAY IS A POINTER TO THE FIRST ELEMENT

	// A POINTER IS AN INTEGRAL VALUE
	// in 32 bit mode they are 4 bytes large
	// in 64 bit mode they are 8 bytes large

	int a = 3;
	printf("a is %d\n", a);

	int* a_ptr = &a;

	// & symbol means: the address of

	*a_ptr = 5;

	// *ptr means: the contents of ptr
	// it's called the deference operator

	printf("a is %d\n", a);
}

int main(int argc, char* argv[]) {

    SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    doing_array_stuff();

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}