	#include <iostream>
	#include <fstream>
	#include <string>
	using namespace std;
	
	// Function to register a new user
	void registerUser() {
	    string username, password;
	    ofstream file("users.txt", ios::app); // Open file in append mode
	
	    cout << "Enter a username: ";
	    cin >> username;
	    cout << "Enter a password: ";
	    cin >> password;
	
	    // Store username and password in the file
	    file << username << ":" << password << endl;
	    file.close();
	
	    cout << "Registration successful!" << endl;
	}
	
	// Function to log in a user
	bool login() {
	    string username, password, storedUsername, storedPassword;
	    ifstream file("users.txt"); // Open the file to read user details
	
	    cout << "Enter username: ";
	    cin >> username;
	    cout << "Enter password: ";
	    cin >> password;
	
	    // Check each line in the file for matching credentials
	    while (getline(file, storedUsername, ':') && getline(file, storedPassword)) {
	        if (storedUsername == username && storedPassword == password) {
	            file.close();
	            return true; // Successfully logged in
	        }
	    }
	
	    file.close();
	    return false; // Failed to log in
	}
	
	// Inventory size
	const int MAX_INVENTORY_SIZE = 10;
	string inventory[MAX_INVENTORY_SIZE];
	int inventoryCount = 0;
	
	// Function to load inventory from file
	void loadInventory() {
	    ifstream file("inventory.txt");
	    if (file.is_open()) {
	        inventoryCount = 0;
	        while (file >> inventory[inventoryCount] && inventoryCount < MAX_INVENTORY_SIZE) {
	            inventoryCount++;
	        }
	        file.close();
	    }
	}
	
	// Function to save inventory to file
	void saveInventory() {
	    ofstream file("inventory.txt");
	    if (file.is_open()) {
	        for (int i = 0; i < inventoryCount; i++) {
	            file << inventory[i] << endl;
	        }
	        file.close();
	    }
	}
	
	void showInventory() {
    cout << "Your Inventory: \n";
    for (int i = 0; i < inventoryCount; i++) {
        cout << i + 1 << ". " << inventory[i] << endl;
    	}
	}

	// Function to add an item to inventory
	void addToInventory(const string& item) {
	    if (inventoryCount < MAX_INVENTORY_SIZE) {
	        inventory[inventoryCount++] = item;
	        saveInventory();
	        cout << "Added '" << item << "' to your inventory.\n";
	    } else {
	        cout << "Inventory full! Cannot add '" << item << "'.\n";
	    }
	}
	
	// Transition function for smooth scene transitions
	void transition() {
	    cout << "\n--- Transitioning to the next scene... ---\n";
	    cout << "Press Enter to continue...";
	    cin.ignore();
	    cin.get();
	}
	
