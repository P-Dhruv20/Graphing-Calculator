#ifndef ANIMATE_HPP
#define ANIMATE_HPP
#include <SFML/Graphics.hpp>
#include "eval.hpp"
#include <string>
#include <vector>
#include "constant.hpp"
#include "graphingstrategy.hpp"
#include "concretehandler1.hpp"
#include "concretehandler2.hpp"

class Animate{
public:
    Animate();
    void Run ();
    void Update();
    void Render();
    void ProcessEvents();
    void Draw();
private:
    bool check_input;
    sf::RenderWindow window;
    string _input;
    vector<sf::CircleShape> c;
    queue<Base*> q;
    int range;
    double screenwidthcenter;
    double screenheightcenter;
    double graph_unit;
    float hi = 15;
    float lo = -15;

};

#endif // ANIMATE_HPP
