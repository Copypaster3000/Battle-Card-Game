# Battle Card Game

This project is a two-player battle card game written in C++. Each player is dealt three types of cards (attack, defense, heal) and must strategically select cards each round to reduce their opponent’s health to zero. The game leverages custom data structures, operator overloading, and object-oriented programming to provide an engaging card-based battle system.

## Features
- Object-Oriented Design: The game is built using a hierarchy of classes, including AttackCard, DefenseCard, and HealCard, all derived from a base Card class. This modular design allows for the easy addition of new card types.
- Circular Linked List (CLL) and Linear Linked List (LLL): The game uses a Circular Linked List to manage defense cards and a Linear Linked List to manage attack cards, providing efficient card management. Additionally, the Standard Template Library (STL) vector is used to manage heal cards, allowing dynamic resizing and efficient access.
- Dynamic Card Stats: Cards are created with randomized stats within defined ranges. Each game the cards are different making for a new and unpredictable game each time.

## Instructions
