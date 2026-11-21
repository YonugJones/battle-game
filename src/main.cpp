/*
cmake -S . -B build                     # first time only (or after editing CMakeLists.txt)
cmake --build build                     # compile; run this every time you change code
./build/battle                          # run
cmake --build build && ./build/battle   # chain them so it only runs if the compile worked:
*/

#include <iostream>
#include <string>
#include <algorithm>

class Fighter
{
  // declarations
public:
  Fighter(std::string name, int maxHp, int attack);
  bool isAlive() const;               // const = "this doesn't change the fighter"
  const std::string &getName() const; // hands back a read only reference instead of copying the string every call
  int getHp() const;
  void takeDamage(int damage);
  void attack(Fighter &target) const;

private:
  std::string m_name;
  int m_hp;
  int m_maxHp;
  int m_attack;
};

// Fighter definitions
Fighter::Fighter(std::string name, int maxHp, int attack)
    : m_name{name}, m_hp{maxHp}, m_maxHp{maxHp}, m_attack{attack} {}

bool Fighter::isAlive() const
{
  return m_hp > 0;
}

const std::string &Fighter::getName() const
{
  return m_name;
}

int Fighter::getHp() const
{
  return m_hp;
}

void Fighter::takeDamage(int damage)
{
  m_hp = std::max(0, m_hp - damage);
}

void Fighter::attack(Fighter &target) const
{
  target.takeDamage(m_attack);
}

void takeTurn(const Fighter &attacker, Fighter &defender)
{
  attacker.attack(defender);
  std::cout << attacker.getName() << " attacks " << defender.getName() << "!\n";
  std::cout << defender.getName() << " hp: " << defender.getHp() << "\n\n";
}

int main()
{
  std::cout << "\nBattle begins!\n\n";

  Fighter zhaoYun{"Zhao Yun", 100, 15};
  Fighter xiahouDun{"Xiahou Dun", 100, 15};

  int currentRound{1};

  // Battle loop
  while (zhaoYun.isAlive() && xiahouDun.isAlive())
  {

    std::cout << "Round " << currentRound << "!\n\n";
    takeTurn(zhaoYun, xiahouDun);
    if (xiahouDun.isAlive())
    {
      takeTurn(xiahouDun, zhaoYun);
    }

    currentRound++;
  }

  const Fighter &winner = zhaoYun.isAlive() ? zhaoYun : xiahouDun;

  std::cout << "Battle over! Winner is: " << winner.getName() << "!\n\n";

  return 0;
}