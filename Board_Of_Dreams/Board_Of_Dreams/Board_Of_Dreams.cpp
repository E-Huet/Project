#include <iostream> /// std
#include <conio.h>  /// recup touches pour deplacements
#include <cstdlib>  /// random
#include <ctime>    /// random
#include <vector>   /// tableaux
#include <fstream>  /// lire fichiers txt
#include <string>   /// string

struct Case {
    int case_type = 0; // 0 = sol, 1 = montagne, 2 = eau, 3 = ennemi, 4 = hero
    bool traversable = false;
};

struct Character {
    int PV = 1;
    int x = 0;
    int y = 0;
};

struct Spell {
    int x = 0;
    int y = 0;
};

struct TailleGrid {
    int nb_cases = 0;
    int nb_lines = 0;
    int nb_columns = 0;
    int nb_ennemies = 0;
};

void get_taille_file(std::string chemin, TailleGrid& tailles)
{
    std::ifstream fichier(chemin);
    std::string ligne;
    if (!fichier) {
        std::cout << "Impossible d'ouvrir le fichier";
    }
    int lines_counter = 0;
    int columns_counter = 0;
    int ennemies_counter = 0;

    while (std::getline(fichier, ligne))
    {
        lines_counter++;
        for (int i = 0; i < ligne.length(); i++)
        {
            if (ligne[i] == 'X')
            {
                ennemies_counter++;
            }
            columns_counter++;
        }
    }
    tailles.nb_ennemies = ennemies_counter;
    tailles.nb_lines = lines_counter;
    tailles.nb_columns = columns_counter / lines_counter;
    tailles.nb_cases = tailles.nb_columns * tailles.nb_lines;
}

void grid_creation(std::string chemin, Case map[], Character& hero, std::vector<Character>& current_ennemies)
{
    std::ifstream fichier(chemin);
    std::string ligne;
    if (!fichier) {
        std::cout << "Impossible d'ouvrir le fichier";
        return;
    }
    int nb_case = 0;
    int compteur_lignes = 0;
    int ennemies_poses = 0;

    while (std::getline(fichier, ligne))
    {
        for (int i = 0; i < ligne.length(); i++)
        {
            if (ligne[i] == '.')
            {
                map[nb_case].case_type = 0;
                map[nb_case].traversable = true;
            }
            else if (ligne[i] == 'A')
            {
                map[nb_case].case_type = 1;
            }
            else if (ligne[i] == '~')
            {
                map[nb_case].case_type = 2;
            }
            else if (ligne[i] == 'E')
            {
                map[nb_case].case_type = 3;
                map[nb_case].traversable = true;
            }
            else if (ligne[i] == 'H')
            {
                map[nb_case].case_type = 0;
                map[nb_case].traversable = true;

                hero.x = i;
                hero.y = compteur_lignes;
            }
            else if (ligne[i] == 'X')
            {
                map[nb_case].case_type = 0;
                map[nb_case].traversable = true;

                current_ennemies[ennemies_poses].x = i;
                current_ennemies[ennemies_poses].y = compteur_lignes;
                ennemies_poses++;
            }
            nb_case++;
        }
        compteur_lignes++;
    }
}

void display_map(std::vector<Case> map, Character current_hero, TailleGrid tailles, std::vector<Character> ennemis, int nb_ennemis, Spell tab_spell[], bool spell_mod) /// break / continue
{
    for (int i = 0; i < tailles.nb_lines; i++)
    {
        for (int j = 0; j < tailles.nb_columns; j++)
        {
            //std::cout << map[i * tailles.nb_columns + j].spell;
            if (current_hero.x == j && current_hero.y == i)
            {
                std::cout << 'H';
            }
            else
            {
                bool ennemi = false;
                for (int k = 0; k < nb_ennemis; k++)
                {
                    if (ennemis[k].x == j && ennemis[k].y == i)
                    {
                        std::cout << 'X';
                        ennemi = true;
                    }
                }
                /*
                if (spell_mod = true)
                    for (int k = 0; k < 8; k++)
                    {
                        if(tab_spell[i].x == j && tab_spell[i].y == i)
                        {
                            std::cout << '*';
                        }
                    }
                }*/
                if (map[i * tailles.nb_columns + j].case_type == 0 && ennemi == false)
                {
                    std::cout << '.';
                }
                else if (map[i * tailles.nb_columns + j].case_type == 1 && ennemi == false)
                {
                    std::cout << 'A';
                }
                else if (map[i * tailles.nb_columns + j].case_type == 2 && ennemi == false)
                {
                    std::cout << '~';
                }
                else if (map[i * tailles.nb_columns + j].case_type == 3 && ennemi == false)
                {
                    std::cout << 'E';
                }
                ennemi = false;
            }
        }
        std::cout << std::endl;
    }
}

