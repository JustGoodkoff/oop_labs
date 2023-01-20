cmake_minimum_required(VERSION 3.20)
project(Life)

set(CMAKE_CXX_STANDARD 14)
set(Headers GameInterface.h Game.h CommandLineParser.h OnlineGameMode.h OfflineGameMode.h CmdParsedData.h InputFileParser.h Universe.h FileParsedData.h)
set(Sources main.cpp CommandLineParser.cpp GameInterface.cpp Game.cpp OnlineGameMode.cpp OfflineGameMode.cpp CmdParsedData.cpp InputFileParser.cpp Universe.cpp FileParsedData.cpp)

add_executable(Life ${Sources} ${Headers})
