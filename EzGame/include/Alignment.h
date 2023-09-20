#pragma once
#ifndef _EZGAME_ALIGNMENT_H_
#define _EZGAME_ALIGNMENT_H_


// Déclaration du namespace ezgame
namespace ezgame {

    //! \enum Alignment
    //! 
    //! \brief Définit l'alignement des objets graphiques.
    //! 
    //! Cette énumération est utilisée pour aligner les objets de type Circle 
    //! et Text lors de l'affichage. La position finale sur la surface 
    //! graphique dépend : 
    //!  - la position
    //!  - la taille
    //!  - l'alignement
    //! 
    //! Les fonctions Screen::draw (2 surcharges) utilisent toutes ces 
    //! informations pour déterminer la position finale lors de l'affichage.
    //! 
    enum class Alignment {
        BaseLeft = 0,     //!< Cas spécial pour l'alignement du texte. Équivaut à CenterCenter pour un cercle.
        TopLeft,          //!< Aligné en haut à gauche.
        TopCenter,        //!< Aligné en haut au centre.
        TopRight,         //!< Aligné en haut à droite.
        CenterLeft,       //!< Aligné au centre à gauche.
        CenterCenter,     //!< Centré dans les deux dimensions.
        CenterRight,      //!< Aligné au centre à droite.
        BottomLeft,       //!< Aligné en bas à gauche.
        BottomCenter,     //!< Aligné en bas au centre.
        BottomRight       //!< Aligné en bas à droite.
    };

} // namespace ezgame


#endif // _EZGAME_ALIGNMENT_H_