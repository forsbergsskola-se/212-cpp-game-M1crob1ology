# Zombie Dinosaur Game
Zombie Dinosaur Game is a fun 2D game made using the SDL library in C++. It is a clone of the popular Dinosaur game that you can play on Google Chrome when you have no internet connection. However, instead of a normal dinosaur, you get to control a zombie dinosaur in a post-apocalyptic world!

![image](https://user-images.githubusercontent.com/56590155/234280053-d1cc723a-ef60-45b6-9309-9ab7b3a6fb7e.png)

## Game Design
To make the code clean and maintainable, I used several design patterns in the game's architecture.

### Inheritance
I used inheritance to create a base class called GameObject. From this base class, several other classes were derived, such as GroundObj, ObstacleObj, and PlayerObj. This approach allowed me to reuse code and avoid duplicating functionality across different classes.

### State Pattern
To manage the different states of the game, such as the menu, running, and dead states, I used the State pattern. Each state is represented by a class that derives from a base class called GameState. Using the State pattern allowed me to encapsulate the behavior and data associated with each state in a separate class. This made the code more modular and easier to extend.

### Update Pattern
I used the Update pattern by having an abstract update() function on each GameObject. This function is called every frame and tells the object what it should do. This pattern allowed me to decouple the logic for updating the objects from the game loop and make it more flexible.

### Game Loop Pattern
I implemented the Game Loop pattern to ensure that the game runs smoothly. The game loop runs continuously during gameplay and processes user input without blocking, updates the game state, and renders the game. It also tracks the passage of time to control the rate of gameplay.

### Decoupling
To ensure that the code was as modular and maintainable as possible, I divided it into as many classes as I could. This allowed me to decouple the different parts of the codebase, making it easier to extend and maintain.

## How to Play
During the game, you will control the zombie dinosaur by pressing the space bar to jump over obstacles. If you hit an obstacle (or press backspace), the game should switch to the dead state , where you can press the space bar to restart the game.

## Conclusion
I hope you enjoy playing Zombie Dinosaur Game! By using several design patterns such as Inheritance, State, Update, and Game Loop, as well as decoupling, I was able to create a clean and modular codebase that can be easily extended and maintained.

![image](https://user-images.githubusercontent.com/56590155/234279964-9aee17c7-1c57-4942-bfb4-5b54b4e46e3b.png)




https://user-images.githubusercontent.com/56590155/235317232-11ffc7a1-95bd-4489-b73b-477893ece791.mp4



