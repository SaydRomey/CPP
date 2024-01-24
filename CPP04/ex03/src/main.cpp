/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:03:33 by cdumais           #+#    #+#             */
/*   Updated: 2024/01/24 15:26:57 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Implement the AMateria Abstract Class:
This class is abstract (interface-like) with pure virtual functions clone() and use().

Implement Concrete Materia Classes (Ice and Cure):
These classes inherit from AMateria and override the clone() and use() methods.

Implement the ICharacter Interface:
This is an abstract class defining the character interface.

Implement the Character Concrete Class:
This class implements ICharacter and handles Materia management (equip, unequip, use).

Implement the IMateriaSource Interface:
This interface defines methods for learning and creating Materias.

Implement the MateriaSource Concrete Class:
This class implements IMateriaSource and allows learning and creating new Materia instances.

Test Everything in Main:
Create a scenario as described in the exercise, ensuring everything works as expected.
*/

/*
recap of the classes required, along with their types
(abstract, concrete, or interface-like):

	AMateria (Abstract Class)
An abstract class with at least one pure virtual function (clone()).
Serves as the base class for different types of materias.

	Ice (Concrete Class)
Inherits from AMateria.
Represents a specific type of Materia with unique behavior.

	Cure (Concrete Class)
Similar to Ice, but represents a different type of Materia.

	ICharacter (Interface-like Abstract Class)
An abstract class with only pure virtual functions.
Defines the interface for character classes.

	Character (Concrete Class)
Implements the ICharacter interface.
Manages Materias (equip, unequip, use) and has an inventory.

	IMateriaSource (Interface-like Abstract Class)
An abstract class that defines the interface for Materia sources.
Only contains pure virtual functions.

	MateriaSource (Concrete Class)
Implements the IMateriaSource interface.
Manages learning and creating Materias.

	MateriaNode (Utility Structure for Linked List)
A simple struct used for implementing the linked list in the Character class.
Used to manage "floor" Materias.

Each class plays a distinct role, either
defining key behaviors (like AMateria),
providing interfaces (ICharacter and IMateriaSource), or
implementing concrete functionalities (Ice, Cure, Character, MateriaSource).

The MateriaNode structure supports the dynamic management of unequipped Materias.
*/

/*	About the linked list of floorMateria

1. Initialization
When the first Character is created, 
loorMateriaHead is initialized to NULL,
indicating the start of an empty list.
This is done in the source file where the static member is defined.

2. Adding Materias to the List
When any Character instance calls unequip,
the unequipped AMateria is wrapped in a MateriaNode
and added to the front of the linked list.
This node is now the new head of the list.
Since floorMateriaHead is static,
this linked list is the same across all Character instances.
Whether a Character is created normally, copied, or assigned,
they all interact with the same floorMateriaHead.

3. Copying a Character
When a Character is copied
(either through the copy constructor or the assignment operator),
the Materias in the inventory are deeply copied.
However, the linked list (floorMateriaHead) remains unaffected
because it's shared and managed at the class level, not at the instance level.

4. Removing Materias from the List
Materias can be removed from the linked list when you decide to clean up
or when you want to re-equip them to a character.
This would involve iterating over the list, performing the required operation,
and adjusting the pointers accordingly.

5. Clearing the List
The clearFloorMaterias static method is designed to clear the linked list.
When this method is called, it iterates through the linked list,
deletes each AMateria and MateriaNode, and sets floorMateriaHead back to NULL.
This method should be called at a point in your program
where it's safe to remove all unequipped Materias,
like at the end of the program or when you're sure they won't be used anymore.

6. Program Termination
At the end of your program, or when you decide to clear all unequipped Materias,
clearFloorMaterias should be called to clean up the linked list,
ensuring no memory leaks occur.

Key Points
The linked list is shared among all Character instances.

It's used to manage unequipped Materias,
ensuring that they aren't lost or leaked.

Proper management (especially cleanup)
is crucial to avoid memory leaks.
This design allows all characters to share the same pool of unequipped Materias,
which could reflect a shared game world
where items dropped by one character can potentially be picked up by another.
*/

/*
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* player = new Character("player");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    player->equip(tmp);
    tmp = src->createMateria("cure");
    player->equip(tmp);

    ICharacter* bob = new Character("bob");
    player->use(0, *bob);
    player->use(1, *bob);

    // Testing unequip and floor Materia management
    player->unequip(0); // Ice materia is now on the floor
    player->unequip(1); // Cure materia is now on the floor

    // Creating another character to interact with floor Materias
    ICharacter* alice = new Character("alice");
    // Suppose alice picks up a Materia from the floor (simulated here)
    // In a real game, this would be more dynamic
    Character::clearFloorMaterias(); // Cleaning up floor Materias

    delete bob;
    delete alice;
    delete player;
    delete src;

    return 0;
}
*/

