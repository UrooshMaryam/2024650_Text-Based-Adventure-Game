#include <iostream>
#include <fstream>
#include <string>

using namespace std;
	
// Function to display a welcome message with a pattern
	void welcomeScreen() {
	    string welcomeMessage = "Welcome to the Interactive Spy Game!";
	
	    // Display pattern
	    cout << "-------------------------------------------" << endl;
	    cout << "-------------------------------------------" << endl;
	
	    // Display the welcome message with a frame
	    cout << "**  " << welcomeMessage << "  **" << endl;
	    cout << "-------------------------------------------" << endl;
		cout << "-------------------------------------------" << endl;
		
	    // Simulate a loading effect by printing dots in a loop
	    cout << "\nLoading your adventure";
	    for (int i = 0; i < 15; i++) {
	        cout << ".";
	        // Simple delay using loops for effect
	        for (int j = 0; j < 100000000; j++) {} // Delay loop
	    }
	    cout << "\n\n";
	}
	
// Function to register a new user
	void registerUser() {
	    string* username = new string; // Dynamically allocate memory for username
	    string* password = new string; // Dynamically allocate memory for password
	    ofstream file("users.txt", ios::app); // Open file in append mode
	
	    cout << "Enter a username: ";
	    cin >> *username; // Use pointer to store input
	    cout << "Enter a password: ";
	    cin >> *password; // Use pointer to store input
	
	    // Store username and password in the file
	    file << *username << ":" << *password << endl;
	    file.close();
	
	    cout << "Registration successful!" << endl;
	
	    // Free dynamically allocated memory
	    delete username;
	    delete password;
	}

	
// Function to log in a user
	bool login() {
	    // Dynamically allocate memory for strings
	    string* username = new string;
	    string* password = new string;
	    string* storedUsername = new string;
	    string* storedPassword = new string;
	    ifstream file("users.txt"); // Open the file to read user details
	
	    cout << "Enter username: ";
	    cin >> *username;
	    cout << "Enter password: ";
	    cin >> *password;
	
	    while (getline(file, *storedUsername, ':') && getline(file, *storedPassword)) {
	        if (*storedUsername == *username && *storedPassword == *password) {
	            file.close();
	            delete username;
	            delete password;
	            delete storedUsername;
	            delete storedPassword;
	            return true; // Successfully logged in
	        }
	    }
	
	    file.close();
	    delete username;
	    delete password;
	    delete storedUsername;
	    delete storedPassword;
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
	    cout<<endl;
	    cout<<endl;
	    cout<< "-----------------------------------";
	    cout<< endl;
	    cout << "Press Enter to continue...";
	    cin.ignore();
	    cin.get();
	}
	
// A number lock Puzzle
	void numberLockPuzzle() {
    cout << "\nAs you examine the locked safe, a digital keypad lights up. A robotic voice speaks:\n";
    cout << "\"To unlock me, prove your wit. Solve this riddle, or the secrets remain hidden forever.\"\n";
    cout << "\nRiddle:\n";
    cout << "I am a three-digit number.\n";
    cout << "- My tens digit is five more than my ones digit.\n";
    cout << "- My hundreds digit is eight less than my tens digit.\n";
    cout << "- What number am I?\"\n";
    
    int playerAnswer;
    cout << "Enter your answer: ";
    cin >> playerAnswer;

    if (playerAnswer == 194) {
        cout << "\nThe safe beeps and clicks open. Inside, you find a meticulously organized file titled 'Secret Dossier.'\n";
        addToInventory("Secret Dossier");
    } else {
        cout << "\nA red light flashes on the keypad. The voice speaks again: \"Wrong answer. Try again, if you dare.\"\n";
        numberLockPuzzle();  // Recursive call to retry the puzzle
    }
}

