#pragma once
#ifndef _EZGAME_TEXT_H_
#define _EZGAME_TEXT_H_


//#include "Graphical.h"
#include <string>
#include "Vect2d.h"
#include "Alignment.h"
#include "Color.h"


// Déclaration du namespace ezgame
namespace ezgame {

    //! \class Text
    //! 
    //! \brief Classe représentant un texte.
    //! 
    //! \details Cette classe est l'un des deux objets pouvant être affiché à l'écran. 
    //! 
    //! Documentation à venir...
    class Text
    {
    public:
        Text();
        Text(std::string const & text, float textSize, Vect2d const& position, Color const color, Alignment alignment = Alignment::BaseLeft);
        Text(std::string const & text, float textSize, Vect2d const& position, Color const fillColor, Color const edgeColor, float edgeSize, Alignment alignment = Alignment::BaseLeft);
        Text(Text const& other) = default;
        Text& operator=(Text const& other) = default;
        ~Text() = default;

        std::string text() const;
        float textSize() const;
        Vect2d position() const;
        Alignment alignment() const;
        Color fillColor() const;
        Color edgeColor() const;
        float edgeSize() const;

        // to do : textWidth
        // to do : textHeight

        void setText(std::string const& text);
        void setText(size_t number);
        void setText(int number);
        void setText(float number, size_t precision = 3);
        void setText(std::string const& text, float textSize);
        void setTextSize(float textSize);
        void setPosition(Vect2d const& position);
        void setAlignment(Alignment alignment);
        void setFill(Color const& color);
        void setEdge(Color const& color);
        void setEdge(float size);
        void setEdge(Color const& color, float size);
        void setColors(Color const& fillColor, Color const& edgeColor);
        void setColors(Color const& fillColor, Color const& edgeColor, float edgeSize);

    private:
        static float const smMinimumTextSize;
        std::string mText;
        float mTextSize;
        Vect2d mPosition;
        Alignment mAlignment;
        Color mFillColor;
        Color mEdgeColor;
        float mEdgeSize;
    };

} // namespace ezgame


#endif // _EZGAME_TEXT_H_