/*
	AMateria Class (Abstract)
With at least one pure virtual function (clone()).
Base class for different types of Materias.

	Concrete Materia Classes (Ice and Cure)
Inheriting from AMateria.
Each has its unique behavior and implementation of clone() and use().

	ICharacter Interface (Abstract)
An interface with only pure virtual functions.
Defines the structure for character classes.

	Character Class (Concrete)
Implements the ICharacter interface.
Manages Materias with inventory and floor Materias.

	IMateriaSource Interface (Abstract)
An interface for Materia sources.
Defines learnMateria() and createMateria().

	MateriaSource Class (Concrete)
Implements IMateriaSource.
Manages learning and creating new Materia instances.

	Utility Structure (MateriaNode)
Used in the Character class for managing a linked list of Materias.
*/

/*
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main() {
    // Create a Materia source and learn some Materias
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Create player character
    ICharacter* player = new Character("Player");

    // Player equips Materias
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    player->equip(ice);
    player->equip(cure);

    // Create another character for interaction
    ICharacter* enemy = new Character("Enemy");

    // Player uses Materias on enemy
    player->use(0, *enemy); // Uses Ice on Enemy
    player->use(1, *enemy); // Uses Cure on Enemy

    // Unequip and test "floor" Materias
    player->unequip(0); // Ice is now on the floor
    player->unequip(1); // Cure is now on the floor

    // Create a third character
    ICharacter* ally = new Character("Ally");

    // Simulate Ally picking up a floor Materia (ice)
    // In an actual game, this would be more dynamic
    Character::clearFloorMaterias(); // Clearing floor Materias

    // Interaction between player and ally
    player->equip(src->createMateria("ice"));
    player->use(0, *ally); // Player uses a new Ice Materia on Ally

    // Clean up
    delete enemy;
    delete ally;
    delete player;
    delete src;

    return 0;
}
*/

/*
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(NULL); // Edge case: Learning NULL Materia

    ICharacter* player = new Character("Player");
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    AMateria* unknown = src->createMateria("fire"); // Edge case: Unknown Materia

    // Equip Materias
    player->equip(ice);
    player->equip(cure);
    player->equip(unknown); // Should do nothing

    // Fill the inventory and test adding to full inventory
    player->equip(src->createMateria("ice"));
    player->equip(src->createMateria("cure"));
    player->equip(src->createMateria("ice")); // Inventory should now be full

    // Test using and unequipping non-existing Materias
    player->use(4, *player);  // Non-existing slot
    player->unequip(4);       // Non-existing slot

    // Test using valid Materias
    player->use(0, *player);
    player->use(1, *player);

    // Test unequipping and "floor" Materias management
    player->unequip(0); // Ice is now on the floor
    player->unequip(1); // Cure is now on the floor

    // Cleanup
    ICharacter* enemy = new Character("Enemy");
    player->use(0, *enemy);  // Using a slot that was unequipped
    player->use(2, *enemy);  // Using a valid slot

    Character::clearFloorMaterias(); // Clearing floor Materias

    delete enemy;
    delete player;
    delete src;

    return 0;
}
*/

/*
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* player = new Character("Player");
    ICharacter* enemy = new Character("Enemy");

    // Test edge case: valid index but no Materia
    player->use(0, *enemy); // No Materia equipped yet

    // Equip and use Materias
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    player->equip(ice);
    player->equip(cure);
    player->use(0, *enemy); // Uses Ice
    player->use(1, *enemy); // Uses Cure

    // Test full inventory
    player->equip(src->createMateria("ice"));
    player->equip(src->createMateria("cure")); // Inventory is now full
    player->equip(src->createMateria("ice"));  // Should be ignored

    // Test using non-existing Materia
    player->use(3, *enemy); // Valid index but no Materia

    // Test unequipping
    player->unequip(0); // Unequip Ice

    // Test clone function: Cloning Ice Materia
    AMateria* clonedIce = ice->clone();
    player->equip(clonedIce);

    // Reusing unequipped slot
    player->use(0, *enemy); // Should use cloned Ice

    // Cleanup
    Character::clearFloorMaterias(); // Clearing "floor" Materias
    delete player;
    delete enemy;
    delete src;

    return 0;
}
*/

/*	Materia in FFVII

Cure Materia: Allows characters to cast healing spells like Cure, Cura, and Curaga.

Ice Materia: Enables the casting of ice-based spells like Ice, Ice2, and Ice3.

Fire Materia: Similar to Ice, but for fire-based spells like Fire, Fire2, and Fire3.

Lightning Materia: Allows characters to cast lightning-based spells like Bolt, Bolt2, and Bolt3.

Restore Materia: Another healing Materia, similar to Cure, often used to restore HP.

Revive Materia: Grants abilities to resurrect fallen party members, like Life and Life2.

Barrier Materia: Provides protective spells like Barrier and MBarrier, which increase defense against physical and magical attacks.

Time Materia: Grants time-related spells like Haste (speeds up a character), Slow (slows down an enemy), and Stop (freezes an enemy).

Summon Materia: Unique in that they allow characters to summon powerful creatures for attacks, like Ifrit, Shiva, and Bahamut.

All Materia: Used in combination with other Materias to extend their effects to all targets or party members.

Enemy Skill Materia: Enables characters to learn and use certain abilities used by enemies.

Counter Materia: Used for counterattacking when a character is hit by a physical attack.
*/