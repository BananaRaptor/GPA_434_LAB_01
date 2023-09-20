#pragma once
#ifndef _EZGAME_VECT_2_D_H_
#define _EZGAME_VECT_2_D_H_


// Inclusion des bibliothèques
#include <random>
#include <string>
#include <iostream>


// Déclaration du namespace ezgame
namespace ezgame {

	//! \class Vect2d
	//! 
	//! \brief Classe représentant un vecteur mathématique dans l'espace 2d.
	//! 
	//! \details Cette classe est utilisée à divers endroits de la librairie 
	//! comme :
	//! - outil de calcul vectoriel
	//! - représenter une position dans l'esapce (un point)
	//! 
	//! Documentation à venir...
	class Vect2d
	{
	public:
		Vect2d();
		Vect2d(float x, float y);
		Vect2d(Vect2d const& other) = default;
		Vect2d& operator=(Vect2d const& other) = default;
		~Vect2d() = default;

		static Vect2d fromPolar(float length, float orientation);
		static Vect2d fromNormalized(float orientation);
		static Vect2d fromRandomized();
		static Vect2d fromRandomized(float xMin, float xMax, float yMin, float yMax);
		static Vect2d fromPolarRandomized(float lengthMin, float lengthMax);
		static Vect2d fromPolarRandomized(float lengthMin, float lengthMax, float oriMin, float oriMax);

		bool isDefined() const;
		bool isNormalized() const;

		float x() const;
		float y() const;
		void setX(float x);
		void setY(float y);
		void set(float x, float y);

		float squaredLength() const;
		float length() const;
		float orientation() const;
		void setSquaredLength(float squaredLength);
		void setLength(float length);
		void setOrientation(float orientation);
		void setPolar(float length, float orientation);

		Vect2d normalized() const;
		void normalize();

		float squaredDistance(Vect2d const& other) const;
		float distance(Vect2d const& other) const;

		void randomize();
		void randomize(float xMin, float xMax, float yMin, float yMax);
		void randomizePolar(float lengthMin, float lengthMax);
		void randomizePolar(float lengthMin, float lengthMax, float oriMin, float oriMax);

		std::string toString() const;

		bool operator==(Vect2d const& other) const;
		bool operator!=(Vect2d const& other) const;

		Vect2d operator+(Vect2d other) const;
		Vect2d operator-(Vect2d other) const;
		Vect2d operator*(float scalar) const;
		Vect2d operator/(float scalar) const;
		friend Vect2d operator*(float scalar, Vect2d const& other);
		friend Vect2d operator/(float scalar, Vect2d const& other);

		Vect2d& operator+=(Vect2d const& other);
		Vect2d& operator-=(Vect2d const& other);
		Vect2d& operator*=(float scalar);
		Vect2d& operator/=(float scalar);

		friend std::ostream& operator<<(std::ostream& stream, Vect2d const& vector);

		static std::string prefix();
		static std::string separator();
		static std::string suffix();
		static void setPrefix(std::string const& prefix);
		static void setSeparator(std::string const& separator);
		static void setSuffix(std::string const& suffix);
		static void setFormat(std::string const& prefix, std::string const& separator, std::string const& suffix);

		static float epsilon();
		static void setEpsilon(float epsilon);

	private:
		static float smEpsilon;
		static size_t smPrecision;
		static std::string smPrefix;
		static std::string smSeparator;
		static std::string smSuffix;

		float mX;
		float mY;

		static bool floatsApproxZero(float a, float epsilon);
		static bool floatsApproxEqual(float a, float b, float epsilon);
	};

} // namespace ezgame

#endif // _EZGAME_VECT_2_D_H_