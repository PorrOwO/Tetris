#pragma once

#include <iostream>

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

    const int BOARD_WIDTH = 10;
    const int BOARD_HEIGHT = 20;

    const int NUM_OPTIONS = 3;
    const std::string OPTION_1 = "NEWGAME";
    const std::string OPTION_2 = "LEADERBOARD";
    const std::string OPTION_3 = "EXIT";
}