// Function to handle the Interactive Dialogue Puzzle
	void interactiveDialoguePuzzle() {
	    cout << "You catch the suspect and confront them. They are hesitant but willing to talk.\n";
	    cout << "The suspect gives you three cryptic pieces of information:\n";
	    cout << "1. 'The clock strikes at midnight in the old warehouse.'\n";
	    cout << "2. 'The map is hidden beneath the floorboards of the east side.'\n";
	    cout << "3. 'The truth is behind the black door with no handle.'\n";
	    cout << "\nYou must figure out which of these clues is crucial for finding the suspect's next move.\n";
	    cout << "Choose the correct clue to proceed:\n";
	    cout << "1. 'The clock strikes at midnight in the old warehouse.'\n";
	    cout << "2. 'The map is hidden beneath the floorboards of the east side.'\n";
	    cout << "3. 'The truth is behind the black door with no handle.'\n";
	    
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    if (choice == 1) {
	        cout << "The clue about the clock at midnight leads you to a hidden rendezvous in the old warehouse.\n";
	        cout << "You gather intel that will help you track the suspect's next location.\n";
	        // Add relevant item to inventory
	        cout << "Added 'Warehouse Map' to your inventory.\n";
	        addToInventory("Warehouse Map");
	    } else if (choice == 2) {
	        cout << "The map hidden beneath the floorboards leads you to a secret safehouse, but it's a trap!\n";
	        cout << "The suspect escapes, and you're forced to regroup.\n";
	    } else if (choice == 3) {
	        cout << "The black door with no handle hides a hidden message that provides an unexpected lead.\n";
	        cout << "However, it doesn't help you catch the suspect immediately, so you go back to square one.\n";
	    } else {
	        cout << "Invalid choice. Try again...\n";
	        interactiveDialoguePuzzle(); // Restart the puzzle if the input is invalid
	        return;
	    }
	}

// Pattern puzzle
	void patternPuzzle() {
	    cout << "You see a keypad with four buttons: 1, 2, 3, 4.\n";
	    cout << "To unlock the vault, you need to figure out the correct sequence to press based on the clues.\n";
	    cout << "Clue 1: The sequence alternates between even and odd positions.\n";
	    cout << "Clue 2: The first button to press is '1'.\n";
	    cout << "Clue 3: The third button to press is '2'.\n";
	    
	    int playerAnswer[4];  // Array to store the player's answer
	    cout << "Enter the sequence of four numbers separated by spaces (e.g., 1 3 2 4): ";
	    
	    // Get player's input
	    for (int i = 0; i < 4; ++i) {
	        cin >> playerAnswer[i];
	    }
	    
	    // Check if the player's answer matches the correct pattern
	    int correctPattern[4] = {1, 3, 2, 4}; // Correct sequence pattern
	    
	    bool isCorrect = true;  // Assume the answer is correct initially
	    
	    // Compare player's answer to the correct pattern
	    for (int i = 0; i < 4; ++i) {
	        if (playerAnswer[i] != correctPattern[i]) {
	            isCorrect = false;  // If any number is incorrect, the answer is wrong
	            break;
	        }
	    }
	    
	    // If correct, unlock the vault; otherwise, restart the puzzle
	    if (isCorrect) {
	        cout << "The vault unlocks! You found confidential files inside. Added 'Confidential Files' to your inventory.\n";
	        addToInventory("Confidential Files");
	    } else {
	        cout << "Incorrect sequence! Try again...\n";
	        patternPuzzle();  // Restart the puzzle on incorrect answer
	    }
	}

// Function for the fight puzzle
	void fightPuzzle() {
	    cout << "You are surrounded by guards! You need to act fast to survive.\n";
	    cout << "A guard lunges at you with a knife. Quickly, react by choosing the correct command!\n";
	
	    // Quick-time event (QTE) puzzle
	    cout << "Press 'D' to dodge the attack or 'S' to strike first.\n";
	    char reaction;
	    cin >> reaction;
	
	    if (reaction == 'D' || reaction == 'd') {
	        cout << "You dodge the attack and disarm the guard!\n";
	    } else if (reaction == 'S' || reaction == 's') {
	        cout << "You strike first and knock the guard out!\n";
	    } else {
	        cout << "You hesitated! The guard manages to strike you. Let's try again.\n";
	        return;  // Retry the fight if the player fails
	    }
	
	    cout << "A second guard comes at you with a taser. React fast!\n";
	    cout << "Press 'E' to evade or 'F' to fight back.\n";
	    cin >> reaction;
	
	    if (reaction == 'E' || reaction == 'e') {
	        cout << "You evade the taser and counterattack with a swift move!\n";
	    } else if (reaction == 'F' || reaction == 'f') {
	        cout << "You fight back and disable the guard!\n";
	    } else {
	        cout << "You took too long to react! The taser hits you. Try again.\n";
	        return;  // Retry the fight if the player fails
	    }
	
	    addToInventory("Guard Weapon");  // Add the weapon to the inventory after success
	    cout << "You've successfully fought your way out!\n";
	}	
	


