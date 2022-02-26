#include <iostream>
#include <string>

class Iks{
	private:
	int n;
	int move;
	std::string first;
	std::string second;
	char desk[9] = {'1','2','3','4','5','6','7','8','9'};

	private:
	void desk_construct(char* desk){
		for(int i = 0; i < n; ++i){
			if(!(i % 3)){
				std::cout << std::endl;
			}
			std::cout << desk[i] << " ";
		}	
		std::cout << std::endl;
	}

	int chek(){
		for( ; ; ){
			std::cin >> move;
			if((move > 9 || move < 1)){
				std::cout << "insert other number please, number must be 1-9" << std::endl;
			} else if((desk[move-1] == 'X') || (desk[move-1] == 'O')){
				std::cout << "insert other number please, this cell is busy" << std::endl;
			} else {
				break;
			}

		}
		return move; 
	}

	void players(){
		std::cout << "insert your name first player and your game piece is 'X'" << std::endl;
		std::getline(std::cin, first);
		std::cout << "insert your name second player and your game piece is 'O'" << std::endl;
		std::getline(std::cin, second);
	}

	public:

	Iks(){
		n = 9;
		move = 0;
	}

	void play(){
		players();
		for(int i = 0; i <= n; i++){
			desk_construct(desk);
			if(i > 3){
				if(((desk[0] == desk[1]) && (desk[1] == desk[2])) ||
						((desk[3] == desk[4]) && (desk[4] == desk[5])) ||
						((desk[6] == desk[7]) && (desk[7] == desk[8])) ||
						((desk[0] == desk[3]) && (desk[3] == desk[6])) ||
						((desk[1] == desk[4]) && (desk[4] == desk[7])) ||
						((desk[2] == desk[5]) && (desk[5] == desk[8])) ||
						((desk[0] == desk[4]) && (desk[4] == desk[8])) ||
						((desk[6] == desk[4]) && (desk[4] == desk[2]))){
					if((i%2)){
						desk_construct(desk);
						std::cout << "game winner is " << first << std::endl;
						break;
					} else {
						desk_construct(desk);
						std::cout << "game winner is " << second<< std::endl;
						break;
					}
				}
			}
			if(9 == i){
				desk_construct(desk);
				std::cout << "the game ended in a draw " << std::endl;
				break;
			}

			if(!(i%2)){
				std::cout << "your move " << first << std::endl;
				chek();
				desk[move - 1] = 'X';
			} else{
				std::cout << "your move " << second << std::endl;
				chek();
				desk[move - 1] = 'O';
			}
			system("clear");
		}
	}
};

int main(){
	Iks x_o;
	x_o.play();

}
