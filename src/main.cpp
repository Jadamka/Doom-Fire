#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "../include/colors.h"

#define FIRE_WIDTH 200
#define FIRE_HEIGHT 200

void doFire(sf::Image& framebuffer);
void spreadFire(int from, sf::Image& framebuffer);

int main()
{
    std::srand(std::time(0));
    sf::RenderWindow window(sf::VideoMode({FIRE_WIDTH, FIRE_HEIGHT}), "Doom FIRE!");
    window.setFramerateLimit(60);

    sf::Image framebuffer(sf::Vector2u({FIRE_WIDTH, FIRE_HEIGHT}), FireColor::palette[0]);

    sf::Texture texture;
    texture.loadFromImage(framebuffer);
   
    sf::Sprite fire(texture);

    while(window.isOpen()){
        while(const std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)){
            for(int i = 0; i < FIRE_WIDTH; i++){
                framebuffer.setPixel(sf::Vector2u({(unsigned int)i, FIRE_HEIGHT - 1}), FireColor::palette[35]);
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
            for(int i = 0; i < FIRE_WIDTH; i++){
                framebuffer.setPixel(sf::Vector2u({(unsigned int)i, FIRE_HEIGHT - 1}), FireColor::palette[0]);
            }
        }
        

        doFire(framebuffer);
        texture.update(framebuffer);

        window.clear();
        window.draw(fire);
        window.display();
    }

    return 0;
}

void doFire(sf::Image& framebuffer)
{
    for(int x = 0; x < FIRE_WIDTH; x++){
        for(int y = 1; y < FIRE_HEIGHT; y++){
            spreadFire(y * FIRE_WIDTH + x, framebuffer);
        }
    }
}

void spreadFire(int from, sf::Image& framebuffer)
{
    int rand = std::rand() % 3;

    int xfrom = from % FIRE_WIDTH;
    int yfrom = from / FIRE_WIDTH;
    int to = from - FIRE_WIDTH - rand + 1;

    if(to < 0){
        to = 0;
    }
    else if(to >= FIRE_WIDTH * FIRE_HEIGHT){
        to = FIRE_WIDTH * FIRE_HEIGHT - 1;
    }

    int xto = to % FIRE_WIDTH;
    int yto = to / FIRE_WIDTH;

    int colorIndex = FireColor::getColorIndex(framebuffer.getPixel(sf::Vector2u({(unsigned int)xfrom, (unsigned int)yfrom})));
    colorIndex -= (rand & 1);
    if(colorIndex <= 0){
        colorIndex = 0;
    }

    framebuffer.setPixel(sf::Vector2u({(unsigned int)xto, (unsigned int)yto}), FireColor::palette[colorIndex]);
}















