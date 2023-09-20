#pragma once
#ifndef _EZGAME_CIRCLE_H_
#define _EZGAME_CIRCLE_H_


// Inclusion des bibliothèques
#include "Vect2d.h"
#include "Alignment.h"
#include "Color.h"


// Déclaration du namespace ezgame
namespace ezgame {

    //! \class Circle
    //! 
    //! \brief Classe représentant un cercle.
    //! 
    //! \details Cette classe est l'un des deux objets pouvant être affiché à l'écran. 
    //! 
    //! Documentation à venir...
    class Circle
    {
    public:
        Circle();
        Circle(float radius, Vect2d const& position, Color const color, Alignment alignment = Alignment::CenterCenter);
        Circle(float radius, Vect2d const& position, Color const fillColor, Color const edgeColor, float edgeSize, Alignment alignment = Alignment::CenterCenter);
        Circle(Circle const& other) = default;
        Circle& operator=(Circle const& other) = default;
        ~Circle() = default;

        float radius() const;
        Vect2d position() const;
        Alignment alignment() const;
        Color fillColor() const;
        Color edgeColor() const;
        float edgeSize() const;

        bool isColliding(Circle const& circle) const;

        void setRadius(float radius);
        void setPosition(Vect2d const& position);
        void setAlignment(Alignment alignment);
        void setFill(Color const& color);
        void setEdge(Color const& color);
        void setEdge(float size);
        void setEdge(Color const& color, float size);
        void setColors(Color const& fillColor, Color const& edgeColor);
        void setColors(Color const& fillColor, Color const& edgeColor, float edgeSize);

        void adjustSize(float relativeSize);
        void move(Vect2d const& displacement);

    private:
        static float const smMinimumRadius;
        float mRadius;
        Vect2d mPosition;
        Alignment mAlignment;
        Color mFillColor;
        Color mEdgeColor;
        float mEdgeSize;
    };


} // namespace ezgame


#endif // _EZGAME_CIRCLE_H_