#include "QuartoGame.h"
#include "Board.h"
#include "UnusedPieces.h"
#include "Player.h"
#include "BoardStateChecker.h"

#include <string>
void QuartoGame::Run()
{
    // initialization
    Board board;
    UnusedPieces unusedPieces;

    std::string playerName;
    std::cout << "First player name: ";
    std::cin >> playerName;
    Player firstPlayer(playerName);

    std::cout << "Second player name: ";
    std::cin >> playerName;
    Player secondPlayer(playerName);

    std::reference_wrapper<Player> pickingPlayer = firstPlayer; 
    //se comporta la fel ca ref firstPlayer dar nu detine controlul
    
    std::reference_wrapper<Player> placingPlayer = secondPlayer;

    // main loop
    while (true)
    {
        system("cls");

        std::cout << "The board looks like this:\n";
        std::cout << board << std::endl;
        std::cout << "The unused pieces are the following:\n";
        std::cout << unusedPieces << std::endl;

        std::cout << pickingPlayer << ", you should pick a piece for " << placingPlayer << std::endl;

        Piece pickedPiece;
        while (true)
        {
            try
            {
                pickedPiece = std::move(pickingPlayer.get().PickPiece(std::cin, unusedPieces));
                break;
            }
            catch (const char* errorMessage)
            {
                std::cout << errorMessage << std::endl;
            }
        }

        std::cout << placingPlayer << ", you should place the piece on the board" << std::endl;

        Board::Position placedPosition;
        while (true)
        {
            try
            {
                placedPosition = pickingPlayer.get().PlacePiece(std::cin, std::move(pickedPiece), board);
                break;
            }
            catch (const char* errorMessage)
            {
                std::cout << errorMessage << std::endl;
            }
        }

        auto state = BoardStateChecker::Check(board, placedPosition);
        if (state == BoardStateChecker::State::Win)
        {
            std::cout << board;
            std::cout << "We have a winner!\nCongratulations: " << pickingPlayer << std::endl;
            break;
        }
        else if (state == BoardStateChecker::State::Draw)
        {
            std::cout << "Unfortunately we have a draw :(" << std::endl;
            break;
        }

        std::swap(pickingPlayer, placingPlayer);
    }
}