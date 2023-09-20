#pragma once
#ifndef _EZGAME_COLOR_H_
#define _EZGAME_COLOR_H_


// Déclaration du namespace ezgame
namespace ezgame {

    //! \class Color
    //! 
    //! \brief Classe représentant une couleur.
    //! 
    //! \detail La représentation d'une couleur est :
    //!  - dans l'espace RGBA 
    //!     - R -> red -> rouge
    //!     - G -> green -> vert
    //!     - B -> blue -> bleu
    //!     - A -> alpha -> opacité
    //!  - chacune des bandes est :
    //!     - représent par un réel de type float
    //!     - normalisée (dans l'interval [0.0, 1.0])
    //!     - où 0.0f implique aucun et 1.0f veut dire tout, par exemple, 
    //!       {1, 0, 0} indique tout le rouge et aucun vert, aucun bleu 
    //!       => la couleur est rouge
    //! 
    //! Cette classe fournit des méthodes pour :
    //!  - manipuler les couleurs dans les espaces colorimétriques RGB, HSV et HSL 
    //!  - mélanger des couleurs
    //!  - assombrir et éclaircir
    //!  - définir aléatoirement (selon une distribution uniforme)
    //! 
    //! Quelques couleurs sont prédéfénies :
    //!  - Color::Transparent
    //!  - Color::NoColor
    //!  - Color::Black
    //!  - Color::Red
    //!  - Color::Green
    //!  - Color::Blue
    //!  - Color::Yellow
    //!  - Color::Cyan
    //!  - Color::Magenta
    //!  - Color::White
    //!  - Color::Orange
    //!  - Color::Lime
    //!  - Color::Fuchsia
    //!  - Color::Violet
    //!  - Color::Aqua
    //!  - Color::Sky
    //!  - Color::Gray
    //! 
    //! Cette classe est organisée de façon à contenir et maintenir 
    //! exclusivement les valeurs rouge, vert, bleu et alpha de l'espace 
    //! colorimétrique RGB. Les valeurs des autres espaces colorimétriques 
    //! sont calculées au besoin. 
    //! 
    //! L'alignement en mémoire est :
    //!  - 4 réels de 32 bits chacun (float)
    //!  - pour un total de 128 bits, ou 16 octets
    //!  - R-G-B-A
    class Color
    {
    public:
        //! \brief Constructeur par défaut. 
        //! 
        //! \details Initialise un objet Color en noir avec une opacité 
        //! complète.
        Color();
        //! 
        //! \brief Constructeur avec initialisation. 
        //! 
        //! \details Initialise un objet Color avec les valeurs RGBA spécifiées.
        //! 
        //! \param red Composante rouge [0.0, 1.0]
        //! \param green Composante verte [0.0, 1.0]
        //! \param blue Composante bleue [0.0, 1.0]
        //! \param alpha Composante alpha [0.0, 1.0], par défaut à 1.0 (opaque)
        Color(float red, float green, float blue, float alpha = 1.0);
        //! 
        //! \brief Destructeur.
        ~Color() = default;

        //! \cond PRIVATE
        Color(Color const& color) = default;
        Color(Color && color) = default;
        Color& operator=(Color const& color) = default;
        Color& operator=(Color && color) = default;
        //! \endcond

