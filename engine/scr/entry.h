#include "core/application.h"
#include "core/logger.h"
#include "game_types.h"

//Externally-defined function
extern b8 create_game(game* out_game);

/*
Main entry point of the application
*/
int main(void) {

    //Request the game instance frome the application
    game game_inst;
    if (!create_game(&game_inst)) {
        KFATAL("Could not create game!");
        return -1; //False
    }

    //Ensure the function pointers exist
    if (!game_inst.render || !game_inst.update || !game_inst.initialize || !game_inst.on_resize){
        KFATAL("The game's function pointers must be assigned!");
        return -2; //False
    }

    //Initialization
    if (!application_create(&game_inst)) {
        KINFO("Application failed to create!\n");
        return 1;  //False
    }

    //Begin the game loop.
    if (!application_run()) {
        KINFO("Application did not shutdown gracefully\n");
        return 2; //False
    }

    return 0;
}