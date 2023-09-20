#pragma once
#ifndef _EZGAME_APPLICATION_H_
#define _EZGAME_APPLICATION_H_


// Inclusion des bibliothèques
#include <memory>
#include <string>
#include <functional>


//! \brief Le namespace ezgame réuni l'ensemble de la librairie EzGame.
namespace ezgame {

    class Screen;
    class Timer;
    class Keyboard;

    //! \concept GameEngineRequirements
    //!
    //! \brief Ce concept vérifie qu'une classe satisfait aux exigences nécessaires afin de servir de moteur de jeu pour la librairie `EzGame`.
    //! 
    //! \tparam T Le type que le concept évalue.
    //! 
    //! Les exigences sont que la classe T possède :
    //! - les opérations en lecture seule suivantes :
    //!   - `float width() const` : fonction retournant la taille horizontale de la surface graphique.
    //!   - `float height() const` : fonction retournant la taille verticale de la surface graphique.
    //!   - `string title() const` : fonction retournant le titre de la fenêtre graphique.
    //!   - `string iconFileName() const` : fonction retournant le nom du fichier de l'icône de la fenêtre graphique (dossier relatif et nom de fichier complet).
    //! - les opérations en lecture/écriture suivantes :
    //!   - `bool processEvents(Keyboard const& keyboard, Timer const& timer)` : fonction servant faire le traitement de chaque pas de simulation. Lorsque la fonction retourne faux, l'application termine immédiatement.
    //!   - `void processDisplay(Screen & screen)` : fonction servant à redessiner la fenêtre graphique à chaque pas de simulation.
    //! 
    //! Pour être considéré compatibles, il est essentiel que les critères suivants soient **strictement identiques** pour chaque fonction:
    //!  - le nom
    //!  - le type de retour
    //!  - la signature (incluant les `&` et `const`) _ne pas oublié que la mention de fin de fonction `const` fait partie de la signature_
    //! 
    
    //! \cond PRIVATE
    template<typename T>
    concept GameEngineRequirements = requires(T ge, T const gec, ezgame::Keyboard const& k, ezgame::Timer const& t, ezgame::Screen & s) {
        { gec.width() } -> std::same_as<float>;
        { gec.height() } -> std::same_as<float>;
        { gec.title() } -> std::same_as<std::string>;
        { gec.iconFileName() } -> std::same_as<std::string>;
        { ge.provessEvents(k, t) } -> std::same_as<bool>;
        { ge.processDisplay(s) } -> std::same_as<void>;
    };
    //! \endcond
        

    //! \class Application
    //! 
    //! \brief Constitue l'application elle-même et est au coeur de la 
    //! bibliothèque `EzGame`. 
    //!
    //! \details La classe Application simplifie le développement en faisant 
    //! la gestion :
    //!  - des messages de `Windows`
    //!  - de la fenêtre de l'application
    //!  - de l'affichage de la surface graphique
    //!  - du clavier
    //!  - du temps écoulé
    //!  - de la boucle principale en faisant les appels nécessaires
    //! 
    //! La classe repose sur l'appel de la fonction Application::run.
    //! 
    //! La boucle principal du programme est basée sur deux fonctions qui sont 
    //! appelées en boucle afin de rendre l'application interactive. Ces 
    //! deux fonctions ont des rôles précis et sont appelé à chaque pas de 
    //! simulation :
    //!  1. Application::processEvents : mettre à jour le modèle (considérant 
    //!  les entrées du clavier et le temps écoulé)
    //!  2. Application::processDisplay : mettre à jour l'affichage
    //!
    //! Pour exécuter une application `EzGame` il suffit de créer un objet 
    //! de la classe Application et d'appeler la fonction 
    //! Application::run pour démarrer l'application graphique. 
    //! Voici un exemple de code :
    //! 
    //! \code
    //! 
    //! #include <EzGame>
    //! #include "MyAwesomeGameEngine.h"
    //! 
    //! int WinMain()
    //! {
    //!     Application app;
    //!     app.run<MyAwesomeGameEngine>();
    //!     //      ^-- ici on suppose que la classe MyAwesomeGameEngine 
    //!     // répond à toutes les exigences du concept GameEngineRequirements
    //! 
    //!     return 0;
    //! }
    //! \endcode
    //! 
    //! On remarque que le programme utilise la fonction `WinMain` plutôt que 
    //! la fonction `main` comme point d'entrée du programme.
    //! 
    class Application
    {
    public:
        // Constructeurs et destructeur
        //! \brief Constructeur par défaut.
        Application();
        //!
        //! \cond PRIVATE
        Application(Application const&) = delete;
        Application(Application &&) = delete;
        Application& operator=(Application const&) = delete;
        Application& operator=(Application &&) = delete;
        //! \endcond
        //!
        //! \brief Destructeur.
        ~Application(); 