        //! \brief Obtient la composante rouge.
        //! 
        //! \return Le niveau de rouge [0.0, 1.0].
        float red() const;
        //!
        //! \brief Obtient la composante verte.
        //! 
        //! \return Le niveau de vert [0.0, 1.0].
        float green() const;
        //!
        //! \brief Obtient la composante bleue.
        //! 
        //! \return Le niveau de vert [0.0, 1.0].
        float blue() const;
        //!
        //! \brief Obtient la composante alpha.
        //! 
        //! \return Le niveau d'alpha [0.0, 1.0].
        float alpha() const;
        //! 
        //! \brief Obtient la composante de teinte dans l'espace 
        //! colorimétrique HSL.
        //! 
        //! \return La composante de teinte en HSL [0.0, 1.0].
        float hslHue() const;
        //! 
        //! \brief Obtient la composante de saturation dans l'espace 
        //! colorimétrique HSL.
        //! 
        //! \return La composante de saturation en HSL [0.0, 1.0].
        float hslSaturation() const;
        //! 
        //! \brief Obtient la composante de luminosité dans l'espace 
        //! colorimétrique HSL.
        //! 
        //! \return La composante de luminosité en HSL [0.0, 1.0].
        float hslLightness() const;
        //! 
        //! \brief Obtient les composantes de teinte, de saturation et de 
        //! luminosité dans l'espace colorimétrique HSL.
        //! 
        //! \details Cette fonction remplit les valeurs des paramètres avec 
        //! les composantes de teinte, de saturation et de luminosité de la 
        //! couleur.
        //! 
        //! \param hue Référence à une variable float pour stocker la teinte 
        //! [0.0, 1.0].
        //! \param saturation Référence à une variable float pour stocker la 
        //! saturation [0.0, 1.0].
        //! \param lightness Référence à une variable float pour stocker la 
        //! luminosité [0.0, 1.0].
        void getHsl(float& hue, float& saturation, float& lightness) const;
        //! 
        //! \brief Obtient la composante de teinte dans l'espace 
        //! colorimétrique HSV.
        //! 
        //! \return La composante de teinte en HSV [0.0, 1.0].
        float hsvHue() const;
        //! 
        //! \brief Obtient la composante de saturation dans l'espace 
        //! colorimétrique HSV.
        //! 
        //! \return La composante de saturation en HSV [0.0, 1.0].
        float hsvSaturation() const;
        //! 
        //! \brief Obtient la composante de valeur dans l'espace 
        //! colorimétrique HSV.
        //! 
        //! \return La composante de valeur en HSV [0.0, 1.0].
        float hsvValue() const;
        //! 
        //! \brief Obtient les composantes de teinte, de saturation et de 
        //! valeur dans l'espace colorimétrique HSV.
        //! 
        //! \details Cette fonction remplit les valeurs des paramètres avec 
        //! les composantes de teinte, de saturation et de valeur de la couleur.
        //! 
        //! \param hue Référence à une variable float pour stocker la teinte 
        //! [0.0, 1.0].
        //! \param saturation Référence à une variable float pour stocker la 
        //! saturation [0.0, 1.0].
        //! \param value Référence à une variable float pour stocker la 
        //! valeur [0.0, 1.0].
        void getHsv(float& hue, float& saturation, float& value) const;
        //!
        //! \brief Retourne une nouvelle couleur issue du mélange de la 
        //! couleur actuelle et d'une autre couleur.
        //! 
        //! \details Le mélange ce fait avec une proportion de la couleur 
        //! courante et de la couleur spécifiée.
        //! 
        //! \param otherColor La couleur à mélanger à celle-ci.
        //! \param blendFactor Le pourcentage de couleur à préserver. Le 
        //! pourcentage est défini entre 0 et 1 et sera limité à cet 
        //! intervalle. Par exemple, la valeur 0.25 garde 25% de la présente 
        //! couleur et 75% de la couleur donnée.
        //! \param blendAlpha La valeur indiquant si le canal de transparence 
        //! doit être mélangé. Si oui, mélange la transparence, si faux, la 
        //! transparence reste la même que la couleur courante.
        //! \return La couleur mélangée.
        Color blended(Color const& otherColor, float blendFactor = 0.5, bool blendAlpha = false) const;

        // doc to do
        Color darker(float factor = 0.5) const;
        Color lighter(float factor = 0.5) const;
        // to do : saturated
        // to do : desaturated

        //!
        //! \brief Défini la composante rouge.
        //! 
        //! \param red Le niveau de rouge avec une valeur normalisée. La valeur 
        //! est limitée à l'intervalle [0.0, 1.0].
        void setRed(float red);
        //!
        //! \brief Défini la composante verte.
        //! 
        //! \param green Le niveau de vert avec une valeur normalisée. La valeur 
        //! est limitée à l'intervalle [0.0, 1.0].
        void setGreen(float green);
        //!
        //! \brief Défini la composante bleue.
        //! 
        //! \param blue Le niveau de bleu avec une valeur normalisée. La valeur 
        //! est limitée à l'intervalle [0.0, 1.0].
        void setBlue(float blue);
        //!
        //! \brief Défini la composante alpha.
        //! 
        //! \param alpha Le niveau d'opacité avec une valeur normalisée. La valeur 
        //! est limitée à l'intervalle [0.0, 1.0].
        void setAlpha(float alpha);
        //!
        //! \brief Défini les composantes chromatiques de la couleur.
        //! 
        //! \details Toutes les valeurs doivent être normalisée. Les valeurs
        //! sont limitées à l'intervalle [0.0, 1.0].
        //! 
        //! \param red Le niveau de rouge.
        //! \param green Le niveau de vert.
        //! \param blue Le niveau de bleu.
        void set(float red, float green, float blue);
        //!
        //! \brief Défini les composantes de la couleur.
        //! 
        //! \details Toutes les valeurs doivent être normalisée. Les valeurs
        //! sont limitées à l'intervalle [0.0, 1.0].
        //! 
        //! \param red Le niveau de rouge.
        //! \param green Le niveau de vert.
        //! \param blue Le niveau de bleu.
        //! \param blue Le niveau d'opacité.
        void set(float red, float green, float blue, float alpha);

        void setHslHue(float hue);
        void setHslSaturation(float saturation);
        void setHslLightness(float lightness);
        void setHsl(float hue, float saturation, float lightness);
        void setHsl(float hue, float saturation, float lightness, float alpha);

        void setHsvHue(float hue);
        void setHsvSaturation(float saturation);
        void setHsvValue(float value);
        void setHsv(float hue, float saturation, float value);
        void setHsv(float hue, float saturation, float value, float alpha);