// Declaration of scene 10, to be used in function.
	void scene10();
	
//Runaway Puzzle
	void runwayPuzzle(int choice) {
	    if (choice == 1) {
        // Jet Ignition Control Puzzle
        cout << "You approach the jet's ignition control panel.\n";
        cout << "There are 6 switches labeled A, B, C, D, E, F.\n";
        cout << "You need to turn off switches B, E, and D in that order.\n";
        cout << "Enter the sequence of switches to turn off (e.g., B E D): ";
        string sequence;
        cin.ignore();
        getline(cin, sequence);

        if (sequence == "B E D") {
            cout << "You disable the ignition system. The jet won't start!\n";
            // Add item to inventory
            cout << "Added 'Disabled Ignition System' to your inventory.\n";
            addToInventory("Disabled Ignition System");
        } else {
            cout << "Incorrect sequence. Try again...\n";
            scene10();  // Restart the scene for retry
            return;
        }
    } else if (choice == 2) {
        // Runway Lights Puzzle
        cout << "You head to the runway lights control panel.\n";
        cout << "You notice a clue on the ground: The sequence 3-1-5-2-4.\n";
        cout << "You need to turn off the runway lights in this sequence.\n";
        cout << "Enter the sequence of light numbers to turn off (e.g., 3 1 5 2 4): ";
        string sequence;
        cin.ignore();
        getline(cin, sequence);

        if (sequence == "3 1 5 2 4") {
            cout << "You sabotage the runway lights, causing confusion for the plane's takeoff.\n";
            // Add item to inventory
            cout << "Added 'Sabotaged Runway Lights' to your inventory.\n";
            addToInventory("Sabotaged Runway Lights");
        } else {
            cout << "Incorrect sequence. Try again...\n";
            scene10();  // Restart the scene for retry
            return;
        }
    } else if (choice == 3) {
        // Security Terminal Code Puzzle
        cout << "You approach the security terminal.\n";
        cout << "You need to enter the correct code to lock down the plane's access doors.\n";
        cout << "Solve the puzzle: Add 3 to the number of doors (4) and multiply by the number of windows (6).\n";
        int answer;
        cout << "Enter the code: ";
        cin >> answer;

        if (answer == 42) {
            cout << "You lock down the access doors, preventing the mastermind from escaping!\n";
            // Add item to inventory
            cout << "Added 'Locked Access Doors' to your inventory.\n";
            addToInventory("Locked Access Doors");
        } else {
            cout << "Incorrect code. Try again...\n";
            scene10();  // Restart the scene for retry
            return;
        }
    } else {
        cout << "Invalid choice. Try again...\n";
        scene10();  // Restart the scene for retry
        return;
    }
}

// Puzzle for the direct confrontation (Choice 1) in scene9
	void confrontationPuzzle() {
	    cout << "\nYou confront the mastermind with your evidence, but they deny everything.\n";
	    cout << "They make three statements about their alibi. One of them is false.\n";
	    cout << "1. \"I was at home during the time of the crime.\"\n";
	    cout << "2. \"I have an airtight alibi; I was with a colleague at the time.\"\n";
	    cout << "3. \"I was visiting an old friend in another city during the crime.\"\n";
	
	    // Question to the player
	    cout << "\nWhich statement is a lie?\n";
	    cout << "1. Statement 1\n";
	    cout << "2. Statement 2\n";
	    cout << "3. Statement 3\n";
	
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    // Puzzle solution: Statement 3 is a lie, because they were seen at the crime scene.
	    if (choice == 3) {
	        cout << "Correct! Statement 3 is false. The mastermind was lying about their alibi!\n";
	        cout << "The truth is exposed. You now have a solid lead!\n";
	        addToInventory("Mastermind's Confession");  // Adding to inventory after solving the puzzle
	    } else {
	        cout << "Incorrect. Try again. Think carefully about the alibi.\n";
	        confrontationPuzzle();  // Restart the puzzle if the player chooses wrong
	        return;
	    }
	}

