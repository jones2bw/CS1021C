/*
 * Project Title:
 * - Chess
 * Description: (should be a few sentences)
 * - Operates the game of chess, using 3 different classes
 * - Has a piece class, a coordinate class, and a board class
 * - The piece class assigns player values, piece names, and piece displays
 * - The coordinate class assigns a row value, column value, and a piece object
 * - The board class is what the user actually interacts with, making a 2d array of coordinates and a display board based on the 2d array that goes with it
 *
 * Developers:
 * - Brandon Jones - jones2bw@mail.uc.edu
 *
 * Special Instructions:
 * - Enter moves in the form "CR CR" where C is the column and R is the row, the first set being the piece you want to move and the second set being the spot you want to move to
 *
 * Developer comments: // Not optional
 * Developer 1:
 * Created the layout for the code and created functions for checking validity of the different pieces
 * I learned a lot from working on this project, especially how intricate code can get when you are trying to keep track of several different classes interacting at once
 * One thing that would have made this project move smoother would have been more initial planning of the code instead of trying to hop right into and go as it went
 * Lots of times, I found myself having to change functions because I didn't plan in advance how I would actually implement them and wasted time because of it
 */

#include <iostream>
#include <string>

using namespace std;

// The piece class will create a piece object that stores the piece's name, which player the piece belongs to, and the character associated with that piece

class Piece {

public:
    // Default case for a piece assigns teh name to N/a and player 1 and displays as an empty character
    Piece() {
        pieceName = "N/a";
        player = 0;
        pieceDisplay = ' ';
        moves = 0;
    }

    // Makes piece object based on input, will assign a character based on piece name
    Piece(string pieceNameNew, int playerNew) {
        setPiece(pieceNameNew, playerNew);
        moves = 0;
        setChar();
    }

    // Sets the values of a piece based on input
    void setPiece(string pieceNameNew, int playerNew) {
        pieceName = pieceNameNew;
        player = playerNew;
        setChar();
    }

    // Will assign the appropriate character to a piece based on its name
    void setChar() {
        if (pieceName == "Pawn" || pieceName == "pawn")
            pieceDisplay = 'P';
        else if (pieceName == "Rook" || pieceName == "rook")
            pieceDisplay = 'R';
        else if (pieceName == "Knight" || pieceName == "knight")
            pieceDisplay = 'N';
        else if (pieceName == "Bishop" || pieceName == "bishop")
            pieceDisplay = 'B';
        else if (pieceName == "Queen" || pieceName == "queen")
            pieceDisplay = 'Q';
        else if (pieceName == "King" || pieceName == "king")
            pieceDisplay = 'K';
        else
            pieceDisplay = ' ';
    }

    string getPieceName() {
        return pieceName;
    }

    int getPlayer() {
        return player;
    }

    char getPieceDisplay() {
        return pieceDisplay;
    }

    int getMoves() {
        return moves;
    }

    void setPlayer(int p) {
        player = p;
    }

    void incMove() {
        moves++;
    }

    // Checks to make sure that the piece is valid
    bool validPiece() {
        if (pieceDisplay == ' ' || player != 1 || player != 2)
            return false;
        else
            return true;
    }

private:
    string pieceName;
    int player;
    char pieceDisplay;
    int moves;

};

// Creates a coordinate object that will have a row and column based on the chess board so the row will be an int 1-8 and the column will be a char A-H
// Each coordinate will also have a piece associated with it

class Coordinate {

    // Overloading operaters mostly for testing usage

    friend ostream& operator<<(ostream& output, Coordinate& C) {
        output << C.column << C.row << " " << C.p.getPieceDisplay();
        return output;
    }

    friend istream& operator>>(istream& input, Coordinate& C) {
        input >> C.row >> C.column;
        return input;
    }

public:
    // Creates a default coordinate at A1 with a default piece
    Coordinate() {
        Piece empty;
        setCoordinate('A', 1, empty);
    }

    // Creates a coordinate based on the inputs
    Coordinate(char c, int r, Piece p1) {
        setCoordinate(c, r, p1);
    }

    // Sets the coordinate values based on the inputs
    void setCoordinate(char c, int r, Piece p1) {
        row = r;
        column = c;
        p = p1;
    }

    int getRow() {
        return row;
    }

    char getColumn() {
        return column;
    }

    Piece getPiece() {
        return p;
    }

private:
    int row;
    char column;
    Piece p;
};

class Board {

public:
    // Creates the chess board for the game, will always be the default case
    Board() {
        setPiecesP1();
        setPiecesP2();
        fillCoordinates();
        fillMap();
        setDisplayBoard();
    }

    // Creates a piece object for all the pieces for player 1
    void setPiecesP1() {
        P1_1.setPiece("Pawn", 1);
        P2_1.setPiece("Pawn", 1);
        P3_1.setPiece("Pawn", 1);
        P4_1.setPiece("Pawn", 1);
        P5_1.setPiece("Pawn", 1);
        P6_1.setPiece("Pawn", 1);
        P7_1.setPiece("Pawn", 1);
        P8_1.setPiece("Pawn", 1);
        R1_1.setPiece("Rook", 1);
        R2_1.setPiece("Rook", 1);
        B1_1.setPiece("Bishop", 1);
        B2_1.setPiece("Bishop", 1);
        N1_1.setPiece("Knight", 1);
        N2_1.setPiece("Knight", 1);
        Q_1.setPiece("Queen", 1);
        K_1.setPiece("King", 1);
    }

