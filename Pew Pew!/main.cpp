#include "Game/Game.h"

#include <stdexcept>
#include <iostream>

int main() {
	try {
    Pew::Game game;
		game.run();
	} catch (std::exception& e) {
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}