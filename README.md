# Battle Card Game

This project is a two-player battle card game written in C++. Each player is dealt three types of cards (attack, defense, heal) and must strategically select cards each round to reduce their opponent’s health to zero. The game leverages custom data structures, an inheritance hierarchy, and object-oriented programming to provide an engaging card-based battle system.

## Features

- Object-Oriented Design: The game is built using a hierarchy of classes, including AttackCard, DefenseCard, and HealCard, all derived from a base Card class. This modular design allows for the easy addition of new card types.
- Circular Linked List (CLL) and Linear Linked List (LLL): The game uses a Circular Linked List to manage defense cards and a Linear Linked List to manage attack cards, providing efficient card management. Additionally, the Standard Template Library (STL) vector is used to manage heal cards, allowing dynamic resizing and efficient access.
- Dynamic Card Stats: Cards are created with randomized stats within defined ranges. Each game the cards are different making for a new and unpredictable game each time.

## Instructions

This is a two-player card game. Each player starts with 1000 health. The first player to reduce their opponent’s health to zero wins. Each player is dealt three decks of cards at the beginning of the game. There are attack cards, defense cards, and heal cards.

In each round, both players will select one card from a deck of their choice. The cards will then be played against each other, and the results will impact each player’s health. Attack cards have a strength level of 500 to 0. The level of strength is the amount of damage that can be done to the opponent's health. However, there are two different types of attacks. If the opponent chooses a defense card that corresponds to the type of attack card you have, your attack will be reduced in strength by the defense card's strength. If the defense card does not block the attack type, all of the attack's damage will be subtracted from the opponent's health.

Defense cards have a strength between 375 to 0. If the defense type does not block the attack, the damage will still be done. There are two types of attack and defense cards. Defense cards also have between 150 to 0 heal strength. Regardless of the opponent's card, the heal strength will be added to your health.

Lastly, there are heal cards. Heal cards have a strength from 300 to 200, which increases your health each time you play it. But they do not defend against attacks or do any damage to your opponent.

The stats for all the cards are randomly generated within their listed ranges. The player who chooses their card first alternates each round. Players cannot look at the type of card their opponent selects before the battle.
