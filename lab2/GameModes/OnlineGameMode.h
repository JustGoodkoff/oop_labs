//
// Created by 79631 on 18.01.2023.
//

#ifndef LIFE_ONLINEGAMEMODE_H
#define LIFE_ONLINEGAMEMODE_H

#include "../Universe.h"
#include "../Game.h"

namespace GameOfLife {

    static const std::string kFirstMessage = "Type <help> to see all commands\n";
    static const std::string kHelpMessage = "dump <filename> - save universe to file \n"
                                            "tick <n=1> - calculate n (default 1) iterations and print the result.\n"
                                            "exit - close this game\n"
                                            "help - print a command sheet\n";
    static const std::string kIncorrectNumberOfTicks = "Incorrectly entered number of ticks, try again\n";
    static const std::string kDumpCommand = "dump";
    static const std::string kTickCommand = "tick";
    static const int kTickCommandLength = 4;
    static const std::string kExitCommand = "exit";
    static const std::string kHelpCommand = "help";
    static const std::string kEnterCommand = "Enter command: ";
    static const std::string kIncorrectOutputFilename = "Incorrectly entered file name, the default value is set to default_output.txt\n";


    class OnlineGameMode : Game {
    public:
        static void startOnlineGame(Universe *universe);

    };

}
#endif //LIFE_ONLINEGAMEMODE_H
