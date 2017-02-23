#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


#define NUM_ZOMBIES 10

enum class Weapon{
	FISTS, GLOCK, GUN_MACHINE, MAX
};

class Zombie;

class Player{
private:
	Weapon weapon;
	float precision;
	float life;

public:
	Player() :
		weapon(Weapon((rand() % 2))),
		precision(static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 5.0f))),
		life(100.0f)
	{}
	Player(Weapon t_weapon, float t_precision, float t_life) :
		weapon(t_weapon),
		precision(t_precision),
		life(t_life)
	{}

	void loseLife(float x){
		if (life > 0.0f){
			life -= x;
			if (life < 0.0f){
				life = 0.0f;
			}
		}
	}
	void attack(Zombie &zombie);
	bool isAlive(){
		return (life > 0.0f);
	}
	void printInfo(){
		std::cout << "Player:\n      weapon: " << (int)weapon << ", precision: " << precision << ", life: " << life << std::endl;
	}
};

class Zombie{
private:
	int distanceToPlayer;
	float precision;
	float damage;
	float life;

public:
	Zombie() :
		distanceToPlayer(rand() % (199 - 20 + 1) + 20),
		precision(((static_cast<float>(rand()) / (static_cast<float>(RAND_MAX))) * (40.0f - 20.0f)) + 20.0f),
		damage(static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 20.0f))),
		life(100.0f)
	{}
	Zombie(int t_distanceToPlayer, float t_precision, float t_damage, float t_life) :
		distanceToPlayer(t_distanceToPlayer),
		precision(t_precision),
		damage(t_damage),
		life(t_life)
	{}

	void loseLife(float x){
		if (life > 0.0f){
			life -= x;
			if (life < 0.0f){
				life = 0.0f;
			}
		}
	}
	void attack(Player &player){
		if (distanceToPlayer <= 0){
			player.loseLife(damage * precision);
		}
		else if (distanceToPlayer > 0){
			distanceToPlayer--;
		}
	}
	bool isAlive(){
		return (life > 0.0f);
	}
	void printInfo(int pos){
		std::cout << "Zombie[" << pos << "]:\n      distance: " << distanceToPlayer << ", precision: " << precision << ", damage: " << damage << ", life: " << life << std::endl;
	}
};

void Player::attack(Zombie &zombie){
	zombie.loseLife((int)weapon * precision);
}


int main(){
	srand(static_cast <unsigned> (time(0)));

	Player player;
	Zombie zombies[NUM_ZOMBIES];

	bool zombiesAreAlive = true;
	do{
		zombiesAreAlive = false;
		for (int i = 0; i < NUM_ZOMBIES; i++){
			if (zombies[i].isAlive()){
				zombies[i].attack(player);
				player.attack(zombies[i]);

				if (zombies[i].isAlive() && !zombiesAreAlive){
					zombiesAreAlive = true;
				}
			}
			zombies[i].printInfo(i);
		}
		std::cout << "----------------------------------------------\n";
		player.printInfo();
		std::cout << std::endl;

	} while (player.isAlive() && zombiesAreAlive);

	std::cout << "----------------------------------------------\n";
	if (!zombiesAreAlive){
		std::cout << "GAME OVER: Player has killed all zombies!\n";
	}
	else{
		std::cout << "GAME OVER: Player has dead.\n";
	}

	return 0;
}