bool check_limits_map(std::vector<Case> map, int x, int y, TailleGrid tailles)
{
    if (x < tailles.nb_columns && x > -1)
    {
        if (y < tailles.nb_lines && y > -1)
        {
            return true;
        }
    }
    return false;
}

bool case_traversable(std::vector<Case> map, int x, int y, TailleGrid tailles)
{
    if (check_limits_map(map, x, y, tailles) == true)
    {
        if (map[y * tailles.nb_columns + x].traversable == true)
        {
            return true;
        }
    }
    return false;
}

bool case_monster(Character hero, std::vector<Character> ennemis, int nb_ennemis)
{
    for (int i = 0; i < nb_ennemis; i++)
    {
        if (ennemis[i].x == hero.x && ennemis[i].y == hero.y)
        {
            return true;
        }
    }
    return false;
}

bool case_exit(std::vector<Case> map, int x, int y, int nb_colonnes)
{
    if (map[y * nb_colonnes + x].case_type == 3)
    {
        return true;
    }
    else
    {
        return false;

    }
}

void move_entity(std::vector<Case> current_map, Character& character, char direction, TailleGrid tailles, std::vector<Character> ennemis)
{
    int direction_x = 0;
    int direction_y = 0;
    bool autres_ennemis_ok = false;

    if (direction == 'z')
    {
        direction_y = -1;
    }
    else if (direction == 'q')
    {
        direction_x = -1;
    }
    else if (direction == 's')
    {
        direction_y = 1;
    }
    else if (direction == 'd')
    {
        direction_x = 1;
    }

    if (case_traversable(current_map, character.x + direction_x, character.y + direction_y, tailles) == true)
    {
        for (int j = 0; j < tailles.nb_ennemies; j++)
        {
            if (ennemis[j].x == character.x + direction_x && ennemis[j].y == character.y + direction_y)
            {
                autres_ennemis_ok = true;
            }
        }
        if (autres_ennemis_ok == false)
        {
            character.x += direction_x;
            character.y += direction_y;
        }
    }
}

void move_ennemies(std::vector<Case> current_map, std::vector<Character>& ennemis, TailleGrid tailles)
{
    char directions[5] = { 'z', 'q', 's', 'd', 'p' };

    int random;
    int direct_x = 0;
    int direct_y = 0;

    for (int i = 0; i < tailles.nb_ennemies; i++)
    {
        random = rand() % 4;

        move_entity(current_map, ennemis[i], directions[random], tailles, ennemis);
    }
}

void move_hero(std::vector<Case>& current_map, Character& current_hero, std::vector<Character>& ennemis, int nb_ennemis, TailleGrid tailles, bool& spell_mod, bool& action)
{
    char touche = _getch();

    if (touche == 'p')
    {
        spell_mod = true;
    }
    else
    {
        move_entity(current_map, current_hero, touche, tailles, ennemis);
        move_ennemies(current_map, ennemis, tailles);
    }
    action = true;
}

std::vector<Case> initialisation_map(std::vector<Case> current_map, Case* map, TailleGrid tailles) /// Moyen de faire sans copie / return void
{
    current_map.clear();
    current_map.resize(tailles.nb_cases);
    for (int i = 0; i < tailles.nb_cases; i++)
    {
        current_map[i] = map[i];
    }
    return current_map;
}