    // Creates a piece object for all the pieces for player 2
    void setPiecesP2() {
        P1_2.setPiece("Pawn", 2);
        P2_2.setPiece("Pawn", 2);
        P3_2.setPiece("Pawn", 2);
        P4_2.setPiece("Pawn", 2);
        P5_2.setPiece("Pawn", 2);
        P6_2.setPiece("Pawn", 2);
        P7_2.setPiece("Pawn", 2);
        P8_2.setPiece("Pawn", 2);
        R1_2.setPiece("Rook", 2);
        R2_2.setPiece("Rook", 2);
        B1_2.setPiece("Bishop", 2);
        B2_2.setPiece("Bishop", 2);
        N1_2.setPiece("Knight", 2);
        N2_2.setPiece("Knight", 2);
        Q_2.setPiece("Queen", 2);
        K_2.setPiece("King", 2);
    }

    // Creates the board that the user will interact with
    // Most of this board is for show and will not have any functional value for the 2d array
    void setDisplayBoard() {
        for (int r = 0; r < 19; r++) {
            for (int c = 0; c < 38; c++) {
                if (c < 5 && (r % 2 == 0 && r < 17)) {
                    displayBoard[r][c] = ' ';
                }
                else if (c >= 5 && (r % 2 == 0 && r < 17)) {
                    displayBoard[r][c] = '-';
                }
                if (c < 5 && (r % 2 != 0 && r < 17)) {
                    if (r == 1) {
                        if (c == 2)
                            displayBoard[r][c] = '8';
                        else
                            displayBoard[r][c] = ' ';
                    }
                    if (r == 3) {
                        if (c == 2)
                            displayBoard[r][c] = '7';
                        else
                            displayBoard[r][c] = ' ';
                    }
                    if (r == 5) {
                        if (c == 2)
                            displayBoard[r][c] = '6';
                        else
                            displayBoard[r][c] = ' ';
                    }
                    if (r == 7) {
                        if (c == 2)
                            displayBoard[r][c] = '5';
                        else
                            displayBoard[r][c] = ' ';
                    }
                    if (r == 9) {
                        if (c == 2)
                            displayBoard[r][c] = '4';
                        else
                            displayBoard[r][c] = ' ';
                    }
                    if (r == 11) {
                        if (c == 2)
                            displayBoard[r][c] = '3';
                        else
                            displayBoard[r][c] = ' ';
                    }
                    if (r == 13) {
                        if (c == 2)
                            displayBoard[r][c] = '2';
                        else
                            displayBoard[r][c] = ' ';
                    }
                    if (r == 15) {
                        if (c == 2)
                            displayBoard[r][c] = '1';
                        else
                            displayBoard[r][c] = ' ';
                    }
                }
                else if (c >= 5 && (r % 2 != 0 && r < 17)) {
                    if (c == 5 || c == 9 || c == 13 || c == 17 || c == 21 || c == 25 || c == 29 || c == 33 || c == 37)
                        displayBoard[r][c] = '|';
                    else {
                        displayBoard[r][c] = ' ';
                    }
                }
                else if (r == 17) {
                    displayBoard[r][c] = ' ';
                }
                else if (r == 18) {
                    if (c == 7)
                        displayBoard[r][c] = 'A';
                    else if (c == 11)
                        displayBoard[r][c] = 'B';
                    else if (c == 15)
                        displayBoard[r][c] = 'C';
                    else if (c == 19)
                        displayBoard[r][c] = 'D';
                    else if (c == 23)
                        displayBoard[r][c] = 'E';
                    else if (c == 27)
                        displayBoard[r][c] = 'F';
                    else if (c == 31)
                        displayBoard[r][c] = 'G';
                    else if (c == 35)
                        displayBoard[r][c] = 'H';
                    else {
                        displayBoard[r][c] = ' ';
                    }
                }
            }
        }
        updateBoard();
    }

