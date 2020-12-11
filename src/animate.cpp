#include "animate.hpp"

Animate::Animate()
{
    window.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "GRAPHIC CALCULATOR");
    window.setFramerateLimit(60);
    screenwidthcenter= SCREEN_WIDTH/2;
    screenheightcenter = SCREEN_HEIGHT/2;
    range = hi-lo;
    graph_unit =SCREEN_WIDTH/range;
    _input = "";
    check_input = false;

}
void Animate::Draw(){
    sf::VertexArray x_axis(sf::LinesStrip, 3);
    x_axis[0].position = sf::Vector2f(0,screenheightcenter);
    x_axis[0].color = sf::Color::White;
    x_axis[1].position = sf::Vector2f(SCREEN_WIDTH/2,screenheightcenter);
    x_axis[1].color = sf::Color::White;
    x_axis[2].position = sf::Vector2f(SCREEN_WIDTH, screenheightcenter);
    x_axis[2].color = sf::Color::White;
    window.draw(x_axis);
    sf::VertexArray y_axis(sf::LinesStrip,3);
    y_axis[0].position = sf::Vector2f(screenwidthcenter,0);
    y_axis[0].color = sf::Color::White;
    y_axis[1].position = sf::Vector2f(screenwidthcenter,SCREEN_HEIGHT/2);
    y_axis[1].color = sf::Color::White;
    y_axis[2].position = sf::Vector2f(screenwidthcenter, SCREEN_HEIGHT);
    y_axis[2].color = sf::Color::White;
    window.draw(y_axis);
    if(!_input.empty()){
        for(int i=0; i<SMOOTH; i++){
            q = shunting_yard(_input);
            float x = lo + ((graph_unit)*i)/(SCREEN_WIDTH+10000);
            float y = eval(q,x);
            x = x*graph_unit+(screenwidthcenter);
            y = -(y*graph_unit) + (screenheightcenter);
            sf::CircleShape hold(4);
            hold.setPosition(x,y);
            hold.setFillColor(sf::Color::White);
            c.push_back(hold);
        }
        for(int i =0; i<c.size();i++){
            window.draw(c.at(i));
        }
        c.clear();
    }
}
void Animate::Render(){
    window.clear();
    Draw();
    window.display();
}
void Animate::ProcessEvents(){
    sf::Event event;
    GraphingStrategy a;
    Handler* handler1 = new ConcreteHandler1();
    Handler* handler2 = new ConcreteHandler2();
    handler1->setNextHandler(handler2);
    string new_input;
    while(window.pollEvent(event)){
        switch(event.type){
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            switch(event.key.code){
            case sf::Keyboard::Escape:
                handler1->handleRequest(Request(1));
                if(handler1->get_code()==1){
                    window.close();
                }
                break;
            case sf::Keyboard::F:
                handler1->handleRequest(Request(2));
                if(handler2->get_code()==2){
                    cout<<"Enter your function (with variable x): ";
                    cin>>_input;
                    while(a.inputIsValid(_input)==0){
                        cout<<"Invalid Input try again : ";
                        cin>>_input;
                    }
                    check_input = true;
                }
                break;
            default:
                break;
            }
        }
    }

}

void Animate::Run(){
    cout<<"Press f to input new function and press ESC to close program and return to main menu"<<endl<<endl;
    while(window.isOpen()){
        ProcessEvents();
        Render();
        window.clear();
    }
}
