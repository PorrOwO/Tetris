#pragma once

#include <iostream>
#include <ncurses.h>

namespace utils {
    const int SHAPE_1[4][4] = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    const int SHAPE_2[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    const int SHAPE_3[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0}
    };

    const int SHAPE_4[4][4] = {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    const int SHAPE_5[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0}
    };

    const int SHAPE_6[4][4] = {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0}
    };

    const int SHAPE_7[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0}
    };

    // --- Board Dimensions --- //
    const int BOARD_WIDTH = 20;
    const int BOARD_HEIGHT = 20;
    
    // --- Menu Options --- //
    const int NUM_OPTIONS = 3;
    const std::string OPTION_1 = "NEWGAME";
    const std::string OPTION_2 = "LEADERBOARD";
    const std::string OPTION_3 = "EXIT";

    // --- Colors --- //
    const int RED = 1;
    const int GREEN = 2;
    const int YELLOW = 3;
    const int BLUE = 4;
    const int PURPLE = 5;
    const int CYAN = 6;
    const int ORANGE = 7;   

    // --- Multiplier --- //
    const int MULTIPLIER = 500;
}