    // Creates a coordinate object for every spot on the board
    // Assigns the appropriate piece to each coordinate for the start of the game
    // Every spot that that doesn't have a piece to start is assigned the default empty piece
    void fillCoordinates() {
        Piece empty;

        A1.setCoordinate('A', 1, R1_1);
        B1.setCoordinate('B', 1, N1_1);
        C1.setCoordinate('C', 1, B1_1);
        D1.setCoordinate('D', 1, K_1);
        E1.setCoordinate('E', 1, Q_1);
        F1.setCoordinate('F', 1, B2_1);
        G1.setCoordinate('G', 1, N2_1);
        H1.setCoordinate('H', 1, R2_1);

        A2.setCoordinate('A', 2, P1_1);
        B2.setCoordinate('B', 2, P2_1);
        C2.setCoordinate('C', 2, P3_1);
        D2.setCoordinate('D', 2, P4_1);
        E2.setCoordinate('E', 2, P5_1);
        F2.setCoordinate('F', 2, P6_1);
        G2.setCoordinate('G', 2, P7_1);
        H2.setCoordinate('H', 2, P8_1);

        A3.setCoordinate('A', 3, empty);
        B3.setCoordinate('B', 3, empty);
        C3.setCoordinate('C', 3, empty);
        D3.setCoordinate('D', 3, empty);
        E3.setCoordinate('E', 3, empty);
        F3.setCoordinate('F', 3, empty);
        G3.setCoordinate('G', 3, empty);
        H3.setCoordinate('H', 3, empty);

        A4.setCoordinate('A', 4, empty);
        B4.setCoordinate('B', 4, empty);
        C4.setCoordinate('C', 4, empty);
        D4.setCoordinate('D', 4, empty);
        E4.setCoordinate('E', 4, empty);
        F4.setCoordinate('F', 4, empty);
        G4.setCoordinate('G', 4, empty);
        H4.setCoordinate('H', 4, empty);

        A5.setCoordinate('A', 5, empty);
        B5.setCoordinate('B', 5, empty);
        C5.setCoordinate('C', 5, empty);
        D5.setCoordinate('D', 5, empty);
        E5.setCoordinate('E', 5, empty);
        F5.setCoordinate('F', 5, empty);
        G5.setCoordinate('G', 5, empty);
        H5.setCoordinate('H', 5, empty);

        A6.setCoordinate('A', 6, empty);
        B6.setCoordinate('B', 6, empty);
        C6.setCoordinate('C', 6, empty);
        D6.setCoordinate('D', 6, empty);
        E6.setCoordinate('E', 6, empty);
        F6.setCoordinate('F', 6, empty);
        G6.setCoordinate('G', 6, empty);
        H6.setCoordinate('H', 6, empty);

        A7.setCoordinate('A', 7, P1_2);
        B7.setCoordinate('B', 7, P2_2);
        C7.setCoordinate('C', 7, P3_2);
        D7.setCoordinate('D', 7, P4_2);
        E7.setCoordinate('E', 7, P5_2);
        F7.setCoordinate('F', 7, P6_2);
        G7.setCoordinate('G', 7, P7_2);
        H7.setCoordinate('H', 7, P8_2);

        A8.setCoordinate('A', 8, R1_2);
        B8.setCoordinate('B', 8, N1_2);
        C8.setCoordinate('C', 8, B1_2);
        D8.setCoordinate('D', 8, K_2);
        E8.setCoordinate('E', 8, Q_2);
        F8.setCoordinate('F', 8, B2_2);
        G8.setCoordinate('G', 8, N2_2);
        H8.setCoordinate('H', 8, R2_2);
    }

    // Assigns the predifened coordinate objects to a 2d coordinate array called map
    // This is the array that the game will actually function from, not the character array being displayed
    void fillMap() {
        map[0][0] = A8;
        map[0][1] = B8;
        map[0][2] = C8;
        map[0][3] = D8;
        map[0][4] = E8;
        map[0][5] = F8;
        map[0][6] = G8;
        map[0][7] = H8;

        map[1][0] = A7;
        map[1][1] = B7;
        map[1][2] = C7;
        map[1][3] = D7;
        map[1][4] = E7;
        map[1][5] = F7;
        map[1][6] = G7;
        map[1][7] = H7;

        map[2][0] = A6;
        map[2][1] = B6;
        map[2][2] = C6;
        map[2][3] = D6;
        map[2][4] = E6;
        map[2][5] = F6;
        map[2][6] = G6;
        map[2][7] = H6;

        map[3][0] = A5;
        map[3][1] = B5;
        map[3][2] = C5;
        map[3][3] = D5;
        map[3][4] = E5;
        map[3][5] = F5;
        map[3][6] = G5;
        map[3][7] = H5;

        map[4][0] = A4;
        map[4][1] = B4;
        map[4][2] = C4;
        map[4][3] = D4;
        map[4][4] = E4;
        map[4][5] = F4;
        map[4][6] = G4;
        map[4][7] = H4;

        map[5][0] = A3;
        map[5][1] = B3;
        map[5][2] = C3;
        map[5][3] = D3;
        map[5][4] = E3;
        map[5][5] = F3;
        map[5][6] = G3;
        map[5][7] = H3;

        map[6][0] = A2;
        map[6][1] = B2;
        map[6][2] = C2;
        map[6][3] = D2;
        map[6][4] = E2;
        map[6][5] = F2;
        map[6][6] = G2;
        map[6][7] = H2;

        map[7][0] = A1;
        map[7][1] = B1;
        map[7][2] = C1;
        map[7][3] = D1;
        map[7][4] = E1;
        map[7][5] = F1;
        map[7][6] = G1;
        map[7][7] = H1;
    }

    // This will return the coordinate at the [r][c] value of the map array
    Coordinate getMapCoordinate(int r, int c) {
        return map[r][c];
    }

