#include <iostream>
#include <stdlib.h>
#include "Scene.hpp"
#include <csignal>

void signalHandler (int signum) {
	exit (signum);
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	Scene *scene = new Scene();
	signal(SIGINT, signalHandler);
	scene->RunEngine();
	return 0;
}
