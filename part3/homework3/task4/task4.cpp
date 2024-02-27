/*Реализуйте упрощённую версию пошаговой ролевой игры.
Действие разворачивается на карте размером 20 на 20 клеток. По клеткам
перемещаются игрок и его противники. После каждого хода игрока карта
показывается вновь со всеми противниками на ней: • игрок помечается буквой P, •
противники — буквой E, • пустые места — точкой. Каждый персонаж игры представлен
в виде структуры с полями: • «Имя», • «Жизни», • «Броня», • «Урон». Сначала
создаётся пять противников в случайных клетках карты: • Имена противникам
задаются в формате Enemy #N, где N — порядковый номер. • Уровень жизни
противников задаётся случайно — от 50 до 150. • Уровень брони варьируется от 0
до 50. • Урон тоже выбирается случайно — от 15 до 30 единиц. Игрок конструирует
своего персонажа самостоятельно. Задаёт все его параметры, включая имя. Все
персонажи появляются в случайных местах карты. Игрок ходит с помощью команд: L,
R, U, D (по первым буквам слов left, right, up, down). В зависимости от команды
выбирается направление перемещения: влево, вправо, вверх, вниз. Противники
перемещаются в случайном направлении. Если игрок перемещается в сторону, где уже
кто-то находится, он наносит этому персонажу урон. Противники при этом никогда
не бьют друг друга: они просто пропускают ход и остаются на своём месте. За
пределы карты (20 на 20 клеток) ходить нельзя никому. Если кто-то выбрал
направление за границами, ход пропускается. Формула расчёта урона совпадает с
той, что была в материале. Жизни уменьшаются на размер урона. При этом броня
тоже сокращается на приведённый урон. Игра заканчивается тогда, когда умирают
либо все противники, либо игрок. В первом случае на экран выводится сообщение о
победе, во втором — о поражении. Если в начале хода игрок вводит команду save
или load вместо направления перемещения, то игра либо сохраняет своё состояние в
файл, либо загружает это состояние из файла.*/

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

// Константы из условия
#define BOARD_SIZE 20
#define NUMBER_ENEMIES 5
#define ENEMY_LIFE_MIN 50
#define ENEMY_LIFE_MAX 150
#define ENEMY_ARMOR_MIN 0
#define ENEMY_ARMOR_MAX 50
#define ENEMY_DAMAGE_MIN 15
#define ENEMY_DAMAGE_MAX 30

#define LEFT 'l'
#define RIGHT 'r'
#define UP 'u'
#define DOWN 'd'
#define DIRECTIONS "lrud"

// симаолы для отображения игрового поля
#define EMPTY '.'
#define OCCUPIED_PLAYER 'P'
#define OCCUPIED_ENEMY 'E'

enum class GameStatus
{
  IN_PROCESS,
  PLAYER_WON,
  PLAYER_LOST
};

struct Position
{
  int row;
  int column;

  bool operator==(const Position &otherPosition)
  {
    return row == otherPosition.row && column == otherPosition.column;
  }

  bool operator!=(const Position &otherPosition)
  {
    return row != otherPosition.row || column != otherPosition.column;
  }
};

struct Character
{
  std::string name;
  int health;
  int armor;
  int damage;
  Position position;
};

struct Game
{
  char board[BOARD_SIZE][BOARD_SIZE];
  Character player;
  std::vector<Character> enemies;
  GameStatus status = GameStatus::IN_PROCESS;
};

// Получить координаты случайно не занятой ячейки
Position getRandomPosition(Game &game)
{
  int row, column;
  do
  {
    row = std::rand() % BOARD_SIZE;
    column = std::rand() % BOARD_SIZE;
  } while (game.board[row][column] != EMPTY);
  return {row, column};
}

// Инициализаия игры
void initGame(Game &game)
{
  // Начальное заполнение игрового поля
  std::srand((unsigned)std::time(nullptr));
  for (size_t i = 0; i < BOARD_SIZE; i++)
    for (size_t j = 0; j < BOARD_SIZE; j++)
      game.board[i][j] = EMPTY;

  // Создание персонажей врагов
  game.enemies.clear();
  game.enemies.resize(NUMBER_ENEMIES);
  int i = 0;
  for (Character &enemy : game.enemies)
  {
    enemy.name = "Enemy #" + std::to_string(++i);
    enemy.health = std::rand() % (ENEMY_LIFE_MAX - ENEMY_LIFE_MIN + 1) + ENEMY_LIFE_MIN;
    enemy.armor = std::rand() % (ENEMY_ARMOR_MAX - ENEMY_ARMOR_MIN + 1) + ENEMY_ARMOR_MIN;
    enemy.damage = std::rand() % (ENEMY_DAMAGE_MAX - ENEMY_DAMAGE_MIN + 1) + ENEMY_DAMAGE_MIN;
    Position position = getRandomPosition(game);
    enemy.position.row = position.row;
    enemy.position.column = position.column;
    game.board[position.row][position.column] = OCCUPIED_ENEMY;
  }

  // Создание персонажа игрока
  std::cout << "Player name: ";
  std::cin >> game.player.name;
  std::cout << "Player health: ";
  std::cin >> game.player.health;
  std::cout << "Player armor: ";
  std::cin >> game.player.armor;
  std::cout << "Player damage: ";
  std::cin >> game.player.damage;
  Position position = getRandomPosition(game);
  game.player.position.row = position.row;
  game.player.position.column = position.column;
  game.board[position.row][position.column] = OCCUPIED_PLAYER;

  game.status = GameStatus::IN_PROCESS;
}