// Scene 1
void scene1() {
    cout << "Scene 1: The Mysterious Call\n";
    cout << "Blake receives an encrypted call hinting at a conspiracy involving powerful figures.\n";
    cout << "Choices:\n";
    cout << "1. Trace the call.\n";
    cout << "2. Ignore it and investigate the sender.\n";
    cout << "3. View your inventory.\n";  // Option to view inventory
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "You trace the call to a suspicious warehouse. Added 'Tracking Device' to your inventory.\n";
        addToInventory("Tracking Device");
    } else if (choice == 2) {
        cout << "You investigate the sender and find a secret dossier. Added 'Secret Dossier' to your inventory.\n";
        addToInventory("Secret Dossier");
    } else if (choice == 3) {
        showInventory();  // Call to display the player's inventory
        return;  // Let the player go back to the choices in this scene
    } else {
        cout << "Invalid choice. Moving forward...\n";
    }
    transition();
}

	
	// Scene 2
	void scene2() {
	    cout << "Scene 2: The Warehouse\n";
	    cout << "You arrive at the warehouse and find clues linking a powerful corporation to illegal activity.\n";
	    cout << "Choices:\n";
	    cout << "1. Search the warehouse thoroughly.\n";
	    cout << "2. Set up surveillance and wait for suspects to arrive.\n";
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    if (choice == 1) {
	        cout << "You find a hidden stash of documents. Added 'Evidence Folder' to your inventory.\n";
	        addToInventory("Evidence Folder");
	    } else if (choice == 2) {
	        cout << "You observe a key suspect arriving. Added 'Suspect Photo' to your inventory.\n";
	        addToInventory("Suspect Photo");
	    } else {
	        cout << "Invalid choice. Moving forward...\n";
	    }
	    transition();
	}
	
	// Scene 3
	void scene3() {
	    cout << "Scene 3: The Chase\n";
	    cout << "The suspect notices your presence and tries to escape.\n";
	    cout << "Choices:\n";
	    cout << "1. Chase them through the alleys.\n";
	    cout << "2. Call for backup and tail them discreetly.\n";
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    if (choice == 1) {
	        cout << "You catch the suspect and retrieve a cryptic key. Added 'Cryptic Key' to your inventory.\n";
	        addToInventory("Cryptic Key");
	    } else if (choice == 2) {
	        cout << "You tail them to a hidden lair. Added 'Lair Location' to your inventory.\n";
	        addToInventory("Lair Location");
	    } else {
	        cout << "Invalid choice. Moving forward...\n";
	    }
	    transition();
	}
	
	// Scene 4
	void scene4() {
	    cout << "Scene 4: The Hidden Lair\n";
	    cout << "You infiltrate the lair and discover a map leading to a hidden vault.\n";
	    cout << "Choices:\n";
	    cout << "1. Take the map and leave quietly.\n";
	    cout << "2. Search the lair for more clues.\n";
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    if (choice == 1) {
	        cout << "You take the map. Added 'Vault Map' to your inventory.\n";
	        addToInventory("Vault Map");
	    } else if (choice == 2) {
	        cout << "You find a coded message. Added 'Coded Message' to your inventory.\n";
	        addToInventory("Coded Message");
	    } else {
	        cout << "Invalid choice. Moving forward...\n";
	    }
	    transition();
	}
	
	// Scene 5
	void scene5() {
	    cout << "Scene 5: The Encounter\n";
	    cout << "As you leave, you are confronted by armed guards.\n";
	    cout << "Choices:\n";
	    cout << "1. Fight your way out.\n";
	    cout << "2. Use a distraction to escape.\n";
	    cout << "3. View your inventory.\n";  // Option to view inventory
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    if (choice == 1) {
	        cout << "You overpower the guards and escape. Added 'Guard Weapon' to your inventory.\n";
	        addToInventory("Guard Weapon");
	    } else if (choice == 2) {
	        cout << "You create a diversion and flee. Added 'Smoke Grenade' to your inventory.\n";
	        addToInventory("Smoke Grenade");
	    } else if (choice == 3) {
	        showInventory();  // Call to display the player's inventory
	        return;  // Let the player go back to the choices in this scene
	    } else {
	        cout << "Invalid choice. Moving forward...\n";
	    }
	    transition();
	}

	//scene 6
	void scene6() {
	    cout << "Scene 6: The Vault\n";
	    cout << "You arrive at a hidden vault in the mountains based on the map you found.\n";
	    cout << "Choices:\n";
	    cout << "1. Use the Cryptic Key to open the vault.\n";
	    cout << "2. Attempt to crack the vault manually.\n";
	    cout << "3. Set up a trap in case someone else comes.\n";
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    if (choice == 1) {
	        cout << "You open the vault and find confidential files. Added 'Confidential Files' to your inventory.\n";
	        addToInventory("Confidential Files");
	    } else if (choice == 2) {
	        cout << "You crack the vault but accidentally trigger a silent alarm. Added 'Vault Blueprints' to your inventory.\n";
	        addToInventory("Vault Blueprints");
	    } else if (choice == 3) {
	        cout << "You set a trap and capture an enemy agent. Added 'Captured Agent Intel' to your inventory.\n";
	        addToInventory("Captured Agent Intel");
	    } else {
	        cout << "Invalid choice. Moving forward...\n";
	    }
	    transition();
	}
	
	// Scene 7
	void scene7() {
	    cout << "Scene 7: The Betrayal\n";
	    cout << "Returning from the vault, you are ambushed by someone you trusted.\n";
	    cout << "Choices:\n";
	    cout << "1. Fight back and escape.\n";
	    cout << "2. Convince them to spare you.\n";
	    cout << "3. Pretend to surrender and gather intel.\n";
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    if (choice == 1) {
	        cout << "You manage to escape but lose some key documents.\n";
	    } else if (choice == 2) {
	        cout << "They spare you but warn you not to proceed further.\n";
	    } else if (choice == 3) {
	        cout << "You gain critical intel on the conspiracy. Added 'Spy Intel' to your inventory.\n";
	        addToInventory("Spy Intel");
	    } else {
	        cout << "Invalid choice. Moving forward...\n";
	    }
	    transition();
	}
	
	// Scene 8
	void scene8() {
	    cout << "Scene 8: The Alliance\n";
	    cout << "You reach out to an old ally for assistance.\n";
	    cout << "Choices:\n";
	    cout << "1. Share your findings and request help.\n";
	    cout << "2. Keep the details vague but seek resources.\n";
	    cout << "3. Test their loyalty before trusting them fully.\n";
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    if (choice == 1) {
	        cout << "They agree to help and provide you with new tools. Added 'Hacking Device' to your inventory.\n";
	        addToInventory("Hacking Device");
	    } else if (choice == 2) {
	        cout << "They lend you resources but remain suspicious.\n";
	    } else if (choice == 3) {
	        cout << "You test their loyalty and confirm they can be trusted.\n";
	    } else {
	        cout << "Invalid choice. Moving forward...\n";
	    }
	    transition();
	}
	
	// Scene 9
	void scene9() {
	    cout << "Scene 9: The Confrontation\n";
	    cout << "You track down the mastermind behind the conspiracy.\n";
	    cout << "Choices:\n";
	    cout << "1. Confront them directly with your evidence.\n";
	    cout << "2. Set a trap and lure them into it.\n";
	    cout << "3. Use your hacking device to expose their crimes publicly.\n";
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    if (choice == 1) {
	        cout << "They deny the allegations but you stand firm.\n";
	    } else if (choice == 2) {
	        cout << "You successfully trap them and gather additional evidence. Added 'Mastermind's Confession' to your inventory.\n";
	        addToInventory("Mastermind's Confession");
	    } else if (choice == 3) {
	        cout << "You expose their crimes, but they manage to escape.\n";
	    } else {
	        cout << "Invalid choice. Moving forward...\n";
	    }
	    transition();
	}
	
	// Scene 10
	void scene10() {
	    cout << "Scene 10: The Final Showdown\n";
	    cout << "The mastermind prepares to flee the country. You intercept them at the airport.\n";
	    cout << "Choices:\n";
	    cout << "1. Engage them in a fight.\n";
	    cout << "2. Sabotage their escape route.\n";
	    cout << "3. Gather the authorities to arrest them.\n";
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    if (choice == 1) {
	        cout << "You fight valiantly and stop them. Added 'Victory Medal' to your inventory.\n";
	        addToInventory("Victory Medal");
	    } else if (choice == 2) {
	        cout << "You sabotage their plane and ensure they cannot escape.\n";
	    } else if (choice == 3) {
	        cout << "You call the authorities, who arrest the mastermind based on your intel.\n";
	    } else {
	        cout << "Invalid choice. Moving forward...\n";
	    }
	    transition();
	}
	
	// Scene 11
	void scene11() {
	    cout << "Scene 11: Justice Served\n";
	    cout << "With the mastermind arrested, you reflect on your journey and the choices you made.\n";
	    cout << "Choices:\n";
	    cout << "1. Retire and enjoy a peaceful life.\n";
	    cout << "2. Continue investigating other conspiracies.\n";
	    cout << "3. Mentor a new generation of investigators.\n";
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    if (choice == 1) {
	        cout << "You retire and live a quiet, fulfilling life.\n";
	    } else if (choice == 2) {
	        cout << "You dive into a new conspiracy, ready for the next challenge.\n";
	    } else if (choice == 3) {
	        cout << "You mentor a promising young investigator and prepare them for the future.\n";
	    } else {
	        cout << "Invalid choice. Moving forward...\n";
	    }
	    cout << "Congratulations! You completed the game.\n";
	}
	
	// Main function
	int main() {
	    char restart;
	    do {
	        loadInventory();  // Function to load inventory from file
	        inventoryCount = 0;  // Reset inventory for a new game
	
	        cout << "Welcome to *Lies Unveiled: An Interactive Text-Based Conspiracy Game*!\n";
	        cout << "Press Enter to begin your journey...\n";
	        cin.ignore();
	    
	        int choice;
	        bool loggedIn = false;
	    
	        // Login or registration
	        cout << "Welcome to the game!\n";
	        cout << "1. Log in\n";
	        cout << "2. Register\n";
	        cout << "Choose an option: ";
	        cin >> choice;
	    
	        if (choice == 1) {
	            loggedIn = login();  // Calls the login function
	            if (!loggedIn) {
	                cout << "Login failed. Please check your credentials.\n";
	                return 0;  // Exit if login fails
	            }
	        } else if (choice == 2) {
	            registerUser();  // Calls the registration function
	        } else {
	            cout << "Invalid option.\n";
	            return 0;  // Exit if invalid choice
	        }
	    
	        // Scene progression
	        scene1();  // Calls scene 1
	        scene2();  // Calls scene 2
	        scene3();  // Calls scene 3
	        scene4();  // Calls scene 4
	        scene5();  // Calls scene 5
	        scene6();  // Calls scene 6
	        scene7();  // Calls scene 7
	        scene8();  // Calls scene 8
	        scene9();  // Calls scene 9
	        scene10(); // Calls scene 10
	        scene11(); // Calls scene 11
	    
	        cout << "\nYou have completed the game. Would you like to start again? (y/n): ";
	        cin >> restart;
	
	    } while (restart == 'y' || restart == 'Y');  // Loop if the player wants to restart
	
	    cout << "Thank you for playing! Goodbye!\n";
	    return 0;
	}

