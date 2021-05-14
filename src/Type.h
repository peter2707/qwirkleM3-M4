#ifndef ASSIGN2_TYPE_H
#define ASSIGN2_TYPE_H

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

// Define Row
typedef char Row;

// Define Col
typedef int Col;

// Define Board Max Size
#define     BOARD_SIZE      26
#define     START_SIZE      6

// Define player size
#define     PLAYERS         2

// Define Colwidth
#define     COLWID          3

// Define Regex
#define     REGEX_SAVE      2
#define     REGEX_TILE      2
#define     REGEX_ROW       4
#define     REGEX_COL       5

// Define for loading board tile
#define     COLOUR          0
#define     SHAPE           1
#define     ROW             3
#define     COL             4

// Define each row in the save file
#define     PLAYER1         0
#define     PLAYER1_SCORE   1
#define     PLAYER1_HAND    2


#define     PLAYER2         3
#define     PLAYER2_SCORE   4
#define     PLAYER2_HAND    5

#define     BOARD_Size      6

#define     BOARD           7
#define     BAG             8
#define     CURRENT_PLAYER  9

#define     ZERO_CHAR      '0'
#define     A_CHAR         'A'

#define     REGTILEPLACE   "^(place) ([R|O|Y|G|B|P][1-6]) (at) ([A-Z])([0-9]|1[0-9]|2[0-5])$"
#define     REGTILEREPLA   "^(replace) ([R|O|Y|G|B|P][1-6])$"
#define     REGEXIT        "^(quit|exit)$"
#define     REGSAVE        "^(save) ([a-z0-9]+)$"

#define     SAVEFOLDER     "save_game/"

#endif // ASSIGN2_TYPE_H