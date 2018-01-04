#include <iostream>
#include <windows.h>

using namespace std;

class Controller {
	
	unsigned short int volume;
	unsigned short int lastVolume;
	unsigned short int initVolume 	= 0;
	unsigned short int limitVolume 	= 100;
	bool mute;
	
	public:
		void setVolume(int);
		void aumentarVolume();
		void diminuirVolume();
		void Mute();
		void apresentarInfo();
		
		Controller ();
		Controller (int);
		Controller (int, int);
		
};

//CONSTRUCTER
Controller::Controller(){
	//Inicia as variaveis
	Controller::volume 		= Controller::initVolume;
	Controller::lastVolume 	= Controller::initVolume;
	//Caso o volmue for igual 0 fica Mute()
	if( Controller::volume == 0 )
		Controller::mute = true; else Controller::mute = false;	
}

Controller::Controller(int initVolume){
	//Caso o initVolume for negativo ou Maior que limitVolume
	if(initVolume < 0 || initVolume > limitVolume)
		initVolume = 0;
	//Inicia as variaveis
	Controller::volume 		= initVolume;
	Controller::lastVolume 	= initVolume;
	//Caso o volmue for igual 0 fica Mute()
	if( Controller::volume == 0 )
		Controller::mute = true; else Controller::mute = false;	
}

Controller::Controller(int initVolume, int initLimitVolume){
	//Caso o initVolume for negativo ou Maior que limitVolume
	if(initVolume < 0 || initVolume > limitVolume)
		initVolume = 0;
	//Inicia as variaveis
	Controller::volume 		= initVolume;
	Controller::lastVolume 	= initVolume;
	Controller::limitVolume = initLimitVolume;
	//Caso o volmue for igual 0 fica Mute()
	if( Controller::volume == 0 )
		Controller::mute = true; else Controller::mute = false;	
}	

//FUNCTIONS
void Controller::setVolume(int volume){
	//Para editar a variavel Volume
	Controller::volume = volume;
}

void Controller::aumentarVolume(){
	//Caso o Volume for null
	if( Controller::volume == NULL )
		Controller::volume = 0;
	//Caso for Maior que 0 e Menor que 100
	if( Controller::volume < limitVolume && Controller::volume >= 0){
		Controller::volume++; //Adiciona mais 1 sempre presionado
		
		//Caso estiver Mute()
		if( Controller::mute == true)
		{
			//Tira o Mute()
			Controller::mute = false;
			//Mete o lastVolume no volume
			Controller::volume = Controller::lastVolume;
		}
		//O lastVolume sera igual ao Volume
		Controller::lastVolume = Controller::volume;
	}
	
}

void Controller::diminuirVolume(){
	//Caso o Volume for maior que zero pode diminuir o Volume
	if( Controller::volume > 0 && Controller::volume <= limitVolume){
		Controller::volume--;
	}
	//Quando diminuir o som e estiver menos de 1 fica Mute()
	if( Controller::volume == 0 && Controller::mute == false )
		Controller::Mute();
	//Caso estiver Mute()
	if( Controller::mute == true)
	{
		//Tira o Mute()
		Controller::mute = false;
		//Mete o lastVolume no volume
		Controller::volume = Controller::lastVolume;
	}	
	//O lastVolume sera igual ao Volume
	Controller::lastVolume = Controller::volume;
}

void Controller::Mute(){
	//Caso o Volume for maior que 0 e nao tiver em Mute()
	if( Controller::volume > 0 && Controller::mute == false )
		Controller::volume = 0;
	//caso estiver Mute() retira do Mute()
	if( Controller::volume == 0 && Controller::mute == true )
		Controller::volume = Controller::lastVolume;
	//Mute fica sempre o contrario do seu
	Controller::mute = !Controller::mute;
	
}

void Controller::apresentarInfo(){
	
	cout << "Mute: " << Controller::mute << endl;
	cout << "Volume: " << Controller::volume << endl;
	cout << "lastVolume: " << Controller::lastVolume << endl;
	cout << "limitVolume: " << Controller::limitVolume << endl;
	cout << "-----------------------------" << endl;
	
}


int main(){
	
	Controller c(0, 90);
	
	c.apresentarInfo();	
	
	for(int i = 0; i < 110; i++)
	{
		c.aumentarVolume();
		
		if( i % 2 == 0)
			c.Mute();
			
		c.apresentarInfo();	
		cout << i << endl;
		
		Sleep(200);
	}
		
	
	
}