        static Color fromHsl(float hue, float saturation, float lightness, float alpha = 1.0f);
        static Color fromHsv(float hue, float saturation, float value, float alpha = 1.0f);

        //!
        //! \brief Mélange la couleur actuelle et une autre couleur.
        //! 
        //! \details Le mélange ce fait avec une proportion de la couleur 
        //! courante et de la couleur spécifiée.
        //! 
        //! \param otherColor La couleur à mélanger à celle-ci.
        //! \param blendFactor Le pourcentage de couleur à préserver. Le 
        //! pourcentage est défini entre 0 et 1 et sera limité à cet 
        //! intervalle. Par exemple, la valeur 0.25 garde 25% de la présente 
        //! couleur et 75% de la couleur donnée.
        //! \param blendAlpha La valeur indiquant si le canal de transparence 
        //! doit être mélangé. Si oui, mélange la transparence, si faux, la 
        //! transparence reste la même que la couleur courante.
        //! \return La couleur mélangée.
        void blend(Color const& color, float blendFactor = 0.5, bool blendAlpha = false);
        
        // doc to do
        void darken(float factor = 0.5);
        void lighten(float factor = 0.5);
        // to do : saturate
        // to do : desaturate

        void randomize(bool randomizeAlpha = false);
        void randomize( float hueFrom, float hueTo, 
                        float saturationFrom = 0.85f, float saturationTo = 1.0f, 
                        float lightnessFrom = 0.45f, float lightnessTo = 0.55f);
        void randomize( float hueFrom, float hueTo, 
                        float saturationFrom, float saturationTo, 
                        float lightnessFrom, float lightnessTo, 
                        float alphaFrom, float alphaTo);

        static Color randomized(bool randomizeAlpha = false);
        static Color randomized(float hueFrom, float hueTo,
                                float saturationFrom = 0.85f, float saturationTo = 1.0f, 
                                float lightnessFrom = 0.45f, float lightnessTo = 0.55f);
        static Color randomized(float hueFrom, float hueTo,
                                float saturationFrom, float saturationTo, 
                                float lightnessFrom, float lightnessTo, 
                                float alphaFrom, float alphaTo);


        static Color const Transparent; //!< Couleur prédéfinie : transparente [0.0, 0.0, 0.0, 0.0]
        static Color const NoColor; //!< Couleur prédéfinie : transparente [0.0, 0.0, 0.0, 0.0]

        static Color const Black; //!< Couleur prédéfinie : noir [0.0, 0.0, 0.0, 1.0]
        static Color const Red; //!< Couleur prédéfinie : rouge [1.0, 0.0, 0.0, 1.0]
        static Color const Green; //!< Couleur prédéfinie : vert [0.0, 1.0, 0.0, 1.0]
        static Color const Blue; //!< Couleur prédéfinie : bleu [0.0, 0.0, 1.0, 1.0]
        static Color const Yellow; //!< Couleur prédéfinie : jaune [1.0, 1.0, 0.0, 1.0]
        static Color const Cyan; //!< Couleur prédéfinie : cyan [0.0, 1.0, 1.0, 1.0]
        static Color const Magenta; //!< Couleur prédéfinie : magenta [1.0, 0.0, 1.0, 1.0]
        static Color const White; //!< Couleur prédéfinie : blanc [1.0, 1.0, 1.0, 1.0]

        static Color const Orange; //!< Couleur prédéfinie : orange [1.0, 0.5, 0.0, 1.0]
        static Color const Lime; //!< Couleur prédéfinie : lime (vert intense) [0.5, 1.0, 0.0, 1.0]
        static Color const Fuchsia; //!< Couleur prédéfinie : fushia [1.0, 0.0, 0.5, 1.0]
        static Color const Violet; //!< Couleur prédéfinie : violet [0.5, 0.0, 1.0, 1.0]
        static Color const Aqua; //!< Couleur prédéfinie : aqua [0.0, 1.0, 0.5, 1.0]
        static Color const Sky; //!< Couleur prédéfinie : ciel [0.0, 0.5, 1.0, 1.0]

        static Color const LightGray; //!< Couleur prédéfinie : gris pâle [0.75, 0.75, 0.75, 1.0]
        static Color const Gray; //!< Couleur prédéfinie : gris moyen [0.5, 0.5, 0.5, 1.0]
        static Color const DarkGray; //!< Couleur prédéfinie : gris sombre [0.25, 0.25, 0.25, 1.0]
        static Color gray(float level = 0.5); //!< Retourne une couleur du niveau de gris spécifié : [level, level, level, 1.0]

    private:
        float mRed;
        float mGreen;
        float mBlue;
        float mAlpha;

        static float clamp(float value);
        static float hslHueToRGB(float p, float q, float t);
    };

} // namespace ezgame



#endif // _EZGAME_COLOR_H_