// Puzzle for setting a trap (Choice 2) in scene 9
	void trapPuzzle() {
	    cout << "\nYou set a trap for the mastermind and hack into their communication device.\n";
	    cout << "You find a code that is the key to unlocking their secret message.\n";
	    cout << "The code is made up of numbers, and you must decipher it.\n";
	    cout << "The code is: 3 14 2 9 5.\n";
	
	    // The puzzle: Decode the numbers into letters using the alphabet (A=1, B=2, C=3, etc.)
	    cout << "\nWhat is the decoded message?\n";
	    cout << "1. C I B J E\n";
	    cout << "2. C I B I E\n";
	    cout << "3. D I B J E\n";
	
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    // Puzzle solution: Correct decoding is "C I B J E", corresponding to choice 1.
	    if (choice == 1) {
	        cout << "Correct! The decoded message reveals the mastermind's secret plan!\n";
	        cout << "You have successfully uncovered valuable information!\n";
	        addToInventory("Mastermind's Secret Plan");  // Adding to inventory after solving the puzzle
	    } else {
	        cout << "Incorrect. Try decoding the message again.\n";
	        trapPuzzle();  // Restart the puzzle if the player chooses wrong
	        return;
	    }
	}
	
// Hacking Puzzle for the Hacking Choice (Choice 3) in scene 9
	void hackingPuzzle() {
	    cout << "\nYou use your hacking device to expose the mastermind's crimes.\n";
	    cout << "The security system is tough, but you can bypass it if you follow the right sequence of actions.\n";
	    cout << "You are presented with a series of security measures.\n";
	    cout << "To proceed, you must choose the correct order of actions to hack the system.\n";
	    
	    cout << "\nSecurity Measures to Bypass:\n";
	    cout << "1. Disable the firewall\n";
	    cout << "2. Decrypt the server password\n";
	    cout << "3. Bypass the security lock\n";
	    cout << "4. Access the secret files\n";
	    cout << "You must choose the correct sequence of actions. What's the right order?\n";
	    cout << "Choices:\n";
	    cout << "1. Disable the firewall -> Decrypt the server password -> Bypass the security lock -> Access the secret files\n";
	    cout << "2. Bypass the security lock -> Disable the firewall -> Decrypt the server password -> Access the secret files\n";
	    cout << "3. Decrypt the server password -> Disable the firewall -> Access the secret files -> Bypass the security lock\n";
	    cout << "4. Access the secret files -> Bypass the security lock -> Decrypt the server password -> Disable the firewall\n";
	
	    int choice;
	    cout << "Enter your choice: ";
	    cin >> choice;
	
	    // The correct sequence of actions is: 1. Disable the firewall -> 2. Decrypt the server password -> 3. Bypass the security lock -> 4. Access the secret files
	    if (choice == 1) {
	        cout << "Correct! You bypass the security system and gain access to the secret files.\n";
	        cout << "The mastermind's crimes are now exposed to the public!\n";
	        addToInventory("Mastermind's Exposed Files");  // Adding to inventory after solving the puzzle
	    } else {
	        cout << "Incorrect sequence. Try again.\n";
	        hackingPuzzle();  // Restart the puzzle if the player chooses the wrong sequence
	        return;
	    }
	}
	
