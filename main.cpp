#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>


using namespace sf;
using namespace std;


int main()
{
    // création de la fenêtre
    RenderWindow window(VideoMode(960, 540), "Upmusic");
    Image icon;
    icon.loadFromFile("image/music32_v2.png");
    window.setIcon(32,32,icon.getPixelsPtr());

    //Initialisation des polices de caractères et du text
    Font arial;
    arial.loadFromFile("font/arial.ttf");
    Text text;
    text.setFont(arial);

    //Création d'une texture vide (à remplir dans la boucle)
    Texture menu;
    if (!menu.loadFromFile("image/menu.jpg"))
    {
        return EXIT_FAILURE;
    }
    menu.setSmooth(true);

    //Création du sprite, et redimmensionnement de la texture à la taille de la fenetre
    Sprite background;

    Vector2u TextureSize= menu.getSize();  //Added to store texture size. //Get size of texture.
    Vector2u WindowSize= window.getSize();;   //Added to store window size. //Get size of window.

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    background.setTexture(menu);
    background.setScale(ScaleX, ScaleY);      //Set scale.

    //Création de la musique
    Music music;
    if (!music.openFromFile("music/happylittlepill.wav"))
        return EXIT_FAILURE;

    // Play the music
    music.play();

    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        Event event;
        while (window.pollEvent(event))
        {
            // on regarde le type de l'évènement...
            switch (event.type)
            {
                // fenêtre fermée
                case Event::Closed:
                    window.close();
                    break;

                // touche pressée
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Escape){
                        text.setString("Echap");
                        cout<<"Touche Echap pressé"<<endl;
                    }
                    if (event.key.code == Keyboard::Space){
                        text.setString("Espace");
                        cout<<"Touche Espace presse"<<endl;
                    }
                    break;

                // on ne traite pas les autres types d'évènements
                default:
                    break;
            }
        }
        // Clear Window
        window.clear(Color::White);
        // c'est ici qu'on dessine tout
        window.draw(background);
        window.draw(text);

        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }

    return 0;
}
