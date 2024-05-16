#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

// Screen size
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768


constexpr auto MAXR = 1000; // Number of rectangles
SDL_Rect r[MAXR];

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

bool quit = false;
int frames = 0; // Number of Drawn frames

//Struct for storing the data that must be passed to the threads, for instance, the start rectangle and the number of iterations
struct ThreadData
{
	int start;
	int iters;
};

// move: Move a recangle in a random direction
void move(SDL_Rect *r) {
	int dir = rand() % 4;
	if (dir == 0) {
		r->x += 10;
		r->x = r->x %SCREEN_WIDTH;
	}
	else if (dir == 1) {
		r->y += 10;
		r->y = r->y %SCREEN_HEIGHT;

	}
	else if (dir == 2) {
		r->x -= 10;
		r->x = r->x %SCREEN_WIDTH;

	}
	else if (dir == 3) {
		r->y -= 10;
		r->y= r->y %SCREEN_HEIGHT;

	}
}

// Move all rectangles from 'start' to 'start+iters' in a random way
// Update the result and increase number of frames drawn.
void updateRect(int start, int iters) {
	for (int i = 0; i < iters; i++) {
		SDL_FillRect(screenSurface, &r[start + i], SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
		move(&r[start + i]);
		SDL_FillRect(screenSurface, &r[start + i], SDL_MapRGB(screenSurface->format, rand() % 0xFF, rand() % 0xFF, 0xFF));
	}
	SDL_UpdateWindowSurface(window);
	frames++;
}

// updateRectThread: TODO
int updateRectThread(void* data) {
	ThreadData* td = (ThreadData*)data;
	while (!quit) {
		updateRect(td->start, td->iters);
	}
	return 0;
}

// Initialize SDL
int initSDL() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf(" SDL could not initialize SDL_Error =%s\n", SDL_GetError());
		return(-1);
	}

	window = SDL_CreateWindow("SDL prova", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf(" SDL could not create Window SDL_Error =%s\n", SDL_GetError());
		return(-1);

	}
	screenSurface = SDL_GetWindowSurface(window);
	return 0;
}

int main(int argc, char** argv) {
	if (initSDL() < 0) {
		printf("ERROR: Unable to init SDL");
		return (-1);
	}
	printf(" Starting \n");
	// Draw background
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	SDL_UpdateWindowSurface(window);
	
	// Init rectangles
	for (int i = 0; i < MAXR; i++) {
		r[i].x = rand() % SCREEN_WIDTH;
		r[i].y = rand() % SCREEN_HEIGHT;
		r[i].h = 10;
		r[i].w = 10;
	}

	// TODO: Create threads

	int numThreads;
	printf("Input how many threads do you want: ");
	scanf_s("%ud\n", &numThreads);

	if (numThreads <= 0)
	{
		printf("Thread number must be greater than 0");
		return -1;
	}

	SDL_Thread** threads = new SDL_Thread*[numThreads];
	ThreadData* threadData = new ThreadData[numThreads];
	for (int i = 0; i < numThreads; ++i)
	{
		threadData[i].start = (i * (MAXR / numThreads));
		threadData[i].iters = (MAXR / numThreads);

		//We have to take into account that the amount of rectangles may not be divisible may the amount of threads
		if (i == numThreads - 1)
		{
			threadData[i].iters += MAXR % numThreads;
		}

		threads[i] = SDL_CreateThread(updateRectThread, "UpdateThread", (void*)&threadData[i]);
	}

	// Start game loop
	SDL_Event e;
	Uint32 start, now;
	start = SDL_GetTicks();
	while (quit == false) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) quit = true;
		}
	
		//updateRect(0, MAXR); // Update Rectangles

		now = SDL_GetTicks();
		if ((now - start) > 1000) { // a SECOND has passed!
			start = now;
			printf("frames/s = %d\n", frames);
			frames = 0;
		}
	}
    
	// TODO: Wait threads
	for (int i = 0; i < numThreads; ++i)
	{
		SDL_WaitThread(threads[i], NULL);
	}

	//Free allocated memory
	delete[] threads;
	delete[] threadData;

	return 0;
}
