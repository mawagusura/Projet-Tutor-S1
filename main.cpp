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
    // cr�ation de la fen�tre
    RenderWindow window(VideoMode(960, 540), "Upmusic");
    Image icon;
    icon.loadFromFile("image/music32_v2.png");
    window.setIcon(32,32,icon.getPixelsPtr());

    //Initialisation des polices de caract�res et du text
    Font arial;
    arial.loadFromFile("font/arial.ttf");
    Text text;
    text.setFont(arial);

    //Cr�ation d'une texture vide (� remplir dans la boucle)
    Texture menu;
    if (!menu.loadFromFile("image/menu.jpg"))
    {
        return EXIT_FAILURE;
    }
    menu.setSmooth(true);

    //Cr�ation du sprite, et redimmensionnement de la texture � la taille de la fenetre
    Sprite background;

    Vector2u TextureSize= menu.getSize();  //Added to store texture size. //Get size of texture.
    Vector2u WindowSize= window.getSize();;   //Added to store window size. //Get size of window.

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y;     //Calculate scale.

    background.setTexture(menu);
    background.setScale(ScaleX, ScaleY);      //Set scale.

    //Cr�ation de la musique
    Music music;
    if (!music.openFromFile("music/happylittlepill.wav"))
        return EXIT_FAILURE;

    // Play the music
    music.play();

    // on fait tourner le programme tant que la fen�tre n'a pas �t� ferm�e
    while (window.isOpen())
    {
        // on traite tous les �v�nements de la fen�tre qui ont �t� g�n�r�s depuis la derni�re it�ration de la boucle
        Event event;
        while (window.pollEvent(event))
        {
            // on regarde le type de l'�v�nement...
            switch (event.type)
            {
                // fen�tre ferm�e
                case Event::Closed:
                    window.close();
                    break;

                // touche press�e
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Escape){
                        text.setString("Echap");
                        cout<<"Touche Echap press�"<<endl;
                    }
                    if (event.key.code == Keyboard::Space){
                        text.setString("Espace");
                        cout<<"Touche Espace presse"<<endl;
                    }
                    break;

                // on ne traite pas les autres types d'�v�nements
                default:
                    break;
            }
        }
        // Clear Window
        window.clear(Color::White);
        // c'est ici qu'on dessine tout
        window.draw(background);
        window.draw(text);

        // fin de la frame courante, affichage de tout ce qu'on a dessin�
        window.display();
    }

    return 0;
}
