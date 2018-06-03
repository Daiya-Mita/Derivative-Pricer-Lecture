#ifndef PayOff_H 
#define PayOff_H
class PayOff
{
    public:
        enum OptionType {call, put};
        PayOff(double strike, OptionType optionType);
        double operator()(double Spot) const;
    private:
        double myStrike;
        OptionType myOptionType; 
};
#endif