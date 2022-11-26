cmake_minimum_required(VERSION 3.23)
project(RpgHelper C)

set(CMAKE_C_STANDARD 99)

add_executable(RpgHelper main.c src/table.c src/sheet.c headers/sheetH.h headers/tableH.h src/Menus/menusH.c headers/menusH.h src/section.c headers/sectionH.h src/sqlTest.c)