// Scene 1
	void scene1() {
    cout << endl;
    cout << "Scene 1: The Mysterious Call\n";
    cout << "Blake is sitting in his dimly lit office, the rain tapping softly against the windows. The clock strikes midnight. Suddenly, his phone rings; an encrypted call from an unknown number.\n";
    cout << "Blake receives an encrypted call hinting at a conspiracy involving powerful figures.\n";
    cout << "Choices:\n";
    cout << "1. Trace the call to a suspicious warehouse.\n";
    cout << "2. Ignore it and investigate the sender.\n";
    cout << "3. View your inventory.\n"; // Option to view inventory
    int choice;
    
    // Loop until a valid choice is made
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "You trace the call to a suspicious warehouse. Inside, you find a locked safe glowing ominously.\n";
            cout << "To unlock the secrets within, you must solve a puzzle.\n";
            numberLockPuzzle(); // Call the puzzle function
            cout << "\nWith the 'Secret Dossier' in hand, you decide to prepare for the next step of your mission.\n";
            break; // Exit the loop and move to the next scene
        } else if (choice == 2) {
            cout << "You investigate the sender and uncover a small clue: a locked safe. To proceed, you must solve its riddle.\n";
            numberLockPuzzle(); // Call the puzzle function
            cout << "\nAfter cracking the safe and retrieving the 'Secret Dossier,' you feel ready to dive deeper into the mystery.\n";
            break; // Exit the loop and move to the next scene
        } else if (choice == 3) {
            showInventory(); // Call to display the player's inventory
            // The loop will continue, asking the user for input again without progressing to the next scene
        } else {
            cout << "Invalid choice. Let's try again...\n"; // Retry on invalid input
        }
    }

    transition(); // Smooth flow to the next scene after a valid choice
}

	
// Scene 2
	void scene2() {
	cout << endl;
    cout << "Scene 2: The Warehouse\n";
    cout << "After a tense drive through the city’s backstreets, you arrive at the outskirts of town.\n";
    cout<< "The warehouse looms ahead—an abandoned structure, its windows broken, casting shadows under the pale moonlight. The air is thick with the scent of oil and rust.\n";
    cout << "You cautiously step inside, the creaking of old wooden floors echoing in the silence. A faint glow from a single overhead light illuminates the dust-covered floor, where you spot signs of recent activity. There’s something here—something hidden in the corners of this forgotten place.\n";
    cout << "You begin to search for clues linking a powerful corporation to illegal activity.\n";
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
        cout << "Invalid choice. Let's try again...\n";
        scene2(); // Restart the scene on invalid input
        return;  
    }
    transition(); 
}

	
// Scene 3
	void scene3() {
    cout << endl;
    cout << "Scene 3: The Chase\n";
    cout << "The suspect, realizing he’s been compromised, bolts into the night. His footsteps echo through the narrow alleyways as the sound of distant traffic fades into the background. The dim streetlights flicker above, casting long, ominous shadows across the cobblestone streets. A cold wind rushes through the alleys, carrying with it the faint smell of wet asphalt and urgency.\n";
    cout << "You must decide how to respond as the suspect disappears into the darkness, his form growing smaller with each passing second.\n";
    cout << "Choices:\n";
    cout << "1. Chase them through the alleys.\n";
    cout << "2. Call for backup and tail them discreetly.\n";
    cout << "3. View your inventory.\n";  // Option to view inventory
    int choice;

    // Loop until a valid choice is made
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "You catch the suspect and retrieve a mysterious encrypted message.\n";
            cout << "The message seems crucial, but it's encrypted. To continue, you need to solve this interactive puzzle.\n";
            interactiveDialoguePuzzle(); // Call the interactive dialogue puzzle function
            cout << "\nWith the valuable lead in hand, you uncover the suspect's next move.\n";
            break; // Exit the loop and move to the next scene
        } else if (choice == 2) {
            cout << "You tail the suspect to a hidden lair. There, you find a cryptic message written on a wall.\n";
            cout << "To proceed, you must solve this puzzle by talking to the suspect's informant.\n";
            interactiveDialoguePuzzle(); // Call the interactive dialogue puzzle function
            cout << "\nThe conversation reveals the suspect's safehouse location.\n";
            break; // Exit the loop and move to the next scene
        } else if (choice == 3) {
            showInventory(); // Call to display the player's inventory
            // The loop will continue, asking the user for input again without progressing to the next scene
        } else {
            cout << "Invalid choice. Let's try again...\n"; // Retry on invalid input
        }
    }

    transition();
}


// Scene 4
	void scene4() {
	cout << endl;
    cout << "Scene 4: The Hidden Lair\n";
   cout << "You’ve made your way to the hidden lair, a desolate, underground bunker concealed beneath the city’s crumbling ruins. The walls are damp, and the air smells of mildew and rust. Dim, flickering lights cast long shadows, adding to the eerie atmosphere of this forgotten place.\n";
    cout << "In the center of the lair, a large wooden table is cluttered with old maps, files, and strange symbols. On the wall, a map catches your attention—its routes and markings lead to a hidden vault, perhaps the key to unraveling the conspiracy.\n";
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
        cout << "Invalid choice. Let's try again...\n";
        scene4(); 
        return; 
    }
    transition(); 
}

//scene 5	
	void scene5() {
	    cout << endl;
	    cout << "Scene 5: The Encounter\n";
	    cout << "As you leave, you are confronted by armed guards blocking your escape.\n";
	    cout << "Choices:\n";
	    cout << "1. Fight your way out.\n";
	    cout << "2. Use a distraction to escape.\n";
	    cout << "3. View your inventory.\n";  // Option to view inventory
	    int choice;
	
	    while (true) {
	        cout << "Enter your choice: ";
	        cin >> choice;
	
	        if (choice == 1) {
	            fightPuzzle();  // Call the fight puzzle function
	            break;  // End the scene after the puzzle
	
	        } else if (choice == 2) {
	            cout << "You use a smoke grenade to create a diversion and escape!\n";
	            addToInventory("Smoke Grenade");
	            break;  // End the scene after using the smoke grenade
	
	        } else if (choice == 3) {
	            showInventory();  // Show inventory and let the player choose again
	        } else {
	            cout << "Invalid choice. Try again...\n";  // Retry on invalid input
	        }
	    }
	
	    transition();  // Move to the next scene
	}



