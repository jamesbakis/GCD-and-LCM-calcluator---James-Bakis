#ifndef FACTOR_H
#define FACTOR_H

class Factor {

    public:
        Factor(int);
        int getValue();
        int getOccurence();
        void setValue(int);
        void incrementOccurence();
    private:
        int value = 0;
        int occurence = 0;
};

#endif