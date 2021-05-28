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

// Define Menu options
#define     NEWGAME         1
#define     LOADGAME        2
#define     SHOWCREDIT      3
#define     HELP            4
#define     QUIT            5

// Define Board Max Size
#define     BOARD_SIZE          26
#define     START_SIZE          6
#define     NUM_OF_EACH_TILE    2
#define     MAX_NUM_OF_TILE     72

// Define player size
#define     MIN_PLAYERS     2
#define     THREE_PLAYERS   3
#define     MAX_PLAYERS     4

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

#define     PLAYER3         6
#define     PLAYER3_SCORE   7
#define     PLAYER3_HAND    8

#define     PLAYER4         9
#define     PLAYER4_SCORE   10
#define     PLAYER4_HAND    11

#define     BOARD_Size      12

#define     BOARD           13
#define     BAG             14
#define     CURRENT_PLAYER  15

#define     ZERO_CHAR      '0'
#define     A_CHAR         'A'

// Define Game Rules
#define     WIN_BONUS       6

// Define regex for user's commands
#define     REGTILEPLACE   "^\t*\\s*(place)\t*\\s*([R|O|Y|G|B|P][1-6])\t*\\s*(at)\t*\\s*([A-Z])([0-9]|1[0-9]|2[0-5])$"
#define     REGTILEREPLA   "^\t*\\s*(replace)\t*\\s*([R|O|Y|G|B|P][1-6])$"
#define     REGEXIT        "^\t*\\s*(quit|exit)$"
#define     REGSAVE        "^\t*\\s*(save)\t*\\s*([a-z0-9]+)$"
#define     REGHELP        "^\t*\\s*(help|guide)$"
#define     REGCOLORFUL    "^\t*\\s*(enable)\t*\\s*(colorful)$"
#define     REGCOLORLESS   "^\t*\\s*(disable)\t*\\s*(colorful)$"

#define     SAVEFOLDER     "save_game/"

#endif // ASSIGN2_TYPE_H