        // Accesseurs
        // 
        //! \brief Retourne la largeur de la surface graphique. 
        //! 
        //! \details La valeur retournée est définie seulement après l'appel 
        //! de la fonction Application::run. Sinon, la valeur est 0.
        //! La valeur déterminée par la fonction Application::run est bornée 
        //! par l'interval [64, 2048].
        //! 
        //! \return La dimension horizontale de la surface graphique.
        size_t width() const;
        //!
        //! \brief Retourne la hauteur de la surface graphique. 
        //! 
        //! \details La valeur retournée est définie seulement après l'appel 
        //! de la fonction Application::run. Sinon, la valeur est 0.
        //! La valeur déterminée par la fonction Application::run est bornée 
        //! par l'interval [64, 2048].
        //! 
        //! \return La dimension verticale de la surface graphique.
        size_t height() const;
        //!
        //! \brief Retourne le titre de la fenêtre. 
        //! 
        //! \details La valeur retournée est définie seulement après l'appel 
        //! de la fonction Application::run. Sinon, la valeur est une chaîne 
        //! de caractères vide.
        //! 
        //! Si une chaîne de caractères vide est retournée, le nom par défaut 
        //! de la librairie est utilisé.
        //! 
        //! \return Le titre de l'application.
        std::string title() const;
        //!
        //! \brief Retourne le nom du fichier image utilisé pour l'icône de 
        //! la fenêtre. 
        //! 
        //! \details La valeur retournée est définie seulement après l'appel 
        //! de la fonction Application::run. Sinon, la valeur est une chaîne 
        //! de caractères vide.
        //! 
        //! Le fichier doit être accessible par l'application lors de son 
        //! exécution. Ainsi, le nom du fichier peut inclure un chemin 
        //! d'accès relatif au dossier de travail de l'application ou un 
        //! chemin d'accès absolue. Il est préférable d'utiliser un chemin 
        //! d'accès relatif.
        //! 
        //! Si une chaîne de caractères vide est retournée, l'icône par défaut 
        //! de la librairie est utilisé (à condition que le fichier soit 
        //! accessible). Si le fichier n'est pas accessible, l'icône par défaut 
        //! de Windows est affichée.
        //! 
        //! \return Le nom du fichier de l'icône utilisée pour l'application.
        std::string iconFileName() const;

        // Fonction utilitaire
        // 
        //! \brief Exécute l'application graphique en utilisant le moteur 
        //! donné.
        //! 
        //! \details L'appel de cette fonction lance l'exécution formelle du 
        //! programme. Cette fonction est bloquante et tourne en boucle tant 
        //! qu'elle n'est pas terminée. La fin de son exécution dépend la 
        //! valeur de retour de la fonction `processEvents` 
        //! (voir détails plus bas).
        //! 
        //! Cette fonction est une fonction `template` et requiert une classe 
        //! qui soit donnée à titre d'argument `template` (entre chevrons 
        //! `<...>`). Voir les détails du concept 
        //! ezgame::GameEngineRequirements.
        //! 
        //! Quelques éléments en rafal :
        //!  - `T` doit avoir :
        //!    - `float width() const` : fonction retournant la largeur de la fenêtre graphique. Cette valeur est bornée par l'interval [64, 2048]. Voir la fonction Application::width pour les détails.
        //!    - `float height() const` : fonction retournant la hauteur de la fenêtre graphique. Cette valeur est bornée par l'interval [64, 2048]. Voir la fonction Application::height pour les détails.
        //!    - `std::string title() const` : fonction retournant le titre de la fenêtre graphique. Voir la fonction Application::title pour les détails.
        //!    - `std::string iconFileName() const` : fonction retournant le nom du fichier de l'icône de la fenêtre graphique. Voir la fonction Application::iconFileName pour les détails.
        //!    - `bool processEvents(ezgame::Keyboard const& keyboard, ezgame::Timer const& timer)` : fonction réalisant les calculs pour chaque pas de simulation.
        //!    - `void processDisplay(ezgame::Screen & screen)` : fonction réalisant la mise à jour de l'affichage pour chaque pas de simulation.
        //! 
        //! Il est important de comprendre que l'application tourne en boucle et 
        //! appel indéfiniment les deux fonctions. 
        //! La valeur retournée par la fonction processEvents 
        //! détermine la fin de la boucle : 
        //!  - si vrai : poursuit l'exécution normale du programme
        //!  - si faux : l'application termine immédiatement et abruptement
        //! 
        //! Ainsi, le corps du programme se résume à :
        //! \verbatim
        //
        //          Application::run
        //          >--------------------+
        //                               |
        //                               |
        //          +--------------------v--------------+
        //          |                    |              |
        //          |           +--------v-------+      |
        //          |     +-----> processEvents  |      |
        //          |     |     +--------v-------+      |
        //          |     |              |              |
        //          |     |              v              |
        //          |     |             _-_             |
        //          |     |          _-'   '-_  faux    |
        //          |     |         <         >------------->[ out ]
        //          |     |          '-_   _-'          |
        //          |     |             'v'             |
        //          |     |         vrai |              |
        //          |     |              |              |
        //          |     |     +--------v-------+      |
        //          |     |     | processDisplay |      |
        //          |     |     +--------v-------+      |
        //          |     |              |              |
        //          |     +--------------+              |
        //          |                                   |
        //          +-----------------------------------+
        //
        // \endverbatim
        //! 
        //! 
        //! 
        //! \tparam GE La classe représentant le moteur de jeu. Cette classe 
        //! doit répondre à toutes les exigences du concept 
        //! ezgame::GameEngineRequirements. 
        //! 
        template <GameEngineRequirements GE>
        void run();

    private:
        class Impl;
        std::unique_ptr<Impl> mImpl;
        void * w();

        friend class Screen;

        using UpdateModelFunction = bool(Keyboard const&, Timer const&);
        using UpdateViewFunction = void(Screen&);
        void run(std::function<UpdateModelFunction> updateModel, std::function<UpdateViewFunction> updateView);
        void setup(size_t width, size_t height, std::string const & title, std::string const & iconFileName);
    };













    //! \cond PRIVATE
    template <GameEngineRequirements GE>
    inline void Application::run() {
        GE gameEngine;
        setup(static_cast<size_t>(gameEngine.width()), static_cast<size_t>(gameEngine.height()), gameEngine.title(), gameEngine.iconFileName());
        run(std::bind(&GE::provessEvents, &gameEngine, std::placeholders::_1, std::placeholders::_2), 
            std::bind(&GE::processDisplay, &gameEngine, std::placeholders::_1));
    }
    //! \endcond



} // namespace ezgame


#endif // _EZGAME_APPLICATION_H_