void printGameData(const Game &game)
{
  std::cout << "==========================================" << std::endl;
  std::cout << game.player.name << ": health " << game.player.health
            << ", armor: " << game.player.armor
            << ", damage: " << game.player.damage << std::endl;

  for (const Character &enemy : game.enemies)
    std::cout << enemy.name << ": life " << enemy.health
              << ", armor: " << enemy.armor << ", damage: " << enemy.damage
              << std::endl;

  for (size_t i = 0; i < BOARD_SIZE; i++)
  {
    for (size_t j = 0; j < BOARD_SIZE; j++)
      std::cout << game.board[i][j];
    std::cout << std::endl;
  }
  std::cout << "==========================================" << std::endl;
}

void atack(const Character &character1, Character &character2)
{
  std::cout << character1.name << " attacked " << character2.name << std::endl;

  // урон сначала снимает очки брони
  character2.armor -= character1.damage;

  // если броня закончилась, снимаются очки здоровья
  if (character2.armor < 0)
  {
    character2.health += character2.armor;
    character2.armor = 0;
  }
}

// Получение координат новой позиции по текущей позиции и направлению движения
Position getNewPosition(const Position &currentPosition, char direction)
{
  Position newPosition;
  switch (direction)
  {
  case LEFT:
    newPosition.row = currentPosition.row;
    newPosition.column = currentPosition.column - 1;
    break;
  case RIGHT:
    newPosition.row = currentPosition.row;
    newPosition.column = currentPosition.column + 1;
    break;
  case UP:
    newPosition.row = currentPosition.row - 1;
    newPosition.column = currentPosition.column;
    break;
  case DOWN:
    newPosition.row = currentPosition.row + 1;
    newPosition.column = currentPosition.column;
    break;
  }

  return newPosition;
}

// Проверка на выход за пределы поля
bool outOfBoard(Position position)
{
  return position.column < 0 || position.column > BOARD_SIZE - 1 ||
         position.row < 0 || position.row > BOARD_SIZE - 1;
}

// ход игрока
void playerMove(Game &game, char direction)
{
  // получаем новые координаты
  Position newPosition = getNewPosition(game.player.position, direction);

  // если вышли за пределы поля, ничего не делаем
  if (outOfBoard(newPosition))
    return;

  // Если в направлении движения находится враг
  if (game.board[newPosition.row][newPosition.column] == OCCUPIED_ENEMY)
  {
    size_t enemyIndex;

    // Ищем, какой конкретно враг на пути
    for (size_t i = 0; i < game.enemies.size(); i++)
      if (game.enemies[i].position == newPosition)
      {
        enemyIndex = i;
        break;
      }

    // и атакуем
    atack(game.player, game.enemies[enemyIndex]);

    // если враг убит, убираем его с поля и удаляем из списка врагов
    // если врагов больше не осталось, игрок победил
    if (game.enemies[enemyIndex].health <= 0)
    {
      std::cout << "Enemy " << game.enemies[enemyIndex].name << " killed" << std::endl;
      game.board[game.enemies[enemyIndex].position.row][game.enemies[enemyIndex].position.column] = EMPTY;
      game.enemies.erase(game.enemies.cbegin() + (int)enemyIndex);
      if (game.enemies.size() == 0)
      {
        game.status = GameStatus::PLAYER_WON;
        return;
      }
    }
  }

  // Шагаем на свободное поле (также сработает, если в поле был находился враг, но он был убит)
  if (game.board[newPosition.row][newPosition.column] == EMPTY)
  {
    game.board[game.player.position.row][game.player.position.column] = EMPTY;
    game.player.position = newPosition;
    game.board[game.player.position.row][game.player.position.column] = OCCUPIED_PLAYER;
  }
}

// Ход врагов
void enemiesMove(Game &game)
{
  for (Character &enemy : game.enemies)
  {
    // получаем случайное направление
    char direction = DIRECTIONS[std::rand() % 4];

    Position newPosition = getNewPosition(enemy.position, direction);

    // если вышли за пределы поля или в направлении хода находится другой враг, это враг пропускает ход
    if (outOfBoard(newPosition) || game.board[newPosition.row][newPosition.column] == OCCUPIED_ENEMY)
      continue;

    // если в направлениии хода находится игрок, атакуем его
    // если здоровье игрока закончилось, игрок проиграл
    if (game.board[newPosition.row][newPosition.column] == OCCUPIED_PLAYER)
    {
      atack(enemy, game.player);

      if (game.player.health <= 0)
      {
        std::cout << "Player " << game.player.name << " killed" << std::endl;
        game.status = GameStatus::PLAYER_LOST;
        return;
      }
    }
    else
    {
      game.board[enemy.position.row][enemy.position.column] = EMPTY;
      enemy.position = newPosition;
      game.board[enemy.position.row][enemy.position.column] = OCCUPIED_ENEMY;
    }
  }
}

