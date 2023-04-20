#include "MenuState.h"

#include "RunningState.h"
#include "../GameObjects/GroundObj.h"
#include "../GameObjects/InstructionObj.h"
#include "../GameObjects/ObstacleObj.h"
#include "../GameObjects/Player.h"
#include <cstdlib> 
#include <ctime> 

// Start
MenuState::MenuState(RenderWindow& p_window):
window{p_window}, GameState{std::make_unique<std::vector<std::unique_ptr<GameObject>>>()}
{
    randomOffset = rand() % 701 + 100;
    GroundObj groundPrefab = GroundObj{Vector2f(0,500), Vector2f(SCREEN_WIDTH/2/32,5), std::make_shared<Image>("img/pngs/ground_2.png", p_window)};
    auto groundClone1 = std::make_unique<GroundObj>(groundPrefab);
    auto groundClone2 = std::make_unique<GroundObj>(groundPrefab);
    auto groundClone3 = std::make_unique<GroundObj>(groundPrefab);
    auto player = std::make_unique<Player>(Vector2f(200,400), Vector2f(3, 3), std::make_shared<Image>("img/pngs/zombie_dinosaur_idle.png", p_window));
    auto startInstruction = std::make_unique<InstructionObj>(Vector2f(SCREEN_WIDTH/3, 0), Vector2f(10,10), std::make_unique<Image>("img/pngs/start.png",p_window));

    ObstacleObj obstaclePrefab = ObstacleObj{Vector2f(0,405), Vector2f(3,3), std::make_shared<Image>("img/pngs/cactus.png", p_window)};
    auto obstacleClone1 = std::make_unique<ObstacleObj>(obstaclePrefab);
    auto obstacleClone2 = std::make_unique<ObstacleObj>(obstaclePrefab);
    auto obstacleClone3 = std::make_unique<ObstacleObj>(obstaclePrefab);

    
    groundClone2->pos.x += SCREEN_WIDTH / 2;
    groundClone3->pos.x += SCREEN_WIDTH;

    obstacleClone1->pos.x += SCREEN_WIDTH + randomOffset;
    obstacleClone2->pos.x += SCREEN_WIDTH + randomOffset * 3;
    obstacleClone3->pos.x += SCREEN_WIDTH + randomOffset * 7;
    
    // Adds the pointers to the objects to the world std::vector
    world->push_back(std::move(player));
    world->push_back(std::move(groundClone1));
    world->push_back(std::move(groundClone2));
    world->push_back(std::move(groundClone3));
    world->push_back(std::move(obstacleClone1));
    world->push_back(std::move(obstacleClone2));
    world->push_back(std::move(obstacleClone3));
    world->push_back(std::move(startInstruction));
    
}

// Update
void MenuState::handleInput(SDL_Event input)
{
    if (input.type == SDL_KEYDOWN)
    {
        if(input.key.keysym.sym == SDLK_SPACE && !startGame)
            {
                std::cout << "Start Game\n";
                startGame = true;
            }
    }
    
}

std::unique_ptr<GameState> MenuState::fixedUpdate()
{
    //std::cout << "menu\n";
    if(startGame)
        return std::make_unique<RunningState>(std::move(world), window);
    else
        return nullptr;
}
