/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "Choose an option:" << endl;
     cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
}

int main(int argc, char const *argv[])
{
	ProducerConsumer pc;
	string input;
	string input2;

	do
	{
		//Prints the menu
		std::cout << "*----------------------------------------*" << '\n';
		menu();
		std::cout << "*----------------------------------------*" << '\n';

		cin >> input;

		switch(stoi(input))
		{
			case 1:
				std::cout << "Enter the number of items to be produced:" << '\n';
				cin >> input;

				//Adds however many items the user added
				for(int i = 0; i < stoi(input); i++)
				{
					std::cout << "Item" << i+1 << ":" << '\n';
					cin >> input2;
					pc.enqueue(input2);
				}

				input = "1"; //Resets the input in case the user entered 3 items
				break;

			case 2:
				std::cout << "Enter the number of items to be consumed:" << '\n';
				cin >> input;

				//Removes however many items the user said to
				for(int i = 0; i < stoi(input); i++)
				{
					//If the queue is empty...
					if(pc.isEmpty())
					{
						//Stop consuming
						std::cout << "No more items to consume from queue" << '\n';
						break;
					}

					//Show what item is being consumed and the dequeue it
					std::cout << "Consumed: " << pc.peek() << '\n';
					pc.dequeue();
				}

				input = "2"; //Resets the input in case the use consumed 4 items
				break;

			case 3:
				std::cout << "Number of items in the queue:" << pc.queueSize() << '\n';
				break;
		}
	}
	while(input != "3");
}