    // This is mostly for testing to display the elements of each coordinate in map[][]
    void displayMap() {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                cout << map[r][c].getColumn() << map[r][c].getRow() << "_" << map[r][c].getPiece().getPieceDisplay() << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Will update the character array based on changes made to map[][]
    void updateBoard() {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                displayBoard[(2 * r) + 1][(4 * c) + 7] = map[r][c].getPiece().getPieceDisplay();
            }
        }
    }

    // The funcction that actually displays the character board
    void displayCharacterBoard() {
        for (int r = 0; r < 19; r++) {
            for (int c = 0; c < 38; c++) {
                cout << displayBoard[r][c];
            }
            cout << endl;
        }
        cout << endl;
    }

    // Will switch the coordinates of the two sets of [r][c] values
    // In actuality, it only switches the piece elements of the coordinates so that the rows and columns remain constant
    // Deletes the piece that gets swapped
    // Displays message when a piece is taken
    void switchCoordinates(char c1, int r1, char c2, int r2) {
        Coordinate start = getMapCoordinate(8 - r1, charColtoInt(c1));
        Coordinate end = getMapCoordinate(8 - r2, charColtoInt(c2));

        Piece empty;
        Piece startPiece = start.getPiece();
        Piece endPiece = end.getPiece();
        int startPlayer = start.getPiece().getPlayer();
        int endPlayer = end.getPiece().getPlayer();
        char startChar = startPiece.getPieceDisplay();
        char endChar = endPiece.getPieceDisplay();
        start.setCoordinate(c1, r1, empty);
        end.setCoordinate(c2, r2, startPiece);

        start.getPiece().setPlayer(endPlayer);
        end.getPiece().setPlayer(startPlayer);

        map[8 - r1][charColtoInt(c1)] = start;
        map[8 - r2][charColtoInt(c2)] = end;

        map[8 - r2][charColtoInt(c2)].getPiece().incMove();

        updateBoard();

        if (start.getPiece().getPlayer() != end.getPiece().getPlayer() && startChar != ' ' && endChar != ' ') {
            cout << endl << "* Player " << startPlayer << " took Player " << endPlayer << "'s " << endPiece.getPieceName() << " *" << endl << endl;
        }
    }

    // Assigns the inputted character for the column based on the display board to the actual column integer associated with that column in map[][]
    int charColtoInt(char c) {
        int ret;

        if (c == 'A') {
            ret = 0;
        }
        else if (c == 'B') {
            ret = 1;
        }
        else if (c == 'C') {
            ret = 2;
        }
        else if (c == 'D') {
            ret = 3;
        }
        else if (c == 'E') {
            ret = 4;
        }
        else if (c == 'F') {
            ret = 5;
        }
        else if (c == 'G') {
            ret = 6;
        }
        else if (c == 'H') {
            ret = 7;
        }
        else {
            ret = 9;
        }

        return ret;
    }

    char intToChar(int c) {
        if (c == 0) {
            return 'A';
        }
        else if (c == 1) {
            return 'B';
        }
        else if (c == 2) {
            return 'C';
        }
        else if (c == 3) {
            return 'D';
        }
        else if (c == 4) {
            return 'E';
        }
        else if (c == 5) {
            return 'F';
        }
        else if (c == 6) {
            return 'G';
        }
        else if (c == 7) {
            return 'H';
        }
        else {
            return ' ';
        }
    }

    // Checks validity of movements for pawn
    // Makes sure that the pawn can only move one space forward
    // Checks each exception to this rule such as how the pawn can move two spaces forward if it's the first time it has moved
    // Also checks to see if the diagonally forward moves are other player's pieces. If so, it is a valid move
    // Checks to see if there is a player in front
    // Makes sure that if a 2 space move is used, the pawn doesn't jump over a piece
    bool validPawnMove(char c1, int r1, char c2, int r2) {
        int intc1 = charColtoInt(c1);
        int intc2 = charColtoInt(c2);
        if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
            if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r2 - r1 == 1 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r2 - r1 == 1 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 1 && c2 - c1 == 0) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && getMapCoordinate(9 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 2 && c2 - c1 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
            if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r1 - r2 == 1 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r1 - r2 == 1 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 1 && c2 - c1 == 0) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && getMapCoordinate(9 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 2 && c2 - c1 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    // Checks the validity of rook movements
    // Has four for loops, one for each direction it can move
    // In each loop, it checks to make sure that the rook can't run into one of it's own pieces but it can take another player's piece
    // Also checks to make sure that the rook can't jump over other pieces
    // The only variation between checking each direction is the values iterated in the for loop and the placement of the i variable depending on if the row or column changes
    // For checking vertically up, it runs from the row above the piece until it reaches the top of the board
    // For checking vertically down, it runs from the row below the piece until it reaches the bottom of the board
    // For checking horizontally right, it runs from the column to the right of the piece until it reaches the very right of the board
    // For checking horizontally left, it runs from the column to the left of the piece until it reaches the very left of the board
    bool validRookMove(char c1, int r1, char c2, int r2) {
        int intc1 = charColtoInt(c1);
        int intc2 = charColtoInt(c2);
        int piecesInWay = 0;
        // Checks vertically up
        if (r2 - r1 > 0 && c1 - c2 == 0 && r1 != 8) {
            for (int i = r1 + 1; i < r2; i++) {
                if (getMapCoordinate(8 - i, intc1).getPiece().getPieceDisplay() != ' ') {
                    piecesInWay++;
                }
            }
            if (piecesInWay > 0) {
                return false;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ') {
                if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return true;
                    }
                }
                else if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return true;
                    }
                }
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ') {
                return true;
            }
            else {
                return false;
            }
        }
        // Checks vertically down
        else if (r1 - r2 > 0 && c1 - c2 == 0 && r1 != 1) {
            for (int i = r1 - 1; i > r2; i--) {
                if (getMapCoordinate(8 - i, intc1).getPiece().getPieceDisplay() != ' ') {
                    piecesInWay++;
                }
            }
            if (piecesInWay > 0) {
                return false;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ') {
                if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return true;
                    }
                }
                else if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return true;
                    }
                }
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ') {
                return true;
            }
            else {
                return false;
            }
        }
        // Checks horizontally right
        else if (r1 - r2 == 0 && c2 - c1 > 0 && c1 != 'H') {
            for (int i = intc1 + 1; i < intc2; i++) {
                if (getMapCoordinate(8 - r1, i).getPiece().getPieceDisplay() != ' ') {
                    piecesInWay++;
                }
            }
            if (piecesInWay > 0) {
                return false;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ') {
                if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return true;
                    }
                }
                else if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return true;
                    }
                }
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ') {
                return true;
            }
            else {
                return false;
            }
        }
        // Checks horizontally left
        else if (r1 - r2 == 0 && c1 - c2 > 0 && c1 != 'A') {
            for (int i = intc1 - 1; i > intc2; i--) {
                if (getMapCoordinate(8 - r1, i).getPiece().getPieceDisplay() != ' ') {
                    piecesInWay++;
                }
            }
            if (piecesInWay > 0) {
                return false;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ') {
                if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return true;
                    }
                }
                else if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return true;
                    }
                }
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ') {
                return true;
            }
            else {
                return false;
            }
        }
    }

    // Checks the validity of knight movements
    // The knight can only move in L type movements, 2 spaces extending from the piece and 1 space branching of the extension perpendicular
    // There are only 8 possible movement for the knight so this function checks each possible move
    // If the space is empty, the move is valid no matter what because knights can move over other pieces
    // If there is a piece in the desired coordinate, it checks to see if it is another player's piece, if so, it is valid
    bool validKnightMove(char c1, int r1, char c2, int r2) {
        int intc1 = charColtoInt(c1);
        int intc2 = charColtoInt(c2);
        if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
            if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 2 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r2 - r1 == 2 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 2 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r2 - r1 == 2 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 1 && c2 - c1 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r2 - r2 == 1 && c2 - c1 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 1 && c2 - c1 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r1 - r2 == 1 && c2 - c1 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 2 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r1 - r2 == 2 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 2 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r1 - r2 == 2 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 1 && c1 - c2 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r1 - r2 == 1 && c1 - c2 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 1 && c1 - c2 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r2 - r1 == 1 && c1 - c2 == 2) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
            if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 2 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r2 - r1 == 2 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 2 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r2 - r1 == 2 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 1 && c2 - c1 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r2 - r2 == 1 && c2 - c1 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 1 && c2 - c1 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r1 - r2 == 1 && c2 - c1 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 2 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r1 - r2 == 2 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 2 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r1 - r2 == 2 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 1 && c1 - c2 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r1 - r2 == 1 && c1 - c2 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 1 && c1 - c2 == 2) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r2 - r1 == 1 && c1 - c2 == 2) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    // Checks the validity of bishop movements
    // Runs a for loop for each possible direction it could move from the piece: diagonally upright, diagonally downright, diagonally upleft, and diagonally downleft
    // Checks to make sure that the bishop doesn't jump over other pieces and can only take another piece if it is the other player's
    // Each loop iterates by the variable i which will be the scalar of the [r][c] of the given piece
    // Each loop will stop if either the row has reached the edge of the board or the column has reached the edge of the board
    // The only variation for each loop is the sign of the i being added based on which direction it is going
    // For diagonally upright, [r+1][c+i]
    // For diagonally downright, [r-1][c+i]
    // For diagonally upleft, [r+1][c-i]
    // For diagonally downleft, [r-1][c-i]
    bool validBishopMove(char c1, int r1, char c2, int r2) {
        int intc1 = charColtoInt(c1);
        int intc2 = charColtoInt(c2);
        int piecesInWay = 0;
        int rDiff = abs(r2 - r1);
        int cDiff = abs(intc2 - intc1);
        // Checks diagonally upright
        if (r2 - r1 > 0 && c2 - c1 > 0 && r1 != 8 && rDiff == cDiff) {
            for (int i = 1; i < rDiff; i++) {
                if (getMapCoordinate(8 - i - r1, intc1 + i).getPiece().getPieceDisplay() != ' ') {
                    piecesInWay++;
                }
            }
            if (piecesInWay > 0) {
                return false;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ') {
                if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return true;
                    }
                }
                else if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return true;
                    }
                }
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ') {
                return true;
            }
            else {
                return false;
            }
        }

        // Checks diagonally downright
        else if (r2 - r1 < 0 && c2 - c1 > 0 && r1 != 1 && rDiff == cDiff) {
            for (int i = 1; i < rDiff; i++) {
                if (getMapCoordinate(8 + i - r1, intc1 + i).getPiece().getPieceDisplay() != ' ') {
                    piecesInWay++;
                }
            }
            if (piecesInWay > 0) {
                return false;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ') {
                if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return true;
                    }
                }
                else if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return true;
                    }
                }
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ') {
                return true;
            }
            else {
                return false;
            }
        }

        // Checks diagonally upleft
        else if (r2 - r1 > 0 && c2 - c1 < 0 && r1 != 8 && rDiff == cDiff) {
            for (int i = 1; i < rDiff; i++) {
                if (getMapCoordinate(8 - i - r1, intc1 - i).getPiece().getPieceDisplay() != ' ') {
                    piecesInWay++;
                }
            }
            if (piecesInWay > 0) {
                return false;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ') {
                if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return true;
                    }
                }
                else if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return true;
                    }
                }
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ') {
                return true;
            }
            else {
                return false;
            }
        }

        // Checks diagonally downleft
        else if (r2 - r1 < 0 && c2 - c1 < 0 && r1 != 1 && rDiff == cDiff) {
            for (int i = 1; i < rDiff; i++) {
                if (getMapCoordinate(8 - i - r1, intc1 - i).getPiece().getPieceDisplay() != ' ') {
                    piecesInWay++;
                }
            }
            if (piecesInWay > 0) {
                return false;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ') {
                if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return true;
                    }
                }
                else if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
                    if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2) {
                        return false;
                    }
                    else if (getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1) {
                        return true;
                    }
                }
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ') {
                return true;
            }
            else {
                return false;
            }
        }

        else {
            return false;
        }
    }

    // Checks the validity of a king move
    // King can only move in a 1 block radius around it leaving 8 possible options
    // Checks each possible option only being valid if the space is empty of has another player's piece in it
    bool validKingMove(char c1, int r1, char c2, int r2) {
        int intc1 = charColtoInt(c1);
        int intc2 = charColtoInt(c2);
        if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
            if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 1 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r2 - r1 == 1 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 0 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r2 - r1 == 0 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 1 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r1 - r2 == 1 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 1 && c2 - c1 == 0) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r1 - r2 == 1 && c2 - c1 == 0) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 1 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r1 - r2 == 0 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 0 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r1 - r2 == 0 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 1 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r2 - r1 == 1 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 1 && c1 - c2 == 0) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 2 && r2 - r1 == 1 && c1 - c2 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
            if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 1 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r2 - r1 == 1 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 0 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r2 - r1 == 0 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 1 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r1 - r2 == 1 && c2 - c1 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 1 && c2 - c1 == 0) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r1 - r2 == 1 && c2 - c1 == 0) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 1 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r1 - r2 == 0 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r1 - r2 == 0 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r1 - r2 == 0 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 1 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r2 - r1 == 1 && c1 - c2 == 1) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() == ' ' && r2 - r1 == 1 && c1 - c2 == 0) {
                return true;
            }
            else if (getMapCoordinate(8 - r2, intc2).getPiece().getPieceDisplay() != ' ' && getMapCoordinate(8 - r2, intc2).getPiece().getPlayer() == 1 && r2 - r1 == 1 && c1 - c2 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    // Chechs the validity of a queen's move
    // Queens can move either horizontally, vertically, or diagonally
    // This is a combination of the rook and bishop
    // If this move is valid for either a rook or a bishop, then it is also valid for a queen
    bool validQueenMove(char c1, int r1, char c2, int r2) {
        if (validRookMove(c1, r1, c2, r2) || validBishopMove(c1, r1, c2, r2)) {
            return true;
        }
        else {
            return false;
        }
    }

    // Assigns an integer identifier to each type of piece
    int whichPiece(char c, int r) {
        if (map[8 - r][charColtoInt(c)].getPiece().getPieceDisplay() == 'P') {
            return 1;
        }
        else if (map[8 - r][charColtoInt(c)].getPiece().getPieceDisplay() == 'R') {
            return 2;
        }
        else if (map[8 - r][charColtoInt(c)].getPiece().getPieceDisplay() == 'N') {
            return 3;
        }
        else if (map[8 - r][charColtoInt(c)].getPiece().getPieceDisplay() == 'B') {
            return 4;
        }
        else if (map[8 - r][charColtoInt(c)].getPiece().getPieceDisplay() == 'K') {
            return 5;
        }
        else if (map[8 - r][charColtoInt(c)].getPiece().getPieceDisplay() == 'Q') {
            return 6;
        }
        else {
            return 7;
        }
    }

    // Uses the integer identifier from whichPiece() to check which type of piece is being moved
    // Depending on the piece type, it checks the validity for that piece type
    // If the move is valid, it switches the pieces with swtichCoordinate()
    // This also updates the turn varaible so it becomes the other players turn
    // If it isn't valid, the player will be prompted to enter the move again until they enter a valid move and will then update the turn variable and switch to the other player
    void move(char& c1, int& r1, char& c2, int& r2, int& turn) {
        if (whichPiece(c1, r1) == 1) {
            if (validPawnMove(c1, r1, c2, r2)) {
                switchCoordinates(c1, r1, c2, r2);
                turn++;
            }
            else {
                while (!validPawnMove(c1, r1, c2, r2)) {
                    cout << endl << "Invalid Move" << endl << endl;
                    getCoorPairs(c1, r1, c2, r2, turn);
                }
            }
        }
        else if (whichPiece(c1, r1) == 2) {
            if (validRookMove(c1, r1, c2, r2)) {
                switchCoordinates(c1, r1, c2, r2);
                turn++;
            }
            else {
                while (!validRookMove(c1, r1, c2, r2)) {
                    cout << endl << "Invalid Move" << endl << endl;
                    getCoorPairs(c1, r1, c2, r2, turn);
                }
            }
        }
        else if (whichPiece(c1, r1) == 3) {
            if (validKnightMove(c1, r1, c2, r2)) {
                switchCoordinates(c1, r1, c2, r2);
                turn++;
            }
            else {
                while (!validKnightMove(c1, r1, c2, r2)) {
                    cout << endl << "Invalid Move" << endl << endl;
                    getCoorPairs(c1, r1, c2, r2, turn);
                }
            }
        }
        else if (whichPiece(c1, r1) == 4) {
            if (validBishopMove(c1, r1, c2, r2)) {
                switchCoordinates(c1, r1, c2, r2);
                turn++;
            }
            else {
                while (!validBishopMove(c1, r1, c2, r2)) {
                    cout << endl << "Invalid Move" << endl << endl;
                    getCoorPairs(c1, r1, c2, r2, turn);
                }
            }
        }
        else if (whichPiece(c1, r1) == 5) {
            if (validKingMove(c1, r1, c2, r2)) {
                switchCoordinates(c1, r1, c2, r2);
                turn++;
            }
            else {
                while (!validKingMove(c1, r1, c2, r2)) {
                    cout << endl << "Invalid Move" << endl << endl;
                    getCoorPairs(c1, r1, c2, r2, turn);
                }
            }
        }
        else if (whichPiece(c1, r1) == 6) {
            if (validQueenMove(c1, r1, c2, r2)) {
                switchCoordinates(c1, r1, c2, r2);
                turn++;
            }
            else {
                while (!validQueenMove(c1, r1, c2, r2)) {
                    cout << endl << "Invalid Move" << endl << endl;
                    getCoorPairs(c1, r1, c2, r2, turn);
                }
            }
        }
        else if (whichPiece(c1, r1) == 7) {
            while (whichPiece(c1, r1) == 7) {
                cout << endl << "Invalid Move" << endl << endl;
                getCoorPairs(c1, r1, c2, r2, turn);
            }
        }
    }

    // The function that prompts the user for their move and will assign the input to the appropriate [r][c] variables
    void getCoorPairs(char& c1, int& r1, char& c2, int& r2, int turn) {
        if (turn % 2 != 0) {
            cout << "Player 1 - Enter your move: ";
            cin >> c1 >> r1 >> c2 >> r2;
        }
        else {
            cout << "Player 2 - Enter your move: ";
            cin >> c1 >> r1 >> c2 >> r2;
        }

        if (!validEntry(c1, r1, c2, r2)) {
            cout << "Invalid Entry" << endl;
            getCoorPairs(c1, r1, c2, r2, turn);
        }
    }

    // Implements turn taking into the movement system
    void playerMove(char& c1, int& r1, char& c2, int& r2, int& turn) {
        int intc1 = charColtoInt(c1);
        //getCoorPairs(c1, r1, c2, r2, turn);
        if (turn % 2 != 0 && getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
            move(c1, r1, c2, r2, turn);
        }
        else if (turn % 2 != 0 && getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
            while (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
                cout << endl << "Not Your Piece" << endl << endl;
                getCoorPairs(c1, r1, c2, r2, turn);
            }
        }
        else if (turn % 2 == 0 && getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 2) {
            move(c1, r1, c2, r2, turn);
        }
        else if (turn % 2 == 0 && getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
            while (getMapCoordinate(8 - r1, intc1).getPiece().getPlayer() == 1) {
                cout << endl << "Not Your Piece" << endl << endl;
                getCoorPairs(c1, r1, c2, r2, turn);
            }
        }
    }

    // Makes sure that the entry for getCoorPairs() is valid
    bool validEntry(char c1, int r1, char c2, int r2) {
        if (c1 != 'A' && c1 != 'B' && c1 != 'C' && c1 != 'D' && c1 != 'E' && c1 != 'F' && c1 != 'G' && c1 != 'H') {
            return false;
        }
        else if (c2 != 'A' && c2 != 'B' && c2 != 'C' && c2 != 'D' && c2 != 'E' && c2 != 'F' && c2 != 'G' && c2 != 'H') {
            return false;
        }
        else if (r1 != 1 && r1 != 2 && r1 != 3 && r1 != 4 && r1 != 5 && r1 != 6 && r1 != 7 && r1 != 8) {
            return false;
        }
        else if (r2 != 1 && r2 != 2 && r2 != 3 && r2 != 4 && r2 != 5 && r2 != 6 && r2 != 7 && r2 != 8) {
            return false;
        }
        else {
            return true;
        }
    }

    // Searches the board and returns the r value for king 1
    int findKingR1() {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                if (getMapCoordinate(r, c).getPiece().getPieceDisplay() == 'K' && getMapCoordinate(r, c).getPiece().getPlayer() == 1) {
                    return r;
                }
            }
        }
    }

    // Searches the board and returns the c value for king 1
    int findKingC1() {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                if (getMapCoordinate(r, c).getPiece().getPieceDisplay() == 'K' && getMapCoordinate(r, c).getPiece().getPlayer() == 1) {
                    return c;
                }
            }
        }
    }

    // Searches the board and returns the r value for king 2
    int findKingR2() {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                if (getMapCoordinate(r, c).getPiece().getPieceDisplay() == 'K' && getMapCoordinate(r, c).getPiece().getPlayer() == 2) {
                    return r;
                }
            }
        }
    }

    // Searches the board and returns the c value for king 2
    int findKingC2() {
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                if (getMapCoordinate(r, c).getPiece().getPieceDisplay() == 'K' && getMapCoordinate(r, c).getPiece().getPlayer() == 2) {
                    return c;
                }
            }
        }
    }

    // Checks every spot on the board, if there is a piece and it is player two, it will check every spot on the board
    // If there is a spot on the board that is a valid move for that piece and the valid move is where the other players king is, it returns true
    // This one works specifically for player 1's king
    bool checkK1(int k1_r, int k1_c) {
        int countNumChecks = 0;
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                char charC = intToChar(c);
                if (map[r][c].getPiece().getPieceDisplay() != ' ' && map[r][c].getPiece().getPlayer() == 2) {
                    for (int r1 = 0; r1 < 8; r1++) {
                        for (int c1 = 0; c1 < 8; c1++) {
                            char charC1 = intToChar(c1);
                            if (whichPiece(charC, r) == 1 && validPawnMove(charC, r, charC1, r1) && c1 == k1_c && r1 == k1_r) {
                                countNumChecks++;
                            }
                            else if (whichPiece(charC, r) == 2 && validRookMove(charC, r, charC1, r1) && c1 == k1_c && r1 == k1_r) {
                                countNumChecks++;
                            }
                            else if (whichPiece(charC, r) == 3 && validKnightMove(charC, r, charC1, r1) && c1 == k1_c && r1 == k1_r) {
                                countNumChecks++;
                            }
                            else if (whichPiece(charC, r) == 4 && validBishopMove(charC, r, charC1, r1) && c1 == k1_c && r1 == k1_r) {
                                countNumChecks++;
                            }
                            else if (whichPiece(charC, r) == 5 && validKingMove(charC, r, charC1, r1) && c1 == k1_c && r1 == k1_r) {
                                countNumChecks++;
                            }
                            else if (whichPiece(charC, r) == 6 && validQueenMove(charC, r, charC1, r1) && c1 == k1_c && r1 == k1_r) {
                                countNumChecks++;
                            }
                        }
                    }
                }
            }
        }

        if (countNumChecks > 0) {
            return true;
        }
        else {
            return false;
        }
    }

    // Checks every spot on the board, if there is a piece and it is player two, it will check every spot on the board
    // If there is a spot on the board that is a valid move for that piece and the valid move is where the other players king is, it returns true
    // This one works specifically for player 1's king
    bool checkK2(int k2_r, int k2_c) {
        int countNumChecks = 0;
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                char charC = intToChar(c);
                if (map[r][c].getPiece().getPieceDisplay() != ' ' && map[r][c].getPiece().getPlayer() == 1) {
                    for (int r1 = 0; r1 < 8; r1++) {
                        for (int c1 = 0; c1 < 8; c1++) {
                            char charC1 = intToChar(c1);
                            if (whichPiece(charC, r) == 1 && validPawnMove(charC, r, charC1, r1) && c1 == k2_c && r1 == k2_r) {
                                countNumChecks++;
                            }
                            else if (whichPiece(charC, r) == 2 && validRookMove(charC, r, charC1, r1) && c1 == k2_c && r1 == k2_r) {
                                countNumChecks++;
                            }
                            else if (whichPiece(charC, r) == 3 && validKnightMove(charC, r, charC1, r1) && c1 == k2_c && r1 == k2_r) {
                                countNumChecks++;
                            }
                            else if (whichPiece(charC, r) == 4 && validBishopMove(charC, r, charC1, r1) && c1 == k2_c && r1 == k2_r) {
                                countNumChecks++;
                            }
                            else if (whichPiece(charC, r) == 5 && validKingMove(charC, r, charC1, r1) && c1 == k2_c && r1 == k2_r) {
                                countNumChecks++;
                            }
                            else if (whichPiece(charC, r) == 6 && validQueenMove(charC, r, charC1, r1) && c1 == k2_c && r1 == k2_r) {
                                countNumChecks++;
                            }
                        }
                    }
                }
            }
        }

        if (countNumChecks > 0) {
            return true;
        }
        else {
            return false;
        }
    }

    //    // Checks to see if every possible move for a king is in check, if so it's true
    //    bool checkmate() {

    //    }

