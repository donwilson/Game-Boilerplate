#include <iostream>

#include "game.hpp"
#include "level.hpp"

int main() {
	Game game(800.0f, 600.0f, "NEW PROJECT");
	Level level(&game);
	
	while(game.isRunning()) {
		// tick game
		game.tick();
		
		// stop animating if we shouldn't be
		if(!game.isAnimating()) {
			continue;
		}
		
		// update level tick
		level.update();
		
		// clear screen
		game.clear();
		
		// draw level
		level.draw();
		
		// draw game parts
		game.draw();
		
		// render screen
		game.render();
	}
	
	return 0;
}