//scene 6
	void scene6() {
		cout << endl;
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
	        // Puzzle integration for using the Cryptic Key
	        cout << "You approach the vault and insert the Cryptic Key into the keypad.\n";
	        patternPuzzle();  // Call the pattern puzzle directly
	    } else if (choice == 2) {
	        cout << "You crack the vault but accidentally trigger a silent alarm. Added 'Vault Blueprints' to your inventory.\n";
	        addToInventory("Vault Blueprints");
	    } else if (choice == 3) {
	        cout << "You set a trap and capture an enemy agent. Added 'Captured Agent Intel' to your inventory.\n";
	        addToInventory("Captured Agent Intel");
	    } else {
	        cout << "Invalid choice. Let's try again...\n";
	        scene6();  // Restart the scene on invalid input
	        return;  // Ensure we don't proceed to transition if the choice was invalid
	    }
	    transition(); // Smooth flow to the next scene
	}

	
// Scene 7
	void scene7() {
	cout << endl;
    cout << "Scene 7: The Betrayal\n";
    cout << "Returning from the vault, you are ambushed by someone you trusted.\n";
    cout << "Choices:\n";
    cout << "1. Fight back and escape.\n";
    cout << "2. Convince them to spare you.\n";
    cout << "3. Pretend to surrender and gather intel.\n";
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    // Handle valid and invalid choices for scene 7
    if (choice == 1) {
        cout << "You manage to escape but lose some key documents.\n";
    } else if (choice == 2) {
        cout << "They spare you but warn you not to proceed further.\n";
    } else if (choice == 3) {
        cout << "You gain critical intel on the conspiracy. Added 'Spy Intel' to your inventory.\n";
        addToInventory("Spy Intel");
    } else {
        cout << "Invalid choice. Let's try again...\n";
        scene7(); 
        return;  
    }
    transition(); 
}

	
// Scene 8
	void scene8() {
		cout << endl;
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
        cout << "Invalid choice. Let's try again...\n";
	    scene8();
	    return;
	    }
	    transition();
	}
	
// Scene 9
	void scene9() {
    cout << endl;
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
        confrontationPuzzle();  // Call the confrontation puzzle if player chooses to confront directly
    } else if (choice == 2) {
        trapPuzzle();  // Call the trap puzzle if player chooses to set a trap
    } else if (choice == 3) {
        hackingPuzzle();  // Call the hacking puzzle if player chooses to use hacking device
    } else {
        cout << "Invalid choice. Let's try again...\n";
        scene9(); 
        return;
    }

    transition();
}
	
// Scene 10
	void scene10() {
		cout << endl;
	    cout << "Scene 10: The Final Showdown\n";
	    cout << "The mastermind prepares to flee the country. You intercept them at the airport.\n";
	    cout << "You must sabotage their escape route to stop them. Choose carefully.\n";
	
	    cout << "Choices:\n";
	    cout << "1. Disable the jet's ignition control.\n";
	    cout << "2. Sabotage the runway lights.\n";
	    cout << "3. Lock down the airplane access doors.\n";
	    cout << "Enter your choice: ";
	    int choice;
	    cin >> choice;
	
	    runwayPuzzle(choice);  // Call the puzzle function based on the player's choice
	
	    // Transition to the next scene after the puzzle
	    cout << "You successfully sabotage the mastermind's escape attempt!\n";
	    cout << "Added 'Victory Medal' to your inventory.\n";  // Victory Medal for completing the mission
	    addToInventory("Victory Medal");  // Add the Victory Medal to inventory
	
	    cout << "Transitioning to the next scene...\n";
	}
	
// Scene 11
	void scene11() {
		cout << endl;
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
	         cout << "Invalid choice. Let's try again...\n";
		    scene11();
		    return;
	    }
	    cout << "Congratulations! You completed the game.\n";
	}
	
// Main function
	int main() {
	    char restart;
	    do {
	        loadInventory();  // Function to load inventory from file
	        inventoryCount = 0;  // Reset inventory for a new game
			welcomeScreen();
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