// Сохранение и загрузка отдельного персонажа
// Формат:
// длина имени: int
// строка имени: char[]
// здоровье: int
// броня: int
// урон: int
// Позиция на поле: Position
void saveCharacter(std::ofstream &file, const Character &character)
{
  int nameLen = character.name.length();
  file.write((char *)&nameLen, sizeof(nameLen));
  file.write(character.name.c_str(), nameLen);
  file.write((char *)&character.health, sizeof(character.health));
  file.write((char *)&character.armor, sizeof(character.armor));
  file.write((char *)&character.damage, sizeof(character.damage));
  file.write((char *)&character.position, sizeof(character.position));
}

void loadCharacter(std::ifstream &file, Character &character)
{
  int nameLen;
  file.read((char *)&nameLen, sizeof(nameLen));
  character.name.resize(nameLen);
  file.read((char *)character.name.c_str(), nameLen);
  file.read((char *)&character.health, sizeof(character.health));
  file.read((char *)&character.armor, sizeof(character.armor));
  file.read((char *)&character.damage, sizeof(character.damage));
  file.read((char *)&character.position, sizeof(character.position));
}

// Сохранение и загрузка игры
// Формат:
// Персонаж игрока:
// Количество врагов: int
// Все персонажи врагов
// Текущий статус игры: GameStatus
// Игровое поле не сохраняется. При загрузке восстанавливается по координатам отдельных персонажей
void save(const char *filePath, Game &game)
{
  std::ofstream file(filePath, std::ios::binary);
  if (file.is_open())
  {
    saveCharacter(file, game.player);
    int countEnemies = game.enemies.size();
    file.write((char *)&countEnemies, sizeof(countEnemies));
    for (const Character &enemy : game.enemies)
      saveCharacter(file, enemy);
    file.write((char *)&game.status, sizeof(game.status));
  }
  else
  {
    std::cout << "File not saved!" << std::endl;
  }
}

void load(const char *filePath, Game &game)
{
  std::ifstream file(filePath, std::ios::binary);
  if (file.is_open())
  {
    for (size_t i = 0; i < BOARD_SIZE; i++)
      for (size_t j = 0; j < BOARD_SIZE; j++)
        game.board[i][j] = EMPTY;
    loadCharacter(file, game.player);
    game.board[game.player.position.row][game.player.position.column] = OCCUPIED_PLAYER;
    int countEnemies;
    file.read((char *)&countEnemies, sizeof(countEnemies));
    game.enemies.clear();
    game.enemies.resize(countEnemies);
    for (int i = 0; i < countEnemies; i++)
    {
      loadCharacter(file, game.enemies[i]);
      game.board[game.enemies[i].position.row][game.enemies[i].position.column] = OCCUPIED_ENEMY;
    }
    file.read((char *)&game.status, sizeof(game.status));
  }
  else
  {
    std::cout << "Failed to read file!" << std::endl;
  }
}

int main()
{
  // Список допустимых команд
  std::vector<std::string> validСom = {"save", "load", "new", "exit"};
  char filePath[] = "gamedata.bin";

  Game game;
  initGame(game);

  while (game.status == GameStatus::IN_PROCESS)
  {
    printGameData(game);
    std::cout << "===== Player move =====" << std::endl;
    char direction;
    std::string command;

    // Ввод команды, пока не будет введена корректная команда или первый символ введенной строки не будет одним из символов направления
    do
    {
      std::cout << "Enter direction (l - left, r - right, u - up, d - down)" << std::endl
                << "or command (save - save game, load - load game, new - new game, exit - exit the game)" << std::endl
                << "> ";
      std::cin >> command;
      direction = (char)std::tolower(command[0]);
    } while (std::find(validСom.begin(), validСom.end(), command) == validСom.end() && !strchr(DIRECTIONS, direction));

    if (command == "save")
    {
      save(filePath, game);
      continue;
    }

    if (command == "load")
    {
      load(filePath, game);
      continue;
    }

    if (command == "new")
    {
      initGame(game);
      continue;
    }

    if (command == "exit")
      break;

    playerMove(game, direction);
    if (game.status == GameStatus::IN_PROCESS)
      enemiesMove(game);
  }

  if (game.status == GameStatus::PLAYER_WON)
    std::cout << "Victory!!!" << std::endl;
  else if (game.status == GameStatus::PLAYER_LOST)
    std::cout << "Defeat :(" << std::endl;
  else
    std::cout << "Bye Bye" << std::endl;
}