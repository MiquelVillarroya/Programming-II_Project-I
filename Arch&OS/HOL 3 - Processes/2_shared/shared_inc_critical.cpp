#include <stdio.h>
#include "SDL.h"
#include <iostream>

constexpr int N = 10000000;
int globalVar=0;

int TestThread(void *data)
{
	int i;

	for (i = 0; i < N; i++) {
		globalVar++; // Critical region
	}
	return i;
}

int main(int argc, char *argv[])
{
	int  threadReturnValue;

	//Get number of threads from user
	int numThreads;
	printf("Input how many threads do you want: ");
	scanf_s("%d", &numThreads);

	if (numThreads <= 0)
	{
		printf("Thread number must be greater than 0");
		return -1;
	}

	//Create Threads
	SDL_Thread** threads = new SDL_Thread * [numThreads];

	std::cout << "Creating "<< numThreads << " SDLThreads...\n" << std::endl;
	for (int i = 0; i < numThreads; ++i) {
		threads[i] = SDL_CreateThread(TestThread, "TestThread", (void*)NULL);
		if (threads[i] == NULL) {
			printf("SDL_CreateThread failed: %s\n", SDL_GetError());
			return -1;
		}
	}

	//Wait for threads
	for (int i = 0; i < numThreads; ++i)
	{
		SDL_WaitThread(threads[i], &threadReturnValue);
	}

	printf("Thread returned value: %d\n", threadReturnValue);

	printf("ID: Thread counter : %d\n", globalVar);
	
	//Delete allocated memory
	delete[] threads;

	return 0;
}
