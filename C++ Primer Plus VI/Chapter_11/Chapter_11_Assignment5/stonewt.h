// stonewt.h -- definicja klasy Stonewt
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
    private:
        enum {Lbs_per_stn = 14}; // liczba funtów na kamień
		enum state {STN, IPND, FPND};
        int stone;               // masa w całych kamieniach
        double pds_left;         // reszta w funtach
        double pounds;           // masa w funtach
		state Mode;
    public:
        Stonewt(double lbs, state st=IPND);          // konstruktor dla funtów
        Stonewt(int stn, double lbs, state st=STN); // konstruktor dla kamieni i funtów
        Stonewt();                    // konstruktor domyślny
        ~Stonewt();

		friend std::ostream & operator<<(std::ostream & os, Stonewt & obj);
		Stonewt operator+(Stonewt & obj) const;	
		Stonewt operator-(Stonewt & obj) const;
		Stonewt operator*(Stonewt & obj) const;
};
#endif

