#include "MenuState.h"

#include "RunningState.h"
#include "../GameObjects/GroundObj.h"
#include "../GameObjects/Player.h"

// Start
MenuState::MenuState(RenderWindow& p_window):
window{std::move(p_window)},
GameState{std::make_unique<std::vector<std::unique_ptr<GameObject>>>()}
{
    GroundObj groundPrefab = GroundObj{Vector2f(0,500), Vector2f(SCREEN_WIDTH/2/32,5), std::make_shared<Image>("img/pngs/ground_2.png", window)};
    auto groundClone1 = std::make_unique<GroundObj>(groundPrefab);
    auto groundClone2 = std::make_unique<GroundObj>(groundPrefab);
    auto groundClone3 = std::make_unique<GroundObj>(groundPrefab);
    auto player = std::make_unique<Player>(Vector2f(200,400), Vector2f(3, 3), std::make_shared<Image>("img/pngs/zombie_dinosaur_idle.png", window));

    groundClone2->pos.x += SCREEN_WIDTH / 2;
    groundClone3->pos.x += SCREEN_WIDTH; 
    
    // Adds the pointers to the objects to the world std::vector
    world->push_back(std::move(player));
    world->push_back(std::move(groundClone1));
    world->push_back(std::move(groundClone2));
    world->push_back(std::move(groundClone3));
    
}

// Update
void MenuState::handleInput(SDL_Event input)
{
    if(input.key.keysym.sym == SDLK_SPACE)
    {
        startGame = true;
        
    }
}

std::unique_ptr<GameState> MenuState::update()
{
    if(startGame)
        return std::make_unique<RunningState>(std::move(world), window);
    else
        return nullptr;
}
