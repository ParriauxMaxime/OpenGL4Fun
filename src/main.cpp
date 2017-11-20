#include <iostream>
#include <stdlib.h>
#include "Engine.hpp"
#include <csignal>

void signalHandler (int signum) {
	exit (signum);
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	Engine *engine = new Engine();

	signal(SIGINT, signalHandler);
	engine->run();
	return 0;
}
