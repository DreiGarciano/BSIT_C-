#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    // Stats
    string playerName;
    int playerHP = 100;
    int playerMP = 50;
    int enemyHP  = 80;

    string enemyName = "Icarus";
    int choice;
    int round = 1;

    cout << "\n+----------------------------------+\n";
    cout << "|          RPG BATTLE              |\n";
    cout << "+----------------------------------+\n";
    cout << "  Enter your hero's name: ";
    cin >> playerName;

    cout << "\n  A wild " << enemyName << " appears!\n";
    cout << "  Prepare for battle, " << playerName << "!\n";

    // Battle Loop
    do {
        cout << "\n----------------------------------\n";
        cout << "            ROUND " << round << "\n";
        cout << "----------------------------------\n";

        // Display HP bar using 4 loop
        cout << "  " << playerName << " HP: [";
        for (int i = 0; i < 10; i++) {
            if (i < playerHP / 10) cout << "#";
            else                   cout << ".";
        }
        cout << "] " << playerHP << "/100\n";

        cout << "  " << playerName << " MP: [";
        for (int i = 0; i < 5; i++) {
            if (i < playerMP / 10) cout << "#";
            else                   cout << ".";
        }
        cout << "] " << playerMP << "/50\n";

        cout << "  " << enemyName << " HP: [";
        for (int i = 0; i < 8; i++) {
            if (i < enemyHP / 10) cout << "#";
            else                  cout << ".";
        }
        cout << "] " << enemyHP << "/80\n";

        // Moveset
        cout << "\n  Choose your action:\n";
        cout << "  1. World Cut Slash       (10-20 dmg)\n";
        cout << "  2. Katon no Jutsu   (25-35 dmg, costs 15 MP)\n";
        cout << "  3. Roulette of Death       (50/50)\n";
        cout << "  4. Sacred Restoration   (restore 20 HP)\n";
        cout << "\n  Enter choice: ";
        cin >> choice;

        int playerDmg = 0;
        int enemyDmg  = 0;

        // Player Moves
        switch (choice) {
            case 1:
                playerDmg = 10 + rand() % 11; // 10-20
                if (rand() % 5 == 0) {
                    playerDmg *= 2;
                    cout << "\n  CRITICAL HIT! ";
                } else {
                    cout << "\n  You used World Cut Slash! \n";
                }
                cout << "  Dealt " << playerDmg << " damage to " << enemyName << "!\n";
                enemyHP -= playerDmg;
                break;

			case 2:
                if (playerMP < 15) {

                    cout << "\n   Not enough MP! (15 MP required)\n";

                } else {

                    playerDmg = 25 + rand() % 11;
                    playerMP -= 15;

                    cout << "\n   You cast Katon no Jutsu!\n";
                    cout << "  Flames engulf's " << enemyName << "!\n";
                    cout << "  Dealt " << playerDmg << " damage!\n";

                    enemyHP -= playerDmg;
                }
                break;

            case 3: {

                cout << "\n  Roulette of Death Activated \n";
                cout << "  Fate begins to spin...\n";

                int gambleRoll = rand() % 2;

                if (gambleRoll == 0) {

                    cout << "\n   JACKPOT \n";
                    cout << "  A divine strike annihilates the "
                         << enemyName << " instantly!\n";

                    enemyHP = 0;

                } else {

                    cout << "\n   GAMBLE FAILED \n";
                    cout << "  The " << enemyName
                         << " counters with a fatal attack!\n";

                    playerHP = 0;
                }

                break;
            }

            case 4:

                if (playerHP == 100) {

                    cout << "\n   HP already full! \n";

                } else {

                    playerHP += 20;

                    if (playerHP > 100)
                        playerHP = 100;

                    cout << "\n   Sacred Restoration Activated!\n";
                    cout << "  Restored 20 HP.\n";
                }

                break;

            default:
                cout << "\n   Invalid action!\n";
                cout << "  You hesitated and lost your turn.\n";
        	}

        // Enemy Attacks
        if (enemyHP > 0 && playerHP > 0) {
            enemyDmg = 10 + rand() % 16; // 10-25

            if (enemyHP < 20) {
                enemyDmg += 10;
                cout << "  " << enemyName << " is ENRAGED and hits hard! Took " << enemyDmg << " damage!\n";
            } else {
                cout << "  " << enemyName << " strikes back! Took " << enemyDmg << " damage.\n";
            }

            playerHP -= enemyDmg;
            if (playerHP < 0) playerHP = 0;
        }

        round++;

    } while (playerHP > 0 && enemyHP > 0);

    // result
    cout << "\n----------------------------------\n";
    if (playerHP <= 0 && enemyHP <= 0) {
        cout << "   FINAL CLASH \n";
        cout << "  Both warriors unleash their ultimate power...\n";
        cout << "  The battlefield falls silent.\n";
        cout << "  Result: DRAW.\n";
    } else if (playerHP <= 0) {
        cout << "  DEFEAT \n";
        cout << "  " << enemyName << " has shattered your spirit.\n";
        cout << "  Darkness consumes the battlefield...\n";
        cout << "  \"" << playerName << "... your journey ends here.\"\n";
    } else {
        cout << "   LEGENDARY VICTORY \n";
        cout << "  " << enemyName << " has fallen before your might!\n";
        cout << "  The crowd trembles at your overwhelming power.\n";
        cout << "  " << playerName << " stands undefeated.\n";
        cout << "  Cleared in " << round - 1
             << " rounds with " << playerHP
             << " HP remaining.\n";
    }

    cout << "========================================\n";

    return 0;
}
