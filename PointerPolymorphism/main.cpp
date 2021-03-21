#include <iostream>
using namespace std;

struct character {
	virtual const char* getName() {
		return "BaseCharacterName";
	}
};


struct sideCharacter : public character {
	const char* getName() {
		return "sideCharacterName";
	}
};


struct mainCharacter : public character {
	const char* getName() {
		return "MainCharacterName";
	}
};


int main() {

	cout << "Because we have set the 'base' character struct getName with the virtual keyword, we have allowed that method to be overridden by it's children." << endl
		<< "By declaring the below line as a pointer to an array of pointers, this allows use to put different objects of base 'character' into the array." << endl
		<< "i.e. -> character** characters = new character*[5];" << endl;

	character** characters = new character*[5];

	characters[0] = new mainCharacter();
	characters[1] = new sideCharacter();
	characters[2] = new mainCharacter();
	characters[3] = new character();
	characters[4] = new mainCharacter();

	for (int i = 0; i < 5; i++) {
		cout << characters[i]->getName() << endl;
	}

	for (int i = 0; i < 5; i++) {
		delete characters[i];
	}

	delete[] characters;

	cout << endl; 

	return 0;
}