private:
    Piece P1_1, P2_1, P3_1, P4_1, P5_1, P6_1, P7_1, P8_1, R1_1, R2_1, B1_1, B2_1, N1_1, N2_1, Q_1, K_1;
    Piece P1_2, P2_2, P3_2, P4_2, P5_2, P6_2, P7_2, P8_2, R1_2, R2_2, B1_2, B2_2, N1_2, N2_2, Q_2, K_2;
    Coordinate A1, A2, A3, A4, A5, A6, A7, A8;
    Coordinate B1, B2, B3, B4, B5, B6, B7, B8;
    Coordinate C1, C2, C3, C4, C5, C6, C7, C8;
    Coordinate D1, D2, D3, D4, D5, D6, D7, D8;
    Coordinate E1, E2, E3, E4, E5, E6, E7, E8;
    Coordinate F1, F2, F3, F4, F5, F6, F7, F8;
    Coordinate G1, G2, G3, G4, G5, G6, G7, G8;
    Coordinate H1, H2, H3, H4, H5, H6, H7, H8;
    char displayBoard[19][38];
    Coordinate map[8][8];
};

int main()
{
    bool finished = false;

    // Initial set up of the board
    Board B;
    B.displayCharacterBoard();
    int turn = 1;

    char col1;
    int row1;
    char col2;
    int row2;

    // Runs until one of the players has been put in check mate
    do {

        B.getCoorPairs(col1, row1, col2, row2, turn);
        B.playerMove(col1, row1, col2, row2, turn);
        B.displayCharacterBoard();
        //        if (B.checkK1(B.findKingR1(), B.findKingC1())) {
        //            cout << "Player 1 in check" << endl;
        //            B.getCoorPairs(col1, row1, col2, row2, turn);
        //        }
        //        if (B.checkK2(B.findKingR2(), B.findKingC2())) {
        //            cout << "Player 2 in check" << endl;
        //            B.getCoorPairs(col1, row1, col2, row2, turn);
        //        }
        //        if (B.checkmate()) {
        //            finished = true;
        //        }

    } while (finished == false);

    return 0;
}