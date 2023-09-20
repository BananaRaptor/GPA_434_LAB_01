#pragma once
#ifndef _EZGAME_SCREEN_H_
#define _EZGAME_SCREEN_H_


// Inclusion des bibliothèques
#include <memory>
#include "Color.h"
#include "Circle.h"
#include "Text.h"


// Déclaration du namespace ezgame
namespace ezgame {
    
    class Application;

    //! \class Screen
    //! 
    //! \brief Classe permettant de dessiner à l'écran.
    //! 
    //! \detail La classe Screen permet de dessiner sur la surface graphique 
    //! les primitives disponibles avec la librairie `EzGame`.
    //! 
    //! Il est possible de :
    //!  - connaître la taille de la surface graphique (voir Screen::width et Screen::height)
    //!  - remplir la surface graphique d'une couleur uniforme (voir Screen::clear)
    //!  - dessiner un objet Circle ou Text (voir Screen::draw)
    //! 
    class Screen
    {
    public:
        // Accesseurs
        //!
        //! \brief Retourne la largeur de la surface graphique.
        size_t width() const;
        //!
        //! \brief Retourne la hauteur de la surface graphique.
        size_t height() const;

        // Mutateurs
        //!
        //! \brief Rempli l'écran de la couleur noire. La couleur étant 
        //! opaque, efface tout les éléments présents.
        void clear();
        //!
        //! \brief Rempli l'écran de la couleur donnée. La transparence 
        //! de la couleur est utilisée.
        void clear(Color const& color);
        //!
        //! \brief Dessine le cercle donné.
        void draw(Circle const& circle);
        //!
        //! \brief Dessine le texte donné.
        void draw(Text const& text);

    private:
        Screen(Application & app);
        Screen(Screen const &) = delete;
        Screen(Screen &&) = delete;
        Screen& operator=(Screen const &) = delete;
        Screen& operator=(Screen &&) = delete;
        ~Screen();

        class Impl;
        std::unique_ptr<Impl> mImpl;

        friend class Application;
    };

} // namespace ezgame

#endif // _EZGAME_SCREEN_H_