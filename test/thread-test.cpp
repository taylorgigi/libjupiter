#include <unistd.h>
#include <functional>
#include "../Thread.h"

void hello()
{
	int i = 0;
	while(i++ < 10) {
		printf("hi ...\n");
		sleep(1);
	}
}

int main(int argc, char *argv[])
{
	jupiter::Thread thread(std::bind(&hello), "thread1");

	thread.launch();

	thread.join();

	return 0;
}

