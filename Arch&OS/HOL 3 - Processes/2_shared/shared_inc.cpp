#include <stdio.h>
#include "SDL.h"
#include <iostream>

constexpr int N = 10000000;
int globalVar=0;

//Declare the mutex for the global variable
SDL_mutex* mutex = NULL;

int TestThread(void *data)
{
	int i;
	SDL_LockMutex(mutex);

	for (i = 0; i < N; i++) {
		globalVar++; // Critical region
	}
	SDL_UnlockMutex(mutex);

	return i;
}

int main(int argc, char *argv[])
{
	//Create the mutex
	mutex = SDL_CreateMutex();

	if(mutex == NULL)
	{
		printf("Failed to create mutex");
		return 1;
	}

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
	printf("ID: Thread counter divided by number of threads (%d): %d\n", numThreads, globalVar / numThreads);
	
	//Delete allocated memory
	delete[] threads;

	//Delete global variable mutex
	SDL_DestroyMutex(mutex);

	return 0;
}