bool game_over(Character& hero_actuel, std::vector<Character> ennemis, int nb_ennemis)
{
    bool game_over = false;
    if (case_monster(hero_actuel, ennemis, nb_ennemis) == true)
    {
        hero_actuel.PV--;
        //std::cout << "PV2 : " << hero->PV;
        if (hero_actuel.PV <= 0)
        {
            game_over = true;
            if (game_over == true)
            {
                std::cout << "Game Over";
                return true;
            }
        }
    }
    return false;
}


int main()
{
    srand(time(0));

    bool end = false;
    bool spell_mod = false;

    int map = 1;
    bool change_map = false;

    std::vector<Case> current_map = {};
    std::vector<Character> current_ennemies = {};


    std::string chemin_acces_map1 = "..\\maps\\map1.txt";
    std::string chemin_acces_map2 = "..\\maps\\map2.txt";

    TailleGrid tailles = {};
    get_taille_file(chemin_acces_map1, tailles);

    Case* map1 = new Case[tailles.nb_cases]{};
    current_ennemies.resize(tailles.nb_ennemies);

    Character current_hero;

    grid_creation(chemin_acces_map1, map1, current_hero, current_ennemies);

    // Création tab_spell
    Spell* tab_spell = new Spell[8]{ {current_hero.x - 1, current_hero.y - 1},
                                    {current_hero.x - 1, current_hero.y},
                                    {current_hero.x - 1, current_hero.y + 1},
                                    {current_hero.x, current_hero.y - 1},
                                    {current_hero.x, current_hero.y + 1},
                                    {current_hero.x + 1, current_hero.y - 1},
                                    {current_hero.x + 1, current_hero.y},
                                    {current_hero.x + 1, current_hero.y + 1} };

    // Initialisation map1
    std::cout << "Votre long perible a travers les plaines vous a amene devant cette source sortant des montagnes.\nVous savez que vous devez atteindre ce chemin traversant ces montagnes afin d'atteindre l'autre cote.\nMais sur la route se trouve des ennemis...\n";
    current_map = initialisation_map(current_map, map1, tailles);
    display_map(current_map, current_hero, tailles, current_ennemies, tailles.nb_ennemies, tab_spell, spell_mod);

    bool action = false;
    while (end == false)
    {
        /// Evenements
        while (action == false)
        {
            if (spell_mod == false)
            {
                move_hero(current_map, current_hero, current_ennemies, tailles.nb_ennemies, tailles, spell_mod, action);
            }
            else if (spell_mod == true)
            {
                exit;
            }
        }
        action = false;

        /// Clear
        system("cls");

        int direction_x = 0;
        int direction_y = 0;

        /// Afficher
        change_map = case_exit(current_map, current_hero.x, current_hero.y, tailles.nb_columns);

        if (game_over(current_hero, current_ennemies, tailles.nb_ennemies))
        {
            end = true;
        }
        else if (change_map == true)
        {
            map++;

            if (map == 2)
            {
                std::cout << "Vous etes arrive au chemin serpentant a travers les montagnes, le franchir ne sera pas facile.\n";
                get_taille_file(chemin_acces_map2, tailles);
                Case* map2 = new Case[tailles.nb_cases]{};
                current_ennemies.clear();
                current_ennemies.resize(tailles.nb_ennemies);

                grid_creation(chemin_acces_map2, map2, current_hero, current_ennemies);

                current_map = initialisation_map(current_map, map2, tailles);

                display_map(current_map, current_hero, tailles, current_ennemies, tailles.nb_ennemies, tab_spell, spell_mod);
            }
            if (map == 3)
            {
                std::cout << "Vous avez traverse cette chaine de montagnes et avez pu rejoindre votre village sain et sauf.\nVotre famille vous accueille a bras ouverts.";
                end = true;
            }
        }
        else
        {
            display_map(current_map, current_hero, tailles, current_ennemies, tailles.nb_ennemies, tab_spell, spell_mod);
        }
        change_map = false;
    }
    return 0;
}